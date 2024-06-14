#if 0
1、包含Python.h头文件，以便使用Python API。
2、使用void Py_Initialize()初始化Python解释器，
3、使用PyObject *PyImport_ImportModule(const char *name)和PyObject
*PyObject_GetAttrString(PyObject *o, const char *attr_name)获取sys.path对象，并利用
int PyList_Append(PyObject *list, PyObject *item)将当前路径.添加到sys.path中，以便加载
当前的Python模块(Python文件即python模块)。
4、使用PyObject *PyImport_ImportModule(const char *name)函数导入Python模块，并检查是否
有错误。
5、使用PyObject *PyObject_GetAttrString(PyObject *o, const char *attr_name)函数获取
Python函数对象，并检查是否可调用。
6、使用PyObject *PyObject_CallObject(PyObject *callable, PyObject *args)函数调用
Python函数，并获取返回值。
7、使用void Py_DECREF(PyObject *o)函数释放所有引用的Python对象。
8、结束时调用void Py_Finalize()函数关闭Python解释器。
相关的函数参数说明参考网站（网站左上角输入函数名即可开始搜索）：
https://docs.python.org/zh-cn/3/c-api/import.html
#endif

#include "/usr/include/python3.10/Python.h"
#include "garbage.h"
#include <string.h>
#include <stdlib.h>
//编译此程序需要指定头文件的目录 gcc c_python.c -o c_python -I /usr/include/python3.10 -lpython3.10

void garbage_init(void)
{
    // 初始化Python解释器 让c语言可以执行python代码
    Py_Initialize();
    //先让我知道要导入哪个模块
    PyObject* sys = PyImport_ImportModule("sys");
    //然后获得要导入模块的路径
    PyObject* path = PyObject_GetAttrString(sys, "path");
    //再给当前路径加入到导入模块路径下面
    PyList_Append(path, PyUnicode_FromString("."));  

    return;
}

void garbage_final(void)
{
    Py_Finalize();
}

char* garbage_category(char* category)
{
    //把rubbish导入进来执行
    PyObject* pModule = PyImport_ImportModule("rubbish");
    if(!pModule)
    {
        PyErr_Print();
        printf("Error: failed to load rubbish.py\n"); 
        goto  FAILED_MODULE;     
    }

    PyObject *pFunc = PyObject_GetAttrString(pModule, "alibaba_garbage");
    if(!pFunc)
    {
        PyErr_Print();
        printf("Error: failed to load alibaba_garbage\n");
        goto  FAILED_FUNC;
    }

    //传参操作
    //char* category = "nihao";
    //PyObject* pArgs = Py_BuildValue("(s)", category);

    PyObject* pValue = PyObject_CallObject(pFunc, NULL);
    if(!pValue)
    {
        PyErr_Print();
        printf("Error: function call failed\n");
    }

    char* result = NULL;
    if(!PyArg_Parse(pValue, "s", &result))
    {
        PyErr_Print();
        printf("Error: function return failed\n"); 
        goto  FAILED_VALUE;  
    }

    printf("%s\n", result);
    category = (char*)malloc( sizeof(char) * ((strlen(result))+1) );
    memset(category, 0, ((strlen(result))+1));
    //category = result;
    strncpy(category, result,((strlen(result))+1));
    
    //Py_DECREF(pArgs);
FAILED_MODULE:
    Py_DECREF(pModule);
FAILED_FUNC:
    Py_DECREF(pFunc);
FAILED_VALUE:
    Py_DECREF(pValue);
    return category;
}
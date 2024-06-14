# Git分布式版本控制工具

## 目标



## 概述

### 开发的实际场景

- 备份
- 代码还原
- 协同开发
- 追溯问题代码和编写人的编写时间!

### 版本控制器的方式

- 集中式版本控制工具
- 分布式版本控制工具

### Git

- 速度
- 简单的设计
- 对非线性开发模式的强力支持(允许成千上万个并行开发的分支)
- 完全分布式
- 有能力高效管理Linux内核一样的超大规模项目(速度和数据量)

### 基本概念-工作区文件状态

- untracked 未跟踪 (未被纳入版本控制)
- tracked 已跟踪 (被纳入版本控制)
	1. Unmodified 未修改状态
	2. Modified 已修改状态
	3. Staged 已暂存状态

## git安装与常用命令

- ls
- cat
- touch
- vi

### 基础操作指令

- git add  	 (工作区 	—> 	暂存区)
- git commit      (暂存区 	—> 	本地仓库)
- git status     查看文件状态

#### 查看修改的状态(status)

#### 查看提交日志(log)

- 命令形式:**git log [option]**
	- options
		- – –all 显示所有分支
		- – –pretty=oneline 将提交信息显示为一行
		- – –abbrev-commit 使得输出的commitld简短
		- – –graph 以图的形式显示

#### 版本回退

- 命令形式: **git reset – –hard commit id**
	- 将暂存区的文件取消暂存或者是切换到指定版本


#### 添加文件至忽略列表

#### 远程仓库

- 注意:

	1. 一个本地仓库对应一个远程仓库
	2. 如果是clone的仓库,会自动关联远程仓库

	- 命令形式:   **git remote add 	[自己给远程仓库起个名字 一般叫origin]  	网址**

- 查看远程仓库详细信息
	- 命令形式:   **git remote -v**
- 从远程仓库拉取
	- 命令形式:   **git pull [short-name] [branch-name]**
	- 从远程仓库获取最新版本并合并到本地仓库
- 推送到远程仓库
	- 命令形式:   **git push**

## 分支操作

- 概述:

	1. 分支是Git使用过程中非常重要的概念.使用分支意味着你可以把你的工作从开发主线上分离开来,以免影响开发主线

	2. 同一个仓库可以有多个分支,各个分支相互独立,互不干扰.

	3. 通过git init命令创建本地仓库时默认会创建一个master分支.

- 指令
	1. **git branch**				查看分支
	2. **git branch [name]** 				创建分支
	3. **git checkout [name**]				切换分支
	4. **gir push [short name] [branch-name]**				推送至远程仓库分支
	5. **gir merge [name]**				合并分支:把指定分支的代码合并到当前分支
	6. **gir branch -d [name]**				删除分支
	7. **git push origin --delete [branchName]**				删除远程分支

## 标签操作

- 指令

	| 指令                            |         作用         |
	| :------------------------------ | :------------------: |
	| git tag                         |    列出已有的标签    |
	| git tag [name]                  |       创建标签       |
	| git push [shortname] [name]     | 将标签推送至远程仓库 |
	| gir checkout -b [branch] [name] |       检出标签       |

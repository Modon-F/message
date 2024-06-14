#ifndef __OLE_H__
#define __OLE_H__

extern struct display_info disp;
extern int garbage_flag;

int oled_show(struct display_info *disp,int garbage_flag);
void show_error(int err, int add);
void show_usage(char *progname);
int oled(void);

#endif
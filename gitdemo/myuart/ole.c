#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include "oled.h"
#include "font.h"

int garbage_flag;
int oled_show(struct display_info *disp, int garbage_flag)
{
    int i;
    char buf[100];
    switch (garbage_flag)
    {
        case 1:
            oled_putstrto(disp, 0, 9 + 1, "dry garbage");
            disp->font = font2;
            break;
        case 2:
            oled_putstrto(disp, 0, 9 + 1, "shi garbage");
            disp->font = font2;
            break;
        case 3:
            oled_putstrto(disp, 0, 9 + 1, "recurse garbage");
            disp->font = font2;
            break;
        case 4:
            oled_putstrto(disp, 0, 9 + 1, "laji garbage");
            disp->font = font2;
            break;
        case 5:
            oled_putstrto(disp, 0, 9 + 1, "weishibie garbage");
            disp->font = font2;
            break;                
    }
    oled_send_buffer(disp);
    return 0;
}

void show_error(int err, int add)
{
    printf("\nERROR: %i, %i\n\n", err, add);
}

void show_usage(char *progname)
{
    printf("\nUsage:\n%s <I2C bus device node >\n", progname);
}

int oled(void)
{
    int e;
    char filename[32];
    struct display_info disp;
    memset(&disp, 0, sizeof(disp));
    sprintf(filename, "%s", "/dev/i2c-3");
    disp.address = OLED_I2C_ADDR;
    disp.font = font2;
    e = oled_open(&disp, filename);
    e = oled_init(&disp);
    oled_show(&disp,garbage_flag);
    return 0;
}
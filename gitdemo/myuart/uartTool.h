#ifndef __UARTTOOL_H__
#define __UARTTOOL_H__

int myserialOpen (const char *device, const int baud);
void serialSendstring (const int fd, const char *s, int len);
int serialGetstring (const int fd, char *buffer);

#define SERIAL_DEV "/dev/ttyS5"
#define BAUD 115200

#endif

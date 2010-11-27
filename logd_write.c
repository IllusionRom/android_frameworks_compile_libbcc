#include <cutils/log.h>

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define LOG_BUF_SIZE    1024

int __android_log_print(int prio, const char *tag, const char *fmt, ...)
{
    va_list ap;
    char buf[LOG_BUF_SIZE];

    va_start(ap, fmt);
    vsnprintf(buf, LOG_BUF_SIZE, fmt, ap);
    va_end(ap);

    return __android_log_write(prio, tag, buf);
}

int __android_log_write(int prio, const char *tag, const char *msg)
{
    if (!tag)
        tag = "";

    return fprintf(stderr, "[%s] %s", tag, msg);
}

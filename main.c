#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <unistd.h>
#include <time.h>
#include <stdarg.h>
#include <string.h>

#include "config.h"
#include "defs.h"

void die(int code, char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
    exit(code);
}

void getuptime(char *buffer, int max_length)
{
    struct timespec uptime;
    clock_gettime(CLOCK_BOOTTIME, &uptime);
    int days    = uptime.tv_sec / 86400;
    int hours   = uptime.tv_sec / 3600 % 24;
    int minutes = uptime.tv_sec / 60 % 60;
    int seconds = uptime.tv_sec % 60;

    if (uptime.tv_sec < 60)
        snprintf(buffer, max_length, "Up %d seconds", seconds);
    else if (uptime.tv_sec < 3600)
        snprintf(buffer, max_length, "Up %d minutes", minutes);
    else if (uptime.tv_sec < 86400)
        snprintf(buffer, max_length, "Up %d hours, %d minutes", hours, minutes);
    else
        snprintf(buffer, max_length, "Up %d days, %d hours, %d minutes", days, hours, minutes);
}

int main(int argc, char **argv)
{
    char **art = NULL;
    if (argc > 2)
    {
        die(1, "usage: %s [artname]\n", argv[0]);
    }
    else if (argc == 2)
    {
        for (int i = 0; i < sizeof(arts)/sizeof(struct art_entry); ++i)
            if (!strcmp(arts[i].name, argv[1])) { art = arts[i].art; break; }
        if (!art) die(1, "Art %s not found\n", argv[1]);
    } else
    {
        art = arts[0].art;
    }

    struct utsname uname_buf;
    char hostname[max_hostname_length];
    char username[max_username_length];
    char uptime[max_uptime_length];

    gethostname(hostname, max_hostname_length);
    getlogin_r(username, max_username_length);
    getuptime(uptime, max_uptime_length);
    uname(&uname_buf);

    printf("%s %s@%s\n", art[0], username, hostname);
    printf("%s --\n",    art[1]);
    printf("%s %s %s\n", art[2], uname_buf.sysname, uname_buf.release);
    printf("%s %s\n",    art[3], uptime);
    return 0;
}

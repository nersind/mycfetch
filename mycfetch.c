#define _POSIX_C_SOURCE 200112L

#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#include "config.h"
#include "defs.h"


const char** LC_find() 
{
    const char *lang = getenv("LANG");
    if    (strcmp(lang, "ru_RU.Utf-8") == 0) {return locale_ru;}
    if    (strcmp(lang, "uk_UA.Utf-8") == 0) {return locale_ua;}
    return locale_en;
}

void getuptime(char *buffer, int max_length)
{
    struct timespec uptime;
    clock_gettime(CLOCK_BOOTTIME, &uptime);
    int d    = uptime.tv_sec / 86400;
    int h   = uptime.tv_sec / 3600 % 24;
    int m = uptime.tv_sec / 60 % 60;
    int s = uptime.tv_sec % 60;
    const char** lc = LC_find();

    if (uptime.tv_sec < 60)
        snprintf(buffer, max_length, "%s %d %s",               lc[0], s, lc[1]);
    else if (uptime.tv_sec < 3600)
        snprintf(buffer, max_length, "%s %d %s",               lc[0], m, lc[2]);
    else if (uptime.tv_sec < 86400)
        snprintf(buffer, max_length, "%s %d %s %d %s",         lc[0], h, lc[3], m, lc[2]);
    else
        snprintf(buffer, max_length, "%s %d %s, %d %s, %d %s", lc[0], d, lc[4], h, lc[3], m, lc[2]);
}

int main(int argc, char **argv)
{
    char **art = arts[0].art, *name = argv[1];
    int ret = 0;
    if (name)
    {
        bool found = false;
        for (int i = 0; i < sizeof(arts) / sizeof(*arts); ++i)
            if (!strcmp(arts[i].name, name))
            { art = arts[i].art; found = true; break; }
        if (!found) ret = 69;
    }

    struct utsname uname_buf;
    char hostname[max_hostname_length];
    char username[max_username_length];
    char uptime[max_uptime_length];

    gethostname(hostname, max_hostname_length);
    getlogin_r(username, max_username_length);
    getuptime(uptime, max_uptime_length);
    uname(&uname_buf);

    printf(
        "%s %s@%s\n"
        "%s --\n"
        "%s %s %s\n"
        "%s %s\n",
        art[0], username, hostname,
        art[1],
        art[2], uname_buf.sysname, uname_buf.release,
        art[3], uptime
    );
    return ret;
}

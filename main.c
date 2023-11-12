#include <stdio.h>
#include <sys/utsname.h>
#include <unistd.h>
#include <time.h>

#include "config.h"

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
    struct utsname uname_buf;
    struct timespec uptime_buf;
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
    // #include "order.c"
	return 0;
}

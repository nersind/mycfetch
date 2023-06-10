#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *GetKernelVer(void)
{
	FILE *ptr;
	char *uptime = malloc(50 * sizeof(char));
	for (int i = 0; i < 50; ++i)
		uptime[i] = 0;
	ptr = popen("/bin/uname -r", "r");
	if (ptr == NULL)
		return "idk";
	fgets(uptime, 49, ptr);
	pclose(ptr);
	int i = 0;
	for (i = 0; uptime[i] != 0; ++i);
	uptime[i-1] = 0;
	return uptime;
}

char *GetCurrentUser(void)
{
	char *user = getenv("USER");
	char *host = malloc(25 * sizeof(char));
	char *out = malloc(50 * sizeof(char));
	gethostname(host, 25);
	sprintf(out, "%s@%s", user, host);
	return out;
}

char *GetUptime(void)
{
	FILE *ptr;
	char *uptime = malloc(50 * sizeof(char));
	for (int i = 0; i < 50; ++i)
		uptime[i] = 0;
	ptr = popen("/bin/uptime -p", "r");
	if (ptr == NULL)
		return "idk";
	fgets(uptime, 49, ptr);
	pclose(ptr);
	int i = 0;
	for (i = 0; uptime[i] != 0; ++i);
	uptime[i-1] = 0;
	return uptime+3;
}

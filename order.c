/*
 * Printf needed info
 * Don't include here any libraries
*/

// Gentoo

// printf("\x1B[38;5;135m /‾\\     \x1B[38;5;255m%s\n", GetCurrentUser());
// printf("\x1B[38;5;135m( \x1B[38;5;183mo \x1B[38;5;135m\\\n");
// printf("\x1B[38;5;135m/   /    \x1B[38;5;255m%s\n", GetKernelVer());
// printf("\x1B[38;5;135m\\__/     \x1B[38;5;255m%s\n", GetUptime());

printf(" /‾\\     %s\n", GetCurrentUser());
printf("( o \\\n");
printf("/   /    %s\n", GetKernelVer());
printf("\\__/     %s\n", GetUptime());

// Arch

// printf("   /\\       %s\n", GetCurrentUser());
// printf("  /\\ \\\n");
// printf(" /    \\     %s\n", GetKernelVer());
// printf("/__/\\__\\    %s\n", GetUptime());

// FreeBSD

// printf("\033[31m_    _\033[0m     %s\n", GetCurrentUser());
// printf("\033[31m\\‾‾‾‾/\033[0m\n");
// printf("\033[31m|^ww^|\033[0m     %s\n", GetKernelVer());
// printf("\033[31m\\____/\033[0m     %s\n", GetUptime());

// Just cat

// printf(" ╱|、    %s\n", GetCurrentUser());
// printf("(˚ˎ。7  \n");
// printf(" |、˜〵    %s\n", GetKernelVer());
// printf("じしˍ,)ノ  %s\n", GetUptime());

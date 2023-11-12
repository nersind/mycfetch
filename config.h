const int max_username_length = 128;
const int max_hostname_length = 128;
const int max_uptime_length   = 40;

char *art[] = {
// FreeBSD
    "\033[31m_    _\033[0m",
    "\033[31m\\‾‾‾‾/\033[0m",
    "\033[31m|^ww^|\033[0m",
    "\033[31m\\____/\033[0m"

// Gentoo
// "\x1B[38;5;135m /‾\\",
// "\x1B[38;5;135m( \x1B[38;5;183mo \x1B[38;5;135m\\",
// "\x1B[38;5;135m/   /",
// "\x1B[38;5;135m\\__/"

// Arch
// "   /\\    ",
// "  /\\ \\  ",
// " /    \\  ",
// "/__/\\__\\"

// Just cute cat
// " ╱|、    ",
// "(˚ˎ。7   ",
// " |、˜〵  ",
// "じしˍ,)ノ"
};

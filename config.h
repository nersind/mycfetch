#include "defs.h"

const int max_username_length = 128;
const int max_hostname_length = 128;
const int max_uptime_length   = 40;

struct art_entry arts[] = {
    {
        "cat",
        {
            " ╱|、    ",
            "(˚ˎ。7   ",
            "| 、˜〵  ",
            "じしˍ,)ノ"
        }
    },
    {
        "freebsd",
        {
            "\033[31m_    _\033[0m",
            "\033[31m\\‾‾‾‾/\033[0m",
            "\033[31m|^vv^|\033[0m",
            "\033[31m\\____/\033[0m"
        }
    },
    {
        "gentoo",
        {
            " /‾\\ ",
            "( o \\",
            "/   /",
            "\\__/ "
        }
    },
    {
        "arch",
        {
            "   /\\    ",
            "  /\\ \\  ",
            " /    \\  ",
            "/__/\\__\\"
        }
    }
};

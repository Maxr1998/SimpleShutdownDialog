#include <stdlib.h>
#include <string.h>

const char *i3_exit_cmd = "i3-msg exit";

const char *get_logout_command() {
    const char *current_desktop = getenv("XDG_CURRENT_DESKTOP");
    if (!strcmp(current_desktop, "i3")) {
        return i3_exit_cmd;
    }
    return NULL;
}

#include <stdlib.h>
#include <string.h>

char *get_logout_command() {
    char *cmd = malloc(16);
    const char *current_desktop;

    if (!cmd) return NULL;

    cmd[0] = '\0';

    current_desktop = getenv("XDG_CURRENT_DESKTOP");
    if (!strcmp(current_desktop, "i3")) {
        strcpy(cmd, "i3-msg exit");
    }
    return cmd;
}

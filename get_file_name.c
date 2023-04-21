#include "main.h"

void get_filename(char *cp_cmd, char *filename, int len, int *pos)
{
        if (cp_cmd[len] != '\0')
        {
                filename[*pos] = cp_cmd[len];
                *pos = *pos + 1;
                get_filename(cp_cmd, filename, ++len, pos);
        }
}

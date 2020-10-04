#include <stdio.h>

int main(void)
{
    int i = 0x1;
    char *c = &i;
    if (c[0] == 0x1)
    {
        printf("little endian.\n");
    }
    else
    {
        printf("big endian.\n");
    }
    return 0;
}

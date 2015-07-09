#include <stdio.h>
#include <string.h>

#define TRUE  0x11
#define FALSE 0x00

int main(int argc, char *argv[])
{
    int i;
    int max = 10;
    int still_looping = FALSE;

    for (i = 0; i < max && still_looping; ++i)
    {
        printf("Still looping...\n");
    }

    return 0;
}

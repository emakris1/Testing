#include <stdio.h>
#include <string.h>

#define MAX_BUF_LEN 41
#define MAX_STR_LEN 32
#define VER_STR_START 8

unsigned char ver_str[MAX_BUF_LEN];

void set_str(unsigned char *str);

int main(int argc, char *argv[])
{
    unsigned char buffer[64];

    printf("Enter the version string:");
    scanf("%s", buffer);
    set_str(buffer);
    printf("%s\n", ver_str);

    return 0;
}

void set_str(unsigned char *str)
{
    int len = strlen(str);
    int str_len = (len >= MAX_STR_LEN) ? MAX_STR_LEN : len;

    // copy the unique ID into the start of the version string
    strcpy(ver_str, "VER_STR:");

    // copy str into the version string starting after the unique ID
    memcpy(&ver_str[VER_STR_START], str, str_len);

    // append the null terminator
    ver_str[VER_STR_START+str_len] = 0;
}

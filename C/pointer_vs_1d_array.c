#include <stdio.h>

void ArrayFunction(int *buffer)
{
    int temp = buffer[0];
    printf("%d\n", temp);
}

int main(int argc, char *argv[])
{
    int var = 1337;

    // instead of sending a 1D array to the function,
    // just send the address of an individual variable
    ArrayFunction(&var);
    return 0;
}

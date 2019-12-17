#include <stdio.h>

int main()
{

    const int a = 5;
    const int b = 11;
    // const int *ptr = &a;
    // ptr = &b;

    // int *const ptr = &a;
    // ptr = &b;   // This does not work...

    const int ptr = &a;
    return 0;
}
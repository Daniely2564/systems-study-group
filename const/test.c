// the test have been imported from 'https://www.youtube.com/watch?v=a3SxDgOwYXY'

// Types of Pointers with const keyword

int main()
{
    int a = 10; // creating a dummy variable...
    // try to read from right to left.

    // p is the pointer to integer constant
    const int *p;

    // p is a pointer to a constant integer
    int const *p;

    // Both are the same.
    // p is a pointer to integer constant. Meaning p is not constant, p is a pointer to integer constant.
    p++;    // is valid however,
    (*p)++; // is not valid...

    // this time setting pointer as constant.

    // we will read right to lleft,
    // q is constant pointer to integer.
    int *const q;
    q++;    // not valid.
    (*q)++; // valid.

    // read right to left.
    // r is constant pointer to integer constant
    const int *const r;

    return 0;
}

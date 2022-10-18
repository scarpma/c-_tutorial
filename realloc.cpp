#include <iostream>
#include <cstdlib>

using namespace std;

void printAll(const int *a, const int size)
{
    for (int i=0;i<size;i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(void) {
    int *a;

    // allocate a of size 10
    a = (int *)malloc(sizeof(int)*10);
    for (int i=0;i<10;i++) {
        a[i] = i;
    }
    printAll(a, 10);
    cout << "address of a " << a << endl;

    // ops, I needed a of size 20
    // I can reallocate
    int *b = (int*)realloc(a, sizeof(int)*20);
    cout << "address of a after reallocation " << a << endl;
    cout << "address of b " << b << endl;
    // the old array is automatically deallocated

    // the content of a has been copied into b
    printAll(b,20);
    free(b);
}

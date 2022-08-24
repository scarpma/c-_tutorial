#include <iostream>

using namespace std;

void print_all(const int *a, const int size)
{
    for (int i=0;i<size;i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void merge(int *a, int left, int center, int right)
{
    // create copies of the two sub arrays
    int Nl = center - left + 1;
    int Nr = right - center;
    int al[Nl], ar[Nr];
    for (int i=0;i<Nl;i++)
    {
        al[i] = a[left + i];
    }
    for (int i=0;i<Nr;i++)
    {
        ar[i] = a[center + 1 + i];
    }
    
    // il is the current index for left subarray "al"
    // ir is the current index for right subarray "ar"
    // i_cur is the current index for total array "a"
    int il, ir, i_cur;
    il = 0;
    ir = 0;
    i_cur = left;

    while (il < Nl && ir < Nr)
    // until one of the two have finished its elements
    {
        if (al[il] < ar[ir])
        {
            a[i_cur] = al[il];
            il++;
        } else {
            a[i_cur] = ar[ir];
            ir++;
        }
        i_cur++;
    }

    // fill the remaining elements of "al" or "ar"
    while (il<Nl) {
        a[i_cur] = al[il];
        il++;
        i_cur++;
    }
    while (ir<Nr) {
        a[i_cur] = ar[ir];
        ir++;
        i_cur++;
    }

    return;
}

void mergeSort(int* a, int left, int right)
{
    if (left < right) {
        int center;
        center = (left + right)/2;
        mergeSort(a, left, center);
        mergeSort(a, center+1,right);
        merge(a, left, center, right);
    }
    return;
}


int main(void)
{

    int a[] = {10,2,3,6,10,5,7,8,9};
    print_all(a, 9);
    
    mergeSort(a, 0, 9);

    print_all(a, 9);

    return 0;
}

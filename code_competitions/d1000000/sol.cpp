#include <iostream>

using namespace std;

int argmin(int *a, int size)
{
    int minidx, min, N;
    min = a[0];
    minidx = 0;
    for (int i=1;i<size;i++)
    {
        if (min>a[i]) {min = a[i]; minidx = i;}
    }
    return minidx;
}

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
    int Nl = center - left + 1; // copies from left to center (included)
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

    while (il < Nl && ir < Nr) {
    // until one of the two have finished its elements
        if (al[il] <= ar[ir]) ///////////////////////////////////////////////////////
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
        mergeSort(a, left, center);  // sorts from left to center (included)
        mergeSort(a, center+1, right);
        merge(a, left, center, right);
    }
    return;
}

void selection_sort(int * dS, int size)
{
    int minidx, temp;
    int * p = dS;
    for (int i=0;i<size;i++)
    {
        minidx = argmin(p, size - i); //max of dS from i to end
        // swap elements
        temp = dS[i]; dS[i] = dS[minidx+i]; dS[minidx+i] = temp;
        p ++; // p is dS[i:]
    }

}

int main(void)
{
    int T,N;
    cin >> T;
    //cout << "T: " << T << endl;
    
    for (int ii=1;ii<T+1;ii++)
    {
        cout << "Case #" << ii << ": ";
        cin >> N;
        int dS[N];
        for (int jj=0;jj<N;jj++)
        {
            cin >> dS[jj];
            //cout << dS[jj] << endl;
        }
        //selection_sort(dS, N);
        
        //cout << "dS unordered: ";
        //print_all(dS, N);
        mergeSort(dS, 0, N-1);
        //cout << "dS ordered: ";
        //print_all(dS, N);

        int useless_dices = 0;
        for (int k=1;k<=N;k++)
        {
            if (dS[k-1]<k-useless_dices)
            {
                useless_dices++;
            }
        }
        cout << N - useless_dices << endl;
    }
    return 0;
}















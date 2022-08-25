#include <iostream>

using namespace std;

int sum(int a[], int N)
{
    int res = 0;
    for (int i=0;i<N;i++)
    {
        res += a[i];
    }
    return res;
}

int min(int a, int b, int c)
{
    int res = a;
    if (b<res) {res = b;}
    if (c<res) {res = c;}
    return res;
}


int min(int a, int b)
{
    if (a>b)
    {
        return b;
    } else
    {
        return a;
    }
}

int max(int a, int b)
{
    if (a>b)
    {
        return a;
    } else
    {
        return b;
    }
}


int main(void)
{
    int s1[4], s2[4], s3[4];
    int T;
    int mins[4];

    cin >> T;

    for (int kkk=0;kkk<T;kkk++) {

        cout << "case #" << kkk + 1 << ": ";

        cin >> s1[0] >> s1[1] >> s1[2] >> s1[3];
        cin >> s2[0] >> s2[1] >> s2[2] >> s2[3];
        cin >> s3[0] >> s3[1] >> s3[2] >> s3[3];


        for (int i=0;i<4;i++) // find minimum fill for each color between the printers
        {
            mins[i] = min(s1[i], s2[i], s3[i]);
        }

        if (sum(mins, 4)<1000000)
        {
            cout << "IMPOSSIBLE" << endl;
        } else
        {
            int sol[] = {0,0,0,0};
            int k = 0;
            while (sum(sol, 4) < 1000000)
            {
                sol[k] = min(mins[k], 1000000 - sum(sol, 4));
                k++;
            }
            //cout << "case #" << 
            cout << sol[0] << " " << sol[1] << " " << sol[2] << " " << sol[3] << endl;
        }
    }

    return 0;
}

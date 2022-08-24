#include <iostream>

using namespace std;

int sum(int a[])
{
    int N = size(a);
    //int N = 4;
    cout << "size a " << sizeof(a) << endl;
    cout << "size a[0] " << sizeof(a[0]) << endl;
    cout << "N: " << N << endl;
    int res = 0;
    for (int i=0;i<N;i++)
    {
        res += a[i];
    }
    cout << res << endl;
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
    //int N;
    //cin >> N;

    int s1[4], s2[4], s3[4];
    cin >> s1[0] >> s1[1] >> s1[2] >> s1[3];
    cin >> s2[0] >> s2[1] >> s2[2] >> s2[3];
    cin >> s3[0] >> s3[1] >> s3[2] >> s3[3];

    int mins[4];

    for (int i=0;i<4;i++)
    {
        mins[i] = min(s1[i], s2[i], s3[i]);
        cout << mins[i] << endl;
    }

    if (sum(mins)<1000000)
    {
        cout << "IMPOSSIBLE" << endl;
    } else
    {
        int sol[] = {0,0,0,0};
        int i = 0;
        while (sum(sol) < 1000000)
        {
            sol[i] = min(mins[i], 1000000);
            i++;
            if (sum(sol) > 1000000)
            {
                sol[i] -= sum(sol) - 1000000;
            }
        }
        cout << sol[0] << " " << sol[1] << " " << sol[2] << " " << sol[3] << endl;
    }
    //cout << mins[0] << " " << mins[1] << " " << mins[2] << " " << mins[3] << endl;

    return 0;
}

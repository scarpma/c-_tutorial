//#include <stdlib.h>
#include <iostream>

using namespace std;

string get_border(int N)
{
    string res = "+-";
    for (int i=1;i<N;i++)
    {
        res = res + "+-";
    }
    res = res + "+\n";
    return res;
}
string get_center(int N)
{
    string res = "|.";
    for (int i=1;i<N;i++)
    {
        res = res + "|.";
    }
    res = res + "|\n";
    return res;
}


void draw_punched_card(int R, int C)
{
    string init_border = get_border(C);
    init_border[0] = '.'; init_border[1] = '.';
    string init_center = get_center(C);
    init_center[0] = '.'; init_center[1] = '.';
    cout << init_border; cout << init_center;

    for (int i=1;i<R;i++)
    {
        cout << get_border(C);
        cout << get_center(C);
    }
    cout << get_border(C);

    return;
}


int main(void)
{
    int N, R, C;
    cin >> N;

    for (int i=0;i<N;i++)
    {
        cin >> R >> C;
        cout << "Case #" << i+1 << ":" << endl;
        draw_punched_card(R,C);
    }
}

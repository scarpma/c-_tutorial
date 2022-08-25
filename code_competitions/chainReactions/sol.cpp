#include <iostream>

using namespace std;

struct Machine {
    int N;
    int * F; // fun factors. will be dimension N
    int * P; // connections. will be dimension N
    int * triggered; // 0 if already triggered, 1 otherwise
};

void printMachine(Machine m) {
    cout << "N: " << m.N << endl;
    cout << "F: ";
    for (int i=0;i<m.N;i++) {
        cout << m.F[i] << " ";
    }
    cout << endl;
    cout << "P: ";
    for (int i=0;i<m.N;i++) {
        cout << m.P[i] << " ";
    }
    cout << endl;
    cout << "triggered: ";
    for (int i=0;i<m.N;i++) {
        cout << m.triggered[i] << " ";
    }
    cout << endl;
}

int max(int * a, int size) {
    int temp = a[0];
    for (int i=1;i<size;i++) {
        if (a[i]>temp) {
            temp = a[i];
        }
    }
    return temp;
}

int reaction(Machine m, int index) {
    int cur_index = index;
    int max = 0;
    while (cur_index != 0 and m.triggered[cur_index-1]==1) {
        if (max < m.F[cur_index-1]) {
            max = m.F[cur_index-1];
        }
        m.triggered[cur_index-1] = 0; // mark module as triggered
        cur_index = m.P[cur_index-1]; // go to next module
    }
    return max;
}


// find initiators


int main(void)
{
    int T;
    int ans; // answer
    cin >> T;
    
    for (int cc=1;cc<T+1;cc++)
    {
        Machine m;
        cin >> m.N;
        m.F = new int [m.N];
        m.P = new int [m.N];
        m.triggered = new int [m.N];
        for (int i=0;i<m.N;i++) {
            cin >> m.F[i];
        }
        for (int i=0;i<m.N;i++) {
            cin >> m.P[i];
        }
        for (int i=0;i<m.N;i++) {
            m.triggered[i] = 1;
        }

        printMachine(m);
        int fun = reaction(m,4);
        cout << "fun " << fun << endl;
        //cout << "Case #" << cc << ": " << ans << endl;
        printMachine(m);
    }
    return 0;
}










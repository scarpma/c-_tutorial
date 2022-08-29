#include <iostream>

using namespace std;

int getint (char c) {
    int i = c;
    return i;
}

char next_diff_char(const string str, const int i) {
    int j = i+1;
    for (int j=i+1;j<str.size();j++) {
        if (str[j] != str[i]) {
            return str[j];
        }
    }
    char res = '@';
    return res;
}

string transform_string(string str) {
    int i=0;
    string tr_string;
    char next;

    tr_string.reserve(2*str.size());

    // add new char after char[j] if it is convenient
    while (i<str.size()-1) {
        tr_string += str[i];
        next = next_diff_char(str,i);
        if (next == '@') {i++; break;}
        if (getint(str[i]) <= getint(next)) {
            tr_string += str[i];
        }
        i++;
    }
    // fill remaining chars
    while (i<str.size()) {
        tr_string += str[i];
        i++;
    }

    return tr_string;
}

int main(void) {
    int T;
    string str, tr_str;

    cin >> T;

    for (int i=0;i<T;i++) {
        string str;
        cin >> str;
        tr_str = transform_string(str);
        cout << "Case #" << i+1 << ": " << tr_str << endl;
    }

    return 0;
}

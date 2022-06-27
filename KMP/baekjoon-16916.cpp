#include "iostream"
using namespace std;
// 백준 16916번 부분 문자열

string str;
string pattern;
int table[1000001];

// 접두사와 접미사가 일치하는 문자열의 길이를 저장
void makeTable(const string p, int t[]) {
    for (int i=1, j=0; i<p.size(); i++) {
        while (j>0 && p[i] != p[j]) {
            j = t[j-1];
        }
        if (p[i] == p[j]) {
            t[i] = ++j;
        }
    }
}

void KMP(const string s, const string p, const int t[]) {
    for (int i=0, j=0; i<s.size(); i++) {
        while (j>0 && s[i] != p[j]) {
            j = t[j-1];
        }
        if (s[i] == p[j]) {
            if (j == p.size()-1) {
                cout << 1;
                return;
            }
            j++;
        }
    }
    cout << 0;
}

int main() {
    cin >> str >> pattern;
    makeTable(pattern, table);
    KMP(str, pattern, table);
}

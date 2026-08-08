#include<iostream>
#include<cctype>
#include<vector>
using namespace std;

char maxOcc(string &s) {
    vector<int> count(26,0);
    for(char ch : s) {
        ch = tolower(ch);
        int index = ch - 'a';
        count[index]++;
    }
    int value = -1;
    int idx = 0;
    for(int i = 0; i < 26; i++) {
        if(count[i] > value) {
            value = count[i];
            idx = i;
        }
    }
    return 'a' + idx;
}
int main() {
    string s1 = "a";
    cout << "String: " << s1 << " Max: " << maxOcc(s1) << endl;

    string s2 = "aaaaa";
    cout << "String: " << s2 << " Max: " << maxOcc(s2) << endl;

    string s3 = "abcde";
    cout << "String: " << s3 << " Max: " << maxOcc(s3) << endl;

    string s4 = "abbccc";
    cout << "String: " << s4 << " Max: " << maxOcc(s4) << endl;

    string s5 = "banana";
    cout << "String: " << s5 << " Max: " << maxOcc(s5) << endl;

    string s6 = "mississippi";
    cout << "String: " << s6 << " Max: " << maxOcc(s6) << endl;

    string s7 = "zzzyyyxx";
    cout << "String: " << s7 << " Max: " << maxOcc(s7) << endl;

    string s8 = "leetcode";
    cout << "String: " << s8 << " Max: " << maxOcc(s8) << endl;

    string s9 = "codingninjas";
    cout << "String: " << s9 << " Max: " << maxOcc(s9) << endl;

    string s10 = "aabb";
    cout << "String: " << s10 << " Max: " << maxOcc(s10) << endl;

    string s11 = "bbaa";
    cout << "String: " << s11 << " Max: " << maxOcc(s11) << endl;

    string s12 = "ababab";
    cout << "String: " << s12 << " Max: " << maxOcc(s12) << endl;

    string s13 = "z";
    cout << "String: " << s13 << " Max: " << maxOcc(s13) << endl;

    string s14 = "zzzzzz";
    cout << "String: " << s14 << " Max: " << maxOcc(s14) << endl;

    string s15 = "abcdefghijklmnopqrstuvwxyz";
    cout << "String: " << s15 << " Max: " << maxOcc(s15) << endl;
    return 0;
}
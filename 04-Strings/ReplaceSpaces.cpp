#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string replaceSpaces(string &str) {
        string temp;
        for(char ch : str) {
            if(ch == ' ') {
                temp += "@40";
            }
            else {
                temp += ch;
            }
        }
        return temp;
    }
};

int main() {
    Solution obj;

    string s1 = "My Name Is Srishti";
    cout << obj.replaceSpaces(s1) << endl;

    string s2 = "Hello World";
    cout << obj.replaceSpaces(s2) << endl;

    string s3 = "NoSpaces";
    cout << obj.replaceSpaces(s3) << endl;

    string s4 = " ";
    cout << obj.replaceSpaces(s4) << endl;

    string s5 = "   ";
    cout << obj.replaceSpaces(s5) << endl;

    string s6 = "A B C D";
    cout << obj.replaceSpaces(s6) << endl;

    return 0;
}
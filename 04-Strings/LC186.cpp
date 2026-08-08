// Reverse words in a string II.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void reverse(vector<char> & s, int start, int end) {
        while(start < end) {
            swap(s[start++], s[end--]);
        }
    }

public:
    void reverseWords(vector<char>& s) {
        reverse(s, 0, s.size()-1);
        int start = 0;
        int end = 0;
        while(end < s.size()) {
            while((end < s.size()) && (s[end] != ' ')) {
                end++;
            }
            reverse(s, start, end-1);
            start = end + 1;
            end++;
        }
    }
};

void print(vector<char>& s) {
    for (char ch : s) {
        cout << ch;
    }
    cout << endl;
}

int main() {
    Solution obj;

    vector<char> s1 = {'t','h','e',' ','s','k','y',' ','i','s',' ','b','l','u','e'};
    obj.reverseWords(s1);
    print(s1);

    vector<char> s2 = {'a'};
    obj.reverseWords(s2);
    print(s2);

    vector<char> s3 = {'h','e','l','l','o'};
    obj.reverseWords(s3);
    print(s3);

    return 0;
}
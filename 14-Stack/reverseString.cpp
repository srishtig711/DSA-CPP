#include <iostream>
#include <stack>
#include <string>
using namespace std;

string reverseString(string str) {
    stack <char> st;
    for(char ch : str) {
        st.push(ch);
    }
    string ans = "";
    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main() {
    string testCases[] = {
        "hello",
        "world",
        "abcd",
        "a",
        "",
        "racecar",
        "OpenAI",
        "12345"
    };

    for (string s : testCases) {
        cout << "Original: " << s << endl;
        cout << "Reversed: " << reverseString(s) << endl;
        cout << "------------------" << endl;
    }

    return 0;
}

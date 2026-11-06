#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

bool findRedundantBrackets(string s) {
    stack <char> st;
    for(char ch : s) {
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            st.push(ch);
        }
        else {
            if(ch == ')') {
                bool isRedundant = true;
                while(st.top() != '(') {
                    char top = st.top();
                    if(top == '+' || top == '-' || top == '*' || top == '/') {
                        st.pop();
                        isRedundant = false;
                    }
                }
                if(isRedundant == true)
                    return true;
                st.pop();
            }
        }
    }
    return false;
}

int main() {
    vector<string> testCases = {
        "(a+b)",
        "((a+b))",
        "(a+(b*c))",
        "(a)",
        "(a+b*(c-d))",
        "((a*b)+(c))",
        "a+b",
        "((a))",
        "(a+b)+(c+d)",
        "((a+b)*(c+d))"
    };

    for (string s : testCases) {
        cout << s << " -> " << findRedundantBrackets(s) << '\n';
    }

    return 0;
}

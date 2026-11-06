#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int findMinimumCost(string str) {
    stack <char> st;
    if(str.length() % 2)
        return -1;
    for(char ch : str) {
        if(ch == '{') {
            st.push(ch);
        }
        else {
            if(!st.empty() && st.top() == '{') {
                st.pop();
            }
            else {
                st.push(ch);
            }
        }
    }
    int a = 0, b = 0;
    while(!st.empty()) {
        if(st.top() == '}')
            a++;
        else    
            b++;
        st.pop();
    }
    return (a+1)/2 + (b+1)/2;
}

int main() {
    vector<string> testCases = {
        "{{",
        "{{{}",
        "}{{}}{{{",
        "{{{{}}",
        "}}}}{{",
        "{}{}",
        "",
        "{",
        "}",
        "{{{{",
        "}}}}",
        "{{}}",
        "}{}{{"
    };

    for (string s : testCases) {
        cout << "String: " << s
             << " | Cost: " << findMinimumCost(s) << '\n';
    }

    return 0;
}

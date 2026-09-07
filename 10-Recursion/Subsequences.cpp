#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void solve(string str, string output, int index, vector<string>& ans) {
    if(index >= str.length()) {
        if(output.length() > 0)
            ans.push_back(output);
        return;
    }
    solve(str, output, index+1, ans);
    output.push_back(str[index]);
    solve(str, output, index+1, ans);
}

vector<string> subsequences(string& str) {
    vector<string> ans;
    string output;
    solve(str, output, 0, ans);
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    string str = "abc";
    vector<string> ans;
    ans = subsequences(str);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}

// 2nd approach
/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<string> subsequences(string& str) {
    vector<string> ans;
    for(int mask = 0; mask < (1 << str.length()); mask++) {
        string output;
        for(int i = 0; i < str.length(); i++) {
            if(mask & (1 << i))
                output += str[i];
        }
        if(output.length() > 0)
            ans.push_back(output);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    string str = "abc";
    vector<string> ans;
    ans = subsequences(str);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
    */
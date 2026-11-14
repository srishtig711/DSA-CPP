// Approach 1: using stack

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat[0].size();
        stack<int> s;
        for(int i = 0; i < n; i++) {
            s.push(i);
        }
        while(s.size() > 1) {
            int A = s.top();
            s.pop();
            int B = s.top();
            s.pop();
            if(mat[A][B] == 1) 
                s.push(B);
            else
                s.push(A);
        }
        int ans = s.top();
        int zeroCount = 0;
        for(int i = 0; i < n; i++) {
            if(ans == i || mat[ans][i] == 0)
                zeroCount++;
        }
        if(zeroCount != n)
            return -1;
        int oneCount = 0;
        for(int i = 0; i < n; i++) {
            if(ans != i && mat[i][ans] == 1) {
                oneCount++;
            }
        }
        if(oneCount != n-1)
            return -1;
        return ans;
    }
};

void runTest(vector<vector<int>> mat, int testNo) {
    Solution sol;
    cout << "Test Case " << testNo << ": ";
    cout << sol.celebrity(mat) << endl;
}

int main() {
    runTest({
        {1, 1, 0},
        {0, 1, 0},
        {0, 1, 1}
    }, 1); // Expected: 1

    runTest({
        {1, 0, 0},
        {1, 1, 0},
        {1, 0, 1}
    }, 2); // Expected: 0

    runTest({
        {1, 1, 1},
        {0, 1, 1},
        {0, 0, 1}
    }, 3); // Expected: 2

    runTest({
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    }, 4); // Expected: -1

    runTest({
        {1}
    }, 5); // Expected: 0

    runTest({
        {0, 0},
        {0, 0}
    }, 6); // Expected: -1

    runTest({
        {1, 1},
        {1, 1}
    }, 7); // Expected: -1

    runTest({
        {1, 0, 0, 0},
        {1, 1, 0, 0},
        {1, 1, 1, 0},
        {1, 1, 1, 1}
    }, 8); // Expected: 0

    runTest({
        {1, 1, 1, 1},
        {0, 1, 1, 1},
        {0, 0, 1, 1},
        {0, 0, 0, 1}
    }, 9); // Expected: 3

    runTest({
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    }, 10); // Expected: -1

    runTest({
        {1, 0, 0, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 1},
        {0, 0, 0, 1}
    }, 11); // Expected: 2

    return 0;
}

/* Approach 2: using two pointer

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        int A = 0;
        int B = n-1;
        while(A < B) {
            if(mat[A][B] == 1)
                A++;
            else
                B--;
        }
        int ans = A;
        for(int i = 0; i < n; i++) {
            if(i == ans)
                continue;
            if(!(mat[ans][i] == 0 && mat[i][ans] == 1))
                return -1;
        }
        return ans;
    }
};

void runTest(vector<vector<int>> mat, int testNo) {
    Solution sol;
    cout << "Test Case " << testNo << ": "
         << sol.celebrity(mat) << endl;
}

int main() {
    runTest({
        {1, 1, 0},
        {0, 1, 0},
        {0, 1, 1}
    }, 1); // Expected: 1

    runTest({
        {1, 0, 0},
        {1, 1, 0},
        {1, 0, 1}
    }, 2); // Expected: 0

    runTest({
        {1, 1, 1},
        {0, 1, 1},
        {0, 0, 1}
    }, 3); // Expected: 2

    runTest({
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    }, 4); // Expected: -1

    runTest({
        {1}
    }, 5); // Expected: 0

    runTest({
        {0, 0},
        {0, 0}
    }, 6); // Expected: -1

    runTest({
        {1, 1},
        {1, 1}
    }, 7); // Expected: -1

    runTest({
        {1, 0, 0, 0},
        {1, 1, 0, 0},
        {1, 1, 1, 0},
        {1, 1, 1, 1}
    }, 8); // Expected: 0

    runTest({
        {1, 1, 1, 1},
        {0, 1, 1, 1},
        {0, 0, 1, 1},
        {0, 0, 0, 1}
    }, 9); // Expected: 3

    runTest({
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    }, 10); // Expected: -1

    runTest({
        {1, 1, 1, 1},
        {0, 1, 1, 1},
        {0, 0, 1, 1},
        {0, 0, 0, 1}
    }, 11); // Expected: 3

    return 0;
}
*/
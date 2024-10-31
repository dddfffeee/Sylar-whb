
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>

using namespace std;
class Solution {
public:
    string getSmallestString(string s) {
        int n = s.size();
        bool flag = false;

        for(int i = 0; i < n - 1 && flag == false; i++){
            if(s[i] < s[i + 1] && s[i] % 2 == s[i + 1] % 2){
                char temp = s[i];
                s[i] = s[i + 1];
                s[i + 1] = temp;
                flag = true;
            }
        }

        return s;
    }
};
// Test cases
int main() {
    Solution solution;

    vector<int> num1 = {1,2,1,2,1};
    string test1 = "45320";
    string test2 = "shmtulqrypy";
    string ans = solution.getSmallestString(test1);

    cout << ans << endl;
}

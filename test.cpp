//
// Created by whb on 2024/12/17.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <unordered_set>

using namespace std;
class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<int>> records;
        vector<vector<string>> ans;

        auto helper = [&](auto helper, vector<int> temp){
            int size = temp.size();
            if(size == n){
                records.push_back(temp);
                return;
            }

            unordered_set<int> not_stand;
            for(int i = 0; i < size; i++){
                not_stand.insert(temp[i]);
                if (temp[i] + (size - i) < n){
                    not_stand.insert(temp[i] + (size - i));
                }
                if (temp[i] - size + i >= 0){
                    not_stand.insert(temp[i] - (size - i));
                }
            }
            if(not_stand.size() == n) return;

            for(int i = 0; i < n; i++){
                if(!not_stand.count(i)){
                    temp.push_back(i);
                    helper(helper, temp);
                    temp.pop_back();
                }
            }
        };

        helper(helper, {});

        return records.size();
    }
};
// Test cases
int main() {
    Solution solution;

    int num1 = 4;
    string test1 = "cbbd";
    string test2 = "shmtulqrypy";
    solution.totalNQueens(num1);

//    cout << ans << endl;
}

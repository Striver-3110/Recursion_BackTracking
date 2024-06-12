#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    // TC: --> O(2^n * k)
    //? k here stand for pushing temp into ans
    //? as copying one data structure into another dosent take constant time

    // SC: --> O([let c combination] * [each of average size s])
    void solve(vector<int>& candidates,int n, int ind, int target,vector<vector<int>> & ans,vector<int> temp){
        if(ind == n){
            if(target == 0){
                ans.push_back(temp);
                return;
            }
            return;
        }
        else if(target < 0){
            return;
        }

        // only pick up the element if it is less then the target
        if(candidates[ind] <= target){
            // push and pop should be togather
            // because if you havent pushed how could you pop?
            temp.push_back(candidates[ind]);
            solve(candidates,n,ind,target-candidates[ind],ans,temp);
            temp.pop_back();
        }
        solve(candidates,n,ind+1,target,ans,temp);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates,candidates.size(),0,target,ans, temp);
        return ans;
    }
};


int main() {
    Solution sol;

    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result = sol.combinationSum(candidates, target);

    cout << "Combinations that sum to " << target << " are:" << endl;
    for (const auto& combination : result) {
        cout << "[ ";
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
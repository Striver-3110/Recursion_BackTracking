#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<int>& nums, int ind, int& n, vector<int>& temp, vector<vector<int>>& ans){
        if(ind == n){
            ans.push_back(temp);// takes O(k) where k is size of temp
            return;
        }
        // for(int i = ind; i < n; i++){
        //     if(i > ind && nums[i] == nums[i-1])continue;
        temp.push_back(nums[ind]);
        solve(nums,ind+1,n,temp,ans);
        temp.pop_back();
        // }
        while(ind+1 < nums.size() && nums[ind] == nums[ind+1])ind++;
        solve(nums,ind+1,n,temp,ans);
        // return ;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> temp;
        vector<vector<int>> ans;
        solve(nums,0,n,temp,ans);
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 2};
    
    vector<vector<int>> result = solution.subsetsWithDup(nums);
    
    cout << "Subsets with duplicates:" << endl;
    for (const auto& subset : result) {
        cout << "[";
        for (size_t i = 0; i < subset.size(); ++i) {
            cout << subset[i];
            if (i < subset.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}

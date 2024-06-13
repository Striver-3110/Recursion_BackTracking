#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void solve(int& n, vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp, unordered_map<int, bool>& mp) {
        if (temp.size() == n) {
            ans.push_back(temp);
            return;
        }
        
        for (int i = 0; i < n; i++) {
            if (mp[nums[i]]) continue;
            mp[nums[i]] = true;
            temp.push_back(nums[i]);
            solve(n, nums, ans, temp, mp);
            temp.pop_back();
            mp[nums[i]] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int, bool> mp;
        for (auto& n : nums) {
            mp[n] = false;
        }
        vector<int> temp;
        int n = nums.size();
        solve(n, nums, ans, temp, mp);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3}; // Example input
    vector<vector<int>> result = sol.permute(nums);

    // Print the result
    for (const auto& permutation : result) {
        for (int num : permutation) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // by passing temp as copy variable
    // we can save significant time
    // as we dont have to make a copy
    // of temp for each different recursive call

    void solve(vector<int> &candidates, int ind, int &n, int target, vector<int> &temp, vector<vector<int>> &ans)
    {
        if (ind >= n)
        {
            if (target == 0)
            {
                ans.push_back(temp); // takes O(k) where k is average size of ans array
            }
            return;
        }
        if (target < 0)
        {
            return;
        }
        if (target >= candidates[ind])
        {
            temp.push_back(candidates[ind]);
            // the only difference with the combination sum 1 is
            // here we can not include single number more than one
            // where in comnbination sum 1 we are allowed to include
            // single element of candidates more than one number of times
            solve(candidates, ind + 1, n, target - candidates[ind], temp, ans);
            temp.pop_back();
        }
        // we will ignore the candidate that is in left recursive call
        // for the same level
        // so as to avoid duplicate calls
        // and thus by saving significant space and time complexity

        // [1,1,1,1,1,1,2,3,4]
        // once first one is taken
        // avoid funtion call for that of the successing ones
        while (ind + 1 < candidates.size() && candidates[ind] == candidates[ind + 1])
            ind++;
        solve(candidates, ind + 1, n, target, temp, ans);
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end()); // O(nlogn)
        int sum = 0;
        // for(auto &a: candidates){
        //     sum+= a;
        // }
        // if(target > sum)return ans;

        int n = candidates.size();
        vector<int> temp;
        solve(candidates, 0, n, target, temp, ans);
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solution solution;
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    vector<vector<int>> result = solution.combinationSum2(candidates, target);

    cout << "Combinations that sum to " << target << " are:" << endl;
    for (const auto &combination : result)
    {
        cout << "[";
        for (size_t i = 0; i < combination.size(); ++i)
        {
            cout << combination[i];
            if (i < combination.size() - 1)
                cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}

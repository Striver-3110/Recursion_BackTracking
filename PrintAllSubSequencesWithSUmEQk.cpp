#include <bits/stdc++.h>
using namespace std;


// --> TC: O(2^n) //? bcz for each possible position you are calling the function twice 
// ?either include or exclude
// --> SC: O(n) //? bcz depth of the recursion tree will be at most 'n'!
void printF(int arr[],vector<int> ss, int ind,int n,int sum){
    // only check the sum when the recursion is at its most possible depth
    // or we can say that ind == n
    if(ind == n){
        if(sum == 0){
            for(auto& it: ss){
                cout<<it<<" ";
            }
            if(ss.size() == 0){
                cout<<"{}";
            }
            cout<<endl;
        }
        return;
    }
    ss.push_back(arr[ind]);
    sum = sum-arr[ind];
    printF(arr,ss,ind+1,n,sum);
    ss.pop_back();
    sum = sum+arr[ind];
    printF(arr,ss,ind+1,n,sum);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;

    while (t--)
    {
        int arr[] = {1,1,2};
        int n = 3;
        // vector<int> subSeq;
        
        // cout<<t<<" ";
        printF(arr,{},0,3,2);

    }

    return 0;
}

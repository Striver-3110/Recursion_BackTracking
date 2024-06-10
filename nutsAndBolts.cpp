//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
    
    public:
    
    int partition(char arr[], int left, int right, char pivot) {
        int i = left;
        for(int j = left; j < right; j++){
            if(arr[j] < pivot){
                swap(arr[i],arr[j]);
                i++;
            }else if(arr[j] == pivot){
                swap(arr[j],arr[right]);
                j--;
            }
        }
        swap(arr[i],arr[right]);
        return i;
        
    }

    void quickSort(char nuts[], char bolts[], int left, int right) {
        if (left < right) {
            // Partition nuts array using the pivot from bolts
            int partitionIndex = partition(nuts, left, right, bolts[right]);

            // Now use the partition point from nuts to partition bolts array
            partition(bolts, left, right, nuts[partitionIndex]);

            // Recur for both parts
            quickSort(nuts, bolts, left, partitionIndex - 1);
            quickSort(nuts, bolts, partitionIndex + 1, right);
        }
    }
    void matchPairs(int n, char nuts[], char bolts[]){
        
        //**********************************************************************************
        // approach 1: using sorting
        // TC: O(nlogn)
        // SC: O(1)
                // sort(nuts,nuts+n);
                // for(int i = 0; i < n; i++){
                //     bolts[i] = nuts[i];
                // }
                
        //**********************************************************************************
        
        
        //**********************************************************************************
        // approach 2: using hash map
        // TC: O(nlogn)
        // SC: O(n)
                // map<char,int> mp;
                // for(int i = 0; i < n; i++){// to traverse it takes O(n)
                //     mp[nuts[i]] = 1;//in ordered map Insetion takes (log n) as internally it uses 
                //                     //concept of self balencing tree  red black tree
                // }// total O(nlogn)
                // int i = 0;
                // for(auto& pair: mp){
                //     nuts[i] = pair.first;
                //     bolts[i] = pair.first;
                //     i++;
                // }
        //**********************************************************************************
        
        
        //**********************************************************************************
        // approach 3: using quick sort
        // TC: O(nlogn)
        // SC: O(logn)
        quickSort(nuts,bolts,0,n-1);
        //**********************************************************************************
    }
    
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(n, nuts, bolts);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
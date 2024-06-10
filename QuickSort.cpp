#include <bits/stdc++.h>
using namespace std;

//? definations

#define vi vector<int>
#define vl vector<long>
#define vll vector<long long>
#define pb(a) push_back(a)

int partition(vll& a, int left , int right){
    int pivot = a[left];
    int s = left;
    int e = right;

    while(s < e){
        while(a[s] <= pivot)s++;
        while(a[e] > pivot)e--;
        if(s < e){
            swap(a[s],a[e]);
        }
    }
    swap(a[left],a[e]);
    return e;
}


void quickSort(vll& a, int left ,int right){
    if(left >= right){
        return;
    }
    int mid = partition(a,left,right);
    quickSort(a,left,mid-1);
    quickSort(a,mid+1,right);
    // merge(a,left,mid,right);
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;

    while (t--){
        vll a;
        int n;
        cin>>n;
        for(int i = 0; i < n ; i++){
            int temp = rand() %1000;
            a.pb(temp);
            cout<<temp<<" ";
        }
        cout<<endl;

        quickSort(a,0,n-1);
        for(int i = 0; i < n ; i++){
            cout<<a[i]<<" ";
        }
    }

    return 0;
}

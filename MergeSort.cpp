#include <bits/stdc++.h>
using namespace std;

//? definations

#define vi vector<int>
#define vl vector<long>
#define vll vector<long long>
#define pb(a) push_back(a)

void merge(vll& a, int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;

    vll L,R;
    for(int i = 0; i < n1; i++){
        L.pb(a[i+l]);
    }
    for(int i = 0; i < n2; i++){
        R.pb(a[m+1+i]);
    }

    int i = 0;
    int j = 0;
    int k = l;

    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            a[k++] = L[i++];
        }
        else{
            a[k++] = R[j++];
        }
    }
    while(i < n1){
        a[k++] = L[i++];
    }
    while(j < n2){
        a[k++] = R[j++];
    }
}


void mergeSort(vll& a, int left ,int right){
    //? left == right means that hypothetically divided array has only one element
    //? so no need to divide it further
    //? the base case without = size will result in stack overflow error
    if(left >= right){
        return;
    }
    int mid = left + (right - left)/2;
    mergeSort(a,left,mid);
    mergeSort(a,mid+1,right);
    merge(a,left,mid,right);
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

        mergeSort(a,0,n-1);
        for(int i = 0; i < n ; i++){
            cout<<a[i]<<" ";
        }
    }

    return 0;
}

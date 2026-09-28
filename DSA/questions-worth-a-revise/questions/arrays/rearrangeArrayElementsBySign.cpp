#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>

#define fo(a,b) for(auto i=a;i<b;++i)

using namespace std;

/*
    BRUTE: 
        TC - O(2N)
        SC - O(N)
*/
vi brute(vi &arr){
    int n = arr.size();
    vi pos(n/2, 0), neg(n/2, 0);
    int p=0, s=0;

    for(int i=0; i<n; i++){
        if(arr[i]>0){
            pos[p]=arr[i];
            p++;
        }else{
            neg[s]=arr[i];
            s++;
        }
    }

    for(int i=0; i<n/2; i++){
        arr[2*i] = pos[i];
        arr[2*i+1] = neg[i];
    }

    return arr;
}

/*
    OPTIMAL:
        TC - O(N)
        SC - O(N)
*/

vi optimal(vi &arr){
    int n = arr.size();
    vi ans(n, 0);
    int pos=0, neg=1;

    fo(0, n){
        if(arr[i]>0){
            ans[pos]=arr[i];
            pos+=2;
        }else{
            ans[neg]=arr[i];
            neg+=2;
        }
    }

    return ans;
}

void print(vi arr){
    for(auto i: arr) cout << i << " ";
    cout << endl;
}

int main(){
    vi arr = {3,1,-2,-5,2,-4};
    print(optimal(arr));
    return 0;
}
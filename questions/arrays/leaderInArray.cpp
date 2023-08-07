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

vi brute(vi &arr){
    int n = arr.size(), flag=0;
    vi ans;
    for(int i=0; i<n-1; i++){
        flag=0;
        for(int j=i+1; j<n; j++){
            if(arr[i]>arr[j]){
                continue;
            }else{
                flag=1;
                break;
            }
        }
        if(flag==0) ans.push_back(arr[i]); 
    }

    ans.push_back(arr[n-1]);
    return ans;
}

vi better(vi &arr){
    int n = arr.size(), flag=0;
    vi ans;
    int i=0;
    while(i<n-1){
        flag=0;
        for(int j=i+1; j<n; j++){
            if(arr[i]>arr[j]){
                continue;
            }else{
                i=j;
                flag=1;
                break;
            }
        }
        if(flag==0) ans.push_back(arr[i]); i++;
    }

    ans.push_back(arr[n-1]);
    return ans;
}

/*
    Optimal:
        Needs good observation
        we will iterate from back and keep track of the maximum till i th element...
*/

vi optimal(vi &arr){
    vi ans;
    int maxi=INT_MIN;
    for(int i=arr.size(); i>=0; i--){
        if(arr[i]>maxi){
            ans.push_back(arr[i]);
        }
        maxi = max(maxi, arr[i]);
    }

    return ans;
}

void print(vi arr){
    fo(0, arr.size()) cout << arr[i] << " ";
    cout << endl;
}

int main(){
    vi arr = {10, 22, 12, 3, 0, 6};
    print(brute(arr));
    return 0;
}
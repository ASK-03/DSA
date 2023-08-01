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
        This approach will to compute sum of all two numbers in the array and return the indexs
        of the elements whose sum add upto k
    TC - O(N^2)
    SC - O(1)
*/

vi brute(vi &arr, int k){
    int n = arr.size();
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i]+arr[j] == k) return {i, j};
        }
    }
    return {};
}

/*
    BETTER:
        This approach will be to use hashing... 
    TC -
        when using ordered map
            average case - O(NlogN)

        when using unordered map
            worst case - O(N*N)
            best case - O(N)
    SC - O(N)
*/

vi better(vi &arr, int k){
    mii mpp;
    fo(0, arr.size()){
        if(arr[i]<k){
            if(mpp.find(k-arr[i])!=mpp.end()) return {mpp[k-arr[i]], i};
        }
        mpp[arr[i]] = i;
    }

    return {};
}

/*
    **NOT OPTIMAL WHEN WE HAVE TO RETURN THE INDEXES OF THE ELEMENTS**
    OPTIMAL:

        Optimal in fact is slightly better and will be used when interviewer puts this constraint that you cannot use map

        1. sort the array
        2. use two pointer to find the answer.
    
    TC - O(NlogN)
    SC - O(1)

*/

string optimal(vi &arr, int k){
    sort(arr.begin(), arr.end());
    int i=0, j=1;
    while(i<j && j<arr.size()){
        while(i<j && arr[j]>k-arr[i]){
            i++;
        }
        if(arr[j] == k - arr[i]){
            return "YES";
        }
        j++;
    }

    return "NO";
}

void print(vi &arr){
    fo(0, arr.size()) cout << arr[i] << " ";
    cout << endl; 
}

int main(){
    vi arr = {1,2,3,4,5};
    int k = 6;
    cout << optimal(arr, k) << endl;
    return 0;
}
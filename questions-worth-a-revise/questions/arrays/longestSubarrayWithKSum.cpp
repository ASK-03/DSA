#include<iostream>
#include<vector>
#include<map>

#define ll long long int
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>

#define fo(a,b) for(auto i=a; i<b; i++)

using namespace std;



/*
    Brute:
        1. Find all the subarrays
        2. calc the sum 
        3. find the maximum length subarray with sum = k

    TC - O(N^2)
    SC - O(1)
*/

 ll bruteApproach(vector<int> &arr, ll k){
    ll sum = 0, maxLen = 0;
    for(ll i=0; i<arr.size(); i++){
        sum = 0;
        for(ll j=i; j<arr.size(); j++){
            sum += arr[j];
            if(sum == k) maxLen = max(maxLen, j-i+1);
        }
    }
    return maxLen;
}

/*
    Better:
        This can be made better by using hash...
        1. We will calc prefixSum till j th point and then
            - if prefixSum == k -- we will take maxLen as j index
            - if prefixSum > j -- we will check if hash[prefixSum - k => rem] exists if yes -- maxLen = max(maxLen, j-hash[rem])
        2. save the value of prefixSum and the index it appeared in hash

    TC - O(N*log N) it is bcoz of ordered map but it can be reduced to O(N) in case of unordered map but will be
         O(N*N) in worst case.
    SC - O(N)

    ** IT IS OPTIMAL SOLUTION WHEN THE ARRAY CONTAINS NEGATIVE AND POSITIVE ELEMENTS BOTH **
    ** OTHER OPTIMAL IS ALSO PRESENT WHICH WORKS ONLY WHEN THERE ARE ONLY POSITIVE ELEMENTS **
*/

ll betterApproach(vi &arr, ll k){
    map<ll, int> mpp;
    ll prefixSum = 0, maxLen = 0;
    for(ll i=0; i<arr.size(); i++){
        prefixSum += arr[i];
        if(prefixSum == k) maxLen = max(maxLen, i+1);
        int rem = prefixSum - k;
        if(mpp.find(rem)!=mpp.end()){
            maxLen = max(maxLen, i-mpp[rem]);
        }
        if(mpp.find(rem) == mpp.end()) mpp[prefixSum] = i;
    }

    return maxLen;
}

/*
    Optimal Approach:
        ** OPTIMAL ONLY WHEN THE ARRAY ONLY CONTAINS POSITIVE NUMBERS **
        
        TWO POINTER APPROACH 
            1. we have two pointers starting from 0 th index if sum < k we will move forward j pointer
               if sum > k, we will move forward i pointer. 
            and will take the max(maxLen, j-i+1) when sum == k  

    TC - O(2N) (worst case)
    SC - O(1)
*/

ll optimalApproach(vi &arr, int k){
    ll sum=arr[0], maxLen=0;
    int i=0, j=0;
    while( j<arr.size() ){
        while(i<=j && sum > k){
            sum -= arr[i];
            i++;
        }
        if(sum == k){
            maxLen = max(maxLen, (long long )j-i+1);
        }
        j++;
        if(j<arr.size()) sum += arr[j];
    }
    return maxLen;
}

int main(){
    vector<int> arr = {1,2,3,1,1,1,1};
    ll k = 3;
    cout << optimalApproach(arr, k) << endl;
    return 0;
}
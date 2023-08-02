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
    Brute/Better:
        It will be to compute all the sum of all the subarrays and return the one with maximum sum.
        TC - O(N*N)
        SC - O(1)
*/
int brute(vi &arr){
    int maxi = 0;
    for(int i=0; i<arr.size(); i++){
        for(int j=i; j<arr.size(); j++){
            int temp=0;
            for(int k=i; k<j; k++) temp+=arr[k];
            maxi = max(maxi, temp);
        }
    }

    return maxi;
}

int better(vi &arr){
    int maxi=0, start=0, end=0;
    for(int i=0; i<arr.size(); i++){
        int sum = 0;
        for(int j=i; j<arr.size(); j++){
            sum+=arr[j];
            if(sum > maxi){
                maxi = sum;
                start = i; end = j;
            }
        }
    }

    cout << "start -> " << start << endl;
    cout << "end -> " << end << endl;

    return maxi;
}

/*
    Optimal: 
        KADANE'S ALGORITHM...
        steps:
            - we will be having a variable named sum=0;
            - we will loop around the array 
            - we will add the arr[i] 
                - if sum > 0 - we will move forward
                - if sum <= 0 - we will keep the sum in maxi variable and move forward with sum = 0

        LINK: https://youtu.be/AHZpyENo7k4?list=PLgUwDviBIf0oF6QL8m22w1hIDC1vJ_BHz&t=460
*/

int optimal(vi &arr){
    int sum=0, maxi=INT_MIN, start=0, end=0, tempStart=0;
    fo(0, arr.size()){
        if(sum == 0) tempStart = i;

        sum += arr[i];
        
        if(sum>maxi){
            maxi = sum;
            end = i;
            start = tempStart;
        }
        if(sum<0){
            sum = 0;
        }
    }

    cout << "start -> " << start << endl;
    cout << "end -> " << end << endl;

    return maxi;
}

int main(){
    vi arr = {-2,-3,4,-1,-2,1,5,-3};
    cout << optimal(arr) << endl;
    return 0;
}
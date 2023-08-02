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
    Brute:
        take the element and search in the whole array... return when its more than the size of array... 
        TC - O(N*N)
        SC - O(1)
*/

/*
    Better:
        using hashing 
        TC -
            if using map 
                - O(N*logN)
            if using ordered map
                - best - O(N)
                - average - O(N)
                - worst - O(N*N)
        SC - O(N)
*/

int better(vi &arr){
    map<int, int> mpp;
    fo(0, arr.size()){
        mpp[arr[i]]++;
    }

    for(auto it: mpp){
        if(it.second>arr.size()/2){
            return it.first;
        }
    }

    return -1;
}

/*
    Optimal: 
        One cannot build this approach in the interview itself, unless you have an IQ of 200 :)
        Solution:
            LINK: https://youtu.be/nP_ns3uSh80?list=PLgUwDviBIf0oF6QL8m22w1hIDC1vJ_BHz&t=458
            Steps:
                - Take two variables ele and count... 
                - take the first ele as the ele and count to 1
                - iterate over the array
                    - if count gets equal to 0
                        then change the ele to i and initialize the count to 1
                    - if (arr[i]==ele) 
                        then increase the count by 1
                    - if (arr[i]!=ele)
                        then decrease the count by 1
                - NOTE: 
                    IF IT IS GIVEN THAT THERE WILL ALWAYS EXIST AN ANSWER, THEN THE VALUE IN ELE IN THE END
                    IS THE ANSWER...
                    IF ITS NOT STATED THEN, WE WILL HAVE TO ITERATE OVER THE ARRAY ONCE AGAIN AND CHECK THE 
                    COUNT, IF ITS GREATER THAN THE ARR.SIZE()/2...
*/

int optimal(vi &arr){
    int ele=0, count=0;
    fo(1, arr.size()){
        if(count==0){
            ele=arr[i];
            count++;
        }
        else if(arr[i]==ele){
            count++;
        }
        else{
            count--;
        }
    }
    int count1=0;
    fo(0, arr.size()){
        if(arr[i]==ele) count1++;
    }

    if(count1 > arr.size()/2) return ele;

    return -1;
}

int main(){
    vi arr = {1,1,1,1,2,2,3,};
    cout << optimal(arr) << endl;
    return 0;
}
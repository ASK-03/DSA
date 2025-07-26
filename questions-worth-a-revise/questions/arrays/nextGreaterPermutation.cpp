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
    Question: 
        Link: https://youtu.be/JDOXKqF60RQ

        Question is that you have been given an array, you have to return the next greater permutation of the given array. 
*/

/*
    Brute:
        1. make all the permutations and add in a data structure 
        2. linear search the permutation given
        3. return the next of permutation... if its the last permutation return the first one
*/

/*
    Better:
        using stl if you are using c++ or java
*/

vi better(vi &arr){
    next_permutation(arr.begin(), arr.end());
    return arr;
}

/*
    Optimal:
        - Interviewer can ask you to implement the stl function
        - There are a few observations that are required to solve this question

        Observation: see the video using the link above its very good...
        
*/

vi optimal(vi &arr){
    int idx = -1, n = arr.size();
    for(int i=n-2; i>=0; i--){
        if(arr[i]<arr[i+1]){
            idx = i;
            break;
        }
    }

    if(idx==-1){
        reverse(arr.begin(), arr.end());
        return arr; 
    }

    for(int i=n-1; i>idx; i--){
        if(arr[idx] < arr[i]){
            swap(arr[i], arr[idx]);
            break;
        }
    }

    reverse(arr.begin() + idx + 1, arr.end());

    return arr;
}

void print(vi arr){
    for(auto i: arr) cout << i << " ";
    cout << endl;
}

int main(){
    vi arr = {2,1,5,4,3,0,0};
    print(optimal(arr));
    return 0;
}
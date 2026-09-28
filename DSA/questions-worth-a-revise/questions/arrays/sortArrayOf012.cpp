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
        sort the array 
    
    TC - O(NlogN)
    SC - O(1)

*/

/*
    Better:
        count the number of 0's, 1's and 2's and make a new array that contains them in sorted manner.

    TC - O(2N)
    SC - O(N)
*/
vi better(vi &arr){
    int count0=0, count1=0;
    int n = arr.size();
    fo(0, arr.size()){
        if(arr[i]==0) count0++;
        if(arr[i]==1) count1++;
    }

    vi newArr;
    fo(0, count0) newArr.push_back(0);
    fo(count0, count0+count1) newArr.push_back(1);
    fo(count0+count1, n) newArr.push_back(2);

    return newArr;
}

/*
    Optimal: 
        Yes, optimal for this also exists...
        Name of the algorithm is - Dutch National Flag Algorithm (DNF)

        The algorithm uses three pointers... I will be explaining my best in comments but if it isnt clear
        then LINK is here: https://youtu.be/tp8JIuCXBaU?list=PLgUwDviBIf0oF6QL8m22w1hIDC1vJ_BHz&t=307

        We use three pointers... low, mid and high
            - low pointer contains only 0's in the array
            - low+1 to mid points contains only 1's in the array
            - mid+1 to high - pointing to the unsorted array (array containing 0, 1 and 2)
            - hight to n - contians only 2's in the array

        Initialization - 
            - low and mid pointing to start
            - high pointing to last element

        Process - 
            - when on mid 
                - if arr[mid] == 0
                    - swap elements at mid and low
                    - increment low by 1
                - if arr[mid] == 1
                    - then we just increment mid by 1
                - if arr[mid] == 2
                    - then we swap the elements at mid and high
                    - increment mid by 1
                    - decrement high by 1
        
        Terminating Condition - 
            - mid > high


*/

vi optimal(vi &arr){
    int n = arr.size();
    int low=0, mid=0, high=n-1;

    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[high], arr[mid]);
            high--;
        }
    }

    return arr;
}

void print(vi &arr){
    fo(0, arr.size()) cout << arr[i] << " ";
    cout << endl; 
}

int main(){
    vi arr = {1,1,0,2,1,1,0,2,1,0};
    vi temp = optimal(arr);
    print(temp);
    return 0;
}
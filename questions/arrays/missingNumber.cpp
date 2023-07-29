#include<iostream>
#include<vector>

using namespace std;

/*

It is the most optimal way to solve this problem... but another optimal way is to take sum of array and also sum of all natural numbers till n 
and subtract the sum of all natural numbers till n and sum of array to get the missing number.

For doing it with XOR, you should know two things about XOR...
    1. XOR of a number with itself is always 0.
    2. XOR of a number with 0 is alwaays the number itself.

Utilized these two properties to find the missing number...
*/

int findMissingNumber(vector<int> &arr, int n){
    int temp=0;

    for(int i=1; i<n; i++){
        temp = temp^arr[i-1]^i;
    }

    temp = temp^n;

    return temp;
}


int main(){
    vector<int> arr = {1,2,5,4};
    int n = 5;
    cout << findMissingNumber(arr, n) << endl;
    return 0;
}
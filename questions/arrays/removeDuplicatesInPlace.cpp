#include<iostream>
#include<vector>

using namespace std;

/*

Duplicates can be removed from a *sorted* array like data structure in many ways...

Brute Force: 
1.  using SET, it might look very good solution but its not... set takes O(logN) to insert an element... for n elements in an array it will take 
    O(NlogN), and space complexity will be O(N).

Optimized:
1.  Two pointer approch to determine duplicates in place in a sorted array.
2.  As the array is sorted, we will keep a pointer i starting from first element and j starting from second element to last element and whenever
    we get and element greater than element at i th pointer we will change the (i+1)th element with the element on j th pointer and change 
    value of i -> i+1.

*/

void removeDuplicatesInPlace(vector<int> &arr){
    int n = arr.size();
    if (n <= 1) return;
    int i = 0, j = 1;

    while(j < n){
        if(arr[i] < arr[j]){
            i++;
            arr[i] = arr[j];
        }
        j++;
    }

    for(int k=0; k<(i+1); k++){
        cout << arr[k] << " ";
    }
    cout << endl;
}


int main(){
    vector<int> arr = {1, 2, 3, 3, 4};
    removeDuplicatesInPlace(arr);
    return 0;
}
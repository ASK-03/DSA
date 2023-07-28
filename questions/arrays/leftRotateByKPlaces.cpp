#include<iostream>
#include<vector>

using namespace std;


/*
Rotates the elements of the given array to the left by 1 position.
 */
void rotateArrayToLeftBy1(vector<int> &arr){
    int temp = arr[0];
    for(int i=1; i<arr.size(); i++){
        arr[i-1] = arr[i];
    }

    arr[arr.size()-1] = temp;
}

/*
Rotates the elements in the array by k places
*/

void rotateElementsInArrayByKPlacesBrute(vector<int> &arr, int k){
    /*  
        BRUTE FORCE APPROACH
        TIME COMPLEXITY - O(N+D)
        SPACE COMPLEXITY - O(D)
     */
    if (k > arr.size()) k = k%arr.size();
    vector<int> tempArr;
    
    for(int i=0; i<k; i++) tempArr.push_back(arr[i]);
    for(int i=k; i<arr.size(); i++) arr[i-k] = arr[i];
    for(int i=(arr.size()-k), j=0; i<arr.size(), j<tempArr.size(); i++, j++) arr[i] = tempArr[j]; 
}

void rotate(vector<int> &arr, int start, int end){
    while(start<end){
        swap(arr[start], arr[end]);
        start++; end--;
    }
}
void rotateElementsInArrayByKPlaces(vector<int> &arr, int k){
    /*
        OPTIMIZED APPROACH
        TIME COMPLEXITY : O(2N)
        SPACE COMPLEXITY : O(1)
        - We just have to rotate the array from (0,k) in place, then rotate from (k, n) and then the whole array to get the 
          final results.
    */
   k = k%arr.size();
   rotate(arr, 0, k-1);
   rotate(arr, k, arr.size()-1);
   rotate(arr, 0, arr.size()-1);
}

void print(vector<int> &arr){
    for( auto i : arr) cout << i << " ";
    cout << endl;
}

int main(){
    vector<int> arr = { 1, 2, 3, 4, 5 };
    rotateElementsInArrayByKPlaces(arr, 2);
    print(arr);
    return 0;
}
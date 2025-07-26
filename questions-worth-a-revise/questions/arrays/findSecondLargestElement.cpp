#include<iostream>
#include<vector>

using namespace std;

/*

There are many ways to find second largest element,
- Sorting - O(NlogN)
- Linear pass (2 times) - O(2*N)
- (OPTIMIZED) Linear Pass Using 2 Variables - O(N)

LINK : https://www.codingninjas.com/studio/problems/ninja-and-the-second-order-elements_6581960

*/

int secondLargestElement(vector<int> &arr){
    int largest = arr[0], sslargest = INT16_MIN;
    for(int i=1; i<arr.size(); i++){
        if(arr[i]>largest){
            sslargest = largest;
            largest = arr[i];
        }
        if (arr[i]<largest && arr[i]>sslargest){
            sslargest = arr[i];
        }
    }
    return sslargest;    
}

int main(){
    vector<int> arr = {10, 2, 4, 4, 5};
    cout << secondLargestElement(arr) << endl;
    return 0;
}
#include<iostream>
#include<vector>

using namespace std;

/*
    This property of XOR is used a lot of times... remember this...
    It is also used in the problem -> missingNumber.cpp
    to find the number that was missing... 

    Here, this property is used as we have to find the elements that are appearing in the array twice
    so, XOR with same number will bring it to zero and in the last only the number that is appearing 
    once will remain... 

*/

int findSingleElement(vector<int> &arr){
    int XOR = 0;
    for(auto i : arr){
        XOR = XOR ^ i;
    }

    return XOR;
}

int main(){
    vector<int> arr = {1,1,2,3,3,4,4};
    cout << findSingleElement(arr) << endl;
    return 0;
}
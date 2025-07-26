#include<iostream>
#include<vector>

using namespace std;

/*

Link: https://www.codingninjas.com/studio/problems/ninja-and-the-sorted-check_6581957

*/

bool checkIsSorted(vector<int> &arr){
    int n = arr.size();
    int prevEle = arr[0];
    for(int i=1; i<n; i++){
        if (arr[i]>prevEle){
            prevEle = arr[i];
        }
        else if (arr[i] == prevEle)
        {
            continue;
        }       
        else{
            return false;
        }
    }

    return true;
}

int main(){
    vector<int> sortedVector = { 1, 2, 2, 2, 3, 3, 4 };
    vector<int> unSortedVector = { 1, 3, 2, 4, 3, 3, 4 };

    cout << checkIsSorted(sortedVector) << endl;
    cout << checkIsSorted(unSortedVector) << endl;

    return 0;
}
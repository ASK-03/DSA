#include<iostream>
#include<vector>

using namespace std;

/*
 * Returns the intersection of two arrays.
 * 
 * @param arr1 The first array.
 * @param arr2 The second array.
 * @return The intersection of arr1 and arr2.
 */
vector<int> getIntersectionOfArrays(vector<int> &arr1, vector<int> &arr2) {
    int n1 = arr1.size(), n2 = arr2.size();
    vector<int> intersectionArr;
    int i = 0, j = 0;

    while(i<n1 && j<n2){
        if(arr1[i]>arr2[j]){
            j++;
        }
        else if(arr1[i]<arr2[j]){
            i++;
        }
        else{
            intersectionArr.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    return intersectionArr;
}

void print(vector<int> &arr){
    for(auto i : arr) cout << i << " ";
    cout << endl;
}

int main(){
    vector<int> arr1 = { 1, 2, 3, 4, 5 };
    vector<int> arr2 = { 3, 4, 5, 6 };
    vector<int> intersectionArr = getIntersectionOfArrays(arr1, arr2);
    print(intersectionArr);
    return 0;
}
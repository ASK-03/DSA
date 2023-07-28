#include<iostream>
#include<vector>

using namespace std;

/*
 * Returns the union of two arrays.
 * 
 * @param arr1 The first array.
 * @param arr2 The second array.
 * @return The union of arr1 and arr2.
 */
vector<int> getUnionOfArrays(vector<int> &arr1, vector<int> &arr2) {
    int n1 = arr1.size(), n2 = arr2.size();
    vector<int> unionArr;
    int i = 0, j = 0;

    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            if (unionArr.size() == 0 || unionArr.back() != arr1[i]) {
                unionArr.push_back(arr1[i]);
            }
            i++;
        } else {
            if (unionArr.size() == 0 || unionArr.back() != arr2[j]) {
                unionArr.push_back(arr2[j]);
            }
            j++;
        }
    }

    while (i < n1) {
        if (unionArr.size() == 0 || unionArr.back() != arr1[i]) {
            unionArr.push_back(arr1[i]);
        }
        i++;
    }

    while (j < n2) {
        if (unionArr.size() == 0 || unionArr.back() != arr2[j]) {
            unionArr.push_back(arr2[j]);
        }
        j++;
    }

    return unionArr;
}

void print(vector<int> &arr){
    for(auto i : arr) cout << i << " ";
    cout << endl;
}

int main(){
    vector<int> arr1 = { 1, 2, 3, 4, 5 };
    vector<int> arr2 = { 3, 4, 5, 6 };
    vector<int> unionArr = getUnionOfArrays(arr1, arr2);
    print(unionArr);
    return 0;
}
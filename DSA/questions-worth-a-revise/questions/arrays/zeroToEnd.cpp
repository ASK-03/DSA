#include<iostream>
#include<vector>

using namespace std;

void zeroToEnd(vector<int> &arr){
    int i=0, j=0;
    for(int k=0; k<arr.size(); k++){
        if (arr[k]==0){
            i=k;
            break;
        }
    }
    j = i+1;
    while(j<arr.size()){
        if(arr[j]!=0){
            swap(arr[i], arr[j]);
            i++;
        }    
        j++;
    }
}

void print(vector<int> &arr){
    for(auto i : arr) cout << i << " ";
    cout << endl;
}

int main(){
    vector<int> arr = {1, 2, 0, 2, 3, 0, 3 , 0, 0, 1};
    zeroToEnd(arr);
    print(arr);
    return 0;
}
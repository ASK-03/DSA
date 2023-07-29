#include<iostream>
#include<vector>

using namespace std;

int maxConsecutiveOnes( vector<int> &arr ){
    int maxConsecOnes = 0, currentMaxConsecOnes = 0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] == 1) currentMaxConsecOnes++;
        if(currentMaxConsecOnes>maxConsecOnes) maxConsecOnes = currentMaxConsecOnes;
        if(arr[i]==0) currentMaxConsecOnes=0;
    }
    return maxConsecOnes;
}

int main(){
    vector<int> arr = {1,1,1,0,0,1,1,1,1,1,0,1,1,1,1};
    cout << maxConsecutiveOnes(arr) << endl;
    return 0;
}
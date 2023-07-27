#include<iostream>
#include<vector>

using namespace std;

// SELECTION SORT ALGO
void selection_sort(vector<int> & arr, int n){
    for (int i=0; i<n-1; i++){
        int mini_idx = i; 
        for (int j=i+1; j<n; j++){
            if (arr[j] < arr[mini_idx]){
                mini_idx = j;
            }
            swap(arr[i], arr[mini_idx]);
        }
    }

}

// BUBBLE SORT ALGO
void bubble_sort(vector<int> &arr, int n){
    if (arr.size() < 2){ return; }
    int cycles = arr.size();
    while(cycles--){
        int i=0, j=1;
        while(j <= cycles){
            if (arr[j] < arr[i]){
                swap(arr[j], arr[i]);
            }
            i++; j++;
        }
    }
}

// INSERTION SORT ALGO
void insertion_sort(vector<int> &arr, int n){
    for(int i=1; i<n; i++){
        int j = i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j], arr[j-1]);
            j--;
        }
    }
}

// MERGE SORT ALGO
void merge(vector<int> &arr, int l, int mid, int r, int n){
    vector<int> temp;
    int i = l, j = mid+1;
    while(i<=mid && j<=r){
        if(arr[i]<arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }

    while(j<=r){
        temp.push_back(arr[j]);
        j++;
    }

    for(int i=0; i<r-l+1; i++){
        arr[l+i] = temp[i];
    }
}

void divide(vector<int> &arr, int l, int r, int n){
    if (r<=l){
        return;
    }
    int mid = l + (r-l)/2;
    divide(arr, l, mid, n);
    divide(arr, mid+1, r, n);
    merge(arr, l, mid, r, n);
}

void merge_sort(vector<int> &arr, int n){
    divide(arr, 0, n-1, n);
}

// QUICK SORT ALGO
void partition(vector<int> &arr, int l, int r, int n){
    if (l>=r){
        return;
    }
    int pidx = l;
    int i=l, j=r;
    while(i<j){
        while( i <= r && arr[i]<=arr[pidx]){
            i++;
        }    
        while( j>=l && arr[j]>arr[pidx]){
            j--;
        }

        if (i<j) {
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[j], arr[pidx]);

    partition(arr, l, j-1, n);
    partition(arr, j+1, r, n);
}

void quick_sort(vector<int> &arr, int n){
    partition(arr, 0, n-1, n);
}

// FUNCTION TO PRINT VECTOR
void print(vector<int> &arr){
    for(auto i : arr){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    int n = 6;
    vector<int> arr = {13, 46, 24, 52, 20, 9};

    print(arr);

    quick_sort(arr, n);

    print(arr);

    return 0;
}
#include<iostream>
#include<map>
using namespace std;

// REVERSE AN ARRAY USING RECURSION
void reverse_arr(int arr[], int n, int i){
    if (i >= n/2) return;
    swap(arr[i], arr[n-i-1]);
    reverse_arr(arr, n, i+1);
}

// PALINDROME USING RECURSION
bool check_palindrome(string s, int n, int i){
    if (i >= n/2) return true;
    if (s[i] != s[n-i-1]){
        return false;
    }
    return check_palindrome(s, n, i+1);
}

// FIBONNACI USING RECURSION
int fib(int n){
    if (n < 1) return 0;
    if (n==1) return 1; 
    return fib(n-1) + fib(n-2);
}

// USE OF MAP FOR HASHING
map<int, int> hashing_using_map(int arr[], int n){
    map<int, int> mp;
    for (int i=0; i<n; i++){
        mp[arr[i]]++;
    }
    return mp;
}

int find_in_hash(map<int, int> &mp, int key){
    if (mp.find(key) == mp.end()) return -1;
    return mp[key];
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    map<int, int> mp = hashing_using_map(arr, n);
    for(auto i: mp){
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}
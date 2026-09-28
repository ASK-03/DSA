#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>

#define fo(a,b) for(auto i=a;i<b;++i)

using namespace std;

/*
    Question: you have been given list of stock prices on N days, you have to find the maximum profit... you can sell if you have bought and 
              only can do it once...
*/

int buyOrSellStocks(vi &arr){
    int profit=0;
    int mini = arr[0];

    for(int i=1; i<arr.size(); i++){
        profit = max(arr[i]-mini, profit);
        mini = min(arr[i], mini);
    }   

    return profit;
}

int main(){

    vi arr = {7,1,5,3,6,4};
    cout << buyOrSellStocks(arr) << endl;
    return 0;
}
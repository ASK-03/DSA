#include<bits/stdc++.h>
using namespace std;

template<typename T>

class SparseTable {
    vector<vector<T>> st;
    vector<int> log;
    int n;
    function<T(T,T)> func;

    private:

    public:
    SparseTable(const vector<T> &arr, function<T(T,T)> f) : func(f) {
        n = arr.size();
        log.resize(n+1);
        log[1] = 0;
        for(int i=2; i<=n; i++){
            log[i] = log[i/2] + 1;
        }

        int k = log[n] + 1;
        st.assign(n, vector<T>(k));

        for(int i=0; i<n; i++){
            st[i][0] = arr[i];
        }

        for(int j=1; (1<<j) <= n; j++){
            for(int i=0; (i + (1<<j) - 1) < n; i++){
                st[i][j] = func(st[i][j-1], st[i + (1 << (j-1))][j-1]);
            }
        }
    }

    T query(int l, int r){
        assert(l<r && "l should not be greater than r");
        assert(r<n && "r should be less than n");
        int j = log[r-l+1];
        return func(st[l][j], st[r-(1<<j)+1][j]);
    }
};

int main(){
    vector<int> arr = {2, 5, 1, 4, 9, 3};

    auto func = [](int a, int b){
        return min(a,b);
    };

    SparseTable<int> minTable(arr, func);
    
    cout << minTable.query(2, 4) << endl;

    return 0;
}
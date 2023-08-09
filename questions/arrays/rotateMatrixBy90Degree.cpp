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
    Brute:
        we can see an observation that the elements at position [i][j] goes to [j][n-1-i]

    TC - O(N^2)
    SC - O(N^2) * To create an answer array *
*/

vector<vector<int>> brute(vector<vector<int>> &matrix){
    int n = matrix.size();
    vector<int> temp(n, 0);

    vector<vector<int>> ans (n, temp);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ans[j][n-1-i] = matrix[i][j];
        }
    }

    return ans;
}

/*
    Optimal:
        The problem is SC in the brute, we can change the matrix in-place.
        The observation used here is that, the transpose of the matrix and then reverse of the rows result
        in the rotation of the matrix in-place.

        Link: https://youtu.be/Z0R2u6gd3GU?t=865
     
    TC - O(N^2/4 + N^2/2) ~ O(N^2)
    SC - O(1)
*/

vector<vector<int>> optimal(vector<vector<int>> &matrix){
    int n = matrix.size();
    // transpose of the matrix
        // observation is that the diagonal elements remain at same position
        // elements at position [i][j] go to [j][i]
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for(int i=0; i<n; i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }

    return matrix;
}

void print(vector<vector<int>> matrix){
    int n = matrix.size();
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    vector<vector<int>> matrix = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    vector<vector<int>> temp = optimal(matrix);
    print(temp);
    return 0;
}
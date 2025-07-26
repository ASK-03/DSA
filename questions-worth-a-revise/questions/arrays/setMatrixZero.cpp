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
        - we will iterate over the matrix and will change the row and col to -1 when we find a zero
        - again will iterate over the matrix and will change all the -1 to 0
    TC - O(2*N*M*(N+M)) ~ O(N^3)
    SC - O(1)
*/

vector<vector<int>> brute(vector<vector<int>> &matrix){
    int row=matrix.size(), col=matrix[0].size();
    fo(0, row){
        for(int j=0; j<col; j++){
            if(matrix[i][j]==0){
                for(int k=0; k<row; k++) matrix[k][j] = -1;
                for(int k=0; k<col; k++) matrix[i][k] = -1; 
            }
        }
    }

    fo(0, row){
        for(int j=0; j<col; j++){
            if(matrix[i][j]==-1) matrix[i][j] = 0; 
        }
    }

    return matrix;
}

/*
    Better:
        - we will use two variable arrays row and col to keep track of the zeros 
        - then we will iterate over the array to change the elements to zeros

    TC - O(2*N*M)
    SC - O(N+M)
*/

vector<vector<int>> better(vector<vector<int>> &matrix){
    int r=matrix.size(), c=matrix[0].size();
    vector<int> row(r, 0), col(c, 0);

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(matrix[i][j]==0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(row[i] || col[j]){
                matrix[i][j]=0;
            }
        }
    }

    return matrix;
}

/*
    Optimal:
        - we cannot further optimize the time complexity here
        - we will try to optimize the space complexity

        - we will try to use the matrix itself inspite of using two vectors to keep track of the 
          zeros.

        LINK: https://youtu.be/N0MgLvceX7M?t=911

        see this for better understanding
*/

vector<vector<int>> optimal(vector<vector<int>> &matrix){
    // row -> matrix[..][0]
    // col -> matrix[0][..]

    // we will use a new variable also... for reference see video...
    int col1=1, r=matrix.size(), c=matrix[0].size();

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(matrix[i][j]==0){
                matrix[i][0] = 0;
                if(j!=0){
                    matrix[0][j] = 0;
                }else{
                    col1=0;  
                }
            } 
        }
    }

    for(int i=1; i<r; i++){
        for(int j=1; j<c; j++){
            if(matrix[0][j]==0 || matrix[i][0]==0) matrix[i][j] = 0;
        }
    }

    if(matrix[0][0]==0){
        for(int i=1; i<c; i++) matrix[0][i] = 0;
    }

    if(col1==0){
        for(int i=0; i<r; i++) matrix[i][0] = 0;
    }

    return matrix;
}

void print(vector<vector<int>> matrix){
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[0].size(); j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    vector<vector<int>> matrix = {
        {1,1,1,1},
        {1,0,1,1},
        {1,1,0,1},
        {0,1,1,1}
    };

    vector<vector<int>> result = optimal(matrix);

    print(result);
    return 0;
}
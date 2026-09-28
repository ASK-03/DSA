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

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;   

    return (node);
}

bool isLeaf(struct node* node){
    if(!node->left && !node->right) return true;
    return false;
}

void getLeftBoundary(struct node* node, vector<int>& res){
    struct node* temp = node->left;
    while(temp){
        if(!isLeaf(temp)) res.push_back(temp->data);
        if(temp->left) temp=temp->left;
        else temp=temp->right;
    }
}

void getLeaves(struct node* node, vector<int>& res){
    if(isLeaf(node)) res.push_back(node->data);

    if(node->left) getLeaves(node->left, res);
    if(node->right) getLeaves(node->right, res);
}

void getRightBoundary(struct node* node, vector<int>& res){
    struct node* temp = node;
    stack<int> st;
    while(temp){
        if(!isLeaf(temp)) st.push(temp->data);
        if(temp->right) temp=temp->right;
        else temp=temp->left;
    }

    while(!st.empty()){
        int temp = st.top(); st.pop();
        res.push_back(temp);
    }
}

void boundaryTraversal(struct node* root){
    vector<int> res;

    if(!root){ 
        cout << "Root is NULL" << endl;
        return;
    }

    if(!isLeaf(root)) res.push_back(root->data);

    getLeftBoundary(root, res);
    getLeaves(root, res);
    getRightBoundary(root, res);

    for(int i: res) cout << i << " ";

    cout << endl;
}

int main(){
    
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->left->right->left=newNode(8);
    root->right->left=newNode(6);
    root->right->right=newNode(7);
    root->right->right->left=newNode(9);
    root->right->right->right=newNode(10);

    boundaryTraversal(root);

    return 0;
}
#include <bits/stdc++.h>
#include <queue>

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

struct node{
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

queue<struct node*> q;

void bfs(struct node* root){
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        for(int i=0; i<size; i++){
            struct node* temp = q.front();
            cout << temp->data << " ";
            q.pop();
            if(temp->left!=NULL) q.push(temp->left);
            if(temp->right!=NULL) q.push(temp->right);
        }
    }
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

    bfs(root);

    return 0;
}
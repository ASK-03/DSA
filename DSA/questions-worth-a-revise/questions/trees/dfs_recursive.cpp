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


void preorder(struct node* root){
    if(root==NULL) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node* root){
    if(root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(struct node* root){
    if(root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
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

    cout << "Preorder" << endl;
    preorder(root);
    cout << endl;

    cout << "Inorder" << endl;
    inorder(root);
    cout << endl;

    cout << "Postorder" << endl;
    postorder(root);
    cout << endl;

    return 0;
}
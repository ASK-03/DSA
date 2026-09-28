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

void iterative_inorder(struct node* root){
    if(root == NULL) return;

    stack<struct node*> st;
    struct node* tempNode = root;
    while(true){
        if(tempNode != NULL){
            st.push(tempNode);
            tempNode = tempNode->left;
        }else{
            if(st.empty()) return;
            tempNode = st.top();
            st.pop();
            cout << tempNode->data << " ";
            tempNode=tempNode->right;
        }
    }
}

void iterative_preorder(struct node* root){
    if(root==NULL) return;

    stack<struct node*> st;
    st.push(root);

    while(!st.empty()){
        root = st.top();
        st.pop();
        cout << root->data << " ";
        if(root->right!=NULL) st.push(root->right);
        if(root->left!=NULL) st.push(root->left);
    }
}

void iterative_postorder_2stacks(struct node* root){
    if(root==NULL) return;

    stack<struct node*> st1, st2;
    st1.push(root);

    while(!st1.empty()){
        root=st1.top();
        st1.pop();
        st2.push(root);
        if(root->left!=NULL) st1.push(root->left);
        if(root->right!=NULL) st1.push(root->right);
    }

    while (!st2.empty()){
        cout << st2.top()->data << " ";
        st2.pop(); 
    }
}

void iterative_postorder_1stack(struct node* root){
    if(root==NULL) return;

    stack<struct node*> st;
    struct node* curr = root;
    while(curr!=NULL || !st.empty()){
        if(curr!=NULL){
            st.push(curr);
            curr = curr->left;
        }else{
            struct node* temp = st.top()->right;
            if(temp==NULL){
                temp = st.top();
                st.pop();
                cout << temp->data << " ";
                while(!st.empty() && temp == st.top()->right){
                    temp = st.top(); st.pop();
                    cout << temp->data << " ";
                }
            }else{
                curr=temp;
            }
        }
    }
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

    iterative_inorder(root); cout << endl;
    iterative_preorder(root); cout << endl;
    iterative_postorder_2stacks(root); cout << endl;
    iterative_postorder_1stack(root); cout << endl;

    return 0;
}
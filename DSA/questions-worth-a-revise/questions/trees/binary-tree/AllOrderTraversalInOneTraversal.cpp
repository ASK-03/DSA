#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int v){
        val = v;
    }
};


void print(vector<int> &vec){
    for(int i=0; i<vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << endl;
}

void allTraversalsInOne(Node* root, vector<int> &pre, vector<int> &in, vector<int> &post){
    if(root == NULL) return;

    stack<pair<Node*, int>> st;

    st.push({root, 1});

    while(!st.empty()){
        auto [node, num] = st.top();
        st.pop();

        if(num==1){
            in.push_back(node->val);
            st.push({node, 2});

            if(node->left){
                st.push({node->left, 1});
            }
        }
        else if(num==2){
            pre.push_back(node->val);
            st.push({node, 3});
            if(node->right){
                st.push({node->right, 1});
            }
        }
        else{
            post.push_back(node->val);
        }
    }
}

int main(){
    // Question: 
    // Perform inorder, preorder and postorder traversal in one traversal

    // Solution: 
    // In this solution we are using a stack of pairs in which we will put 
    // the Node* and num

    // num represents how many time the node has come into the stack. 
    // if the node is present in the stack for the first time then it goes into inorder
    // and then it is again added to the stack increasing the num

    // I am writing the solution below, do a dry run to understand the solution

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // The code snippet above creates a tree structure;

    vector<int> pre, in, post;
    allTraversalsInOne(root, pre, in, post);

    cout << "Preorder Traversal -> "; 
    print(pre);
    cout << "Inorder Traversal -> ";
    print(in);
    cout << "Postorder Traversal -> ";
    print(post);

    return 0;
}
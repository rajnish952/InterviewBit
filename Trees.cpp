#include<iostream>

using namespace std;

struct Tree{

//public:
    int data;
    Tree *left, *right;
    Tree(int data){
        this->data=data;
        left=right=nullptr;
    }

};

void inorderTraversal(Tree *root){
    if(root==nullptr)
            return;

    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

void preorderTraversal(Tree *root){
    if(root==nullptr)
            return;

    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Tree *root){
    if(root==nullptr)
            return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data<<" ";
}

int main(){

    Tree *root=new Tree(5);
    root->left=new Tree(1);
    root->right=new Tree(2);
    root->left->left=new Tree(3);
    root->left->right=new Tree(4);

    inorderTraversal(root);
    cout<<endl;
    preorderTraversal(root);
    cout<<endl;
    postorderTraversal(root);
    return 0;
}

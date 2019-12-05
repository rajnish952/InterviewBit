#include<iostream>
#include<queue>

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

struct TreeNode{

    int data;
    TreeNode *left, *right, *hasnext;
    TreeNode(int data){
        this->data=data;
        left=right=hasnext=nullptr;
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

void levelorderTraversal(Tree *root){
    queue<Tree *> q;

    if(!root)
        return;

    q.push(root);

    while(!q.empty()){
        Tree *t=q.front();
        cout<<t->data<<" ";
        q.pop();

        if(t->left)
            q.push(t->left);
        if(t->right)
            q.push(t->right);
    }

}

void connectNextPointer(TreeNode *root){

    queue<TreeNode *> q;
    if(!root)
        return;

    q.push(root);
    q.push(nullptr);

    while(!q.empty()){

        TreeNode *t=q.front();
        q.pop();
        if(t!=nullptr){
            t->hasnext=q.front();
            if(t->left)
                q.push(t->left);
            if(t->right)
                q.push(t->right);
        }else if(!q.empty())
            q.push(nullptr);

    }

}

int main(){

    Tree *root=new Tree(5);
    root->left=new Tree(1);
    root->right=new Tree(2);
    root->left->left=new Tree(3);
    root->left->right=new Tree(4);

    TreeNode *root1 = new TreeNode(1);
    root1->left=new TreeNode(2);
    root1->right=new TreeNode(3);
    root1->left->left=new TreeNode(4);
    root1->left->right=new TreeNode(5);

    inorderTraversal(root);
    cout<<endl;
    preorderTraversal(root);
    cout<<endl;
    postorderTraversal(root);
    cout<<endl;
    levelorderTraversal(root);
    cout<<endl;
    connectNextPointer(root1);
    return 0;
}

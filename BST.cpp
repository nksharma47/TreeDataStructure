#include<iostream>

using namespace std;

struct BST
{
    int data;
    BST *left;
    BST *right;
};

BST* insert(BST *root,int ele)
{
    BST* node=new BST();
    node->data=ele;
    node->left=node->right=NULL;
    if(root==NULL)
        root=node;
    else if(ele <= root->data)
        root->left=insert(root->left,ele);
    else
        root->right=insert(root->right,ele);

    return root;
}

void preorder(BST* root)
{
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(BST* root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(BST* root)
{
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int search(BST *root,int ele)
{
    if(root==NULL)
        return 0;
    if(ele == root->data)
        return 1;
    if(ele<root->data)
        search(root->left,ele);
    else 
        search(root->right,ele);
}

int main()
{
    BST *root=NULL;
    int ch,ele,f;
    
    while(1)
    {
        cout<<"1.INSERT\n2.SEARCH\n3.DISPLAY\n4.EXIT\n";
        cout<<"Enter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1: cout<<"Enter no. :";
                    cin>>ele;
                    root=insert(root,ele);
                    break;
            
            case 2: cout<<"Enter element to be searched: ";
                    cin>>ele;
                    f=search(root,ele);
                    if(f==1)
                        cout<<"Found\n";
                    else
                        cout<<"Not Found\n";
                    break;
                    
            case 3: cout<<"PREORDER TRAVERSAL:\n";
                    preorder(root);
                    cout<<endl;
                    cout<<"INORDER TRAVERSAL:\n";
                    inorder(root);
                    cout<<endl;
                    cout<<"POSTORDER TRAVERSAL:\n";
                    postorder(root);
                    cout<<endl;
                    break;

            case 4: exit(0);
                    break;
        }
    }
    
    return 0;
}

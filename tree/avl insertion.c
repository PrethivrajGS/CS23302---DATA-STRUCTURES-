#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
     int key;
     struct Node* left;
     struct Node* right;
     int height;
}one;
int getHeight(one* n)
{
    if(n==NULL)
    {
        return 0;
    }
    return n->height;
}
one* createnode(int key)
{
    one* node=(one*)malloc(sizeof(one));
    node->left=node->right=NULL;
    node->key=key;
    node->height=1;
    return node;
}
int max(int a,int b)
{
    return a>b?a:b;
}
int getBalance(one* n)
{
    if(n==NULL)
    {
        return 0;
    }
    return getHeight(n->left)-getHeight(n->right);
}
one* rightrotate(one* y)
{
    one* x=y->left;
    one* T2=x->right;
    x->right=y;
    y->left=T2;
    
    y->height=max(getHeight(y->right),getHeight(y->left))+1;
    x->height=max(getHeight(x->right),getHeight(x->left))+1;
    return x;
}
one* leftrotate(one* x)
{
    one* y=x->right;
    one* T2=y->left;
     y->left=x;
    x->right=T2;
    
    y->height=max(getHeight(y->right),getHeight(y->left))+1;
    x->height=max(getHeight(x->right),getHeight(x->left))+1;
    return y;
}
one* insert(one *node,int key)
{
    if(node==NULL)
    {
        return(createnode(key));
    }
    else if(key<node->key)
    {
        node->left=insert(node->left,key);
    }
    else
    {
        node->right=insert(node->right,key);
    }
   // return node;
    
    node->height=1+max(getHeight(node->left),getHeight(node->right));
    int bf= getBalance(node);
    //left left
    if(bf>1 && key<node->left->key)
    {
        node=rightrotate(node);
    }
    //right right
    if(bf<-1 && key>node->right->key)
    {
      node=leftrotate(node);
    }
    //left-right
    if(bf>1 && key>node->left->key)
    {
        node->left=leftrotate(node->left);
        rightrotate(node);
    }
    if(bf<-1 && key<node->right->key)
    {
        node->right=rightrotate(node->right);
        leftrotate(node);
    }
    return node;
}
one* deletenode(one* node,int key)
{
    if(node==NULL)
    {
        return NULL;
    }
    if(key<node->key)
    {
        node->left=deletenode(node->left,key);
    }
    else if(key>node->key)
    {
        node->right=deletenode(node->right,key);
    }
    else
    {
        //leaf node
        if(!node->left && !node->right)
        {
            free(node);
            return NULL;
        }
        //one child
        else if(!node->left&& node->right)
        {
            one* temp=node->right;
            free(node);
            return temp;
        }
        else if(!node->right && node->left)
        {
            one* temp=node->left;
             free(node);
            return temp;
        }
        //both child
        else
        {
            one* curr= node->right;
            while(curr->left)
            {
                curr=curr->left;
            }
            node->key=curr->key;
        }
        node->right=deletenode(node->right,node->key);
        return node;
        
         node->height=1+max(getHeight(node->left),getHeight(node->right));
    int bf= getBalance(node);
    //left left
    if(bf>1 && key<node->left->key)
    {
        node=rightrotate(node);
    }
    //right right
    if(bf<-1 && key>node->right->key)
    {
      node=leftrotate(node);
    }
    //left-right
    if(bf>1 && key>node->left->key)
    {
        node->left=leftrotate(node->left);
        rightrotate(node);
    }
    if(bf<-1 && key<node->right->key)
    {
        node->right=rightrotate(node->right);
        leftrotate(node);
    }
    }
}
void inorder(one* root)
{
 if(root!=NULL)
 {
     inorder(root->left);
     printf("%d ",root->key);
     inorder(root->right);
 }
}
int main()
{
    one* root=NULL;
    root=insert(root,78);
    root=insert(root,67);
    root=insert(root,46);
    root=insert(root,56);
   
    printf("inorder traversal:");
    inorder(root);
    deletenode(root,78);
    printf("\nafter deletion:");
    inorder(root);
    
     return 0;
}
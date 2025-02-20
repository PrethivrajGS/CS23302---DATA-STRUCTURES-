#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int key;
    struct node* left;
    struct node* right;
}bt;
bt* newnode(int data)
{
    bt* temp=(bt*)malloc(sizeof(bt));
    temp->key=data;
    temp->right=temp->left=NULL;
    return temp;
}
bt* insert(bt* node,int key)
{
    if(node==NULL)
       return newnode(key);
    if(node->key ==key)
        return node;
    if(node->key >key)
    {
        node->left=insert(node->left,key);
    }
    else
    {node->right= insert(node->right,key);}
     return node;
}
bt* min(bt * node) {
  if (node == NULL)
    return NULL;
  else if (node->left != NULL)
    return min(node->left);
  return node;
}
bt* delete(bt* node, int key) {

  if (node == NULL)
    return NULL;
  if (key > node->key)
    node->right = delete(node->right,key);
  else if (key < node->key)
    node->left = delete(node->left, key);
  else {
    if (node->left == NULL && node->right== NULL){
      free(node);
      return NULL;
    }
    else if (node->left == NULL || node->right == NULL){
      struct node *bit;
      if (node->left == NULL)
        bit = node->right;
      else
        bit = node->left;
      free(node);
      return bit;
    }
    else {
      bt* bit = min(node->right);
      node->key = bit->key;
      node->right= delete(node->right, bit->key);
    }
  }
  return node;
}
void inorder(bt* root)
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
  bt* root=newnode(50);
  root=insert(root,30);
  root= insert(root,35);
  root= insert(root,60);
  root=insert(root,75);
  printf("AFTER INSERTION:");
   inorder(root);
   printf("\nAFTER DELETION:");

    root = delete(root, 30);
  root = delete(root, 75);

  inorder(root);
  printf("\n");

  return 0;
}



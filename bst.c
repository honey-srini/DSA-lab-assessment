#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left,*right;
}*root=0,*newnode,*temp;
struct node *min(struct node *root){
    if (root->left==0) return root;
    else
    return min(root->left);
}                      

struct node* insert(struct node *root,int val){
    if (root==0)
        {
            newnode = (struct node*)malloc(sizeof(struct node));
            newnode->data=val;
            newnode->left=newnode->right=0;
            return newnode;
        }
    else if (val<root->data)
        root->left=insert(root->left,val);
    else
        root->right=insert(root->right,val);
        return root;
}

struct node* delete(struct node *root,int val){
    if (val<root->data)
        root->left=delete(root->left,val);
    else if (val>root->data)
        root->right=delete(root->right,val);
    else{
            if (root->left==0 && root->right==0){
                free(root);
                root=0;
            }
            else if(root->left==0 || root->right==0){
                if (root->left==0){
                temp = root->right;
                free(root);
                return temp;}
                else{
                temp = root->left;
                free(root);
                return temp;}}
            else{
                printf("two child");
                temp=min(root->right);
                root->data=temp->data;
                root->right=delete(root->right,temp->data);}
    }
    return root;
}

void inorder(struct node *root){
    if (root==0)
        return;
    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);
}

void postorder(struct node *root)
{
    if (root==0)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d\t",root->data);
}
void preorder(struct node *root)
{
    if (root==0)
        return;
    printf("%d\t",root->data);
    preorder(root->left);
    preorder(root->right);
}
void display(struct node *root,int space){
    if (root==0) return;
    space+=1;
    display(root->right,space);
    for(int i=1;i<space;i++)
        printf("\t");
    printf("%d\n",root->data);
    display(root->left,space);
}

struct node *max(struct node *root){
    if (root->right==0) return root;
    else
    return max(root->right);
}



int main() {
    int ch,val;
        root=insert(root,50);
        root=insert(root,25);
        root=insert(root,75);
        root=insert(root,15);
        root=insert(root,35);
        root=insert(root,65);
        root=insert(root,90);
        root=insert(root,100);
        root=insert(root,80);
        root=insert(root,55);
        root=insert(root,30);
        root=insert(root,36);
        root=insert(root,16);
        root=insert(root,14);
        root=insert(root,66);
        printf("\nInorder\n");
        inorder(root);
        printf("\nPostorder\n");
        postorder(root);
        printf("\nPreorder\n");
        preorder(root);
        printf("\nDisplay as tree\n");
        display(root,0);
        // root=delete(root,14);
        // printf("\nDisplay as tree\n");
        // display(root,0);
        // root=delete(root,100);
        // printf("\nDisplay as tree\n");
        // display(root,0);
        // root=delete(root,90);
        // printf("\nDisplay as tree\n");
        // display(root,0);
        // root=delete(root,15);
        // printf("\nDisplay as tree\n");
        // display(root,0);
        // root=delete(root,25);
        // printf("\nDisplay as tree\n");
        // display(root,0);
        printf("\n1.Insert\t2.Min and Max\t11.Inorder,Postorder,Preorder, Display\t\n");
    while(1){
        printf("\nEnter your Choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter Value: ");
            scanf("%d",&val);
            root=insert(root,val);
            break;
            case 2:
            if (root==0)
            printf("\nTree is empty\n");
            else
            printf("The minimum data is %d\n",(min(root)->data));
            printf("The maximum data is %d\n",(max(root)->data));
            break;
            case 11:
            {
                if(root==0)
                printf("\nTree is Empty\n");
                else
                printf("\nInorder\n");
                inorder(root);
                printf("\nPostorder\n");
                postorder(root);
                printf("\nPreorder\n");
                preorder(root);
                printf("\nDisplay Tree\n");
                display(root,0);
                break;
            }
        }
    }
}
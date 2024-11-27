#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node* NODE;
NODE NewNode(int data){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
NODE insertNode(NODE root, int data){
    if(root == NULL){
        return NewNode(data);
    }
    if(data < root->data){
        root->left = insertNode(root->left, data);
    }
    else if(data > root->data){
        root->right = insertNode(root->right, data);
    }
    return root;
}
void preOrder(NODE root){
    if(root != NULL){
        preOrder(root->left);
        preOrder(root->right);
        printf("%d ", root->data);
    }
}
void InOrder(NODE root){
    if(root != NULL){
        InOrder(root->left);
        printf("%d ", root->data);
        InOrder(root->right);

    }
}
void postOrder(NODE root){
    if(root != NULL){
        printf("%d ", root->data);
        postOrder(root->left);
        postOrder(root->right);

    }
}
int main(){
    int choice, data;
    NODE root = NULL;
    root = insertNode(root, 50);
    printf("\n-----------------------MENU--------------------------\n");
    printf("1. insertValue\n2. preOrder\n3. inOrder\n4. postOrder\n5. exit");
    while(1){
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d",&data);
            root = insertNode(root, data);
            break;
            case 2:
            printf("PreOrder Traversal: ");
            preOrder(root);
            printf("\n");
            break;
            case 3:
            printf("InOrder Traversal: ");
            InOrder(root);
            printf("\n");
            break;
            case 4:
            printf("PostOrder Traversal: ");
            postOrder(root);
            printf("\n");
            break;
            case 5:
            printf("Exiting......\n");
            exit(0);
            break;
        }
    }
    return 0;
}

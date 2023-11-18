#include <stdlib.h>
#include <stdio.h>

struct node //düðüm yapýsý oluþturuldu;
{
    int data; //düðümün taþýdýðý veri;
    struct node *left; //sað ve sol göstericiler create edildi;
    struct node *right;
};

struct node *newNode(int data)
{
    struct node *new = malloc(sizeof(struct node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;

    return new;
}

struct node* insert(struct node *root, int data)
{
    if (root != NULL){
    	if (data < root->data)
        	root->left = insert(root->left, data);
    	else if (data > root->data)
        	root->right = insert(root->right, data);
	}
	else{
		root=newNode(data);
	}
    return root;
}

void inorder(struct node *root) {
    if(root == NULL) {
        printf("Agac bos.");
        return;
    }
    if(root->left) 
		inorder(root->left);
    printf("%d - ",root->data);
    if(root->right) 
		inorder(root->right);
}

void preorder(struct node *root) {
    if(root == NULL) {
        printf("Agac bos.");
        return;
    }
    printf("%d - ",root->data);
    if(root->left) 
		preorder(root->left);
    if(root->right) 
		preorder(root->right);
}
 
void postorder(struct node *root) {
    if(root == NULL) {
        printf("Agac bos.");
        return;
    }
    if(root->left) 
		postorder(root->left);
    if(root->right) 
		postorder(root->right);
    printf("%d - ",root->data);
}

int main(){
    // Root
    struct node *root = newNode(25);
/*
    root->left  = newNode(14);
    root->right = newNode(40);

    root->left->left  = newNode(7);
    root->left->right = newNode(23);

    root->right->left  = newNode(34);
    root->right->right = newNode(48);
    
    root->left->left->left= newNode(5);
    root->left->left->right= newNode(10);
    
    root->left->left->right->left= newNode(7);
    
    root->left->right->left= newNode(17);
    root->left->right->right= newNode(24);
    
    root->left->right->right->left= newNode(23);
    
    root->right->left->right  = newNode(36);
    
    root->right->right  = newNode(48); */
    
//Preorder : 25-14-7-5-10-7-23-17-24-23-40-34-36-48
//Inorder : 5-7-7-10-14-17-23-23-24-25-34-36-40-48
//Postorder : 5-7-10-7-17-23-24-23-14-36-34-48-40-25

	int i;
	do {
		printf("\n\nAgaca veri eklemek icin sayi giriniz...\nSayi = ");
		scanf("%d", &i);
		if(i != -1)
		root = insert(root, i);
	} while(i != -1);
    
    printf("\n");
    preorder(root);
    
    printf("\n");
    inorder(root);
    
    printf("\n");
    postorder(root);
    
    return 0;
}
    
    
    
    

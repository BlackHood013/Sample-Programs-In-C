#include<stdio.h>
#include<conio.h>
 
struct Node 
{
	char data;
	struct Node *left;
	struct Node *right;
};
 
void Preorder(struct Node *root)
 {
	if(root == NULL) return;
 
	printf("%d ",root->data);
	Preorder(root->left); 
	Preorder(root->right);
}
 
void Inorder(struct Node *root) 
{
	if(root == NULL) return;
 
	Inorder(root->left); 
	printf("%d ",root->data);
	Inorder(root->right); 
}
 
void Postorder(struct Node *root)
 {
	if(root == NULL) return;
 
	Postorder(root->left);
	Postorder(root->right); 
	printf("%d ",root->data);
}
 
struct Node* Insert(struct Node *root,char data) 
{
	if(root == NULL)
     {
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(data <= root->data)
		root->left = Insert(root->left,data);
	else 
		root->right = Insert(root->right,data);
	return root;
}
 
int main() {
       int i,j,n;
	struct Node* root = NULL;
	printf("how many elements do you want to enter?");
	scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    printf("enter elements:");
    scanf("%d",&j);
	root = Insert(root,j);
    }
	printf("Preorder: ");
	Preorder(root);
    printf("\n");
	printf("Inorder: ");
	Inorder(root);
	printf("\n");
	printf("Postorder: ");
	Postorder(root);
	printf("\n");
getch();
}


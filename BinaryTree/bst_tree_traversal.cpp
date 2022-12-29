
##Tree Traversal- inorder, preorder,postorder 

#include<iostream>

void init_code(){


   #ifndef ONLINE_JUDGE
   freopen("/Users/sj/Downloads/Fall2022/Algorithms/Week6/BST_codes/input.txt", "r", stdin);
   freopen("/Users/sj/Downloads/Fall2022/Algorithms/Week6/BST_codes/output.txt", "w", stdout);
   #endif // ONLINE_JUDGE

}
/* A binary tree node has data, pointer to left child
and a pointer to right child */

struct Node{
   int data;
   struct Node* left;
   struct Node* right;


};

/* function to create a new tree node*/

Node* newNode(int data)
{
   Node* temp=new Node;
   temp->data=data;
   temp->left=nullptr;
   temp->right=nullptr;
   return temp;
}
void printInorder(struct Node* node)
{
   if(node!=nullptr)
   {
      /*left child recursion*/
      printInorder(node->left);

      /*print the node content */
      std::cout<<node->data;

      /*right child recursion*/
      printInorder(node->right);
   }

}
void printPreorder(struct Node* node)
{
   if(node!=nullptr)
   {
      /* print the node content */
      std::cout<<node->data;

      /*left child recursion*/
      printPreorder(node->left);

      /*right child recursion*/
      printPreorder(node->right);
   }

}
void printPostorder(struct Node* node)
{
   if(node!=nullptr)
   {
      /*left child recursion*/
      printPostorder(node->left);

      /*right child recursion*/
      printPostorder(node->right);

      /* print the node contents */
      std::cout<<node->data;

   }

}

int main()
{
	init_code();
	std::cout<<"Hello World\n";
   struct Node* root=newNode(5);
   root->left=newNode(3);
   root->right=newNode(7);
   root->left->left=newNode(2);
   root->left->right=newNode(5);
   root->right->right=newNode(9);
   std::cout<<"Inorder Traversal:";
   printInorder(root);
   std::cout<<std::endl;

   std::cout<<"Preorder Traversal:";
   printPreorder(root);
   std::cout<<std::endl;

   std::cout<<"PostOrder Traversal";
   printPostorder(root);
   std::cout<<std::endl;
	return 0;
}

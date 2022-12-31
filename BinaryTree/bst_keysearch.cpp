
/*BST_Key bst_keysearch
BST_min
BST_max
BST_successor
BST_predecessor
BST insert Node
BST delete node
*/

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
struct Node* node_addr[100];

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
      std::cout<<node->data<<" ";

      /*right child recursion*/
      printInorder(node->right);
   }

}

bool bst_keysearch(struct Node* node,int key,int index)
{

   if(node==nullptr)
   {
      return false;
   }
   //std::cout<<"I am looking at node Address"<<node<<"Node data "<<node->data<<std::endl;
   node_addr[index]=node;

   if(key==node->data)
   {
      return true;
   }
   else if(key>node->data)
   {
      return bst_keysearch(node->right,key,index+1);
   }
   else
   {
      return bst_keysearch(node->left,key,index+1);
   }


}

int bst_minimum(struct Node* node)
{
   if(node==nullptr)
   {
      std::cout<<"Tree is Empty";
      return -10000;
   }
   if(node->left==nullptr)
   {
      return node->data;
   }
   return bst_minimum(node->left);
}

int bst_maximum(struct Node* node)
{
   if(node==nullptr)
   {
      std::cout<<"Tree is Empty";
      return -10000;
   }
   if(node->right==nullptr)
   {
      return node->data;
   }
   return bst_maximum(node->right);

}

int bst_successor(struct Node* node, int key)
{
   int non_null_index;
   struct Node* parent;
   struct Node* child;
   int pindex;
   int cindex;
   if(node==nullptr)//check if tree is empty
   {
      std::cout<<"Tree is Empty. No successor exist";
      return -10000;
   }
   //check if we are trying to find the successor of maximum node
   if(key==bst_maximum(node))
   {
      std::cout<<"You are trying to find a successor of the node which is Maximum\n";
      return -10000;
   }
   //std::cout<<"root node address "<<node_addr[0]<<std::endl;
   for(int i=0;i<1000;i++)
   {
      node_addr[i]=nullptr;
   }
   //std::cout<<"root node address "<<node_addr[0]<<std::endl;
   if(!bst_keysearch(node,key,0))//If node does not exist,no successor found
   {
      std::cout<<"given node does not exist in the tree.Can't find the successor"<<std::endl;
      return -10000;
   }
   if(bst_keysearch(node,key,0)) //check if key exist in the tree. Find successor only if key exists.
   {
      for(int i=0;i<1000;i++)
   {
      
      if(node_addr[i]==nullptr)
      {
         non_null_index=i-1;
         break;
      }
      std::cout<<"Node Address "<<node_addr[i]<<" Node data "<<node_addr[i]->data<<std::endl;

   }
   std::cout<<"non null index is "<<non_null_index<<std::endl;
   std::cout<<"right child node address:"<<node_addr[non_null_index]->right<<std::endl;
   if(node_addr[non_null_index]->right!=nullptr)
   {
      std::cout<<"Search for the successor in the right subtree\n";
      return bst_minimum(node_addr[non_null_index]->right);
   }

  
   if(node_addr[non_null_index]->right==nullptr)
   {
      std::cout<<"Hi\n";
      std::cout<<"Search for the successor up the tree\n";
      parent=node_addr[non_null_index-1];
      child=node_addr[non_null_index];
      cindex=non_null_index;
      pindex=non_null_index-1;
      while((parent!=nullptr)&&(parent->right!=nullptr)&&(parent->right->data==child->data))
      {
         pindex=pindex-1;
         cindex=cindex-1;
         parent=node_addr[pindex];
         child=node_addr[cindex];


      }
      return parent->data;
   }
  }
  return -10000;

}

int bst_predecessor(struct Node* node,int key)
{
   int non_null_index;
   struct Node* parent;
   struct Node* child;
   int pindex;
   int cindex;
   if(node==nullptr)//check if tree is empty
   {
      std::cout<<"Tree is Empty. No predecessor exist";
      return -10000;
   }
   if(key==bst_minimum(node))
   {
      std::cout<<"You are trying to find a predecessor of the node which is Minimum\n";
      return -10000;
   }
   std::cout<<"root node address "<<node_addr[0]<<std::endl;
   for(int i=0;i<1000;i++)
   {
      node_addr[i]=nullptr;
   }
   std::cout<<"root node address "<<node_addr[0]<<std::endl;

   if(!bst_keysearch(node,key,0))//If node does not exist,no predecessor found
   {
      std::cout<<"given node does not exist in the tree.Can't find the predecessor"<<std::endl;
      return -10000;
   }
   if(bst_keysearch(node,key,0)) //check if key exist in the tree. Find successor only if key exists.
   {
      for(int i=0;i<1000;i++)
   {
      
      if(node_addr[i]==nullptr)
      {
         non_null_index=i-1;
         break;
      }
      std::cout<<"Node Address "<<node_addr[i]<<" Node data "<<node_addr[i]->data<<std::endl;

   }
   std::cout<<"non null index is "<<non_null_index<<std::endl;
   std::cout<<"left child node address:"<<node_addr[non_null_index]->left<<std::endl;
   if(node_addr[non_null_index]->left!=nullptr)
   {
      std::cout<<"Search for the predecessor in the left subtree\n";
      return bst_maximum(node_addr[non_null_index]->left);
   }
   if(node_addr[non_null_index]->left==nullptr)
   {
      std::cout<<"Hi\n";
      std::cout<<"Search for the predecessor up the tree\n";
      parent=node_addr[non_null_index-1];
      child=node_addr[non_null_index];
      cindex=non_null_index;
      pindex=non_null_index-1;
      while((parent!=nullptr)&&(parent->left!=nullptr)&&(parent->left->data==child->data))
      {
         pindex=pindex-1;
         cindex=cindex-1;
         parent=node_addr[pindex];
         child=node_addr[cindex];


      }
      return parent->data;
   }
  }
return -10000;
}

void insert_node(struct Node* node,int key)
{
   if(node==nullptr)
   {
      std::cout<<"Tree is Empty\n";
      return;

   }
   struct Node* prev;
   struct Node* curr;
   prev=nullptr;
   curr=node;
   while(curr!=nullptr)
   {
      prev=curr;
      if(key>curr->data)
      {
         curr=curr->right;
      }
      else if(key<curr->data)
      {
         curr=curr->left;
      }
   }
   if(key>prev->data)
   {
      prev->right=newNode(key);
   }
   else if(key<prev->data)
   {
      prev->left=newNode(key);
   }

}

void delete_node(struct Node* node, int key)
{
   int non_null_index;
   struct Node* curr;
   struct Node* prev;
   struct Node* node_to_be_deleted;
   int successor;
   if(node==nullptr)
   {
      std::cout<<"Tree is Empty.Nothing to delete\n";
      return;
   }
   if(!bst_keysearch(node,key,0))
   {
      std::cout<<"Key not found in the tree.Nothing to delete\n";
      return;
   }
   std::cout<<"root node address "<<node_addr[0]<<std::endl;
   for(int i=0;i<1000;i++)
   {
      node_addr[i]=nullptr;
   }
   std::cout<<"root node address "<<node_addr[0]<<std::endl;
   if(bst_keysearch(node,key,0))
   {
      std::cout<<"Key found in the tree\n";
      for(int i=0;i<1000;i++)
   {
      
      if(node_addr[i]==nullptr)
      {
         non_null_index=i-1;
         break;
      }
      std::cout<<"Node Address "<<node_addr[i]<<" Node data "<<node_addr[i]->data<<std::endl;

   }
   std::cout<<"non null index is "<<non_null_index<<std::endl;

   curr=node_addr[non_null_index];
   prev=node_addr[non_null_index-1];
   std::cout<<"left of current node: "<<curr->left<<std::endl;
   std::cout<<"right of current node:"<<curr->right<<std::endl;
   //Case1: node has no children
   if((curr->left==nullptr)&&(curr->right==nullptr))
   {
      std::cout<<"Case1: The node to be delted has no children\n";
      if((prev->right!=nullptr)&&(prev->right->data==curr->data))
      {
         prev->right=nullptr;
      }
      else
      {
         prev->left=nullptr;
      }

   }

   //Case2:node has 1 child
   if(((curr->left==nullptr)&&(curr->right!=nullptr))||((curr->left!=nullptr)&&(curr->right==nullptr)))
   {
      std::cout<<"Case 2: The node to be deleted has 1 child\n";
      if((prev->left!=nullptr)&&(prev->left==curr))
      {
         std::cout<<"current node is the left child of parent node\n";
         if((curr->left!=nullptr)&&(curr->right==nullptr))
         {
            std::cout<<"The current node has a left child\n";
            prev->left=curr->left;
         }
         else if((curr->left==nullptr)&&(curr->right!=nullptr))
         {
            std::cout<<"The current node has a right child\n";
            prev->left=curr->right;
         }
      }
      else if((prev->right!=nullptr)&&(prev->right==curr))
      {
         std::cout<<"The current node is the right child of the parent node\n";
         if((curr->left!=nullptr)&&(curr->right==nullptr))
         {
            std::cout<<"The current node has a left child\n";
            prev->right=curr->left;
         }
         else if((curr->left==nullptr)&&(curr->right!=nullptr))
         {
            std::cout<<"The current node has a right child\n";
            prev->right=curr->right;
         }

      }
   }

   //Case3: node to be deleted has 2 children
   if((curr->left!=nullptr)&&(curr->right!=nullptr))
   {
      std::cout<<"The current node to be deleted has 2 children\n";
      //Find the successor of the current node
      successor=bst_successor(curr,curr->data);
      std::cout<<"Successor of "<<curr->data<<" is "<<successor<<std::endl;

      node_to_be_deleted=curr;

      //Delete the succesor node
      delete_node(node,successor);

      //print the inorder tree traversal to verify the successor node is deleted
      std::cout<<"Inorder Traversal:";
      printInorder(node);
      std::cout<<std::endl;

      //replace the contents of node to be delted with the successor
      node_to_be_deleted->data=successor;

  }



   }
   return;

}

int main()
{
	init_code();
   int k,min,max,successor,predecessor,successor_k,predecessor_k;
   int non_null_index;
   int node_insert_value;
   int node_delete_value;
	//std::cout<<"Hello World\n";
   struct Node* root=newNode(15);
   root->left=newNode(6);
   root->right=newNode(18);
   root->left->left=newNode(3);
   root->left->right=newNode(7);
   root->left->left->left=newNode(2);
   root->left->left->right=newNode(4);
   root->left->right->right=newNode(13);
   root->left->right->right->left=newNode(9);
   root->right->left=newNode(17);
   root->right->right=newNode(20);
   std::cout<<"Inorder Traversal:";
   printInorder(root);
   std::cout<<std::endl;

   //Key search in BST
   std::cout<<"enter a key to search\n";
   std::cin>>k;
   bool found=bst_keysearch(root,k,0);
   std::cout<<"Key found:"<<found<<std::endl;
   

   //Minimum in BST
   min=bst_minimum(root);
   std::cout<<"Minimum in the BST is "<<min<<std::endl;
   

   //maximum in BST
   max=bst_maximum(root);
   std::cout<<"Maximum of the BST is "<<max<<std::endl;
   
   
   //Successor in BST
   std::cout<<"Enter the value for which you want the successor\n";
   std::cin>>successor_k;
   successor=bst_successor(root,successor_k);
   std::cout<<"Successor of node "<<successor_k<<" is "<<successor<<std::endl;
   


   //Predecessor in BST
   std::cout<<"Enter the value for which you want the predecessor\n";
   std::cin>>predecessor_k;
   predecessor=bst_predecessor(root,predecessor_k);
   std::cout<<"Predecessor of node "<<predecessor_k<<" is "<<predecessor<<std::endl;

   

   //Insertion in BST
   std::cout<<"Enter a node to insert\n";
   std::cin>>node_insert_value;
   insert_node(root,node_insert_value);
   std::cout<<"Inorder Traversal:";
   printInorder(root);
   std::cout<<std::endl;
   
   //Deletion in BST
   std::cout<<"Enter a node to delete\n";
   std::cin>>node_delete_value;
   delete_node(root,node_delete_value);
   std::cout<<"Inorder Traversal:";
   printInorder(root);
   std::cout<<std::endl;


	return 0;
}

#include <iostream>

using namespace std;

class BSTree
{
private:
  struct Node{  
    int data;
    Node * right;
    Node * left;
  };
  Node * root;

public:
  BSTree();
  void preorder(Node *&nodePtr);
  void displaypreorder();
  void inorder(Node *&nodePtr);
  void displayinorder();
  void postorder(Node *&nodePtr);
  void displaypostorder();
  Node* searchNode(Node *&nodePtr,int key);
  void search(int key);
  void insert(Node *&nodePtr,Node *&newNode);
  void insertNode(int key);
  void deleteNode(Node *&nodePtr,int key);
  void makeDeletion(Node *&nodePtr);
  void deleting(int key);
};

BSTree::BSTree()
{
  root=NULL;
}
void BSTree::preorder(Node *&nodePtr)
{

  if (nodePtr==NULL)
      return;
    
      cout << " " << nodePtr->data;
      preorder(nodePtr->left);
      preorder(nodePtr->right);
   
}
void BSTree::displaypreorder()
{
  cout << " Tree preorder: ";
  preorder(root);
  cout << endl;
}
void BSTree::inorder(Node *&nodePtr)
{
  if (nodePtr==NULL)
      return;

    inorder(nodePtr->left);
    cout << " " << nodePtr->data;
    inorder(nodePtr->right);
     
}
void BSTree::displayinorder()
{
  cout << " Tree inorder: ";
  inorder(root);
  cout << endl;
}
void BSTree::postorder(Node *&nodePtr)
{
  if (nodePtr==NULL)
      return;

      postorder(nodePtr->left);
      postorder(nodePtr->right);
      cout << " " << nodePtr->data;
}
void BSTree::displaypostorder()
{
  cout << " Tree postorder: ";
  postorder(root);
  cout << endl;
}
BSTree::Node *BSTree::searchNode(Node *&nodePtr,int key)
{
  if(nodePtr!=NULL)
    {
      if (nodePtr->data == key) 
	return nodePtr; 
      // Key is greater than root's key 
      if (key > nodePtr->data ) 
	{
	  return searchNode(nodePtr->right, key);
	} 
      else
	{
	  return searchNode(nodePtr->left, key); 
	}
    }
  else
    return NULL;
}
void BSTree::search(int key)
{
  Node *temp=new Node;
  temp->data=0; 
  temp->right=temp->left=NULL;

if(searchNode(root,key)!=NULL)
{
  temp->data=searchNode(root,key)->data;
  cout << " " << temp->data << " was found in the Tree." << endl;
}
else
  cout <<" " << key << " was not found in in tree." << endl;
}

void BSTree::insert(Node *&nodePtr,Node *&newNode)
{
  if (nodePtr == NULL)
    {
      nodePtr = newNode; // Insert the node.
    }
  else if (newNode->data < nodePtr->data)
    {
      insert(nodePtr->left, newNode); // Search the left branch
    }
  else
    {
      insert(nodePtr->right, newNode);// Search the right branch
    }
}

void BSTree::insertNode(int key)
{  

  if(searchNode(root,key)==NULL)
  {
    Node *newNode = NULL; // Pointer to a new node.
    // Create a new node and store key in it.
    newNode = new Node;
    newNode->data = key;
    newNode->left = newNode->right = NULL;
    //  Insert the node.
    insert(root, newNode);
    cout << " " << key << " inserted into tree. " << endl;
  }
    else
      cout << " Cannot insert " << key << ", can't have duplicates!" << endl;

}

void BSTree::deleteNode(Node *&nodePtr,int key)
{
  if (key < nodePtr->data)
    {
      deleteNode(nodePtr->left,key);
    }
  else if (key > nodePtr->data)
    {
      deleteNode(nodePtr->right,key);
    }
  else
    {
      makeDeletion(nodePtr);
    }
}

void BSTree::makeDeletion(Node *&nodePtr)
{
  // Define a temporary pointer to use in reattaching
  // the subtree.
  Node *tempNodePtr = NULL;

  if (nodePtr == NULL)
    {
      cout << "Tree is empty";
    }
  else if (nodePtr->right == NULL)
    {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->left; // Reattach the left child
      delete tempNodePtr;
    }
  else if (nodePtr->left == NULL)
    {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->right; // Reattach the right child
      delete tempNodePtr;
    }
  // If the node has two children.
  else
    {
      // Move one node the right.
      tempNodePtr = nodePtr->right;
      // Go to the end left node.
      while (tempNodePtr->left)
        {
          tempNodePtr = tempNodePtr->left;
        }
      // Reattach the left subtree.
      tempNodePtr->left = nodePtr->left;
      tempNodePtr = nodePtr;
      // Reattach the right subtree.
      nodePtr = nodePtr->right;
      delete tempNodePtr;
    }
}

void BSTree::deleting(int key)
{
  //search to see if value in Tree first.
  if(searchNode(root,key)!=NULL)
    {
      deleteNode(root,key);
      cout << " Deleted " << key << " from the tree." << endl;
    }
  else
    cout << " Cannot delete " << key << " since value is not tree." << endl;
}


int main()
{
  BSTree Tree;

  int array[10]={4,2,5,3,12,6,26,81,13,1};
  for (int i=0;i<10;i++)
    {
      Tree.insertNode(array[i]);
    }
  Tree.displaypreorder();
  Tree.displayinorder();
  Tree.displaypostorder();

  Tree.insertNode(6);
  Tree.insertNode(2);
 
  Tree.search(2);
  Tree.search(60);

  Tree.deleting(2);
  Tree.search(2);
  Tree.deleting(27);
  Tree.deleting(12);

  Tree.displaypreorder();
  Tree.displayinorder();
  Tree.displaypostorder();

 
  return 0;
}




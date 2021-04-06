#include <iostream>
#include <cstdlib>
using namespace std;

template<typename Type>
class binaryTree{
  private:

    struct treeNode{
      Type node_value;
      treeNode* left, *right;
    };

    treeNode* parent_node;

  public:

  binaryTree(){parent_node = nullptr;}

  bool isEmpty() const;
  void print_level_order();
  void levelOrder(treeNode*, int);
  void print_post_order();
  void postOrder(treeNode*);
  void print_inorder();
  void inorder(treeNode*);
  void print_preorder();
  void preorder(treeNode*);
  int height(treeNode*) const;
  int print_height();
  
  void attachNode(Type);
  void detachNode(treeNode*, Type);
  void detach(Type);
  bool searchNode(Type);
  
};

template<typename Type>
bool binaryTree<Type>::isEmpty() const{

  return parent_node == NULL;

}

template<typename Type>
int binaryTree<Type>::height(treeNode* searchPtr) const{

  if(searchPtr == NULL){

    return 0;

  } else {

    int left_height = height(searchPtr->left);
    int right_height = height(searchPtr->right);

    if(left_height > right_height){

      return (left_height + 1);

    } else {

      return (right_height + 1);

    } 
  }
}

template<typename Type>
int binaryTree<Type>::print_height(){
  
  return height(parent_node);

}

template<typename Type>
void binaryTree<Type>::print_level_order(){
  
  int h = height(parent_node);
  
  if(h == 0){

    cout << "This tree is empty!" << endl;

  } else {

  for(size_t i{1}; i <= h; ++i){
    
    levelOrder(parent_node, i);
    
  }
  }
}

template<typename Type>
void binaryTree<Type>::levelOrder(treeNode *searchPtr, int h){
  
  if(searchPtr == NULL) return;
  
  if(h == 1){

    cout << searchPtr->node_value << " ";

  } else if(h > 1){

    levelOrder(searchPtr->left, h - 1);
    levelOrder(searchPtr->right, h - 1);

  }

}

template<typename Type>
void binaryTree<Type>::attachNode(Type new_value){

  treeNode* create_node = new treeNode;
  treeNode* parent;

  create_node->node_value = new_value;
  create_node->left = NULL;
  create_node->right = NULL;
  parent = NULL;

  if(isEmpty()){

    parent_node = create_node;

  } else {

      treeNode* current_node;
      current_node = parent_node;

      while(current_node){

        parent = current_node;

			  if(create_node->node_value > current_node->node_value){
      
          current_node = current_node->right;
      
        } else {
      
          current_node = current_node->left;
      
        }
    }

		  if(create_node->node_value < parent->node_value){

			  parent->left = create_node;

      } else {

			  parent->right = create_node;

      }
  }
}

template<typename Type>
void binaryTree<Type>::print_post_order(){

  int h = height(parent_node);
  
  if(h == 0){

    cout << "This tree is empty!" << endl;

  } else {
  
  postOrder(parent_node);
  
  }
}

template<typename Type>
void binaryTree<Type>::postOrder(treeNode* searchPtr)
{

	if(searchPtr != NULL)
	{
    
    postOrder(searchPtr->left);
    postOrder(searchPtr->right);
		cout << searchPtr->node_value << " ";

	}
	else return;
}

template<typename Type>
void binaryTree<Type>::print_inorder(){
  
  int h = height(parent_node);
  
  if(h == 0){

    cout << "This tree is empty!" << endl;

  } else {
  
  inorder(parent_node);
  
  }
  
}

template<typename Type>
void binaryTree<Type>::inorder(treeNode* searchPtr){
  if(searchPtr == NULL){

    return;

  } else {
    
    inorder(searchPtr->left);

    cout << searchPtr->node_value << " ";

    inorder(searchPtr->right);
  }
}

template<typename Type>
void binaryTree<Type>::print_preorder(){
  
  int h = height(parent_node);
  
  if(h == 0){

    cout << "This tree is empty!" << endl;

  } else {
  
  preorder(parent_node);
  
  }
  
}

template<typename Type>
void binaryTree<Type>::preorder(treeNode* searchPtr){
  if(searchPtr == NULL){

    return;
    
  } else {
    
    cout << searchPtr->node_value << " ";

    preorder(searchPtr->left);

    preorder(searchPtr->right);
  }
}
 
template<typename Type>
void binaryTree<Type>::detach(Type deleteValue) { 

  if(parent_node == NULL){

    cout << "The tree is empty!" << endl;
    return;

  } else {

    detachNode(parent_node, deleteValue);

  }
}

template<typename Type>
void binaryTree<Type>::detachNode(treeNode* searchPtr, Type deleteValue){

  treeNode* current_node;
  current_node = parent_node;
  treeNode* parent = NULL;

  while (current_node != NULL && current_node->node_value != deleteValue) { 

        parent = current_node; 

        if (deleteValue < current_node->node_value) {

            current_node = current_node->left; 
        } else {

            current_node = current_node->right; 

        }
   } 
  
   if (current_node == NULL) { 

	cout << "The value expected to delete " << deleteValue << " not found!" << endl; 
        return; 

   } 

  if((current_node->left == NULL) && (current_node->right == NULL)) {
		if (parent == NULL)
		{

			delete current_node;

		} else {

			if(parent->left == current_node){ 

        parent->left = NULL;

      } else {
        
        parent->right = NULL;

      }

			delete current_node;
		
    }
    return;
	}

  if((current_node->left == NULL && current_node->right != NULL)|| (current_node->left != NULL && current_node->right == NULL)) {

		if(current_node->left == NULL && current_node->right != NULL) {		
		
			if(parent->left == current_node) {
			
				parent->left = current_node->right;
				delete current_node;
				
			} else {
			
				parent->right = current_node->right;
				delete current_node;
				
			}
	} else {
			
		if(parent->left == current_node) {
				
			parent->left = current_node->left;
			delete current_node;
			
		} else {
		
			parent->right = current_node->left;
			delete current_node;
		
		}
	}
	return;
   }

  if((current_node->left != NULL) && (current_node->right != NULL)) { 

    treeNode* previous = NULL; 
    treeNode* tempPtr; 
  
    tempPtr = current_node->right; 
    while (tempPtr->left != NULL) { 

        previous = tempPtr; 
        tempPtr = tempPtr->left; 

    } 
  
    if (previous != NULL) {

        previous->left = tempPtr->right; 

    } else {
     
        current_node->right = tempPtr->right; 
    
    }
    
    current_node->node_value = tempPtr->node_value; 
    free(tempPtr); 
    } 
}

template<typename Type>
bool binaryTree<Type>::searchNode(Type searchValue){

  treeNode* current_node = parent_node;
  bool status = false;
  
  while(current_node){
    if (current_node->node_value ==           searchValue) status = true;
    
    if (current_node->node_value <  searchValue){

      current_node = current_node->right;

    } else {
 
      current_node = current_node->left;

    }
  }
 return status;
}

int main(){
int option, number;

binaryTree<int> testTree;

do{
  cout << "\nPlease enter the operation number you want to perform (or Enter 0 to exit): " << endl;
    cout << "1. Insert node" << endl;
    cout << "2. Delete node" << endl;
    cout << "3. Print all by BFT" << endl;
    cout << "4. Print all by DFT In-Order traversal" << endl;
    cout << "5. Print all by DFT Pre-Order traversal" << endl;
    cout << "6. Print all by DFT Post-Order traversal" << endl;
    cout << "7. Search" << endl;
    cout << "8. Clear Screen" << endl << endl;
 
    cin >> option;

    switch(option){
      case 0:

      break;
      
      case 1:
        cout << "Enter the value you would like to attach into the binary tree" << endl;
        cin >> number;
        testTree.attachNode(number);
        
      break;

      case 2:
        cout << "Enter the value (of node) you would like to delete" << endl;
        cin >> number;
        testTree.detach(number);

      break;

      case 3:

        testTree.print_level_order();

      break;

      case 4:
      
        testTree.print_inorder();

      break;

      case 5:

        testTree.print_preorder();

      break;

      case 6:

        testTree.print_post_order();

      break;

      case 7:

        if(testTree.print_height() == 0){
          cout << "The tree is empty!" << endl;
        } else {
          cout << "Enter the number expected to search" << endl;
          cin >> number;
          testTree.searchNode(number);
          
          if(testTree.searchNode(number) == false){
          
            cout << "The data not found!" << endl;
          
          } else {
          
          cout << "The data found!" << endl;
          
          }
        }
      break;
      
      case 8:
      system("clear");
      break;

      default:
        cout << "Please choose the proper option" << endl << endl;
      break;
    }
} while(option != 0);

return 0;
} 

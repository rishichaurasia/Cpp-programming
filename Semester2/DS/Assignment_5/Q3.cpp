#include <iostream> 
using namespace std; 
  

class BST{
    private:
        class Node{
            public:
                int data;
                Node* left;
                Node* right;
            
                Node(int data){
            
                  left=NULL;
                  right=NULL;
                  this->data=data;
                }
        };
    
    public:
        Node* root;    
    
        BST(){
            root = NULL;
        }
        
        // Insert Function
        Node* insert(Node* node, int item){
            if(!root){
                root = new Node(item);
                return NULL;
            }
            if(!node){
                return new Node(item);
            }
            if(item <= node->data)
                node->left = insert(node->left, item);
            else
                node->right = insert(node->right, item);
            return node;
        }
        
        //Find Min Value Function
        Node* minValueNode(Node* node){
            Node* current = node; 
            while (current && current->left != NULL) 
                current = current->left; 
          
            return current; 
        } 
  
        // Delete Node Function
        Node* deleteNode(Node* node, int item) 
        { 
            if (root == NULL) 
                return root; 
        
            if (item < node->data) 
                node->left = deleteNode(node->left, item); 
            else if (item > node->data) 
                node->right = deleteNode(node->right, item); 
            else
            { 
                // node with only one child or no child 
                if (node->left == NULL) 
                { 
                    Node *temp = node->right; 
                    delete node; 
                    return temp; 
                } 
                else if (node->right == NULL) 
                { 
                    Node *temp = node->left; 
                    delete node; 
                    return temp; 
                } 
          
                // node with two children: Get the inorder successor (smallest 
                // in the right subtree) 
                Node* temp = minValueNode(node->right); 
          
                // Copy the inorder successor's content to this node 
                node->data = temp->data; 
          
                // Delete the inorder successor 
                node->right = deleteNode(node->right, temp->data); 
            } 
            return node; 
        }
        
        // Display Inorder Function
        void display(Node* node){
            if(!node)
                return;
            display(node->left);
            cout << node->data << " ";
            display(node->right);
        }
    
};

int main() 
{ 
    BST b; 
    b.insert(b.root, 50); 
    b.insert(b.root, 30); 
    b.insert(b.root, 20); 
    b.insert(b.root, 40); 
    b.insert(b.root, 70); 
    b.insert(b.root, 60); 
    b.insert(b.root, 80); 
  
    b.display(b.root); 
    cout << endl;
    b.deleteNode(b.root, 50);
    b.display(b.root);
    return 0; 
} 


#include <iostream>
using namespace std;

class BinarySearchTree{
public:
    int val;
    BinarySearchTree *left, *right;
    
    BinarySearchTree():val(0), left(nullptr), right(nullptr){};
    BinarySearchTree(int x):val(x), left(nullptr), right(nullptr){};
    BinarySearchTree(int x, BinarySearchTree *left, BinarySearchTree *right):val(x), left(nullptr), right(nullptr){};
};

class TreeNodes{
public:
    BinarySearchTree *root;
    TreeNodes(){
        root = nullptr;
    }
    
    void insert(int num){
        
        BinarySearchTree *newroot = new BinarySearchTree(num);
        if(root == nullptr){
            root=newroot;
            return;
        }
        BinarySearchTree *current_root = root;
        
        while(true){
            if(num<current_root->val){
                if(current_root->left==nullptr){
                    current_root->left = newroot;
                    return;
                }
                current_root=current_root->left;
            }else{
                if(current_root->right==nullptr){
                    current_root->right = newroot;
                    return;
                }
                current_root=current_root->right;
            }
        }
    }
    
    BinarySearchTree *BST(int key){
        BinarySearchTree *searchNode = new BinarySearchTree(key);
        if(root==nullptr){
            return NULL;
        }
        BinarySearchTree *t = root;
        while (t != NULL && t != searchNode){
            if (searchNode < t)
              t = t->left;
            else
              t = t->right;
          }
        if(t==searchNode){
            cout<<t;
            return t;
        }
        else
            return NULL;
        
    }
    BinarySearchTree *getroot(){
        BinarySearchTree *roo1;
        roo1=root;
        cout<<"Inorder Traversal: ";
        inorder(roo1);
        cout<<endl;
        cout<<"Preorder Traversal: ";
        preorder(roo1);
        cout<<endl;
        cout<<"Postorder Traversal: ";
        postorder(roo1);
        cout<<endl;
        BST(6);
        deletion(root);
        return root;
    }
    
    void deletion(BinarySearchTree *root){
        if(root == nullptr){
            return;
        }
        deletion(root->left);
        delete root;
        deletion(root->right);
         }
          
    void inorder(BinarySearchTree *root){
        if(root == nullptr){
            return;
        }
        inorder(root->left);
        cout<<root->val<<" ";
        inorder(root->right);
    }
            
    void preorder(BinarySearchTree *root){
            if(root == nullptr){
                return;
            }
        cout<<root->val<<" ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(BinarySearchTree *root){
        if(root == nullptr){
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout<<root->val<<" ";
    }
};

int main(int argc, const char * argv[]) {
    TreeNodes bst;
    bst.insert(8);
    bst.insert(3);
    bst.insert(10);
    bst.insert(1);
    bst.insert(6);
    bst.insert(14);
    bst.insert(13);
    bst.insert(4);
    bst.insert(7);
    bst.getroot();
    return 0;
}

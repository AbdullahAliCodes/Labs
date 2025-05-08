#include <iostream>

using namespace std;

class TreeNode{
public:
    
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
    int value;

   // constructor 
    TreeNode(int v) : value(v) {}
    
    // destructor 
    ~TreeNode() {
        delete left;
        delete right;
    }
};

class Tree{
private:
    TreeNode* root = nullptr;

public:
    // These functions do the actual work
    void insert(int v, TreeNode* &subtree){
        if(subtree == nullptr){
           subtree = new TreeNode(v);
        }else if(v < subtree->value){
            insert(v, subtree->left);
        }else{
            insert(v, subtree->right);
        }
    }

    void preOrderTraversal(TreeNode* subtree) const{
        cout << subtree -> value << " ";
        
        
        if(subtree-> left != nullptr){
            preOrderTraversal(subtree-> left);
            
        }
        if(subtree ->right != nullptr){
            preOrderTraversal(subtree ->right);
            
        }
            
        
        
    }

    void inOrderTraversal(TreeNode* subtree) const{
        if(subtree -> left != nullptr){
            inOrderTraversal(subtree -> left);
            
        }
        cout << subtree -> value << " ";
        
        if(subtree -> right != nullptr){
            inOrderTraversal(subtree -> right);
            
        }
        

    }

    void postOrderTraversal(TreeNode* subtree) const{
        if(subtree -> left != nullptr){
            postOrderTraversal(subtree -> left);
            
        }
        
        if(subtree -> right != nullptr){
            postOrderTraversal(subtree -> right);
            
        }
        cout << subtree -> value << " ";
        
    }



    int min(TreeNode* subtree) const{
        while(subtree -> left != nullptr){
            subtree = subtree -> left;
            
        }
        return (subtree -> value);
    }



    int max(TreeNode* subtree) const{
        cout << subtree -> value << "";
        while(subtree -> right != nullptr){
            subtree = subtree -> right;
            cout << subtree -> b=value 
        }
        return (subtree -> value);
    }


    bool contains(int value, TreeNode* subtree) const{
        if( subtree -> value == value){
            return true;
        }
        if (value < subtree -> value && subtree -> left != nullptr){
            return contains(value,subtree->left);
        }
        if(value > subtree -> value && subtree -> right != nullptr){
            return contains( value,subtree->right );
        }
        if ( value != subtree -> value){
            return false;
        }
    }


    
    void remove(int value, TreeNode* &subtree){
        if(subtree == nullptr){
            return;
        }
        if(subtree -> value == value){
            if(subtree -> left == nullptr && subtree -> right == nullptr){
                delete subtree;
                subtree = nullptr;
            }
            else if(subtree -> left != nullptr && subtree -> right == nullptr){
                TreeNode*tmp = subtree -> left;
               subtree -> left = nullptr;
                delete subtree;
                subtree = tmp;
            }
            else if(subtree -> left == nullptr && subtree -> right != nullptr){
                TreeNode*tmp = subtree -> right;
                subtree -> right = nullptr;
                delete subtree;
                subtree = tmp;
            }
            else{
                subtree -> value = min(subtree-> right);
                remove(subtree-> value, subtree -> right);
            }
        }
        else if (value < subtree -> value){
            remove(value,subtree->left);
        }
        else{
            remove(value,subtree->right);
        }
        
    }

    void insert(int value){
        insert(value, root);
    }

    void preOrderTraversal(){
        preOrderTraversal(root);
        cout << endl;
        
    }
    void inOrderTraversal(){
        inOrderTraversal(root);
        cout << endl;
    }
    void postOrderTraversal(){
        postOrderTraversal(root);
        cout << endl;
    }
    int min(){
        return min(root);
    }
    int max(){
        return max(root);
    }
    bool contains(int value){
        return contains(value, root);
    }
    void remove(int value){
        remove(value, root);
    }
    ~Tree(){
        // This ends up deleting all the nodes recursively.
        delete root;
    }
};

int main(){
    Tree t;
    int value;
    // Sample code to read and construct the tree.
    while(cin >> value && value != -1){
        t.insert(value);
    }
    
    while(cin >> value && value != -1){
        t.remove(value);
        t.preOrderTraversal();
        t.inOrderTraversal();
        t.postOrderTraversal();
    }
    
    
}

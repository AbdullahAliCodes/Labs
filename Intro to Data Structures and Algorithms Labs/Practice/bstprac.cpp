#include <iostream>
#include <queue>
#include <BSTrees.h>

using namespace std;

void Tree::preOrderTraversal(TreeNode* subtree) const {
    if (subtree == nullptr){
        return;
    }
    else{
        cout << subtree->value << " ";
        preOrderTraversal(subtree->left);
        preOrderTraversal(subtree->right);
    }
}

void Tree::inOrderTraversal(TreeNode* subtree) const{
    if (subtree == nullptr){
        return;
    }
    else{
        inOrderTraversal(subtree->left);
        cout << subtree->value << " ";
        inOrderTraversal(subtree->right);
    }
}

void Tree::postOrderTraversal(TreeNode* subtree) const{
    if (subtree == nullptr){
        return;
    }
    else{
        postOrderTraversal(subtree->left);
        postOrderTraversal(subtree->right);
        cout << subtree->value << " ";
    }
}

int Tree::min(TreeNode* subtree) const{
    if (subtree-> left == nullptr){
        return subtree->value;
    }
    else{
        return min(subtree->left);
    }
}

int Tree::max(TreeNode* subtree) const{
    if (subtree->right == nullptr){
        return subtree->value;
    }
    else{
        return max(subtree->right);
    }
}

bool Tree::contains(int value, TreeNode* subtree) const{
    if (subtree = nullptr){
        return false;
    }
    else if (value == subtree->value){
        return true;
    }
    else if (value < subtree->value){
        return contains(value, subtree->left);
    }
    else{
        return contains(value,subtree->right);
    }
}

void Tree::remove(int value, TreeNode* &subtree){
    if (value < subtree->value){
        remove (value, subtree->left);
    }
    else if (value > subtree->value){
        remove (value, subtree->right);
    }
    else{
        if (subtree->left == nullptr && subtree->right == nullptr){
            delete subtree;
            subtree = nullptr;
        }
        else if(subtree->right == nullptr && subtree->left != nullptr){
            TreeNode*tmp = subtree->left;
            subtree->left = nullptr;
            delete subtree;
            subtree = tmp;
        }
        else if(subtree->right != nullptr && subtree->left == nullptr){
            TreeNode*temp = subtree->right;
            subtree->right = nullptr;
            delete subtree;
            subtree = tmp;
        }
        else{
            subtree->value = min(subtree->right);
            remove(subtree->value, subtree->right);
        }
    }
}

int Tree::height(TreeNode* subtree) const{
    if (subtree == nullptr){
        return 0;
    }
    else{
        int leftH = height(subtree->left);
        int rightH = height(subtree->right);
        if ( leftH > rightH ){
            return leftH + 1;
        }
        else{
            return rightH + 1;
        }
    }
}

void Tree::levelOrderTraversal(TreeNode* subtree) const{

}

// from 2019 past paper, prints all the nodes from root to min
void Tree::pathToMin(TreeNode *subtree) const{
    TreeNode*curr = subtree;
    while (curr != nullptr){
        cout << curr->value << " ";
        curr = curr->left;
    }
}

// prints all nodes from root to max
void Tree::pathToMax(TreeNode *subtree) const{
    TreeNode*curr = subtree;
    while (curr != nullptr){
        cout << curr->value << " ";
        curr = curr->right;
    }
}

// from 2019 past paper, prints all leaf nodes
void Tree::printLeaves(TreeNode *subtree) const{
    if (subtree == nullptr){
        return;
    }
    if (subtree->left == nullptr && subtree->right == nullptr){
        cout <<subtree->value << " ";
        return;
    }
    printLeaves(subtree->left);
    printLeaves(subtree->right);
}

// from 2019 past paper, deletes all current leaves, not working and I don't know why
void Tree::deleteLeaves(TreeNode* subtree){
    if (subtree == nullptr){
        return;
    }
    if (subtree->left == nullptr && subtree->right == nullptr){
        free(subtree);
        return;
    }
    deleteLeaves(subtree->left);
}

// from 2019 past paper, prints longest path between any 2 leaves
int Tree::diameter(TreeNode *subtree) const{
    if (subtree == nullptr){
        return;
    }
    int rightH = height(subtree->right);
    int leftH = height(subtree->left);
    int combined = rightH + leftH + 1;
    int Rdiam = diamter(subtree->right);
    int Ldiam = diamter(subtree->left);
    if (combined > Rdiam && combined > Ldiam){
        return combined;
    }
}

// counts the nodes in the tree
int Tree::numNodes(TreeNode* subtree) const{

}

int Tree::findDepth(TreeNode *subtree, int value) const{
    if (subtree == nullptr){
        return -1;
    }
    if (subtree->value == value){
        return 0;
    }
    int LeftDist = findDepth(subtree->left,value);
    if (LeftDist != -1 ){
        LeftDist + 1;
    }
    return -1;
}

int Tree::successor(TreeNode *subtree, int value) const{

}

int Tree::lowestCommonAncestor(TreeNode* subtree, int v1, int v2) const{

}

int main(){
    Tree t;
    int value;
    cin >> value;
    while (value != -1){
        t.insert(value);
        cin >> value;
    }
    int value1, value2;
    cin >> value1;
    cin >> value2;
    cout << t.lowestCommonAncestor(value1, value2);
    return 0;
}






















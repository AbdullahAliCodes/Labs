#include <iostream>
#include <queue>
#include <BSTrees.h>

using namespace std;

void Tree::preOrderTraversal(TreeNode* subtree) const {
    if (subtree == nullptr) return;
    else{
      cout << subtree->value << " ";
      preOrderTraversal(subtree->left);
      preOrderTraversal(subtree->right);
  }
}

void Tree::inOrderTraversal(TreeNode* subtree) const{
    if (subtree == nullptr) return;
    else{
        inOrderTraversal(subtree->left);
        cout << subtree->value << " ";
        inOrderTraversal(subtree->right);
    }
}

void Tree::postOrderTraversal(TreeNode* subtree) const{
    if (subtree == nullptr) return;
    else{
        postOrderTraversal(subtree->left);
        postOrderTraversal(subtree->right);
        cout << subtree->value << " ";
    }
}

int Tree::min(TreeNode* subtree) const{
    if (subtree->left == nullptr){
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
    if (subtree == nullptr){
        return true;
    }
    else if (value == subtree->value){
        return true;
    }
    else if (value < subtree->value){
        return contains(value, subtree->left);
    }
    else{
        return contains(value, subtree->right);
    }
}

void Tree::remove(int value, TreeNode* &subtree){
    if (value < subtree->value){
        remove(value, subtree->left);
    }
    else if (value > subtree->value){
        remove(value, subtree->right);
    }
    else{
        // no children
        if (subtree->left == nullptr && subtree->right == nullptr){
            delete subtree;
            subtree = nullptr;
        }
        // one child, on right
        else if (subtree->left == nullptr && subtree->right != nullptr){
            TreeNode* tmp = subtree->right;
            subtree->right = nullptr;
            delete subtree;
            subtree = tmp;
        }
        // one child, on left
        else if (subtree->left != nullptr && subtree->right == nullptr){
            TreeNode* tmp = subtree->left;
            subtree->left = nullptr;
            delete subtree;
            subtree = tmp;
        }
        // two children
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
        int leftHeight = height(subtree->left);
        int rightHeight = height(subtree->right);
        if (leftHeight > rightHeight){
            return leftHeight + 1;
        }
        else{
            return rightHeight + 1;
        }
    }
}

void Tree::levelOrderTraversal(TreeNode* subtree) const{
   if (subtree == nullptr){
       return;
   }
   queue<TreeNode*> nodes;
   nodes.push(subtree);
   while (!nodes.empty()){
       TreeNode* curr = nodes.front();
       cout << curr->value << " ";
       nodes.pop();

       if (curr->left != nullptr){
           nodes.push(curr->left);
       }
       if (curr->right != nullptr){
           nodes.push(curr->right);
       }
   }
}

// from 2019 past paper, prints all the nodes from root to min
void Tree::pathToMin(TreeNode *subtree) const{
    TreeNode* curr = subtree;
    while (curr != nullptr){
        cout << curr->value << " ";
        curr = curr->left;
    }
}

// prints all nodes from root to max
void Tree::pathToMax(TreeNode *subtree) const{
    TreeNode* curr = subtree;
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
        cout << subtree->value << " ";
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
    deleteLeaves(subtree->right);
}

// from 2019 past paper, prints longest path between any 2 leaves
int Tree::diameter(TreeNode *subtree) const{
    if (subtree == nullptr){
        return 0;
    }
    int left = height(subtree->left);
    int right = height(subtree->right);
    int combined = left + right + 1;
    int leftDiameter = diameter(subtree->left);
    int rightDiameter = diameter(subtree->right);
    if (combined > leftDiameter && combined > rightDiameter){
        return combined;
    }
    else if (leftDiameter > combined && leftDiameter > rightDiameter){
        return leftDiameter;
    }
    else{
        return rightDiameter;
    }
}

// counts the nodes in the tree
int Tree::numNodes(TreeNode* subtree) const{
    if (subtree == nullptr){
        return 0;
    }
    int left = numNodes(subtree->left);
    int right = numNodes(subtree->right);
    return left + right + 1;
}

int Tree::findDepth(TreeNode *subtree, int value) const{
    if (subtree == nullptr){
        return -1;
    }
    if (subtree->value == value){
        return 0;
    }
    int leftDist = findDepth(subtree->left, value);
    if (leftDist != -1) {
        return leftDist + 1;
    }
    int rightDist = findDepth(subtree->right, value);
    if (rightDist != -1) {
        return rightDist + 1;
    }
    return -1;
}

int Tree::successor(TreeNode *subtree, int value) const{
    if (subtree == nullptr){
        return -1;
    }
    if (subtree->value <= value) {
        return successor(subtree->right, value);
    }
    else{
        int left_successor = successor(subtree->left, value);
        return (left_successor != -1) ? left_successor : subtree->value;
    }
}

int Tree::lowestCommonAncestor(TreeNode* subtree, int v1, int v2) const{
    if (subtree == nullptr) {
        return -1;
    }

    if (subtree->value == v1 || subtree->value == v2) {
        return subtree->value;
    }
    int leftLCA = lowestCommonAncestor(subtree->left, v1, v2);
    int rightLCA = lowestCommonAncestor(subtree->right, v1, v2);
    if (leftLCA != -1 && rightLCA != -1) {
        return subtree->value;
    }
    return (leftLCA != -1) ? leftLCA : rightLCA;
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






















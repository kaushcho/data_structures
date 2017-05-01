#include <iostream>
class BinaryTree
{
    private:
    struct TreeNode 
    {
        int item;    //Value stored in the node.
        TreeNode *left;
        TreeNode *right;
    };
    
    TreeNode *root;

    public:
    BinaryTree()
    {
        root = NULL;
    }

};
    


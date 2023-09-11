# include "inc.hpp"


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;


    // TreeNode() : val(0), left(nullptr), right(nullptr) {}
    // TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    // TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

typedef struct TreeNode tl;

tl *new_node(int val, tl *left, tl *right)
{
    tl *node;
    node = new tl;
    if (!node)
        return nullptr;
    node->val = val;
    node->left = left;
    node->right = right;
    return node;
}


/*

     ()
   /   \
()      ()





*/
tl *init( int val )
{
    tl *root;



}


vector<int> inorderTraversal(TreeNode* root) {
    
    
}


int main() {


}



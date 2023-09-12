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

void Traversal(std::vector<int> &res, tl *root, int level) {
    if (!root)
        return ;
    Traversal(res, root->left, level + 1);
    Traversal(res, root->right, level + 1);
    res.push_back(root->val);
}

vector<int> inorderTraversal(TreeNode* root) {
    std::vector<int> res;
    Traversal(res, root, 0);
    return res;
}


int main() {


}



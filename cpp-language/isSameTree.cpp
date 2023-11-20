# include "leetcode.hpp"

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


typedef struct TreeNode tl;

void Tree(tl *root, std::string &string, int level) {
    if (!root) {
        string.push_back('0');
        return ;
    }

    string.append(to_string(root->val));
    Tree(root->left, string, level + 1);
    Tree(root->right, string, level + 1);
    return ;
}

bool isSameTree__(TreeNode* p, TreeNode* q) {
    std::string s1("");
    std::string s2("");
    
    Tree(p, s1, 0);
    Tree(q, s2, 0);

    // cout << "check s1 : " << s1 << endl;
    // cout << "check s2 : " << s2 << endl;

    return (s1 == s2 ? true : false);
}
/*
    1
  1  null

       1
  nll     1
*/


// int main() 
// {
//     TreeNode* root1 = new TreeNode(10);
//     TreeNode* root2 = new TreeNode(10);

//     tl* node2 = new tl(5); 
//     tl* node3 = new tl(15);


//     tl* node4 = new tl(5); 
//     tl* node5 = new tl(15); 
//     tl* node6 = new tl(1); 

//     root1->left = node2;
//     root1->right = node3;

//     root2->left = node4;
//     root2->right = NULL;
//     root2->left->left = NULL;
//     root2->left->right = node5;


// if (isSameTree__(root1, root2))
//     cout << "TRUE\n";
// else
//     cout << "FALSE\n";


// }











// typedef struct TreeNode tl;

// struct alive {
//     bool sig1, sig2;
//     pthread_mutex_t *mu;
//     int p;
// };
// typedef struct alive t_1;




// void *check(void *arg) {

//     t_1 *ptr = (t_1 *)arg;

//     if (ptr->sig1 != ptr->sig2)
//     {
//         ptr->p = 1;
//         return NULL;
//     }

//     return nullptr;
// }

// void tree1(tl *root,t_1 &signal_, int level) {

//     pthread_mutex_lock(signal_.mu);
//     if (!root) {
//         signal_.sig1 = false;
//     pthread_mutex_unlock(signal_.mu);
//         return ;
//     }

//     tree1(root->right, signal_, level + 1);
//     signal_.sig1 = true;
//     tree1(root->left, signal_, level + 1);
//     signal_.sig1 = true;
//     pthread_mutex_unlock(signal_.mu);
// }

// void tree2(tl *root,t_1 &signal_, int level) {
//     pthread_mutex_lock(signal_.mu);
//     if (!root) {
//         signal_.sig2 = false;
//     pthread_mutex_unlock(signal_.mu);

//         return ;
//     }
//     tree2(root->right, signal_, level + 1);
//     signal_.sig2 = true;
//     tree2(root->left, signal_, level + 1);
//     signal_.sig2 = true;
//     pthread_mutex_unlock(signal_.mu);

// }


// bool isSameTree(TreeNode* p, TreeNode* q)
// {
//     t_1 signal_ = { 0, 0 };
//     signal_.mu = new pthread_mutex_t;
//     signal_.p = 0;
//     pthread_t pid;

//     pthread_create(&pid, NULL, check, &signal_);


//     tree1(p, signal_, 0);
//     tree2(q, signal_, 0);

//     return (signal_.p);

// }
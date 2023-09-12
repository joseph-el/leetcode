# include "inc.hpp"


struct ListNode {

    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

};


/*

    [1] [7] [9] [2] [0]
    [2] [4] [1] [0] [6]

[8,9,9,9,0,0,0,1]


[9,9,9,9,9,9,9]
[9,9,9,9]

8 9 9 9 0 0 0 1

8 9 9 9 0 0 0 1

9 8 7
9 8 7

8 7 5 1

*/

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (!l1 or !l2)
        return nullptr;

    ListNode *list = NULL;
    bool rem = false;
    while (l1 and l2) {

        
        l1 = l1->next, l2 = l2->next;
    }
    // if (rem)
    //      list = new ListNode(1, list);
    return list;

}


void print_node(ListNode *head) {
    if (!head)
    {
        puts("error\n");
        return ;
    }
    while (head ) {
        printf( " [%d] ", head->val); 
        head = head->next;
    }
    puts("");
}


int main() {

    ListNode *list = NULL;
    ListNode *list2 = NULL;


    for (int i = 9; i >= 7; i--)
    {
        list = new ListNode(i, list);
        list2 = new ListNode(i, list2);

    }

    ListNode *ppp = addTwoNumbers(list, list2);

    print_node(ppp);



}
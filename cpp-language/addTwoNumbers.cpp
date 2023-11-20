# include "leetcode.hpp"


struct ListNode {

    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

};

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


[2,4,3]
[5,6,4, 8, 0]

6


*/


void addToBack(ListNode*& head, int value) {
    ListNode* newNode = new ListNode(value);
    if (!head) {
        head = newNode;
    } else {
        ListNode* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (!l1 or !l2)
        return nullptr;

    ListNode *list = NULL;
    bool rem = false;
    while (l1 and l2) {
        int num = l1->val + l2->val + rem;
        rem = false;
        if (num >= 10)
            addToBack(list, num % 10), rem = true;
        else
            addToBack(list, num);
        l1 = l1->next, l2 = l2->next;
    }
    for (ListNode *fill = l1 ? l1 : l2;  fill  ; fill = fill->next) {
        int num = fill->val + rem;
        rem = false;
        if (num >= 10)
            addToBack(list, num % 10), rem = true;
        else
            addToBack(list, num);
    }
    if (rem)
        addToBack(list, 1);
    return list;
}

/*
 [7]  [8]  [9] 
 [7]  [8]  [9]


 4  7 9 1


*/




// int main() {

//     ListNode *list = NULL;
//     ListNode *list2 = NULL;


//     for (int i = 9; i >= 7; i--)
//     {
//         list = new ListNode(i, list);
//         list2 = new ListNode(i, list2);

//     }

//     print_node(list);
//     print_node(list2);

//     ListNode *ppp = addTwoNumbers(list, list2);

//     print_node(ppp);



// }
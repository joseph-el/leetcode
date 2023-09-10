// # include "inc.hpp"
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>

typedef struct  ListNode {
      int val;
      struct ListNode *next;
    //   ListNode() : val(0), next(nullptr) {}
    //   ListNode(int x) : val(x), next(nullptr) {}
    //   ListNode(int x, ListNode *next) : val(x), next(next) {}
}       ListNode;


void print_node(ListNode *head) {
    if (!head)
    {
        puts("error\n");
        return ;
    }
    while (head ) {
        printf( "data : %d\n", head->val); 
        head = head->next;
    }
}

int get_min(ListNode *head) {
    if (!head)
        return -1;

    int min = head->val;
    while (head) {
        if (head->val < min)
            min = head->val;
        head = head->next;
    }
    return min;
}

int count_min(ListNode *head, int  min_target) {
    int count = 0;
    if (!head)
        return -1;

    while (head) {
        if (head->val == min_target)
            count++;
        head = head->next;
    }
    return count;
}

ListNode *new_node(int val) {
    ListNode *node;
    node = (ListNode *)malloc(sizeof(ListNode));
    node->next = NULL;
    node->val = val;
    return node;
}

void add_back(ListNode **head, ListNode *node) {
    if (!*head) {
        *head = node;
        return ;
    }
    ListNode *tmp = *head;
    while (tmp->next) {
        tmp = tmp->next;
    }
    tmp->next = node;
    return ;
}

void remove_node(ListNode **obj, int min, bool ch) {
    ListNode *head = *obj;
    ListNode *tmp;
    ListNode *prev;

    if (!head)
        return ;
    tmp = head;
    while (tmp && tmp->val == min) {
        head = tmp->next;
        free(tmp);
        tmp = head;
    }
    ListNode *save = head;
    if (ch) {
        *obj = NULL;
        return ;
    }
    prev = head;
    while (head) {
        if (head && head->val == min) {
            prev->next = head->next;
            free(head);
            head = prev;
        }
        else {
            prev = head;
        }
        head = head->next;
    }
    *obj = save;
}

bool last_(ListNode *head, int tr) {
    if (!head)
        return false;
    while ( head ) {
        if (head->val != tr)
            return false; 
        head = head->next;
    }
    return true;
}
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){

    if (!list1 && !list2)
        return NULL;
    else if (list1) {
        ListNode *tmp = list1;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = list2;
    }
    else if (!list1 && list2)
        list1 = list2;
    ListNode *sorted_list = NULL;
    ListNode *save = list1;
    while (list1) {

        int min = get_min(list1);
        int size = count_min(list1, min);
        while (size--)
            add_back(&sorted_list, new_node(min));
        bool last = last_(list1, min);
        remove_node(&list1, min, last);
        // break;
    }
    return sorted_list;
}








int main()
{
    ListNode *head = NULL;

    add_back(&head, new_node(0));
    // add_back(&head, new_node(2));
    // add_back(&head, new_node(4));
    // add_back(&head, new_node(1));
    // add_back(&head, new_node(0));
    // add_back(&head, new_node(1));
    // add_back(&head, new_node(1));

    ListNode *hpp = NULL;

    add_back(&hpp, new_node(1));
    // add_back(&hpp, new_node(3));
    // add_back(&hpp, new_node(4));
    // add_back(&hpp, new_node(3));
    // add_back(&hpp, new_node(2));
    // add_back(&hpp, new_node(9));
    // add_back(&hpp, new_node(1));


// [1,2,4], list2 = [1,3,4]




    // print_node(head);
    // puts("---------");
    // puts("---------");

    // remove_node(&head, 1, true);
    // print_node(head);   

    ListNode *ss = mergeTwoLists(head, hpp);
    print_node(ss);

    // system("leaks a.out");
}
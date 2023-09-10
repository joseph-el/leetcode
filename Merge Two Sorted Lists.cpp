# include "inc.hpp"

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};


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

void remove_node(ListNode *target) {

    if (!target)
        return ;
    ListNode *next_node = target->next->next;
    ListNode *removed = target->next;
    free(removed);
    target->next = next_node;
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

bool is_sorted(ListNode *head) {
    if (head == nullptr or head->next == nullptr)
        return true;

    ListNode* current = head;
    while (current->next != nullptr) {
        if (current->val > current->next->val)
            return false;
        current = current->next;
    }
    return true;
}

ListNode *new_node(int val) {
    ListNode *node;
    node = new ListNode;
    node->next = NULL;
    node->val = val;
    return node;
}

void remove_and_add(ListNode **removing, ListNode **sorted, int min, int count_of_min) {
    while (count_of_min--) {
        add_back(sorted, new_node(min));
    }
    ListNode *tmp = *removing;
    ListNode *rev = *removing;
    
    while (rev && rev->val == min) {
        ListNode* temp = rev;
        rev = rev->next;
        delete temp; 
    }
    ListNode* current = rev;
    ListNode* previous = nullptr;
    while (current != nullptr) {

        if (current->val == min) {
            previous->next = current->next;
            delete current; 
            current = previous->next; 
        } else {
            previous = current;
            current = current->next;
        }
    }
}

ListNode *sortList(ListNode *head) {
    if (!head)
        return nullptr;
    ListNode *sorted_list = NULL;

    // 3 4 3 3 3 1 7 1 1 1 2 6
    // get min ;
    // get count min ;
    // push min by count ;
    // remove node && free node;

    while (head) {
        int min = get_min(head);
        int cout_min = count_min(head, min);
        remove_and_add(&head, &sorted_list, min , cout_min);
    }

    return sorted_list;
}

void print_node(ListNode *head) {
    if (!head)
    {
        cout << "error\n";
        return ;
    }
    while (head ) {
        cout << "data : " << head->val << endl; 
        head = head->next;
    }
}


// ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
// }

int main ()
{
    ListNode *head = NULL;

    add_back(&head, new_node(2));
    add_back(&head, new_node(22));
    add_back(&head, new_node(44));
    add_back(&head, new_node(5));
    add_back(&head, new_node(88));
    add_back(&head, new_node(0));
    add_back(&head, new_node(1));

    // print_node(head);

    ListNode *sorting = sortList(head);
    print_node(head);
}
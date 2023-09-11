
 struct ListNode {
     int val;
     struct ListNode *next;
 };

 # include <stdlib.h>
 # include <stdio.h>

typedef  struct ListNode t_l;

t_l *new_node(int value) {

    t_l *node = (t_l *)malloc(sizeof(t_l));

    if (!node)
        return NULL;
    node->next = NULL;
    node->val = value;
    return node;
}

void add_back(t_l **h, t_l *n) {
    if (!*h)
        {
            *h = n;
        return;
        }
        t_l *tm = *h;
        while (tm->next)
            tm = tm->next;
        tm->next = n;
        return ;
}

struct ListNode* deleteDuplicates(struct ListNode* head){
    if (!head)
        return NULL;

    t_l *node =NULL;
    int num = 0;

    while (head) {
        num = head->val;
        add_back(&node, new_node(num));
        debut :
            head = head->next;
        if (head && head->val == num)
            goto debut;
    }
    return node;
}

void print_node(t_l *head) {
    if (!head)
    {
         puts("error");
        return ;
    }
    while (head ) {
        printf("data : %d \n", head->val); 
        head = head->next;
    }
}

int main()
{

    t_l *ss = NULL;


        add_back(&ss, new_node(1));
        add_back(&ss, new_node(1));
        add_back(&ss, new_node(1));
        add_back(&ss, new_node(2));
        add_back(&ss, new_node(2));
        add_back(&ss, new_node(5));
        add_back(&ss, new_node(7));
        add_back(&ss, new_node(9));



    t_l *res = deleteDuplicates(ss);

    print_node(res);


}
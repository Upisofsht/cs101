#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node* next;
} node_t;
node_t* allocate_node(int data) {
    node_t* a = (node_t*)calloc(1,sizeof(node_t));
    a->data = data;
    a->next = NULL;
    return a;
}
void show_list(node_t* list) {
    node_t* temp = list;
    while(temp != NULL) {
        printf("[%d]->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
node_t* append_node(node_t* head, int new_data) {
    node_t* node = allocate_node(new_data);
    
    if (head) {
        node_t* p = head;
        while (p->next) {
            p = p->next;
        }
        p->next = node;
    }
    else {head = node;}
    return head;
}
void free_all_node(node_t* head) {
    node_t* tmp = NULL;
    while (head) {
        tmp = head;
        head = head->next;
        printf("free([%d])->", tmp->data);
        free(tmp);
    }
    printf("NULL\n");
}
node_t* add_node(node_t* head, int new_deta) {
    node_t* node = allocate_node(new_deta);
    node->next = head;
    return node;
}
node_t* del_node(node_t* head, int n) {
    if (n == 0) {
        return head;
    }
    node_t* p = head;
    node_t* pre = head;
    for (int i = 0; i < n; i++) {
        p = p->next;
    }
    while (pre->next != p) {
        pre = pre->next;
    }
    pre->next = p->next;
    free(p);
    return pre_node;
}
int main()
{
    node_t* head = NULL;
    head = append_node(head, 0);
    show_list(head);
    head = append_node(head, 1);
    show_list(head);
    head = add_node(head, -1);
    show_list(head);
    del_node(head, 1);
    show_list(head);
    free_all_node(head);

    return 0;
}

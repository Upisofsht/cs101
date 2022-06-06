#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
};

class LinkedList {
    private:
        Node* head;
        Node* tmp, *temp;
    public:
        LinkedList() {
            head = NULL;
        }
        ~LinkedList() {
            while (head) {
                tmp = head;
                head = head->next;
                cout << "free([" << tmp->data <<"])->";
                free(tmp);
            }
            cout <<"null"<< endl;
        }
        void print_Linklist() {
            tmp = head;
            while(tmp !=NULL) {
                cout << "[" << tmp->data << "]->";
                tmp = tmp->next;
            }
            cout << "null" <<endl;
        }
        void append_node(int n) {
            Node* New = (Node*)malloc(sizeof(Node));
            New->data = n;
            New->next = NULL;
            if (head) {
                tmp = head;
                while(tmp->next !=NULL) tmp = tmp->next;
                tmp->next = New;
            }
            else
                head = New;
            print_Linklist();
        }
        void del_node(int n) {
            tmp = temp = head;
            while(temp->next !=NULL) {
                if (n == temp->data) {
                    tmp->next = temp->next;
                    free(temp);
                    break;
                }
                tmp = temp;
                temp = temp->next;
            }
            print_Linklist();
        }
};

int main () {
    LinkedList mylink;
    mylink.append_node(0);
    mylink.append_node(1);
    mylink.append_node(2);
    mylink.append_node(3);
    mylink.del_node(1);
    return 0;
}

#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node(int data1, Node* next1);
    Node(int data1);
};

Node::Node(int data1, Node* next1)
{
    data = data1;
    next = next1;
}
Node::Node(int data1) {
    data = data1;
    next = nullptr;
}

void printLL(Node* head) {
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<< "\n";
}

Node* deleteNode(Node* head, int k){
    if (head == nullptr)
    {
        return head;
    }
    
    if (k == 1) {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node *temp = head;
    Node *prev = nullptr;
    int cnt = 0;
    while (temp != nullptr)
    {
        cnt++;
        if (cnt == k)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(2);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(8);
    head->next->next->next->next->next->next = new Node(11);
    head->next->next->next->next->next->next->next = new Node(23);

    cout << "Original linked list is "<<"\n";
    printLL(head);

    cout << "Changed linked is: Node deleted at 4 position \n";
    Node* ans = deleteNode(head, 4);
    printLL(ans);
    return 0;
}
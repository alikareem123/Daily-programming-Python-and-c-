class Node
{
public:
    int data;
    Node *next;
    Node(int data1);
    Node(int data1, Node *next1);
    Node() : data(0), next(nullptr) {}
};

Node::Node(int data1)
{
    data = data1;
    next = nullptr;
}

Node::Node(int data1, Node *next1)
{
    data = data1;
    next = next1;
}

Node *addTwoNumbers(Node *head1, Node *head2)
{
    Node *dummy = new Node();
    Node *temp = dummy;
    int carry = 0;

    while (head1 != nullptr || head2 != nullptr)
    {
        int sum = 0;
        if (head1 != nullptr)
        {
            sum += head1->data;
            head1 = head1->next;
        }
        if (head2 != nullptr)
        {
            sum += head2->data;
            head2 = head2->next;
        }
        sum += carry;
        carry = sum / 10;
        Node *node = new Node(sum % 10);
        temp->next = node;
        temp = temp->next;
    }
    return dummy->next;
}
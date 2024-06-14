
/**
 * Node
 */
class Node {
    int data;
    Node next;
    Node(int data, Node next) {
        this.data = data;
        this.next = next;
    }
    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class MiddleNode{

    public static Node middleNodeFinder(Node head){
        Node slow = head;
        Node fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }
    public static void printLinkedList(Node head) {
        Node temp = head;
        while (temp !=  null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }
    public static void main(String[] args) {
        Node head = new Node(1);
        head.next = new Node(3);
        head.next.next = new Node(2);
        head.next.next.next = new Node(4);
        head.next.next.next.next = new Node(5);


        System.out.println("The Original Linked List is ");
        printLinkedList(head);

        Node ans = middleNodeFinder(head);
        System.out.println("The middle of the linked list is " + ans.data);
    }
}
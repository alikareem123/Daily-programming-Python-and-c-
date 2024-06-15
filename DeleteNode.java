import java.util.Scanner;

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

public class DeleteNode {
    static Scanner scan = new Scanner(System.in);
    public static Node deleteNode(Node head, int k) {
        if(head == null) {
            return head;
        }
        if(k == 1) {
            Node temp = head;
            head = head.next;
            temp = null;
            return head;
        }
        Node temp =head;
        Node prev = null;
        int cnt = 0;
        while (temp != null) {
            cnt++;
            if (cnt == k) {
                prev.next = prev.next.next;
                temp = null;
                break;
            }
            prev = temp;
            temp = temp.next;
        }
        return head;
    }
    public static void printLinkedList(Node head) {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }
    public static Node inputList(){
        
        int data = scan.nextInt();
        Node head = new Node(data);
        Node temp = head;

        while(true){
            
            data = scan.nextInt();
            if (data == 0) {
                break;
            }
            temp.next = new Node(data);
            temp = temp.next;
        }
        return head;
    }
    public static void main(String[] args) {
        

        System.out.println("Enter the first Node");
        System.out.println("Enter 0 to end the input");

        Node head = inputList();
        
        // Node head = new Node(1);
        // head.next = new Node(3);
        // head.next.next = new Node(2);
        // head.next.next.next = new Node(4);
        // head.next.next.next.next = new Node(5);
        // head.next.next.next.next.next = new Node(7);
        // head.next.next.next.next.next.next = new Node(21);

        System.out.print("the original linked list is ");
        printLinkedList(head);
        System.out.println("Enter the position for deletion");
        int k = scan.nextInt();
        scan.close();
        System.out.printf("The changed linked list at index %d is ", k);
        Node ans = deleteNode(head, k);
        printLinkedList(ans);
    }
}

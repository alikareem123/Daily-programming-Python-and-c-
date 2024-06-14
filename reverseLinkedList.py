class Node:
    def __init__(self, data, next_node = None) -> None:
        self.data = data
        self.next = next_node

def reverseLinkedList(head):
    if head is None or head.next is None:
        return head
    newHead = reverseLinkedList(head.next)
    head.next.next = head
    head.next = None
    return newHead

def printLinkedList(head):
    temp = head
    while temp is not None:
        print(temp.data, end=" ")
        temp = temp.next
    print()
    

if __name__ == "__main__":
    head = Node(1)
    head.next = Node(3)
    head.next.next = Node(2)
    head.next.next.next = Node(4)
    
    print("Original Linked list is: ", end=" ")
    printLinkedList(head)
    
    print("Reversed Linked list is: ", end=" ")
    head = reverseLinkedList(head)
    
    printLinkedList(head)
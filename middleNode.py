class Node:
    def __init__(self, data, next_null=None) -> None:
        self.data = data
        self.next = next_null
        
def middleNode(head) -> Node:
    slow = head
    fast = head
    while fast != None and fast.next != None:
        slow = slow.next
        fast = fast.next.next
    return slow
def printLinkedList(head) -> None:
    temp = head
    while temp != None:
        print(temp.data,end=" ")
        temp = temp.next
    print()

if __name__ == "__main__":
    head = Node(1)
    head.next = Node(3)
    head.next.next = Node(2)
    head.next.next.next = Node(4)
    head.next.next.next.next = Node(5)
    head.next.next.next.next.next = Node(6)
    
    print("The original Linked List is : ")
    printLinkedList(head)
    
    print("The middle of the linked List is : ")
    ans = middleNode(head)
    print(ans.data)
    
    
    
    
class Node:
    def __init__(self, data, next_node = None) -> None:
        self.data = data
        self.next = next_node

def mergeTwoList(list1, list2):
    dummyNode = Node(-1)
    temp = dummyNode
    
    while list1 is not None and list2 is not None:
        if list1.data <= list2.data:
            temp.next = list1
            list1 = list1.next
        else:
            temp.next = list2
            list2 = list2.next
        temp = temp.next
    if list1 is not None:
        temp.next = list1
    else:
        temp.next = list2
    return dummyNode.next

def printLinkedList(head):
    temp = head
    while temp is not None:
        print(temp.data,end=" ")
        temp = temp.next
    print()

if __name__ == "__main__":
    list1 = Node(1)
    list1.next = Node(3)
    list1.next.next = Node(5)

    list2 = Node(2)
    list2.next = Node(4)
    list2.next.next = Node(6)
    
    head1 = list1
    head2 = list2
    print("The first linked list is ")
    printLinkedList(head1)
    
    print("And the second Linked List is ")
    printLinkedList(head2)
    
    print("And the merged linked list is ")
    head3 = mergeTwoList(list1, list2)
    printLinkedList(head3)
    
    
    
    

class Node:
    def __init__(self, data, next_node = None) -> None:
        self.data = data
        self.next = next_node

def detect_cycle(head) -> bool:
    slow = head
    fast = head

    while fast is not None and fast.next is not None:
        slow = slow.next
        fast = fast.next.next

        if slow == fast:
            return True
    return False

def intersection(head1, head2) -> Node:
    st = set()
    while head1 != None:
        st.add(head1)
        head1 = head1.next
    while head2 != None:
        if head2 in st:
            return head2
        head2 = head2.next
    return None

if __name__ == "__main__":
    head = Node(1)
    second = Node(2)
    third = Node(3)
    fourth = Node(9)
    fifth = Node(7)

    head.next = second
    second.next = third
    third.next = fifth
    fifth.next = fourth
    fourth.next = third

    if detect_cycle(head):
        print("Loop detected")
    else:
        print("No loop found")
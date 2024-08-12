class TreeNode:
    def __init__(self, value) -> None:
        self.value = value
        self.parent = None
        self.children = []
        self.is_locked = False
        self.locked_descendant_count = 0
    
    def can_lock_or_unlock(self):
        current = self.parent
        while current:
            if current.is_locked:
                return False
            current = current.parent
        return self.locked_descendant_count == 0
    
    def lock(self):
        if self.is_locked:
            return False
        if self.can_lock_or_unlock():
            self.is_locked = True

            current = self.parent
            while current:
                current.locked_descendant_count += 1
                current = current.parent
            return True
        return False
    
    def unlock(self):
        if not self.is_locked:
            return False
        if self.can_lock_or_unlock():
            self.is_locked = False

            current = self.parent
            while current:
                current.locked_descendant_count -= 1
                current = current.parent
            return True
        return False
    
    def is_locked_node(self):
        return self.is_locked
    
    def add_child(self, child_node):
        child_node.parent = self
        self.children.append(child_node)
    

root = TreeNode(1)
child1 = TreeNode(2)
child2 = TreeNode(3)

root.add_child(child1)
root.add_child(child2)

grandChild1 = TreeNode(4)
child1.add_child(grandChild1)

print(grandChild1.lock())
print(child1.lock())
print(grandChild1.unlock())
print(child1.lock())
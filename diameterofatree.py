class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None
def diameterOfBinaryTree(root):
    diameter = [0]
    height(root, diameter)
    return diameter[0]
def height(node, diameter):
    if not node:
        return 0
    lh = height(node.left, diameter)
    rh = height(node.right, diameter)

    diameter[0] = max(diameter[0], lh + rh)
    return 1 + max(lh, rh)

if __name__ == "__main__":
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.right = Node(4)
    root.left.left = Node(5)
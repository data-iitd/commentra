
class BinaryTree:
    class Node:
        def __init__(self, data):
            self.data = data
            self.left = None
            self.right = None
    
    def __init__(self):
        self.root = None
    
    def createTree(self):
        self.root = self.createTreeRecursive(self.root)
    
    def createTreeRecursive(self, node):
        if node == None:
            return None
        
        node.left = self.createTreeRecursive(node.left)
        node.right = self.createTreeRecursive(node.right)
        
        return node

def isBalancedRecursive(node):
    isBalanced = True
    
    def isBalancedRecursiveHelper(node, isBalanced):
        if node == None:
            return 0
        
        leftHeight = isBalancedRecursiveHelper(node.left, isBalanced)
        rightHeight = isBalancedRecursiveHelper(node.right, isBalanced)
        
        if abs(leftHeight - rightHeight) > 1:
            isBalanced = False
        
        return max(leftHeight, rightHeight) + 1
    
    isBalancedRecursiveHelper(node, isBalanced)
    
    return isBalanced

def isBalancedIterative(node):
    isBalanced = True
    
    stack = []
    subtreeHeights = {}
    
    node = root
    lastVisited = None
    
    while not stack or node!= None:
        if node!= None:
            stack.append(node)
            node = node.left
            
            if node == None or node == lastVisited:
                leftHeight = subtreeHeights.get(node.left, 0)
                rightHeight = subtreeHeights.get(node.right, 0)
                
                if abs(leftHeight - rightHeight) > 1:
                    isBalanced = False
                
                subtreeHeights[node] = max(leftHeight, rightHeight) + 1
                lastVisited = node
                
                node = None
            else:
                node = node.right
        else:
            node = stack.pop()
    
    return isBalanced

if __name__ == '__main__':
    tree = BinaryTree()
    tree.createTree()
    
    print("Is tree balanced (recursive): " + str(isBalancedRecursive(tree.root)))
    print("Is tree balanced (iterative): " + str(isBalancedIterative(tree.root)))


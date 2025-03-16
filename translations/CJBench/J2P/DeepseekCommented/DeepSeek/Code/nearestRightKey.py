class NRKTree:
    def __init__(self, x):
        self.left = None
        self.right = None
        self.data = x

def main(root, x0):
    if root is None:
        return 0
    else:
        if root.data > x0:
            temp = main(root.left, x0)
            if temp == 0:
                return root.data
            return temp
        else:
            return main(root.right, x0)

def find_nearest_right_key(root, x0):
    if root is None:
        return "No nearest right key found."
    else:
        if root.data > x0:
            temp = find_nearest_right_key(root.left, x0)
            if temp == "No nearest right key found.":
                return root.data
            return temp
        else:
            return find_nearest_right_key(root.right, x0)

# Main function to read input and construct the tree
if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    node_map = {}
    root = None
    
    index = 1
    for i in range(n):
        value = int(data[index])
        left = int(data[index + 1])
        right = int(data[index + 2])
        index += 3
        
        node_map[value] = NRKTree(value)
        current = node_map[value]
        
        if root is None:
            root = current
        
        if left != -1:
            node_map[left] = NRKTree(left)
            current.left = node_map[left]
        
        if right != -1:
            node_map[right] = NRKTree(right)
            current.right = node_map[right]
    
    inputX0 = int(data[-1])
    to_print = find_nearest_right_key(root, inputX0)
    if to_print == "No nearest right key found.":
        print(to_print)
    else:
        print("Nearest Right Key: " + str(to_print))

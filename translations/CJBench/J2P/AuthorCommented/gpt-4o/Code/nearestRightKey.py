class NRKTree:
    def __init__(self, x):
        self.left = None
        self.right = None
        self.data = x

def find_nearest_right_key(root, x0):
    # Check whether tree is empty
    if root is None:
        return 0
    else:
        if root.data > x0:
            # Go left
            temp = find_nearest_right_key(root.left, x0)
            if temp == 0:
                return root.data
            return temp
        else:
            # Go right
            return find_nearest_right_key(root.right, x0)

def main():
    n = int(input())
    
    node_map = {}
    root = None

    for _ in range(n):
        value, left, right = map(int, input().split())
        
        if value not in node_map:
            node_map[value] = NRKTree(value)
        current = node_map[value]

        if root is None:
            root = current  # Assign the first node as the root

        if left != -1:
            if left not in node_map:
                node_map[left] = NRKTree(left)
            current.left = node_map[left]
        if right != -1:
            if right not in node_map:
                node_map[right] = NRKTree(right)
            current.right = node_map[right]

    input_x0 = int(input())
    
    to_print = find_nearest_right_key(root, input_x0)
    if to_print == 0:
        print("No nearest right key found.")
    else:
        print("Nearest Right Key:", to_print)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

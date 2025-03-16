class BT:
    def __init__(self):
        self.parent = -1
        self.right = -1
        self.left = -1

bt = [BT() for _ in range(26)]
n = 0

def preorder(a):
    if a == -1:
        return
    print(f" {a}", end="")
    preorder(bt[a].left)
    preorder(bt[a].right)

def inorder(a):
    if a == -1:
        return
    inorder(bt[a].left)
    print(f" {a}", end="")
    inorder(bt[a].right)

def postorder(a):
    if a == -1:
        return
    postorder(bt[a].left)
    postorder(bt[a].right)
    print(f" {a}", end="")

if __name__ == "__main__":
    n = int(input())
    
    for i in range(n):
        bt[i].parent = -1

    for i in range(n):
        num = int(input())
        left, right = map(int, input().split())
        bt[num].left = left
        bt[num].right = right

        if left != -1 and right != -1:
            bt[left].parent = num
            bt[right].parent = num
        elif left != -1:
            bt[left].parent = num
        elif right != -1:
            bt[right].parent = num

    root = 0
    while bt[root].parent != -1:
        root += 1

    print("Preorder")
    preorder(root)
    print("\n")

    print("Inorder")
    inorder(root)
    print("\n")

    print("Postorder")
    postorder(root)
    print("\n")

# <END-OF-CODE>

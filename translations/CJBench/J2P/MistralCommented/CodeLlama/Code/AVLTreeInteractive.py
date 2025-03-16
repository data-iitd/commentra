
class Node:
    def __init__(self, key, parent):
        self.key = key
        self.parent = parent
        self.left = None
        self.right = None
        self.balance = 0
        self.height = 0

class AVLTree:
    def __init__(self):
        self.root = None

    def insert(self, key):
        if self.root is None:
            self.root = Node(key, None)
        else:
            node = self.root
            parent = self.root
            while True:
                if node.key == key:
                    return False
                parent = node
                go_left = node.key > key
                node = node.left if go_left else node.right
                if node is None:
                    if go_left:
                        parent.left = Node(key, parent)
                    else:
                        parent.right = Node(key, parent)
                    self.rebalance(parent)
                    break
        return True

    def delete(self, del_key):
        if self.root is None:
            return
        node = self.root
        child = self.root
        while child is not None:
            node = child
            child = del_key > node.key if del_key > node.key else node.left
            if del_key == node.key:
                self.delete_node(node)
                return
        return

    def delete_node(self, node):
        if node.left is None and node.right is None:
            if node.parent is None:
                self.root = None
            else:
                if node.parent.left == node:
                    node.parent.left = None
                else:
                    node.parent.right = None
                self.rebalance(node.parent)
            return
        child = node.left if node.left is not None else node.right
        if node.left is not None:
            while child.right is not None:
                child = child.right
            node.key = child.key
        else:
            while child.left is not None:
                child = child.left
            node.key = child.key
        self.delete_node(child)

    def search(self, key):
        result = self.search_helper(self.root, key)
        return result is not None

    def search_helper(self, root, key):
        if root is None or root.key == key:
            return root
        return self.search_helper(root.left, key) if key < root.key else self.search_helper(root.right, key)

    def display(self):
        self.display_helper(self.root)

    def display_helper(self, node):
        if node is not None:
            self.display_helper(node.left)
            print(node.key, end=" ")
            self.display_helper(node.right)

    def rebalance(self, n):
        self.set_balance(n)

        if n.balance == -2:
            if self.height(n.left.left) >= self.height(n.left.right):
                n = self.rotate_right(n)
            else:
                n = self.rotate_left_then_right(n)
        elif n.balance == 2:
            if self.height(n.right.right) >= self.height(n.right.left):
                n = self.rotate_left(n)
            else:
                n = self.rotate_right_then_left(n)

        if n.parent is not None:
            self.rebalance(n.parent)
        else:
            self.root = n

    def rotate_right(self, a):
        b = a.left
        b.parent = a.parent
        a.left = b.right
        if a.left is not None:
            a.left.parent = a
        b.right = a
        a.parent = b
        self.set_balance(a, b)
        return b

    def rotate_left(self, a):
        b = a.right
        b.parent = a.parent
        a.right = b.left
        if a.right is not None:
            a.right.parent = a
        b.left = a
        a.parent = b
        self.set_balance(a, b)
        return b

    def rotate_left_then_right(self, n):
        n.left = self.rotate_left(n.left)
        return self.rotate_right(n)

    def rotate_right_then_left(self, n):
        n.right = self.rotate_right(n.right)
        return self.rotate_left(n)

    def height(self, node):
        return node.height if node is not None else -1

    def set_balance(self, *nodes):
        for node in nodes:
            self.reheight(node)
            node.balance = self.height(node.right) - self.height(node.left)

    def reheight(self, node):
        if node is not None:
            node.height = 1 + max(self.height(node.left), self.height(node.right))

    def main():
        tree = AVLTree()
        tree.insert(10)
        tree.insert(20)
        tree.insert(30)
        tree.insert(40)
        tree.insert(50)
        tree.insert(60)
        tree.insert(70)
        tree.insert(80)
        tree.insert(90)
        tree.insert(100)
        tree.insert(110)
        tree.insert(120)
        tree.insert(130)
        tree.insert(140)
        tree.insert(150)
        tree.insert(160)
        tree.insert(170)
        tree.insert(180)
        tree.insert(190)
        tree.insert(200)
        tree.insert(210)
        tree.insert(220)
        tree.insert(230)
        tree.insert(240)
        tree.insert(250)
        tree.insert(260)
        tree.insert(270)
        tree.insert(280)
        tree.insert(290)
        tree.insert(300)
        tree.insert(310)
        tree.insert(320)
        tree.insert(330)
        tree.insert(340)
        tree.insert(350)
        tree.insert(360)
        tree.insert(370)
        tree.insert(380)
        tree.insert(390)
        tree.insert(400)
        tree.insert(410)
        tree.insert(420)
        tree.insert(430)
        tree.insert(440)
        tree.insert(450)
        tree.insert(460)
        tree.insert(470)
        tree.insert(480)
        tree.insert(490)
        tree.insert(500)
        tree.insert(510)
        tree.insert(520)
        tree.insert(530)
        tree.insert(540)
        tree.insert(550)
        tree.insert(560)
        tree.insert(570)
        tree.insert(580)
        tree.insert(590)
        tree.insert(600)
        tree.insert(610)
        tree.insert(620)
        tree.insert(630)
        tree.insert(640)
        tree.insert(650)
        tree.insert(660)
        tree.insert(670)
        tree.insert(680)
        tree.insert(690)
        tree.insert(700)
        tree.insert(710)
        tree.insert(720)
        tree.insert(730)
        tree.insert(740)
        tree.insert(750)
        tree.insert(760)
        tree.insert(770)
        tree.insert(780)
        tree.insert(790)
        tree.insert(800)
        tree.insert(810)
        tree.insert(820)
        tree.insert(830)
        tree.insert(840)
        tree.insert(850)
        tree.insert(860)
        tree.insert(870)
        tree.insert(880)
        tree.insert(890)
        tree.insert(900)
        tree.insert(910)
        tree.insert(920)
        tree.insert(930)
        tree.insert(940)
        tree.insert(950)
        tree.insert(960)
        tree.insert(970)
        tree.insert(980)
        tree.insert(990)
        tree.insert(1000)
        tree.insert(1010)
        tree.insert(1020)
        tree.insert(1030)
        tree.insert(1040)
        tree.insert(1050)
        tree.insert(1060)
        tree.insert(1070)
        tree.insert(1080)
        tree.insert(1090)
        tree.insert(1100)
        tree.insert(1110)
        tree.insert(1120)
        tree.insert(1130)
        tree.insert(1140)
        tree.insert(1150)
        tree.insert(1160)
        tree.insert(1170)
        tree.insert(1180)
        tree.insert(1190)
        tree.insert(1200)
        tree.insert(1210)
        tree.insert(1220)
        tree.insert(1230)
        tree.insert(1240)
        tree.insert(1250)
        tree.insert(1260)
        tree.insert(1270)
        tree.insert(1280)
        tree.insert(1290)
        tree.insert(1300)
        tree.insert(1310)
        tree.insert(1320)
        tree.insert(1330)
        tree.insert(1340)
        tree.insert(1350)
        tree.insert(1360)
        tree.insert(1370)
        tree.insert(1380)
        tree.insert(1390)
        tree.insert(1400)
        tree.insert(1410)
        tree.insert(1420)
        tree.insert(1430)
        tree.insert(1440)
        tree.insert(1450)
        tree.insert(1460)
        tree.insert(1470)
        tree.insert(1480)
        tree.insert(1490)
        tree.insert(1500)
        tree.insert(1510)
        tree.insert(1520)
        tree.insert(1530)
        tree.insert(1540)
        tree.insert(1550)
        tree.insert(1560)
        tree.insert(1570)
        tree.insert(1580)
        tree.insert(1590)
        tree.insert(1600)
        tree.insert(1610)
        tree.insert(1620)
        tree.insert(1630)
        tree.insert(1640)
        tree.insert(1650)
        tree.insert(1660)
        tree.insert(1670)
        tree.insert(1680)
        tree.insert(1690)
        tree.insert(1700)
        tree.insert(1710)
        tree.insert(1720)
        tree.insert(1730)
        tree.insert(1740)
        tree.insert(1750)
        tree.insert(1760)
        tree.insert(1770)
        tree.insert(1780)
        tree.insert(1790)
        tree.insert(1800)
        tree.insert(1810)
        tree.insert(1820)
        tree.insert(1830)
        tree.insert(1840)
        tree.insert(1850)
        tree.insert(1860)
        tree.insert(1870)
        tree.insert(1880)
        tree.insert(1890)
        tree.insert(1900)
        tree.insert(1910)
        tree.insert(1920)
        tree.insert(1930)
        tree.insert(1940)
        tree.insert(1950)
        tree.insert(1960)
        tree.insert(1970)
        tree.insert(1980)
        tree.insert(1990)
        tree.insert(2000)
        tree.insert(2010)
        tree.insert(2020)
        tree.insert(2030)
        tree.insert(2040)
        tree.insert(2050)
        tree.insert(2060)
        tree.insert(2070)
        tree.insert(2080)
        tree.insert(2090)
        tree.insert(2100)
        tree.insert(2110)
        tree.insert(2120)
        tree.insert(2130)
        tree.insert(2140)
        tree.insert(2150)
        tree.insert(2160)
        tree.insert(2170)
      
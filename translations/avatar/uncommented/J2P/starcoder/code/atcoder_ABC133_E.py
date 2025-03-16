import java.util.LinkedList ; import java.util.Scanner ; class Main:
    def __init__(self):
        self.nodes = []
        self.N = 0
        self.K = 0

    def solve(self):
        in_ = Scanner(System.in)
        self.N = in_.nextInt()
        self.K = in_.nextInt()
        for i in range(self.N):
            self.nodes.append(Node(i))
        for i in range(self.N - 1):
            a = in_.nextInt() - 1
            b = in_.nextInt() - 1
            self.nodes[a].children.add(b)
            self.nodes[b].children.add(a)
        self.nodes[0].setParent(self.K, -1, 0, self.nodes)
        patterns = 1
        for i in range(self.N):
            patterns = (patterns * self.nodes[i].pattern) % 1_000_000_007
        System.out.println(patterns)

class Node:
    def __init__(self, i):
        self.pattern = 0
        self.index = i
        self.children = LinkedList()
        self.parent = -1

    def setParent(self, K, parent, use, nodes):
        self.pattern = K - use
        self.parent = parent
        count = 1
        if parent!= -1:
            count += 1
        for n in self.children:
            if n == self.parent:
                continue
            nodes[n].setParent(K, self.index, count, nodes)
            count += 1

if __name__ == '__main__':
    main = Main()
    main.solve()


class Main:
    def __init__(self):
        self.connect = []
        self.visited = []
        self.odd = []
        self.print_output = []

    def dfs(self, crt, parent):
        self.visited[crt] = 1
        crt_connect = self.connect[crt]
        for child in crt_connect:
            if child == parent or self.visited[child] == 1:
                continue
            elif self.visited[child] == 2:
                self.print_output.append(f"{crt + 1} {child + 1}")
                self.odd[crt] = not self.odd[crt]
            else:
                self.dfs(child, crt)
                if self.odd[child]:
                    self.print_output.append(f"{child + 1} {crt + 1}")
                    self.odd[child] = not self.odd[child]
                else:
                    self.print_output.append(f"{crt + 1} {child + 1}")
                    self.odd[crt] = not self.odd[crt]
        self.visited[crt] = 2

    def main(self):
        num_node = int(input())
        num_edge = int(input())
        self.connect = [[] for _ in range(num_node)]
        
        for _ in range(num_edge):
            a, b = map(int, input().split())
            self.connect[a - 1].append(b - 1)
            self.connect[b - 1].append(a - 1)

        if num_edge % 2 != 0:
            print(-1)
            return

        self.visited = [0] * num_node
        self.odd = [False] * num_node
        self.print_output = []
        self.dfs(0, -1)
        print("\n".join(self.print_output))

if __name__ == "__main__":
    Main().main()

# <END-OF-CODE>

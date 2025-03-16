from collections import defaultdict

def main():
    num_node = int(input())
    num_edge = int(input())
    connect = defaultdict(list)
    for _ in range(num_edge):
        a, b = map(int, input().split())
        connect[a].append(b)
        connect[b].append(a)
    
    if num_edge % 2 != 0:
        print(-1)
        return
    
    visited = [0] * num_node
    odd = [False] * num_node
    print_ = []
    
    def dfs(crt, parent):
        visited[crt] = 1
        for child in connect[crt]:
            if child == parent or visited[child] == 1:
                continue
            elif visited[child] == 2:
                print_.append(f"{crt} {child}")
                odd[crt] = not odd[crt]
            else:
                dfs(child, crt)
                if odd[child]:
                    print_.append(f"{child} {crt}")
                    odd[child] = not odd[child]
                else:
                    print_.append(f"{crt} {child}")
                    odd[crt] = not odd[crt]
        visited[crt] = 2
    
    dfs(0, -1)
    for line in print_:
        print(line)

if __name__ == "__main__":
    main()

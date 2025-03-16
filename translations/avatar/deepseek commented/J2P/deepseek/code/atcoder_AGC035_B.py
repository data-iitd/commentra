def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    numNode = int(data[0])
    numEdge = int(data[1])
    
    connect = [[] for _ in range(numNode)]
    
    index = 2
    for i in range(numEdge):
        a = int(data[index]) - 1
        b = int(data[index + 1]) - 1
        connect[a].append(b)
        connect[b].append(a)
        index += 2
    
    if numEdge % 2 != 0:
        print(-1)
        return
    
    visited = [0] * numNode
    odd = [False] * numNode
    print = []
    
    def dfs(crt, parent):
        visited[crt] = 1
        for child in connect[crt]:
            if child == parent or visited[child] == 1:
                continue
            elif visited[child] == 2:
                print.append(f"{crt + 1} {child + 1}")
                odd[crt] = not odd[crt]
            else:
                dfs(child, crt)
                if odd[child]:
                    print.append(f"{child + 1} {crt + 1}")
                    odd[child] = not odd[child]
                else:
                    print.append(f"{crt + 1} {child + 1}")
                    odd[crt] = not odd[crt]
        visited[crt] = 2
    
    dfs(0, -1)
    
    for line in print:
        print(line)

main()

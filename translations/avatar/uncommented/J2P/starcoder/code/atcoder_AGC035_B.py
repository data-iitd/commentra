import sys

def main():
    numNode = int(sys.stdin.readline())
    numEdge = int(sys.stdin.readline())
    connect = [[] for i in range(numNode)]
    for i in range(numEdge):
        a, b = map(int, sys.stdin.readline().split())
        connect[a-1].append(b-1)
        connect[b-1].append(a-1)
    if numEdge % 2!= 0:
        print(-1)
        return
    visited = [0 for i in range(numNode)]
    odd = [False for i in range(numNode)]
    print = []
    dfs(0, -1)
    print('\n'.join(print))

def dfs(crt, parent):
    visited[crt] = 1
    crtConnect = connect[crt]
    for child in crtConnect:
        if child == parent or visited[child] == 1:
            continue
        elif visited[child] == 2:
            print.append(str(crt+1)+' '+str(child+1))
            odd[crt] = not odd[crt]
        else:
            dfs(child, crt)
            if odd[child]:
                print.append(str(child+1)+' '+str(crt+1))
                odd[child] = not odd[child]
            else:
                print.append(str(crt+1)+' '+str(child+1))
                odd[crt] = not odd[crt]
    visited[crt] = 2

if __name__ == "__main__":
    main()


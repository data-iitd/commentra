from sys import stdin

def main():
    while True:
        n = int(stdin.readline().strip())
        if n == 0:
            break
        v = [0] * n
        d = [[] for _ in range(33)]
        for i in range(n):
            line = stdin.readline().strip().split()
            m = int(line[1])
            v[i] = [0, line[0]]
            for j in range(m):
                a = int(line[2 + j])
                v[i][0] += n - len(d[a])
                for k in d[a]:
                    v[k][0] -= 1
                d[a].append(i)
        v.sort(key=lambda x: x[0])
        print(v[0][0], v[0][1])

if __name__ == "__main__":
    main()

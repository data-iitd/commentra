import sys

def main():
    while True:
        n = int(input().strip())
        if n == 0:
            break
        d = [[] for _ in range(33)]
        v = []
        for _ in range(n):
            line = input().strip().split()
            name = line[0]
            m = int(line[1])
            points = 0
            for _ in range(m):
                a = int(line[2 + _])
                points += n - len(d[a])
                d[a].append(_)
                for j in d[a]:
                    if j != _:
                        v[j] -= 1
            v.append((points, name))
        v.sort()
        print(v[0][0], v[0][1])

if __name__ == "__main__":
    main()

import sys

def main():
    n = int(sys.stdin.readline())
    q = int(sys.stdin.readline())
    c = sys.stdin.readline().strip()
    range = []
    for i in range(q):
        range.append(list(map(int, sys.stdin.readline().strip().split())))
    frag = [0] * (n + 1)
    rui = [0] * (n + 1)
    for i in range(2, n + 1):
        if c[i - 2] == 'A' and c[i - 1] == 'C':
            frag[i] += 1
        rui[i] = rui[i - 1] + frag[i]
    for i in range(q):
        left = range[i][0]
        right = range[i][1]
        print(rui[right] - rui[left])

if __name__ == "__main__":
    main()


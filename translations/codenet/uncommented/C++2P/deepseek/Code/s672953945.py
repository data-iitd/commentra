from typing import List

def main():
    N, L = map(int, input().split())
    v = []
    for _ in range(N):
        s = input()
        v.append(s)

    v.sort()

    print(''.join(v))

if __name__ == "__main__":
    main()

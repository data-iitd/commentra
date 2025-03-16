def main():
    while True:
        n = int(input())
        if n == 0:
            break
        st = [False] * 7
        for _ in range(n):
            t = int(input())
            ans = ['0'] * 7
            for i in range(7):
                ans[i] = '1' if st[i] ^ seg[t][i] else '0'
                st[i] = seg[t][i]
            print(''.join(ans))

seg = [
    [0, 1, 1, 1, 1, 1, 1], # 0
    [0, 0, 0, 0, 1, 1, 0], # 1
    [1, 0, 1, 1, 0, 1, 1], # 2
    [1, 0, 0, 1, 1, 1, 1], # 3
    [1, 1, 0, 0, 1, 1, 0], # 4
    [1, 1, 0, 1, 1, 0, 1], # 5
    [1, 1, 1, 1, 1, 0, 1], # 6
    [0, 1, 0, 0, 1, 1, 1], # 7
    [1, 1, 1, 1, 1, 1, 1], # 8
    [1, 1, 0, 1, 1, 1, 1]  # 9
]

if __name__ == "__main__":
    main()

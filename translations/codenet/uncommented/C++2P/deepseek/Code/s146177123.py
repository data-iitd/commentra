def main():
    seg = [
        [0, 1, 1, 1, 1, 1, 1],
        [0, 0, 0, 0, 1, 1, 0],
        [1, 0, 1, 1, 0, 1, 1],
        [1, 0, 0, 1, 1, 1, 1],
        [1, 1, 0, 0, 1, 1, 0],
        [1, 1, 0, 1, 1, 0, 1],
        [1, 1, 1, 1, 1, 0, 1],
        [0, 1, 0, 0, 1, 1, 1],
        [1, 1, 1, 1, 1, 1, 1],
        [1, 1, 0, 1, 1, 1, 1]
    ]
    
    while True:
        n = int(input())
        if n == 0:
            break
        st = [0] * 7
        for _ in range(n):
            t = int(input())
            ans = ['0'] * 7
            for i in range(7):
                ans[i] = '1' if st[i] ^ seg[t][i] else '0'
                st[i] = seg[t][i]
            print(''.join(ans))

main()

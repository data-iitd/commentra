def main():
    n = int(input())
    cnt = [1] * 26
    s = list(input())
    for i in range(n):
        cnt[ord(s[i]) - ord('a')] += 1

    ans = cnt[0]
    for i in range(1, 26):
        ans *= cnt[i]
        ans %= 10**9 + 7

    print(ans - 1)

main()

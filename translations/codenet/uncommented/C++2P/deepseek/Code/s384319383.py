import sys

def main():
    n = int(input().strip())
    cnt = [1] * 26
    s = list(input().strip())
    
    for char in s:
        cnt[ord(char) - ord('a')] += 1
    
    ans = cnt[0]
    for i in range(1, 26):
        ans *= cnt[i]
        ans %= 10**9 + 7
    
    print(ans - 1)

if __name__ == "__main__":
    main()

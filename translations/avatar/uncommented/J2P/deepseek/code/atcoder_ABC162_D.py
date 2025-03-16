import sys

def main():
    n = int(input().strip())
    s = input().strip()
    rc = gc = bc = 0
    for char in s:
        if char == 'R':
            rc += 1
        elif char == 'G':
            gc += 1
        elif char == 'B':
            bc += 1
    result = rc * gc * bc
    for i in range(1, n):
        for k in range(i + 1, n):
            if (i + k) % 2 == 0:
                j = (i + k) // 2
                if s[i] != s[k] and s[k] != s[j] and s[j] != s[i]:
                    result -= 1
    print(result)

if __name__ == "__main__":
    main()

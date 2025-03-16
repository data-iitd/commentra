import sys
from typing import List

def scan_string() -> str:
    return input().strip()

def scan_int() -> int:
    return int(scan_string())

def scan_ints(n: int) -> List[int]:
    return [scan_int() for _ in range(n)]

def debug(*args):
    print(*args, file=sys.stderr)

def abs_value(a: int) -> int:
    return -a if a < 0 else a

def min_value(a: int, b: int) -> int:
    return a if a < b else b

def max_value(a: int, b: int) -> int:
    return a if a > b else b

def main():
    s = list(scan_string())
    t = list(scan_string())

    ans = []
    for i in range(len(s) - len(t) + 1):
        f = True
        ss = s[:]

        for j in range(len(t)):
            if s[i + j] != t[j] and s[i + j] != '?':
                f = False
                break
            else:
                ss[i + j] = t[j]

        if f:
            ans.append(''.join(ss).replace('?', 'a'))

    ans.sort()
    if len(ans) == 0:
        print("UNRESTORABLE")
    else:
        print(ans[0])

if __name__ == "__main__":
    main()

# <END-OF-CODE>

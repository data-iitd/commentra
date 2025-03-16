import sys
from typing import List

def read_int() -> int:
    return int(sys.stdin.readline().strip())

def read_int_slice(n: int) -> List[int]:
    return list(map(int, sys.stdin.readline().strip().split()))

def main():
    n = read_int()
    x = read_int()
    A = read_int_slice(n)

    A.sort()

    ans = 0
    for i in range(n):
        if x >= A[i]:
            ans += 1
            x -= A[i]
        else:
            break
    if ans == n and x > 0:
        ans -= 1
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

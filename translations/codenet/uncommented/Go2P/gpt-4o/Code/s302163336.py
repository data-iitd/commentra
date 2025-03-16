import sys

def next_int():
    return int(sys.stdin.readline().strip())

def main():
    n = next_int()
    m = next_int()
    h = [next_int() for _ in range(n)]
    good = [True] * n
    
    for _ in range(m):
        ai = next_int() - 1
        bi = next_int() - 1
        if h[ai] > h[bi]:
            good[bi] = False
        elif h[ai] < h[bi]:
            good[ai] = False
        else:
            good[ai] = False
            good[bi] = False
    
    ans = sum(good)
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

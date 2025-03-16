import sys

def next_int():
    return int(sys.stdin.readline().strip())

def reva(b):
    b.reverse()

def main():
    n = next_int()
    a = list(map(int, sys.stdin.readline().strip().split()))
    q = next_int()
    for _ in range(q):
        b = next_int()
        e = next_int()
        reva(a[b:e])
    
    print(" ".join(map(str, a)))

if __name__ == "__main__":
    main()

# <END-OF-CODE>

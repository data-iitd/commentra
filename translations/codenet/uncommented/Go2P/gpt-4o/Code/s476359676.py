import sys

def next_int():
    return int(sys.stdin.readline().strip())

def main():
    n = next_int()
    ans = 0
    a_prev = 0
    
    for i in range(n):
        a = next_int()
        if a > i or a > a_prev + 1:
            print(-1)
            return
        elif a == a_prev + 1:
            ans += 1
        else:
            ans += a
        a_prev = a
    
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

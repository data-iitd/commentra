def solve(a, b, c):
    if c == a + b:
        temp_ = b + c
    elif c - 1 > a + b:
        temp = (c - 1) - (a + b)
        temp_ = b + c - temp
    else:
        temp_ = b + c

    return temp_

def main():
    a, b, c = map(int, input().split())
    ans = solve(a, b, c)
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

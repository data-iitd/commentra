import sys

def get_next_string():
    return input().strip()

def get_next_int():
    return int(get_next_string())

def main():
    if len(sys.argv) > 1:
        with open(sys.argv[1], 'r') as fp:
            n = int(fp.readline().strip())
            ans = "second"
            for _ in range(n):
                a = int(fp.readline().strip())
                if a % 2 == 1:
                    ans = "first"
                    break
    else:
        n = get_next_int()
        ans = "second"
        for _ in range(n):
            a = get_next_int()
            if a % 2 == 1:
                ans = "first"
                break

    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

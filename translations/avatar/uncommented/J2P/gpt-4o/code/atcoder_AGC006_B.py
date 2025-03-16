def main():
    n = int(input())
    x = int(input())
    print_result(x, n)

def print_result(x, n):
    max_value = n * 2 - 1
    if x == 1 or x == max_value:
        print("No")
        return
    print("Yes")
    sep = "\n"
    ans = ''.join(str((e % max_value) + 1) + sep for e in range(x + n - 1, x + n + max_value - 1))
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

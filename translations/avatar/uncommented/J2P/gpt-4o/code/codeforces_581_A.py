def main():
    a = int(input())
    b = int(input())
    count = 0
    while True:
        if a > 0 and b > 0:
            count += 1
            a -= 1
            b -= 1
        else:
            break
    ans = a // 2 + b // 2
    print(count, ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

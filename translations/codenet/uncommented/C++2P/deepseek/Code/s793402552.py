def main():
    a, b = map(int, input().split())
    bstr = str(b)
    num = a * (10 ** len(bstr)) + b

    i = 1
    while i * i <= num:
        if i * i == num:
            print("Yes")
            return
        i += 1

    print("No")


if __name__ == "__main__":
    main()

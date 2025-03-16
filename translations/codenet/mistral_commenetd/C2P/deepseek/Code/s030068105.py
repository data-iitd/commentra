def main():
    n = int(input("Enter the number of elements: "))
    data = list(map(int, input().split()))

    max_value = max(data)
    max_index = data.index(max_value)

    a = sum(data) - max_value

    if a > max_value:
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()

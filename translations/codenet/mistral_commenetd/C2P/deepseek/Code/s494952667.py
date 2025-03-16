def main():
    str = input("Enter a string: ")
    len_str = len(str)

    print("Reversed string: ", end="")

    for i in range(len_str - 1, -1, -1):
        print(str[i], end="")

    print()


main()

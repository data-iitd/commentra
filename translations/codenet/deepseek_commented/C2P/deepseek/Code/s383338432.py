def main():
    height, width = map(int, input().split())  # Read the height and width from the user input
    input_str = [input() for _ in range(height)]  # Read each line of input

    # Print the top border of the output
    print("#" * (width + 2))

    # Print each line of input with borders
    for line in input_str:
        print(f"#{line}#")

    # Print the bottom border of the output
    print("#" * (width + 2))


if __name__ == "__main__":
    main()


# Function main is the entry point of the program
def main():
    # Read the height and width of the rectangle from the user
    height, width = map(int, input().split())

    # Print the top border of the rectangle
    print('#' * (width + 2))

    # Print the body of the rectangle
    for _ in range(height):
        # Read a string from the user
        input_str = input()
        # Print the top and bottom border of each row with '#' character
        print(f'#{input_str}#')

    # Print the bottom border of the rectangle
    print('#' * (width + 2))

# Call the main function to execute the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>

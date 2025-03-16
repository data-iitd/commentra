# Function main is the entry point of the program
def main():
    # Initialize a list named in with a length of 3
    in_list = [0] * 3

    # Use input to read three integers from the standard input and store them in the list in_list
    in_list[0], in_list[1], in_list[2] = map(int, input().split())

    # Sort the integers in ascending order using sorted function
    in_list.sort()

    # Multiply the last integer by 10 and add the second last and the last integer
    # Then print the result
    print(in_list[2] * 10 + in_list[1] + in_list[0])

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>

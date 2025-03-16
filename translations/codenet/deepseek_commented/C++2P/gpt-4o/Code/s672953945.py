# Main function to execute the program
def main():
    # Read the number of strings N and the length L from the standard input
    N, L = map(int, input().split())

    # Read N strings from the standard input and store them in the list v
    v = [input().strip() for _ in range(N)]

    # Sort the list v in lexicographical order
    v.sort()

    # Concatenate and print the sorted strings without spaces
    print(''.join(v))

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>


# Define the main function, taking no arguments
def main():

    # Read the integer K from the standard input
    K = int(input())

    # Read a string S from the standard input
    S = input()

    # Check if the length of the string S is less than or equal to K
    if len(S) <= K:

        # If the condition is true, return the string S
        return S

    # If the condition is false, return a slice of the string S
    # from the beginning to the index K, followed by three dots '...'
    return S[:K] + '...'

# Define the entry point of the script
if __name__ == '__main__':

    # Call the main function and print its result
    print(main())

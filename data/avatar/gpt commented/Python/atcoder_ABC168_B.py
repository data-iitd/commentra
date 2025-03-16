def main():
    # Read an integer input K from the user
    K = int(input())
    
    # Read a string input S from the user
    S = input()
    
    # Check if the length of the string S is less than or equal to K
    if len(S) <= K:
        # If true, return the original string S
        return S
    
    # If the length of S is greater than K, return the first K characters followed by '...'
    return S[:K] + '...'

# Entry point of the program
if __name__ == '__main__':
    # Call the main function and print its result
    print(main())

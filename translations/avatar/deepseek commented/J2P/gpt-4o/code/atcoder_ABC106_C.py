def main():
    import sys
    
    # Step 1: Read input from the user
    input_data = sys.stdin.read().splitlines()
    str_input = input_data[0]  # Step 2: Read the input string
    k = int(input_data[1])  # Step 4: Read the value of k
    c = list(str_input)  # Step 3: Convert the string to a character array
    n = len(str_input)  # Step 5: Initialize the length of the string
    
    # Step 6: Loop through the character array k times
    for i in range(k):
        # Step 7: Check if the character at the current index is '1'
        if c[i] == '1':
            # Step 8: Check if the current index is the last index
            if i == k - 1:
                print(1)  # Step 9: Print '1' and return
                return
        else:  # Step 10: If it is not '1'
            print(c[i])  # Step 11: Print the character and return
            return

if __name__ == "__main__":
    main()

# <END-OF-CODE>

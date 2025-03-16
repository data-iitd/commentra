def main():
    # Step 1: Read input from the user
    str = input()
    # Step 2: Read the input string
    c = list(str)
    # Step 3: Convert the string to a character array
    k = int(input())
    # Step 4: Read the value of k
    n = len(str)
    # Step 5: Initialize the length of the string
    
    for i in range(k):
        # Step 6: Loop through the character array k times
        if c[i] == '1':
            # Step 7: Check if the character at the current index is '1'
            if i == k - 1:
                # Step 8: Check if the current index is the last index
                print(1)
                # Step 9: Print '1' and return
                return
        else:
            # Step 10: If it is not '1'
            print(c[i])
            # Step 11: Print the character and return
            return

main()

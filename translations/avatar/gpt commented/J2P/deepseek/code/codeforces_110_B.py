def main():
    # Reading an integer input from the user which determines the size of the character array
    n = int(input())
    
    # Creating a character array of size 'n'
    c = [''] * n
    
    # Filling the character array with letters starting from 'a'
    p = 97  # 'p' is initialized to 97, which is the ASCII value for 'a'
    for i in range(4):  # Looping through the first 4 positions
        for j in range(i, n, 4):  # Filling every 4th position starting from 'i'
            c[j] = chr(p)  # Assigning the character corresponding to ASCII value 'p'
            p += 1  # Incrementing 'p' to get the next character
    
    # Printing the filled character array to the console
    print(''.join(c))  # Outputting each character in the array

if __name__ == "__main__":
    main()

import sys

def main():
    n = int(input().strip())  # Read the size of the array from the user
    c = [None] * n  # Initialize the character array of size n
    p = 97  # ASCII value for 'a'
    
    # Nested loops to assign characters to the array
    for i in range(4):
        for j in range(i, n, 4):
            c[j] = chr(p)  # Assign character and increment ASCII value
        p += 1  # Increment the ASCII value for the next character
    
    # Print the character array to the console
    print(''.join(c))

if __name__ == "__main__":
    main()

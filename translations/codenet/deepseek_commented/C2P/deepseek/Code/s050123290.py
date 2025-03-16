N = 1000

def main():
    while True:
        # 1. Define the array and variables
        su = ['0'] * N  # Array to store the sequence of digits
        susum = 0  # Variable to store the sum of the digits
        j = 0  # Index to iterate through the array
        
        # 2. Read input and calculate sum
        while True:
            char = input()
            if char == '\n':
                break  # Break if newline character is encountered
            su[j] = char  # Store the character in the array
            susum += int(char)  # Convert character to integer and add to sum
            j += 1
        
        if su[0] == '0':
            break  # Break if the sequence starts with '0'
        
        # 3. Print the sum
        print(susum)  # Print the sum of the digits
        susum = 0  # Reset the sum for the next sequence

# 4. Check for termination condition
if __name__ == "__main__":
    main()

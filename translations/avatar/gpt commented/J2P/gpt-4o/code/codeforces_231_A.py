# Importing the sys module for reading input
import sys

def main():
    input = sys.stdin.read  # Reading all input at once
    data = input().split()  # Splitting the input into a list of strings
    
    t = int(data[0])  # Reading the number of test cases
    count = 0  # Initializing a counter to keep track of valid cases
    
    index = 1  # Starting index for reading test cases
    # Looping through each test case
    for _ in range(t):
        a = int(data[index])  # Reading the first integer
        b = int(data[index + 1])  # Reading the second integer
        c = int(data[index + 2])  # Reading the third integer
        index += 3  # Moving to the next set of integers
        
        # Checking if at least one of the integers is equal to 1
        if (a == 1 and b == 1) or (a == 1 and c == 1) or (b == 1 and c == 1) or (a == 1 and b == 1 and c == 1):
            count += 1  # Incrementing the count if the condition is met
    
    # Outputting the total count of valid cases
    print(count)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

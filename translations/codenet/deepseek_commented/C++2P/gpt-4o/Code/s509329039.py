# Import necessary libraries
import sys

def main():
    n, m = map(int, input().split())  # Read the number of digits and the number of constraints
    s = []  # List to store the positions of constraints
    c = []  # List to store the values of constraints
    
    for _ in range(m):
        pos, val = map(int, input().split())  # Read the position and value of each constraint
        s.append(pos - 1)  # Decrement the position by 1 to convert to 0-based index
        c.append(val)  # Store the value of the constraint

    for i in range(1000):
        st = str(i)  # Convert the current number to a string
        if len(st) != n:  # Check if the length of the string is equal to the number of digits
            continue  # If not, continue to the next iteration
        
        f = True  # Initialize a flag to True
        for j in range(m):
            if st[s[j]] == str(c[j]):  # Check if the digit at the constraint position matches the constraint value
                continue  # Do nothing (continue to the next iteration)
            else:
                f = False  # If any constraint is not met, set the flag to False
        
        if f:  # Check if all constraints are met
            print(i)  # Print the valid number
            return  # Exit the program
    
    print(-1)  # If no valid number is found, print -1

if __name__ == "__main__":
    main()

# <END-OF-CODE>

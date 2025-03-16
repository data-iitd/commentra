# Include necessary libraries
import sys

def main():
    n = int(input())  # Read the number of rounds
    taro = 0  # Initialize Tarō's score
    hanako = 0  # Initialize Hanako's score

    # Loop through each round
    for _ in range(n):
        t = input().strip()  # Read Tarō's string
        h = input().strip()  # Read Hanako's string
        
        if t < h:  # Compare and update Hanako's score
            hanako += 3
        elif t > h:  # Compare and update Tarō's score
            taro += 3
        else:  # If strings are equal
            taro += 1  # Increment Tarō's score by 1
            hanako += 1  # Increment Hanako's score by 1

    print(taro, hanako)  # Print the final scores

if __name__ == "__main__":
    main()  # Execute the main function

# <END-OF-CODE>

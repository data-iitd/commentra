import sys

def main():
    # Read a line of input and split it into an array of strings
    str = input().split()
    
    # Parse the first string as an integer representing the initial health
    h = int(str[0])
    
    # Parse the second string as an integer representing the damage dealt per attack
    a = int(str[1])
    
    # Initialize a counter to keep track of the number of attacks
    num = 0
    
    # Loop until the health is greater than zero
    while h > 0:
        # Decrease health by the amount of damage dealt
        h -= a
        
        # Increment the attack counter
        num += 1
    
    # Output the total number of attacks required to reduce health to zero or below
    print(num)

if __name__ == "__main__":
    main()

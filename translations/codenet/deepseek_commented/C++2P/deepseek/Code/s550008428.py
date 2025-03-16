import sys

def main():
    s = int(input().strip())  # Read the initial number from the user
    a = set()
    a.add(s)  # Add the initial number to the set
    d = 2  # Initialize the step count

    while True:  # Start an infinite loop
        if s % 2 == 0:  # Check if the current number is even
            x = s // 2  # Halve the number
            if x in a:  # Check if the halved number has been encountered before
                print(d)  # Output the current step count and terminate the program
                return
            a.add(x)  # Add the halved number to the set
        else:  # The current number is odd
            x = 3 * s + 1  # Triple the number and add one
            if x in a:  # Check if the new number has been encountered before
                print(d)  # Output the current step count and terminate the program
                return
            a.add(x)  # Add the new number to the set
        s = x  # Update the current number to the new number
        d += 1  # Increment the step count

if __name__ == "__main__":
    main()

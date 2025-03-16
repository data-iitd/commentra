import sys

def main():
    n = int(input().strip())  # Read the integer n
    str = input().strip()  # Read the string str
    l = list(str)  # Convert the string to a list of characters

    t = 0  # Initialize t to 0

    # Check each character in the list
    for char in l:
        if char != '4' and char != '7':
            t = 1  # Set t to 1 if a character is neither '4' nor '7'
            break  # Exit the loop early since we found a non-'4'/'7' character

    # If t is 1, print "NO"
    if t == 1:
        print("NO")
    else:
        # Calculate the sum of the first half of the list
        x = sum(int(char) for char in l[:n//2])
        # Calculate the sum of the second half of the list
        y = sum(int(char) for char in l[n//2:])
        # If x equals y, print "YES", otherwise print "NO"
        if x == y:
            print("YES")
        else:
            print("NO")

if __name__ == "__main__":
    main()

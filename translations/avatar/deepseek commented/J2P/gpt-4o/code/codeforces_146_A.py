def main():
    import sys
    
    n = int(input())  # Read the integer n
    str_input = input()  # Read the string str_input
    l = list(str_input)  # Convert the string to a list of characters

    t = 0  # Initialize t
    x = 0  # Initialize sum for the first half
    y = 0  # Initialize sum for the second half

    # Check each character in the list
    for i in range(n):
        if l[i] != '4' and l[i] != '7':
            t = 1  # Set t to 1 if a character is neither '4' nor '7'

    # If t is 1, print "NO"
    if t == 1:
        print("NO")
    else:
        # Calculate the sum of the first half of the list
        for i in range(n // 2):
            x += int(l[i])  # Convert character to integer and add to x

        # Calculate the sum of the second half of the list
        for i in range(n - 1, n // 2 - 1, -1):
            y += int(l[i])  # Convert character to integer and add to y

        # If x equals y, print "YES", otherwise print "NO"
        if x == y:
            print("YES")
        else:
            print("NO")

if __name__ == "__main__":
    main()

# <END-OF-CODE>

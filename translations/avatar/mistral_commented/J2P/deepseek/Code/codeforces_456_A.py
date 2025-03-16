import sys

def main():
    n = int(input().strip())  # Read the first integer n, which represents the number of elements in the arrays a and b
    a = list(map(int, input().strip().split()))  # Read the next n integers for array a
    b = list(map(int, input().strip().split()))  # Read the next n integers for array b

    temp = 0  # Initialize a variable temp to 0
    q = 0  # Initialize a variable q to 0
    w = -sys.maxsize - 1  # Initialize a variable w to the smallest possible integer value
    e = -sys.maxsize - 1  # Initialize a variable e to the smallest possible integer value
    f = False  # Initialize a boolean variable f to False

    for i in range(n):  # Start a for loop that iterates through the elements of arrays a and b
        if temp < a[i]:  # If the current value of temp is less than a[i]
            if q > b[i]:  # Check if the condition q > b[i] is satisfied
                f = True  # If it is, set f to True
            q = b[i]  # Update q with the new value of b[i]
            temp = a[i]  # Update temp with the new value of a[i]

        if temp > a[i]:  # If the current value of temp is greater than a[i]
            if q < b[i]:  # Check if the condition q < b[i] is satisfied
                f = True  # If it is, set f to True
            q = b[i]  # Update q with the new value of b[i]
            temp = a[i]  # Update temp with the new value of a[i]

        if a[i] > w:  # If the current value of a[i] is greater than w
            w = a[i]  # Update w with the new value of a[i]
            if b[i] < e:  # Check if the condition b[i] < e is satisfied
                f = True  # If it is, set f to True

        if a[i] < w:  # If the current value of a[i] is less than w
            if b[i] > e:  # Check if the condition b[i] > e is satisfied
                f = True  # If it is, set f to True

    if f:  # After the loop finishes, check the value of the boolean variable f
        print("Happy Alex")  # If it is true, print the message "Happy Alex"
    else:
        print("Poor Alex")  # Otherwise, print the message "Poor Alex"

if __name__ == "__main__":
    main()
<END-OF-CODE>.
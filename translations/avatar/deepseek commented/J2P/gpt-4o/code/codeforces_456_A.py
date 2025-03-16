def main():
    n = int(input())  # Read the number of elements
    a = [0] * n  # Initialize list 'a' to store first set of values
    b = [0] * n  # Initialize list 'b' to store second set of values
    temp = 0  # Variable to temporarily store a value
    q = 0  # Variable to store a value for comparison
    w = 0  # Variable to store the maximum value of 'a'
    e = 0  # Variable to store a value for comparison
    f = False  # Boolean variable to determine the output

    # Loop through each element
    for i in range(n):
        a[i], b[i] = map(int, input().split())  # Read the values for arrays 'a' and 'b'
        if temp < a[i]:  # Check if the current 'a' value is greater than the stored 'temp' value
            if q > b[i]:  # Check if the stored 'q' value is greater than the current 'b' value
                f = True  # Set 'f' to true if the condition is met
            q = b[i]  # Update 'q' with the current 'b' value
            temp = a[i]  # Update 'temp' with the current 'a' value
        if temp > a[i]:  # Check if the current 'a' value is less than the stored 'temp' value
            if q < b[i]:  # Check if the stored 'q' value is less than the current 'b' value
                f = True  # Set 'f' to true if the condition is met
            q = b[i]  # Update 'q' with the current 'b' value
            temp = a[i]  # Update 'temp' with the current 'a' value
        if a[i] > w:  # Check if the current 'a' value is greater than the stored 'w' value
            w = a[i]  # Update 'w' with the current 'a' value
            if b[i] < e:  # Check if the current 'b' value is less than the stored 'e' value
                f = True  # Set 'f' to true if the condition is met
            e = b[i]  # Update 'e' with the current 'b' value
        if a[i] < w:  # Check if the current 'a' value is less than the stored 'w' value
            if b[i] > e:  # Check if the current 'b' value is greater than the stored 'e' value
                f = True  # Set 'f' to true if the condition is met

    # Determine and print the output based on the value of 'f'
    if f:
        print("Happy Alex")  # Print "Happy Alex" if 'f' is true
    else:
        print("Poor Alex")  # Print "Poor Alex" if 'f' is false

if __name__ == "__main__":
    main()

# <END-OF-CODE>

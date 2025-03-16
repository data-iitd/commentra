a = [0] * 100100  # An array of size 100100 to store input numbers

def main():
    k = int(input())  # Variable to store the number of input numbers
    min_val = 2  # Variable to store the minimum value
    max_val = 3  # Variable to store the maximum value

    # Read the input numbers into the array
    for i in range(k):
        a[i] = int(input())

    # Check if the last number in the array is 2
    if a[k - 1] != 2:
        print(-1)  # If not, print -1 and exit the program
        return

    # Iterate through the array from the second last number to the first number
    for i in range(k - 2, -1, -1):
        # If the current number is greater than the maximum value, print -1 and exit the program
        if a[i] > max_val:
            print(-1)
            return
        else:
            # Update the maximum value based on the current number
            max_val = ((max_val // a[i]) + 1) * a[i] - 1

            # If the current number does not divide the minimum value evenly, update the minimum value
            if min_val % a[i] != 0:
                min_val = ((min_val // a[i]) + 1) * a[i]

        # Check if the minimum value is less than or equal to the maximum value
        if max_val <= min_val:
            print(-1)  # If so, print -1 and exit the program
            return

    # Print the minimum and maximum values
    print(min_val, max_val)

main()

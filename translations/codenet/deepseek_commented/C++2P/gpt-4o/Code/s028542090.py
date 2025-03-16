# Python translation of the given C++ code

def main():
    k = int(input())  # Read the number of elements from the standard input
    a = list(map(int, input().split()))  # Read the elements of the array from the standard input

    max_val = 3
    min_val = 2

    if a[k - 1] != 2:  # Check if the last element of the array is not 2
        print(-1)  # Output -1 and terminate the program
        return

    for i in range(k - 2, -1, -1):  # Iterate through the array in reverse order
        if a[i] > max_val:  # Check if the current element is greater than the current maximum
            print(-1)  # Output -1 and terminate the program
            return
        else:
            max_val = ((max_val // a[i]) + 1) * a[i] - 1  # Update the maximum value
            if min_val % a[i] != 0:  # Check if min is not a multiple of the current element
                min_val = ((min_val // a[i]) + 1) * a[i]  # Update the minimum value

        if max_val <= min_val:  # Check if the maximum value is not greater than the minimum value
            print(-1)  # Output -1 and terminate the program
            return

    print(min_val, max_val)  # Output the minimum and maximum values

if __name__ == "__main__":
    main()

# <END-OF-CODE>

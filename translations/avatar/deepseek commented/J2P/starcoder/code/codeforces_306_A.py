
import java.util.Arrays ; 
import java.util.Scanner ; 

def main():
    # Read the values of n and m from the user
    n = int(input())
    m = int(input())

    # Initialize an array of size m
    a = [0] * m

    # Check if n is divisible by m
    if n % m == 0:
        # Fill the array with equal parts if n is divisible by m
        for i in range(0, m):
            a[i] = n / m
    else:
        # Calculate the base part size
        sub = n / m

        # Fill the array with the base part size
        for i in range(0, m):
            a[i] = sub

        # Distribute the remainder
        test = n - (sub * m)
        count = 0
        for i in range(0, test):
            a[count] = a[count] + 1
            count += 1
            if count >= m:
                count = 0

    # Print the array elements in reverse order
    for i in range(m - 1, -1, -1):
        print(a[i], end=" ")

if __name__ == "__main__":
    main()


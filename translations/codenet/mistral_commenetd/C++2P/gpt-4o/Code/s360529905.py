# Import the necessary library for sorting
import sys

def main():
    N = int(sys.stdin.readline().strip())  # Read the number of elements from standard input
    a = []  # Initialize an empty list for array a
    b = []  # Initialize an empty list for array b

    for _ in range(N):  # Iterate N times to read elements
        a.append(int(sys.stdin.readline().strip()))  # Read an integer and append to array a
        b.append(a[-1])  # Copy the value of the last element in array a to array b

    b.sort()  # Sort the elements in array b in ascending order

    frontHalf = b[N // 2 - 1]  # Assign the middle value of the first half of the sorted array b
    backHalf = b[N // 2]  # Assign the middle value of the second half of the sorted array b

    for i in range(N):  # Iterate through the array a
        if a[i] < backHalf:  # If the value at the ith position in array a is less than backHalf
            print(backHalf)  # Print the middle value of the second half of the sorted array b
        else:
            print(frontHalf)  # Print the middle value of the first half of the sorted array b

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>

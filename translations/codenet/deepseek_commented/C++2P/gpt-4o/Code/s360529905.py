# Import the necessary library for sorting
import sys

def main():
    N = int(sys.stdin.readline().strip())  # Read the number of elements from the user
    a = []  # Initialize list a
    b = []  # Initialize list b

    for _ in range(N):  # Loop to read elements into list a and copy them to list b
        a.append(int(sys.stdin.readline().strip()))  # Read an element into list a
        b.append(a[-1])  # Copy the element from list a to list b

    b.sort()  # Sort list b

    frontHalf = b[N // 2 - 1]  # Calculate the first half's middle value
    backHalf = b[N // 2]  # Calculate the second half's middle value

    for i in range(N):  # Loop to compare each element of list a
        if a[i] < backHalf:  # Check if the element is less than the second middle value
            print(backHalf)  # Print the second middle value
        else:
            print(frontHalf)  # Print the first middle value

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>

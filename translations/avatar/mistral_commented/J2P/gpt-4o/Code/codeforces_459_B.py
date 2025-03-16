import sys

def main():
    input = sys.stdin.read
    data = input().split()
    
    N = int(data[0])  # Read the number of elements N from the standard input
    A = list(map(int, data[1:N+1]))  # Create a list A of size N to store the elements

    A.sort()  # Sort the elements in the list A in ascending order

    min_val = A[0]  # Minimum element
    max_val = A[N - 1]  # Maximum element

    mins = A.count(min_val)  # Count occurrences of the minimum element
    maxs = A.count(max_val)  # Count occurrences of the maximum element

    if min_val == max_val:
        result = (max_val - min_val) + 1  # Calculate the difference plus 1
        result *= mins  # Multiply by the number of occurrences of the minimum element
        result -= mins * (mins - 1) // 2  # Subtract the number of combinations of pairs of minimum elements
        print(result)  # Print the output
    else:
        result = (max_val - min_val)  # Calculate the difference between the minimum and maximum elements
        result *= mins  # Multiply by the number of occurrences of the minimum element
        result *= maxs  # Multiply by the number of occurrences of the maximum element
        print(result)  # Print the output

if __name__ == "__main__":
    main()

# <END-OF-CODE>

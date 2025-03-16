#!python3

# Read an integer input N which represents the number of elements in the list
N = int(input())

# Read a list of integers A from input, splitting the input string and converting each to an integer
A = list(map(int, input().split()))

def main():
    # Sort the list A in ascending order
    A.sort()
    
    # Calculate the difference between the maximum and minimum values in the sorted list
    ans = A[-1] - A[0]
    
    # Print the result, which is the difference calculated
    print(ans)

# Check if the script is being run directly (not imported as a module)
if __name__ == "__main__":
    main()

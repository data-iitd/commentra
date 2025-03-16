# Include necessary libraries
import sys

# Main function
def main():
    # Read input values
    N, D, X = map(int, sys.stdin.readline().split())
    
    # Initialize array A
    A = [0] * N
    
    # Read values into array A
    for i in range(N):
        A[i] = int(sys.stdin.readline().strip())
    
    # Calculate the number of chocolates needed
    num_of_chocolate = 0
    for i in range(N):
        days = 0
        counter = 0
        while True:
            days = counter * A[i] + 1
            if days <= D:
                counter += 1
            else:
                break
        num_of_chocolate += counter
    
    # Add extra chocolates
    num_of_chocolate += X
    
    # Output the result
    print(num_of_chocolate)

# Call the main function
if __name__ == "__main__":
    main()

# Define a function to calculate the sum of positive differences
def main():
    # Read the number of elements
    n = int(input())
    
    # Input the first array 'a'
    a = list(map(int, input().split()))
    
    # Input the second array 'b' and calculate the sum of positive differences
    b = list(map(int, input().split()))
    
    # Initialize sum
    sum_positive_diff = 0
    
    # Calculate the sum of positive differences
    for i in range(n):
        if a[i] - b[i] > 0:
            sum_positive_diff += a[i] - b[i]
    
    # Output the final sum of positive differences
    print(sum_positive_diff)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>

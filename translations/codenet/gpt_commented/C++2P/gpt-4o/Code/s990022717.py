# Global variable to control debug output
debug = False

def main():
    # Read input values: n (total items), k (threshold), x (cost for first k items), y (cost for items beyond k)
    n, k, x, y = map(int, input().split())
    
    # Initialize sum to accumulate total cost
    total_cost = 0

    # Loop through each item from 1 to n
    for i in range(1, n + 1):
        # If the current item index exceeds k, add cost y; otherwise, add cost x
        if i > k:
            total_cost += y  # Cost for items beyond the threshold
        else:
            total_cost += x  # Cost for items within the threshold

    # Output the total calculated cost
    print(total_cost)

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>

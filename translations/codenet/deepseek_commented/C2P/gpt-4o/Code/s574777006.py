# Include the standard input-output header

def main():
    n = int(input())  # Read the number of elements
    x = list(map(int, input().split()))  # Read the elements of array x
    
    q = int(input())  # Read the number of queries
    y = list(map(int, input().split()))  # Read the elements of array y
    
    sum_matches = 0  # Initialize sum of matches
    
    for query in y:  # For each query
        if query in x:  # If the query matches an element in x
            sum_matches += 1  # Increment the sum
    
    print(sum_matches)  # Print the sum of matches

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>

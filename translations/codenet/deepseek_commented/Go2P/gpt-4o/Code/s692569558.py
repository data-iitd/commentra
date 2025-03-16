import sys

def main():
    # Read the first line of input (which we will ignore)
    input()  # Ignore the first line
    
    # Read the second line of input
    ds = input().strip()
    
    # Split the input string into a list of strings
    dd = ds.split()
    
    # Create a list of integers to hold the converted values
    dn = [int(d) for d in dd]
    
    # Initialize the sum variable to hold the result
    total_sum = 0
    
    # Calculate the sum of the products of all pairs of integers in the list
    for i in range(len(dn)):
        for j in range(i + 1, len(dn)):
            total_sum += dn[i] * dn[j]
    
    # Print the result
    print(total_sum)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

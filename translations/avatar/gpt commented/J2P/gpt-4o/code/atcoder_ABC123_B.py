from collections import defaultdict

def main():
    # Initialize two lists to hold the input values and their remainders
    a = [0] * 5
    r = [0] * 5
    
    # Create a dictionary to store the required values for adjustment
    adjustments = {}
    
    # Read 5 integers from the user and calculate their remainders
    for i in range(len(a)):
        a[i] = int(input())  # Read input value
        r[i] = a[i] % 10  # Calculate remainder when divided by 10
        
        # Initialize adjustment value
        b = 10
        # If the remainder is not zero, calculate the adjustment needed to make it a multiple of 10
        if r[i] != 0:
            b = 10 - r[i]
            # Store the adjustment and the original value in the dictionary
            adjustments[b] = a[i]
    
    # Initialize the answer variable to accumulate the result
    ans = 0
    
    # If no adjustments are needed (adjustments is empty), sum all input values
    if not adjustments:
        ans = sum(a)  # Add all values to the answer
        print(ans)  # Print the result
        return  # Exit the program
    
    # Get the last key (largest adjustment) from the dictionary
    last = adjustments[max(adjustments)]  # Get the value corresponding to the largest adjustment
    idx = 0
    
    # Find the index of the last value in the original array
    for i in range(len(a)):
        if a[i] == last:
            idx = i  # Store the index of the last value
    
    # Calculate the final answer by adding values, adjusting as necessary
    for i in range(len(a)):
        if i != idx:  # Skip the last value
            if a[i] % 10 == 0:
                ans += a[i]  # If already a multiple of 10, add directly
            else:
                ans += a[i] + (10 - r[i])  # Adjust to the next multiple of 10
    
    # Add the last value to the answer
    ans += last
    
    # Print the final calculated answer
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

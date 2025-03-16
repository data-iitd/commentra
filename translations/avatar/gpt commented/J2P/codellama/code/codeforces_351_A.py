import math 
import sys 

# Main function definition
def main(): 
    # Read the number of elements (n)
    n = int(sys.stdin.readline()) 
    
    # Tokenize the input line containing the numbers
    arr = list(map(float, sys.stdin.readline().split())) 
    
    # Array to store the numbers and variables for calculations
    non_int = 0 # Counter for non-integer values
    sum_before = 0 # Variable to store the total sum
    sum = 0 # Variable to store the sum of integer parts
    
    # Loop through the input numbers
    for i in range(len(arr)): 
        # Accumulate the total sum of the numbers
        sum_before += arr[i] 
        
        # Check if the number is non-integer and update the counter
        if arr[i] != math.floor(arr[i]): 
            non_int += 1 
        
        # Accumulate the sum of the integer parts of the numbers
        sum += math.floor(arr[i]) 
    
    # Calculate the maximum possible sum considering non-integer values
    max_sum = min(n, non_int) + sum 
    
    # Calculate the minimum possible sum considering non-integer values
    min_sum = max(0, non_int - n) + sum 
    
    ans = 0 # Variable to store the final answer
    
    # Determine the answer based on the calculated sums
    if min_sum > sum_before: 
        ans = min_sum - sum_before # Case where min_sum is greater than the total sum
    elif max_sum < sum_before: 
        ans = sum_before - max_sum # Case where max_sum is less than the total sum
    else: 
        # Case where the total sum is between min_sum and max_sum
        x = sum_before - math.floor(sum_before) 
        ans = min(1 - x, x) # Calculate the minimum distance to the nearest integer
    
    # Print the final answer formatted to three decimal places
    print(f"{ans:.3f}") 


# Call the main function
main() 


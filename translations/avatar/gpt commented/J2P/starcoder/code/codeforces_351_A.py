import sys

# Main class definition
class Main:
    # Function to read input from stdin
    def read_input(self):
        # Read the number of elements (n)
        n = int(input())
        
        # Tokenize the input line containing the numbers
        st = input().split()
        
        # Array to store the numbers and variables for calculations
        arr = [0] * (2 * n)
        non_int = 0 # Counter for non-integer values
        sum_before = 0 # Variable to store the sum of the numbers before the loop
        sum = 0 # Variable to store the sum of the integer parts of the numbers
        
        # Loop through the input numbers
        for i in range(2 * n):
            # Parse the next number from the input
            num = float(st[i])
            
            # Accumulate the total sum of the numbers
            sum_before += num
            
            # Check if the number is non-integer and update the counter
            if num!= int(num):
                non_int += 1
            
            # Accumulate the sum of the integer parts of the numbers
            sum += int(num)
            
            # Store the number in the array
            arr[i] = num
        
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
            x = sum_before - int(sum_before)
            ans = min(1 - x, x) # Calculate the minimum distance to the nearest integer
        
        # Print the final answer formatted to three decimal places
        print(format(ans, '.3f'))

# Main function
if __name__ == '__main__':
    # Instantiate the class
    obj = Main()
    
    # Read input from stdin
    obj.read_input()


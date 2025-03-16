
import sys

# Function to compute the minimum result
def util(arr, ops, idx):
    # Base case: if all operations have been used, update the minimum result
    if idx == 3:
        global min
        min = min(min, arr[0])
        return
    
    # Iterate through all pairs of numbers in the list
    for i in range(len(arr)):
        for j in range(i + 1, len(arr)):
            # Create a new list to hold the remaining numbers after the operation
            a = arr[:]
            
            # Perform the operation based on the current operation in the ops array
            if idx < 3 and ops[idx] == "+":
                res = arr[i] + arr[j] # Addition operation
            else:
                res = arr[i] * arr[j] # Multiplication operation
            
            # Add the result of the operation to the new list
            a.remove(arr[i])
            a.remove(arr[j])
            a.append(res)
            
            # Recursively call util with the new list and the next operation index
            util(a, ops, idx + 1)

# Main function
def main():
    # Create an ArrayList to store the input numbers
    arr = []
    
    # Read 4 long integers from user input and add them to the list
    for _ in range(4):
        arr.append(int(input()))
    
    # Create an array to store the operations
    ops = []
    
    # Read 3 operations from user input
    for _ in range(3):
        ops.append(input())
    
    # Initialize min to the maximum possible value
    global min
    min = sys.maxsize
    
    # Call the utility function to compute the minimum result
    util(arr, ops, 0)
    
    # Print the minimum result found
    print(min)

# Call the main function
if __name__ == "__main__":
    main()


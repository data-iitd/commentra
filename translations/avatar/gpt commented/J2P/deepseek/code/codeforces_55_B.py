import sys

# Variable to store the minimum result found
min_result = sys.maxsize

def util(arr, ops, idx):
    global min_result
    # Base case: if all operations have been used, update the minimum result
    if idx == len(ops):
        min_result = min(min_result, arr[0])
        return
    
    # Iterate through all pairs of numbers in the list
    for i in range(len(arr)):
        for j in range(i + 1, len(arr)):
            # Create a new list to hold the remaining numbers after the operation
            a = []
            # Add the remaining numbers to the new list
            for k in range(len(arr)):
                if k != i and k != j:
                    a.append(arr[k])
            
            res = 0
            # Perform the operation based on the current operation in the ops array
            if ops[idx] == '+':
                res = arr[i] + arr[j]  # Addition operation
            else:
                res = arr[i] * arr[j]  # Multiplication operation
            
            # Add the result of the operation to the new list
            a.append(res)
            
            # Recursively call util with the new list and the next operation index
            util(a, ops, idx + 1)

def main():
    # Create a list to store the input numbers
    arr = []
    
    # Read 4 long integers from user input and add them to the list
    for _ in range(4):
        arr.append(int(input()))
    
    # Create an array to store the operations
    ops = []
    
    # Read 3 operations from user input
    for _ in range(3):
        ops.append(input())
    
    # Call the utility function to compute the minimum result
    util(arr, ops, 0)
    
    # Print the minimum result found
    print(min_result)

if __name__ == "__main__":
    main()

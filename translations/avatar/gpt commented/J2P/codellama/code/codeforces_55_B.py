import sys 

def main(): 
    # Create a Scanner object for user input
    sc = sys.stdin 
    
    # Initialize min to the maximum possible value
    min = 2147483647
    
    # Create an ArrayList to store the input numbers
    arr = [] 
    
    # Read 4 long integers from user input and add them to the list
    for i in range(4): 
        arr.append(int(sc.readline())) 
    
    # Create an array to store the operations
    ops = [] 
    
    # Read 3 operations from user input
    for i in range(3): 
        ops.append(sc.readline().strip()) 
    
    # Call the utility function to compute the minimum result
    util(arr, ops, 0) 
    
    # Print the minimum result found
    print(min) 

def util(arr, ops, idx): 
    # Base case: if all operations have been used, update the minimum result
    if idx == 3: 
        min = min(min, arr[0]) 
        return 
    
    # Iterate through all pairs of numbers in the list
    for i in range(len(arr)): 
        for j in range(i + 1, len(arr)): 
            # Create a new list to hold the remaining numbers after the operation
            a = [] 
            
            # Add the remaining numbers to the new list
            for k in range(len(arr)): 
                if k != j and k != i: 
                    a.append(arr[k]) 
            
            res = 0
            # Perform the operation based on the current operation in the ops array
            if idx < 3 and ops[idx] == "+": 
                res = arr[i] + arr[j] # Addition operation
            else: 
                res = arr[i] * arr[j] # Multiplication operation
            
            # Add the result of the operation to the new list
            a.append(res) 
            
            # Recursively call util with the new list and the next operation index
            util(a, ops, idx + 1) 

if __name__ == "__main__": 
    main() 


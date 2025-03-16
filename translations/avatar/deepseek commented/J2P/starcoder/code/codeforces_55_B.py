import sys

# Function to find the minimum result by applying operations
def util(arr, ops, idx):
    if idx == 3: # Base case: when all operations are applied
        global min # Using the global variable min
        min = min(min, arr[0]) # Update min with the current result
        return

    # Iterating through the array to apply operations between two numbers
    for i in range(len(arr)):
        for j in range(i + 1, len(arr)):
            a = [] # Temporary ArrayList to store remaining numbers
            for k in range(len(arr)):
                if k!= j and k!= i:
                    a.append(arr[k]) # Adding remaining numbers to the temporary ArrayList

            res = 0 # Variable to store the result of the operation
            if idx < 3 and ops[idx] == "+":
                res = arr[i] + arr[j] # Applying addition
            else:
                res = arr[i] * arr[j] # Applying multiplication

            a.append(res) # Adding the result to the temporary ArrayList
            util(a, ops, idx + 1) # Recursively calling util with the updated ArrayList and index

if __name__ == "__main__":
    min = sys.maxsize # Initializing min to the maximum possible long value
    arr = [] # Creating an ArrayList to store the numbers
    ops = [] # Creating an array to store the operations

    # Reading four numbers and adding them to the ArrayList
    for i in range(4):
        arr.append(int(input()))

    # Reading three operations and storing them in an array
    for i in range(3):
        ops.append(input())

    # Calling the recursive function to find the minimum result
    util(arr, ops, 0)

    # Outputting the minimum result
    print(min)


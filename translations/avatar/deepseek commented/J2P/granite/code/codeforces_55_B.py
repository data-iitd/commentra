
import sys

min = sys.maxsize # Declaring a variable to keep track of the minimum result

def util(arr, ops, idx):
    if idx == 3: # Base case: when all operations are applied
        global min
        min = min(min, arr[0]) # Update min with the current result
        return

    # Iterating through the array to apply operations between two numbers
    for i in range(len(arr)):
        for j in range(i + 1, len(arr)):
            a = arr[:] # Creating a copy of the array to avoid modifying the original
            res = arr[i] + arr[j] if ops[idx] == "+" else arr[i] * arr[j] # Applying the operation
            a[i] = res
            a.pop(j) # Removing the second number from the temporary array
            util(a, ops, idx + 1) # Recursively calling util with the updated array and index

def main():
    arr = [int(x) for x in input().split()] # Reading four numbers and converting them to integers
    ops = input().split() # Reading three operations and storing them in a list

    util(arr, ops, 0) # Calling the recursive function to find the minimum result

    print(min) # Outputting the minimum result

if __name__ == "__main__":
    main()


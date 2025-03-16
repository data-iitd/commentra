import sys

min_result = sys.maxsize  # Initialize min to the maximum possible integer value

def util(arr, ops, idx):
    global min_result
    if idx == 3:  # Base case: when all operations are applied
        min_result = min(min_result, arr[0])  # Update min with the current result
        return

    # Iterating through the array to apply operations between two numbers
    for i in range(len(arr)):
        for j in range(i + 1, len(arr)):
            a = []  # Temporary list to store remaining numbers
            for k in range(len(arr)):
                if k != j and k != i:
                    a.append(arr[k])  # Adding remaining numbers to the temporary list

            if ops[idx] == "+":
                res = arr[i] + arr[j]  # Applying addition
            else:
                res = arr[i] * arr[j]  # Applying multiplication

            a.append(res)  # Adding the result to the temporary list
            util(a, ops, idx + 1)  # Recursively calling util with the updated list and index

def main():
    global min_result
    arr = []  # List to store the numbers

    # Reading four numbers and adding them to the list
    for _ in range(4):
        arr.append(int(input()))

    # Reading three operations and storing them in a list
    ops = [input().strip() for _ in range(3)]

    # Calling the recursive function to find the minimum result
    util(arr, ops, 0)

    # Outputting the minimum result
    print(min_result)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

# Python code to achieve the same functionality as the provided Java code

def main():
    # Reading the first integer input 'n'
    n = int(input())
    # Reading the second integer input 'levels'
    levels = int(input())

    # Reading 'levels' number of integers and storing them in 'arr'
    arr = list(map(int, input().split()))

    # Reading the third integer input 'level2'
    level2 = int(input())
    # Calculating the size of 'arr2'
    level3 = levels + level2
    # Reading 'level2' number of integers and storing them in 'arr2'
    arr2 = list(map(int, input().split()))

    # Creating an integer array 'arr3' of size 'n'
    arr3 = list(range(1, n + 1))

    # Initializing 'count' variable to 0
    count = 0

    # Comparing each element of 'arr3' with 'arr2'
    for i in range(n):
        for x in range(len(arr2)):
            if arr3[i] == arr2[x]:
                count += 1
                break

    # Printing the result based on the presence of all elements of 'arr3' in 'arr2'
    if count == n:
        print("I become the guy.")
    else:
        print("Oh, my keyboard!")

# Calling the main function
main()

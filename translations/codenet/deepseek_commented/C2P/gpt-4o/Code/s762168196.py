# Step 1: Define the main function
def main():
    # Step 2: Declare necessary variables
    a = []
    min_val = float('inf')
    max_val = float('-inf')
    n = int(input())  # Step 3: Read the number of elements (n) from the user
    sum_val = 0

    # Step 4: Read the elements of the array from the user and calculate the sum
    for i in range(n):
        num = int(input())
        a.append(num)
        sum_val += num

    # Step 5: Find the minimum and maximum values in the array
    for num in a:
        if num > max_val:
            max_val = num
        if num < min_val:
            min_val = num

    # Step 6: Print the minimum, maximum, and sum of the elements
    print(min_val, max_val, sum_val)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>

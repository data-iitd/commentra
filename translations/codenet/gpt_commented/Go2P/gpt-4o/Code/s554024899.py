import sys

def main():
    # Read two integers from input
    x = next_int()
    y = next_int()

    # Initialize variables to store the category indices of x and y
    xt, yt = -1, -1

    # Define a list of categories where each sub-list represents a category of numbers
    a = [[1, 3, 5, 7, 8, 10, 12], [4, 6, 9, 11], [2]]

    # Iterate through the categories to find the indices of x and y
    for i, t in enumerate(a):
        if x in t:
            xt = i  # Store the category index for x
        if y in t:
            yt = i  # Store the category index for y

    # Compare the category indices of x and y and print the result
    if xt == yt:
        print("Yes")  # x and y belong to the same category
    else:
        print("No")   # x and y belong to different categories

def next_int():
    return int(sys.stdin.readline().strip())  # Read the next integer from input

if __name__ == "__main__":
    main()

# <END-OF-CODE>


# Define a function to read the number of elements in the vector
def read_int():
    return int(input())

# Define a function to read the elements of the vector
def read_list():
    return list(map(int, input().split()))

# Define a function to sort the vector in ascending order
def sort_list(a):
    a.sort()

# Define a function to check if there are any consecutive elements in the sorted vector
def check_consecutive(a):
    for i in range(len(a)-1):
        # If there are consecutive elements, return False
        if a[i] == a[i+1]:
            return False
    # If no consecutive elements were found, return True
    return True

# Define a function to print "YES" if the vector is non-decreasing and "NO" otherwise
def print_result(a):
    if check_consecutive(a):
        print("YES")
    else:
        print("NO")

# Read the number of elements in the vector
n = read_int()

# Read the elements of the vector
a = read_list()

# Sort the vector in ascending order
sort_list(a)

# Print the result
print_result(a)


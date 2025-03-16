# This line is used to get the number of test cases from the user.
n = int(input())

# This line is used to get the list of test cases from the user.
t = list(map(int, input().split()))

# This line is used to get the number of queries from the user.
m = int(input())

# This loop runs m number of times to process each query.
for i in range(m):
    # These lines are used to get the position and value of the query from the user.
    p, x = map(int, input().split())

    # This variable is initialized to 0 and is used to store the sum of the elements in the list t from the starting position p-1 up to the end of the list.
    s = 0

    # This loop calculates the sum of the elements in the list t from the starting position p-1 up to the current index j.
    for j in range(len(t)):
        # If the current index j is equal to the position p-1, then the value of the current element is added to the variable s.
        if j == p - 1:
            s += x
        # If the current index j is not equal to the position p-1, then the value of the current element is added to the variable s as usual.
        else:
            s += t[j]

    # After the inner loop finishes, the value of s is printed to the console.
    # This is the result of the query, which is the sum of the elements in the list t from the starting position p-1 up to the end of the list.
    print(s)

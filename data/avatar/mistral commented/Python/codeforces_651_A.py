
# Define variables x and y by unpacking the tuple returned by the map function
x, y = map(int, input().split())

# Helper functions for simplifying input process
def num_inp():
    return int(input())

def arr_inp():
    return list(map(int, input().split()))

def sp_inp():
    return map(int, input().split())

def str_inp():
    return input()

# Calculate and print the maximum value between x + y - 3 + ( ( y - x ) % 3 > 0 ) and 0
print(max(x + y - 3 + ((y - x) % 3 > 0), 0))
# Define lambda functions for input handling
# num_inp: takes a single input as an integer
# arr_inp: takes a list input where each element is an integer
# sp_inp: takes a list input where each element is an integer, space-separated

num_inp = lambda : int(input())
# This line reads a single integer input from the user

arr_inp = lambda : list(map(int, input().split()))
# This line reads a list input from the user, where each element is an integer

sp_inp = lambda : map(int, input().split())
# This line reads a list input from the user, where each element is an integer, space-separated

# Read input from file instead of user input
a = sorted(map(int, [*open(0)] [1:]))
# This block reads the input from the file, converts each line to a list of integers,
# and sorts the list of integers

# Find the largest number that leaves a remainder when divided by any number in the list
print([a[0], -1][any(x % a[0] for x in a)])
# This block calculates the answer and prints it

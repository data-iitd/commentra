# Ask the user for the number of inputs
N = int(input())

# Create a list 'x' of size 'N' using a list comprehension
x = [eval(input().replace('JPY', '* 1.0').replace('BTC', '* 380000.0')) for i in range(N)]

# Print the sum of all the elements in the list 'x'
print(sum(x))

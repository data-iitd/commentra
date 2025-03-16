# Read the number of currency inputs from the user
N = int(input())

# Create a list of converted currency values
# For each input, replace 'JPY' with its equivalent in float and 'BTC' with its equivalent in float
x = [eval(input().replace('JPY', '* 1.0').replace('BTC', '* 380000.0')) for i in range(N)]

# Calculate and print the total sum of the converted currency values
print(sum(x))

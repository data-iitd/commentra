
# <START-OF-CODE>

# Create a BufferedReader to read input from the console
br = BufferedReader(InputStreamReader(sys.stdin))

# Read a line of input and parse it as a double
input = float(br.readline())

# Calculate the count of odd numbers based on the input
countOdd = round(input / 2)

# Create a BigDecimal to hold the result of the division
result = countOdd / input

# Set the scale of the result to 10 decimal places, rounding half up
result = result.setScale(10, ROUND_HALF_UP)

# Print the result to the console
print(result)

# 
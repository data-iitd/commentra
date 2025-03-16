# Get the number of data points from user input
N = int(input())

# Initialize an empty list to store data points
mo = []

# Read data points from user input and store in list 'mo'
for _ in range(N):
    # Read one data point from user input as a string
    x_str, u_str = input().split()
    # Convert the first element to a float
    x = float(x_str)
    # Append the data point (as a list with float 'x' and string 'u') to 'mo'
    mo.append([x, u_str])

# Initialize variable 'okz' with an initial value of 0
okz = 0

# Calculate the total value of all data points in JPY
for i in mo:
    # Get the current data point
    x = i[0]
    currency = i[1]
    # If the currency is JPY, add the value directly to 'okz'
    if currency == "JPY":
        okz += x
    # If the currency is not JPY, convert the value to JPY and add it to 'okz'
    else:
        # Convert the value to JPY (380,000 is the exchange rate)
        x_jpy = x * 380000
        okz += x_jpy

# Print the total value of all data points in JPY
print(okz)
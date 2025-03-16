# Read the number of currency entries from user input
N = int(input())

# Initialize an empty list to store currency values and their types
mo = []

# Loop to read N currency entries
for _ in range(N):
    # Read the currency value and its type (JPY or other)
    x, u = input().split()
    # Convert the currency value to float for calculations
    x = float(x)
    # Append the currency value and type as a list to the mo list
    mo.append([x, u])

# Initialize a variable to accumulate the total value in a specific currency
okz = 0

# Loop through each currency entry in the mo list
for i in mo:
    # Check if the currency type is JPY
    if i[1] == "JPY":
        # If it's JPY, add the value directly to the total
        okz += i[0]
    else:
        # If it's another currency, convert it to JPY (assuming conversion rate is 380000)
        okz += i[0] * 380000

# Print the total accumulated value in JPY
print(okz)

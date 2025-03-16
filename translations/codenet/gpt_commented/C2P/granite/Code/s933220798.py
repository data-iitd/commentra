
# Read 5 input values and calculate their average, excluding values greater than 40
ave = 0
for i in range(5):
    a = float(input())
    if a <= 40:
        ave += 40
    else:
        ave += a
ave /= 5

# Print the calculated average, formatted as an integer
print(int(ave))


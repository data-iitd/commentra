
# Define a function to calculate the difference in minutes
def diff(h1, m1, h2, m2, k):
    ans = h2 * 60 + m2
    ans -= (h1 * 60 + m1)
    ans -= k
    return ans

# Define a function to convert minutes to hours and minutes
def convert(minutes):
    hours = minutes // 60
    minutes = minutes % 60
    return hours, minutes

# Input the values of hours and minutes for the first and second time
h1, m1 = map(int, input("Enter hours and minutes for the first time: ").split())
h2, m2 = map(int, input("Enter hours and minutes for the second time: ").split())

# Input the difference in minutes
k = int(input("Enter the difference in minutes: "))

# Calculate the difference in minutes
ans = diff(h1, m1, h2, m2, k)

# Convert the difference in minutes to hours and minutes
hours, minutes = convert(ans)

# Output the result
print(hours, "hours and", minutes, "minutes")


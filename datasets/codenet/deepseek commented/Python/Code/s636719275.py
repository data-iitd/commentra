
s = input()
t = input()

# Function to calculate the number of differing characters between two strings
def check(a,b):
    s = 0  # Initialize the difference counter
    for i,j in zip(a,b):  # Iterate over characters of both strings simultaneously
        s += i!=j  # Increment the counter if characters are not equal
    return s  # Return the total number of differing characters

ans = 10**6  # Initialize the answer with a large number
for i in range(len(s)):  # Iterate over the length of string s
    a = s[i:]  # Get the substring starting from index i
    if len(a) >= len(t):  # Check if the length of the substring is enough to compare
        ans = min(ans, check(t, a[:len(t)]))  # Calculate the minimum distance and update ans
print(ans)  # Output the minimum distance found


# Initialize variables
t = 0
h = 0

a = int(input())  # Read number of strings from user

for _ in range(a):  # Loop through each string pair
    taro, hana = input().split()  # Read two strings from user
    lt = len(taro)  # Get length of first string
    lh = len(hana)  # Get length of second string

    if lt > lh:  # Check if first string is longer
        l = lt  # Set length to be the maximum length
    else:
        l = lh  # Set length to be the minimum length

    if taro > hana:  # Check if first string is greater lexicographically
        t += 3  # Increment t if true
    elif hana > taro:
        h += 3  # Increment h if true
    elif hana == taro:  # Check if strings are equal
        h += 1  # Increment h if true
        t += 1  # Increment t if true

print(t, h)  # Output the result

# <END-OF-CODE>



a = int(input()) # Read number of strings from user

t = 0
h = 0

for i in range(a): # Loop through each string pair
    taro = input() # Read first string from user
    hana = input() # Read second string from user
    lt = len(taro) # Get length of first string
    lh = len(hana) # Get length of second string

    if lt > lh: # Check if first string is longer
        l = lt # Set length to be the maximum length
    else:
        l = lh # Set length to be the minimum length

    tt = 0 # Initialize variables for comparing characters
    hh = 0

    if taro > hana: # Check if first string is greater lexicographically
        t = t + 3 # Increment t if true
    elif hana > taro:
        h = h + 3 # Increment h if true
    else: # Check if strings are equal
        h = h + 1 # Increment h if true
        t = t + 1 # Increment t if true

print(t, h) # Output the result


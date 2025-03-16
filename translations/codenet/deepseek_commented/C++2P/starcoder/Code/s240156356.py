
str1, str2 = raw_input().split()

# Sort the first string in ascending order
str1 = ''.join(sorted(str1))

# Sort the second string in descending order
str2 = ''.join(sorted(str2, reverse=True))

# Determine the loop limit based on the length of the shorter string
loop = len(str1) > len(str2) and len(str2) or len(str1)

# Compare characters of the two sorted strings
for i in range(loop):
    ch1 = str1[i]
    ch2 = str2[i]

    # If characters match, continue to the next character
    if ch1 == ch2:
        if loop == i + 1 and len(str1) < len(str2):
            print "Yes"
            break
        else:
            continue
    # If characters do not match, check if the character from the second string is greater
    elif ch2 > ch1:
        print "Yes"
        break
    else:
        break

# Check the flag and print the result
if flag:
    print "Yes"
else:
    print "No"


# Take user input as a string 's'
s = input ( )

# Initialize an empty list 'res' to store the final result
res = [ ]

# Define a list 'punctuation' containing all the punctuation marks
punctuation = [ ',' , '.','!','?' ]

# Iterate through each character 'i' in the string 's'
for i in range ( len ( s ) ) :

    # If current character is a space and previous character is not empty,
    # append the space to the result list
    if i >= 1 :
        if s [ i ] == '':
            if res [-1] != '':
                # Append space to the result list
                res.append(s[i])
            else:
                continue

    # If current character is not a space and is a punctuation mark,
    # check if the previous character is empty, if yes then pop the last character from the result list
    # and append the current punctuation mark along with an empty string
    elif s[i] in punctuation:
        if res [-1] == '':
            res.pop()
            res.append(s[i])
            res.append('')
        else:
            res.append(s[i])

    # If current character is not a space and is not a punctuation mark,
    # simply append it to the result list
    else:
        res.append(s[i])

# Join all the elements of the result list and print the final string
print (''.join ( res ))

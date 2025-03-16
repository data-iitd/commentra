# Assign input function to variable I
I = input

# Multiply the input by 2 and assign the result to variable s
s = I() * 2

# Check if the input is in the string s and print 'No' or 'Yes' accordingly
print(['No', 'Yes'][I() in s])
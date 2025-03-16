# Take input from the user
s = input()

# Check if the input is 'RRR' and print 3 if true
if s == 'RRR':
    print(3)
# Check if the input is 'SSS' and print 0 if true
elif s == 'SSS':
    print(0)
# Check if the input is either 'RRS' or 'SRR' and print 2 if true
elif s == 'RRS' or s == 'SRR':
    print(2)
# For any other input, print 1
else:
    print(1)

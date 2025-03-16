
pandu = int(input()) # The first input value
vundu = int(input()) # The second input value
urdu = int(input())  # The third input value

c = 0 # Declaring a variable to hold the cumulative sum

for i in range(1, urdu + 1): # Looping from 1 to 'urdu'
    c += i * pandu # Incrementing 'c' by the product of 'i' and 'pandu'

if c < vundu: # Checking if the calculated sum 'c' is less than 'vundu'
    print(0) # If true, print "0"
else:
    # If 'c' is greater than or equal to 'vundu', print the difference
    print(c - vundu)


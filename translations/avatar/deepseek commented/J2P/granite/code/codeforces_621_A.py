

n = int(input()) # Read the number of elements
list = [int(x) for x in input().split()] # Read the elements and store them in the list
odd = [] # List to store odd numbers
sum = 0 # Initialize sum of numbers

for i in list: # Iterate through the list
    if i % 2 == 0: 
        sum += i # Add to sum if the number is even
    else: 
        odd.append(i) # Add to odd list if the number is odd

odd.sort() # Sort the list of odd numbers

for i in odd: 
    sum += i # Add all odd numbers to the sum

if len(odd) % 2!= 0: 
    sum -= odd[0] # Subtract the smallest odd number if the count of odd numbers is odd

print(sum) # Print the final sum


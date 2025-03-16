

n = int(input()) # Reading the number of elements in the list from the standard input

list = [] # Creating an empty list to store n elements

for i in range(n): # Iterating through the input to add each element to the list
    list.append(int(input()))

odd = [] # Creating an empty list to store odd numbers
sum = 0 # Initializing the sum variable to 0

for i in list: # Iterating through each element in the list
    if i % 2 == 0: # Checking if the current element is even
        sum += i # Adding the even number to the sum
    else:
        odd.append(i) # Adding the odd number to the odd list

odd.sort() # Sorting the odd list in ascending order

for i in odd: # Iterating through each odd number in the sorted odd list
    sum += i # Adding the odd number to the sum

if len(odd) % 2!= 0: # Checking if the length of the odd list is odd
    sum -= odd[0] # Subtracting the first odd number if the length is odd

print(sum) # Printing the final sum to the standard output




import sys

# Reading the number of elements in the array from the input
n = int ( input ( ) )
ara = [ ] # Creating an empty list to store the array
map = { } # Creating an empty dictionary to store the frequency of each integer

# Reading elements of the array and updating the frequency in the dictionary
for i in range ( n ) :
 v = int ( input ( ) ) # Reading an integer from the input
 ara.append ( v ) # Storing the integer in the array
 if v not in map : # Checking if the integer is already present in the dictionary
 map [ v ] = 1 # If not, add it with a frequency of 1
 else :
 map [ v ] += 1 # If yes, increment its frequency by 1

# Finding the maximum frequency in the dictionary
max = 0
for i in map :
 max = max ( max, map [ i ] ) # Updating max with the maximum frequency found so far

# Finding the element(s) with the maximum frequency
mm = { } # Creating an empty dictionary to store the elements and their frequencies
for i in range ( n ) :
 if ara [ i ] not in mm : # Checking if the current element is already present in the dictionary
 mm [ ara [ i ] ] = 1 # If not, add it with a frequency of 1
 if mm [ ara [ i ] ] == max : # Checking if the frequency of the current element is equal to the maximum frequency
 print ( ara [ i ] ) # If yes, print it and break out of the loop
 break
 else :
 mm [ ara [ i ] ] += 1 # If the current element is already present, increment its frequency by 1
 if mm [ ara [ i ] ] == max : # Checking if the frequency of the current element is equal to the maximum frequency
 print ( ara [ i ] ) # If yes, print it and break out of the loop
 break

# End of code

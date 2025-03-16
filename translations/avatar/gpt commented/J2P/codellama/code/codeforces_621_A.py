
# Importing necessary classes from the java.util package
from java.util import *

# Creating a Scanner object to read input from the console
sc = Scanner(System.in)

# Reading the number of elements to be processed
n = sc.nextInt()

# Initializing a list to store the input numbers
list = ArrayList()

# Reading n long integers from input and adding them to the list
for i in range(n):
    list.add(sc.nextLong())

# Initializing a list to store odd numbers and a variable to hold the sum
odd = ArrayList()
sum = 0

# Iterating through the list to separate even and odd numbers
for i in list:
    if i % 2 == 0:
        # If the number is even, add it to the sum
        sum += i
    else:
        # If the number is odd, add it to the odd list
        odd.add(i)

# Sorting the list of odd numbers in ascending order
Collections.sort(odd)

# Adding all odd numbers to the sum
for i in odd:
    sum += i

# If the count of odd numbers is odd, subtract the smallest odd number from the sum
if odd.size() % 2 != 0:
    sum -= odd.get(0)

# Printing the final calculated sum
print(sum)


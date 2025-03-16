
import fractions
import math

# Read the input values for n and num
n, num = map(int, input().split())

# Read the set of integers
num_set = set(map(lambda x: int(x), input().split()))

# Initialize an empty set to store the number of times each integer is divisible by 2
two_times_set = set()

# Loop through each integer in the num_set
for i in num_set:
    # Divide the integer by 2 repeatedly until it is no longer even
    for j in range(1, 30):
        i //= 2
        if i % 2 != 0:
            # Add the count to two_times_set
            two_times_set.add(j)
            break
    # If two_times_set contains more than one element, print 0 and break
    if len(two_times_set) != 1:
        print(0)
        break
else:
    # If the loop completes, calculate the LCM of the integers in num_set
    num_list = list(num_set)
    lcm = num_list[0]
    for i in range(1, len(num_list)):
        lcm = lcm * num_list[i] // fractions.gcd(lcm, num_list[i])
    
    # Calculate the number of integers in the range from 1 to num that are divisible by the LCM
    print((num - lcm // 2) // (lcm) + 1)
# Initialize an empty list 'a' with 5 elements, each element is an integer input by the user
a = [int(input()) for i in range(5)]

# Initialize an empty dictionary 'dic' to store the indices and their corresponding values
dic = {}

# Iterate through the list 'a' using a for loop, and for each index 'i',
# check the last digit of the number at index 'i' in list 'a'
for i in range(5):
    # If the last digit of the number at index 'i' is '0', assign the index 'i' a value of 0 in the dictionary 'dic'
    if str(a[i])[-1] == "0":
        dic.update({i: 0})
    # If the last digit of the number at index 'i' is not '0', calculate the difference between the last digit and 10,
    # and assign the index 'i' a value of the calculated difference in the dictionary 'dic'
    else:
        dic.update({i: int(str(a[i])[-1]) - 10})

# Find the index 'min_num' with the minimum value in the dictionary 'dic'
min_num = [i for i in dic if dic[i] == min(dic.values())][0]

# Calculate the sum of all numbers in list 'a'
a_sum = sum(a)

# Remove the index 'min_num' and its corresponding value from the dictionary 'dic'
dic.pop(min_num)

# Calculate the sum of all values in the dictionary 'dic' and add it to the sum of list 'a'
print(abs(sum(dic.values())) + a_sum)

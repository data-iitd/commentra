# Prompt the user to input 5 integers and store them in a list
a = [int(input()) for i in range(5)]

# Initialize an empty dictionary to store processed values
dic = {}

# Iterate over the list of integers
for i in range(5):
    # Check if the last digit of the current integer is 0
    if str(a[i])[-1] == "0":
        # If it is, update the dictionary with the index and value 0
        dic.update({i: 0})
    else:
        # If it is not, update the dictionary with the index and the last digit minus 10
        dic.update({i: int(str(a[i])[-1]) - 10})

# Find the index of the minimum value in the dictionary
min_num = [i for i in dic if dic[i] == min(dic.values())][0]

# Calculate the sum of all integers in the original list
a_sum = sum(a)

# Remove the entry with the minimum value from the dictionary
dic.pop(min_num)

# Calculate and print the final result: absolute value of the sum of the remaining dictionary values plus the sum of the original list
print(abs(sum(dic.values())) + a_sum)

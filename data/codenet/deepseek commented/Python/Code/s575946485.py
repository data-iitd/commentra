# Step 1: The code takes 5 integers from the user.
a = [int(input()) for i in range(5)]

# Step 2: It then creates a dictionary where each key is the index of the integer in the list, and the value is either 0 or the last digit of the integer minus 10, depending on whether the last digit is 0 or not.
dic = {}

for i in range(5):
    if str(a[i])[-1] == "0":
        dic.update({i: 0})
    else:
        dic.update({i: int(str(a[i])[-1]) - 10})

# Step 3: It finds the index of the minimum value in the dictionary.
min_num = [i for i in dic if dic[i] == min(dic.values())][0]

# Step 4: It calculates the sum of the original list of integers.
a_sum = sum(a)

# Step 5: It removes the integer at the index of the minimum value in the dictionary from the list.
dic.pop(min_num)

# Step 6: Finally, it prints the sum of the remaining integers plus the absolute value of the sum of the dictionary values.
print(abs(sum(dic.values())) + a_sum)

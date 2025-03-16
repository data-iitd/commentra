import sys

# Reading the number of seconds from user input
sec = int(input())

# Reading the number of items per interval from user input
per_num = int(input())

# Reading the maximum time limit, adding 0.5 to ensure proper rounding
max_sec = int(input()) + 0.5

# Initializing a variable to hold the total count of items
ans_num = 0

# Looping from'sec' to'max_sec' in increments of'sec'
for i in range(sec, max_sec, sec):
    # Accumulating the total number of items produced
    ans_num += per_num

# Outputting the total number of items produced
print(ans_num)

# 
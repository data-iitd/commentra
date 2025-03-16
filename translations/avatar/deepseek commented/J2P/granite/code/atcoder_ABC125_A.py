
sec = int(input()) # Reading the first integer input which seems to be a time interval.
per_num = int(input()) # Reading the second integer input which is a number to be added per iteration.
max_sec = int(input()) + 0.5 # Reading the third integer input and adding 0.5 to it. This might be a misunderstanding.

ans_num = 0 # Initializing the variable to store the result of additions.

# Loop to iterate from'sec' to'max_sec' in steps of'sec' and add 'per_num' to 'ans_num' each time.
for i in range(sec, max_sec, sec):
    ans_num += per_num

print(ans_num) # Printing the final result after the loop completes.


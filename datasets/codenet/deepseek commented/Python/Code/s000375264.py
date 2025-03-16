
X, t = map(int, input().split())  # Taking two integers as input and assigning them to X and t

if X > t:  # Checking if X is greater than t
    answer = X - t  # Calculating the difference and assigning it to answer
elif X <= t:  # Checking if X is less than or equal to t
    answer = 0  # Assigning 0 to answer

print(answer)  # Printing the value of answer


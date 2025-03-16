# Define a list 'cookies' by using list comprehension
cookies = [int(x) for x in input().split()]

# Calculate the difference between the number of cookies given to the first and second child
leftOver = cookies[0] - cookies[2]

# Set the 'takahashi' variable to the maximum value between 0 and the 'leftOver' variable
takahashi = max(0, leftOver)

# Print the result using string concatenation
print(str(takahashi) + ' ' +
      (str(cookies[1]) if takahashi > 0 else
       str(max(0, cookies[1] - abs(leftOver)))))


cookies = [int(x) for x in input().split()]  # Taking input from the user and converting it into a list of integers
leftOver = cookies[0] - cookies[2]  # Calculating the difference between the first and third elements of the list
takahashi = max(0, leftOver)  # Calculating the number of cookies Takahashi gets, ensuring it's not negative
print(str(takahashi) + ' ' + (str(cookies[1]) if takahashi > 0 else str(max(0, cookies[1] - abs(leftOver)))))  # Printing the result, including the number of cookies Takahashi gets and the number of cookies left for Aoki


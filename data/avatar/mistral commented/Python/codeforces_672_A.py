# Initialize an empty list 'li' to store the digits
li = []

# Initialize an index variable 'ind'
ind = 0

# Iterate through the range from 1 to 370
for i in range(1, 371):
    # Initialize an empty list 'temp' to store digits
    temp = []

    # Assign current number 'i' to variables p and q
    p, q = i, i

    # Initialize a counter 'count' to keep track of number of digits
    count = 0

    # While p is not zero, divide it by 10 and increment the counter
    while p != 0:
        p //= 10
        count += 1

    # Based on the number of digits, append the number or its digits to 'li'
    if count == 1:
        # If the number has only one digit, directly append it to 'li'
        li.append(i)

    elif count == 2:
        # If the number has two digits, extract its digits and reverse the list
        while q != 0:
            x = q % 10  # Get the last digit
            q //= 10    # Move to the previous digit
            temp.append(x)
        li = li + temp[::-1]  # Append the reversed list to 'li'

    elif count == 3:
        # If the number has three digits, extract its digits and reverse the list
        while q != 0:
            x = q % 10  # Get the last digit
            q //= 10    # Move to the previous digit
            temp.append(x)
        li = li + temp[::-1]  # Append the reversed list to 'li'

# Remove the first two elements from 'li' as they are not required
li.pop(0)
li.pop(0)

# Take an input 'n' from the user
n = int(input("Enter a number: "))

# Print the required digit or digits from 'li' based on the user input
print(li[n-1])

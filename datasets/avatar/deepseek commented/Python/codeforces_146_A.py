n = int(input())  # Step 1: Take an integer input `n`
number = list(map(int, list(input())))  # Step 1: Take a list of integers `number`

h1 = 0  # Step 2: Initialize `h1` to store the sum of the first half of the digits
h2 = 0  # Step 2: Initialize `h2` to store the sum of the second half of the digits
x = 0  # Step 3: Initialize `x` to check for invalid digits

# Step 4: Enter a for loop to iterate over each digit in the number
for i in range(n):
    if number[i] != 4 and number[i] != 7:  # Step 5: Check if the current digit is invalid
        print("NO")  # Step 5: Print "NO" and break the loop if an invalid digit is found
        x += 1  # Step 5: Set `x` to 1
        break  # Step 5: Break out of the loop
    if i < n // 2:  # Step 6: Add the digit to `h1` if it's in the first half
        h1 += number[i]
    else:  # Step 6: Add the digit to `h2` if it's in the second half
        h2 += number[i]

# Step 7: After the loop, check if `x` is still 0 and compare the sums of the first and second halves
if not x:  # Step 7: Check if no invalid digit was found
    if h1 == h2:  # Step 7: Check if the sums are equal
        print("YES")  # Step 7: Print "YES" if the sums are equal
    else:  # Step 7: Print "NO" if the sums are not equal
        print("NO")

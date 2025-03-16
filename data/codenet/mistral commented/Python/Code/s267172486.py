
h, a = map(int, input().strip().split())  # Take user input and convert it to integers

ans = h // a  # Calculate the quotient of h and a using floor division operator
ama = h % a  # Calculate the remainder of h and a using modulus operator

if ama != 0:  # Check if the remainder is not equal to zero
  ans += 1  # If true, increment the answer by one

print(ans)  # Print the final answer
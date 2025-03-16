
n=int(input())  # Read the integer input `n`
s=input()       # Read the string input `s`
cnt=1           # Initialize the counter `cnt` to 1

# Start a loop that iterates from 0 to `n-2`
for i in range(n-1):
  if s[i]==s[i+1]:  # Check if the current character is equal to the next character
    continue       # If yes, continue to the next iteration
    
  else:             # If not, increment the counter `cnt` by 1
    cnt+=1
    
print(cnt)         # Print the final value of `cnt`


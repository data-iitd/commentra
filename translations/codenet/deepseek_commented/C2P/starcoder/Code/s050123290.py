# 1. Define the array and variables
su=['0']*N # Array to store the sequence of digits
susum=0 # Variable to store the sum of the digits
j=0 # Index to iterate through the array

while(1):
	# 2. Read input and calculate sum
	for j in range(N):
		su[j]=input()
		if(su[j]=='\n'):break # Break if newline character is encountered
		susum=susum+(su[j]-'0') # Convert character to integer and add to sum
	if(su[0]=='0'):break # Break if the sequence starts with '0'
	# 3. Print the sum
	print(susum) # Print the sum of the digits
	susum=0 # Reset the sum for the next sequence
# 4. Check for termination condition

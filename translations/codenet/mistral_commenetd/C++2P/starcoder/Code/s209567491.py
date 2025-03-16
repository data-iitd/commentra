
# Initialize variables
N, D, X = map(int, input().split()) # Number of days, maximum days, and extra chocolate
A = list(map(int, input().split())) # Array A to store the number of chocolate pieces for each day

# Initialize variables
num_of_chocolate = 0 # Total number of chocolate pieces
counter = 0 # Number of chocolate pieces eaten in one day
days = 0 # Number of days eaten from one chocolate piece

# Calculate the total number of chocolate pieces
for i in range(N):
	# Calculate the number of days this chocolate piece lasts
	for j in range(D + 1):
		days = j * A[i] + 1 # Calculate the number of days
		if days <= D: # Check if the number of days is less than or equal to the maximum number of days
			counter = counter + 1 # Increment the counter
		else: # If the number of days is greater than the maximum number of days, break the loop
			break
	# Add the number of chocolate pieces eaten in this day to the total number of chocolate pieces
	num_of_chocolate = num_of_chocolate + counter

# Add the extra chocolate
num_of_chocolate = num_of_chocolate + X

# Output the result
print(num_of_chocolate)


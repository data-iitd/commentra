#include <cstdio>

const int MAXN = 1E5 + 10; # Define the maximum size for arrays

n, m, Q = map(int, input().split()) # Read the size of array a and the number of positions m
a = list(map(int, input().split())) # Read the elements of array a
b = [0] * MAXN # Declare array b to store the unique elements
id = [0] * MAXN # Declare array id to store the positions of the unique elements
vis = [False] * MAXN # Declare a boolean array vis to mark processed elements
cnt = [0] * MAXN # Declare an array cnt to count elements in each position

def main():
	for k, j in enumerate(range(Q, 0, -1)): # Process the elements of array a
		if not vis[a[j]]: # If the element has not been processed
			b[k + 1] = a[j] # Add the element to b and mark it as processed
			vis[a[j]] = True
	for j in range(m, 0, -1): # Fill the remaining positions in b
		if not vis[j]:
			b[j] = j
	for i in range(1, m + 1): # Store the position of each element in b
		id[b[i]] = i

	flag = True # Initialize flag to true
	cnt[0] = n # Initialize the count of elements in the first position
	for i in range(Q, 0, -1): # Iterate through the elements of array a in reverse order
		t = id[a[i]] # Get the position of the current element in b
		if cnt[t - 1] > 0: # If there is a position available one less than the current position
			cnt[t - 1] -= 1 # Decrease the count of the previous position
			cnt[t] += 1 # Increase the count of the current position
			vis[t] = True # Mark the current position as processed
		elif not vis[t]: # If the current position is not available and not yet marked as processed
			flag = False # Set flag to false
			break # Break out of the loop

	l = 0 # Declare variable l to find the smallest non-zero count
	while cnt[l] == 0: # Find the smallest index l with a non-zero count
		l += 1
	for i in range(l + 1, m): # Check if the elements in b are in strictly increasing order
		flag &= b[i] < b[i + 1]
	print("Yes" if flag else "No") # Print "Yes" if the conditions are met, otherwise print "No"



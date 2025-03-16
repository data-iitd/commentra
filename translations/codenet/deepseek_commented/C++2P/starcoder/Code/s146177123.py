
# <START-OF-CODE>

# Array to represent the segments of the digits 0-9
seg=[
	[0,1,1,1,1,1,1], # 0
	[0,0,0,0,1,1,0], # 1
	[1,0,1,1,0,1,1], # 2
	[1,0,0,1,1,1,1], # 3
	[1,1,0,0,1,1,0], # 4
	
	[1,1,0,1,1,0,1], # 5
	[1,1,1,1,1,0,1], # 6
	[0,1,0,0,1,1,1], # 7
	[1,1,1,1,1,1,1], # 8
	[1,1,0,1,1,1,1]  # 9
]

# Function to calculate the current display state
def calc(st,t):
	ans=[0]*7
	for i in range(7):
		# Calculate the current segment state and store it in the answer array
		ans[i]=st[i]^seg[t][i]
		# Update the state array with the current segment state
		st[i]=seg[t][i]
	return ans

# Main function
if __name__=='__main__':
	n,t,st=[0]*3
	while(n!=0):
		# Read the number of digits and check if it's not zero
		n=int(raw_input())
		if(n==0):break
		# Initialize the state array to represent the current display state
		st=[0]*7
		# Read the next digit
		t=int(raw_input())
		# Output the current display state
		print ''.join(map(str,calc(st,t)))

# 
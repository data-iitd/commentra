
# read string a from standard input
a=input()
n=len(a) # get the length of string a

# read string b from standard input
b=input()
m=len(b) # get the length of string b

# iterate through all possible substrings of string a that have the same length as string b
for i in range(1,n-m+1):
	# initialize sum to 0, it will be used to count the number of differences between the i-th substring of string a and string b
	sum=0

	# iterate through each character in the substring of string a and compare it with the corresponding character in string b
	for j in range(1,m+1):
		# if the characters are different, increment sum by 1
		if a[i+j-1]!=b[j]:
			sum+=1

	# update the minimum number of differences if a smaller number is found
	ans=min(ans,sum)

# print the minimum number of differences to standard output
print(ans)




a = input() # read string a from standard input
n = len(a) # get the length of string a

b = input() # read string b from standard input
m = len(b) # get the length of string b

ans = n + 1 # initialize ans to the maximum possible value

for i in range(n - m + 1): # iterate through all possible substrings of string a that have the same length as string b
	sum = 0 # initialize sum to 0, it will be used to count the number of differences between the i-th substring of string a and string b
	for j in range(m): # iterate through each character in the substring of string a and compare it with the corresponding character in string b
		if a[i + j]!= b[j]: # if the characters are different, increment sum by 1
			sum += 1
	ans = min(ans, sum) # update the minimum number of differences if a smaller number is found

print(ans) # print the minimum number of differences to standard output


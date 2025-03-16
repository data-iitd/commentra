# ABC 152-D
# 2020.1.19 bal4u

def in(): # non-negative integer input
	n = 0
	c = input()
	while c >= '0':
		n = 10 * n + (ord(c) & 0xf) # 10 times the number of digits and add
		c = input()
	return n

f1 = [0] * 100
f2 = [0] * 100

def calc(n): # process n
	k = n % 10 # get the last digit of n
	while n >= 10: # while n is a multiple of 10
		n /= 10
	f1[10*k + n] += 1 # count up f1[10*k+n]
	f2[n*10 + k] += 1 # count up f2[n*10+k]

N = in() # input N
while N: # while N is not 0
	calc(N) # call calc
	N -= 1 # N decrement

ans = 0 # initialize answer
for i in range(100): # loop f1, f2 arrays to calculate answer
	ans += f1[i] * f2[i]
print(ans) # output answer


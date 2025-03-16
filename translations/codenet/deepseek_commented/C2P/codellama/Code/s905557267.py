#include <stdio.h>

# Function to return the smaller of two integers
def min(a, b):
	if a <= b:
		return a
	return b

# Function to remove chains of four or more consecutive identical elements
def Chain(b, n):
	a = [0] * 10000
	for i in range(n):
		a[i] = b[i]
	
	for i in range(n - 4):
		if a[i] != 0 and a[i] == a[i + 1] and a[i] == a[i + 2] and a[i] == a[i + 3]:
			count = 0
			color = a[i]
			
			for j in range(i, n):
				if a[j] == color:
					a[j] = 0
					count += 1
			
			for j in range(i, n - count):
				a[j] = a[j + count]
				a[j + count] = 0
			
			i = 0
	
	count = 0
	while a[count] != 0:
		count += 1
	
	if count == 4 and a[0] == a[1] and a[0] == a[2] and a[0] == a[3]:
		return 0
	
	return count

# Main function to read input, process it, and print the result
def main():
	while True:
		n = int(input())
		if n == 0:
			break
		ans = n
		a = [int(x) for x in input().split()]
		
		for i in range(n - 4):
			count = [0, 0, 0]
			for j in range(i, i + 4):
				if a[j] - 1 >= 0:
					count[a[j] - 1] += 1
			
			color = 0
			for j in range(3):
				if count[j] >= 3:
					color = j + 1
					break
			
			if color != 0:
				for j in range(i, i + 4):
					buf = a[j]
					a[j] = color
					ans = min(ans, Chain(a, n))
					a[j] = buf
		
		print(ans)

if __name__ == "__main__":
	main()


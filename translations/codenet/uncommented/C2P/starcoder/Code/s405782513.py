
#include <stdio.h>

def main():
	while True:
		c = [0, 0, 0]
		for i in range(3):
			c[i] = int(input())
		sum = c[0] + c[1]
		count = 0
		card = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
		for i in range(3):
			card[c[i] - 1] = 1
		for i in range(10):
			if card[i] == 0 and sum + i + 1 <= 20:
				count += 1
		if count >= 4:
			print("YES")
		else:
			print("NO")

if __name__ == "__main__":
	main()


import sys
import math

def is_prime(x):
	for i in range(2, int(math.sqrt(x))+1):
		if x % i == 0: return False
	return True

def main():
	N = int(sys.stdin.readline())

	ans = 1
	for i in range(2, N+1):
		if is_prime(i):
			NN = N
			cnt = 0
			while NN:
				cnt += NN/i
				NN /= i
			ans *= cnt+1
			ans %= mod
	print(ans)

if __name__ == "__main__":
	main()


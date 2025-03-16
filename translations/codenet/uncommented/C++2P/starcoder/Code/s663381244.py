# <START-OF-CODE>
import sys

def main():
	for line in sys.stdin:
		line = line.strip()
		if not line:
			continue

		m = [10, 50, 100, 500]
		first = True
		for money in line.split():
			if not first:
				print()

			first = False
			sum = 0
			num = [0, 0, 0, 0]
			for i in range(4):
				num[i] = int(money) / m[i]
				sum += num[i] * m[i]

			change = sum - int(money)
			for i in range(3, -1, -1):
				if change / m[i]:
					num[i] = num[i] - change / m[i]
					change %= m[i]

			for i in range(4):
				if num[i] > 0:
					print(m[i], num[i])

if __name__ == '__main__':
	main()
# 
import sys

def main():
	week = ["SUN","MON","TUE","WED","THU","FRI","SAT"]
	s = sys.stdin.readline().strip()
	index = -1
	for i, day in enumerate(week):
		if s == day:
			index = i
			break
	print(7 - index)

if __name__ == "__main__":
	main()


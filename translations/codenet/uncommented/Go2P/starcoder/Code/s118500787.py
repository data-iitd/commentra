def main():
	S, T = input(), input()
	max = 0
	for i in range(len(S)-len(T)+1):
		c = 0
		for j in range(len(T)):
			if S[i+j] == T[j]:
				c += 1
		if max < c:
			max = c
	print(len(T) - max)

main()


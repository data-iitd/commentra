
# <START-OF-CODE>

def RunLength(s):
	r = []
	if len(s) == 0:
		return r
	t = Block(s[0], 1)
	for _, v in s[1:]:
		if t.Value == v:
			t.Len += 1
		else:
			r.append(t)
			t = Block(v, 1)
	r.append(t)
	return r

class Block:
	def __init__(self, value, length):
		self.Value = value
		self.Len = length

def Max(a, b):
	if b > a:
		return b
	return a

def main():
	N, K = map(int, input().split())
	S = input()
	blocks = RunLength(S)
	sum, zero, l = 0, 0, 0
	for r in range(len(blocks)):
		sum += blocks[r].Len
		if blocks[r].Value == '0':
			zero += 1
		for K < zero:
			sum -= blocks[l].Len
			if blocks[l].Value == '0':
				zero -= 1
			l += 1
		ans = Max(ans, sum)
	print(ans)

if __name__ == '__main__':
	main()

# 
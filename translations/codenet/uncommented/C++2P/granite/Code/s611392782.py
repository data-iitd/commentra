
# ACM-ICPCアジア地区予選2014 B. Miscalculation

def mul(str, idx):
	res = int(str[idx])
	while idx+1 < len(str) and str[idx+1]=='*':
		idx += 2
		res *= int(str[idx])
	return res, idx

def add(str, idx):
	res = mul(str, idx)
	while idx+1 < len(str) and str[idx+1] == '+':
		idx += 2
		res = (res[0], res[1]+mul(str, idx)[0])
	return res

def bob(str, idx):
	res = int(str[idx])
	while idx+1 < len(str):
		if str[idx+1] == '+':
			res += int(str[idx+2])
		else:
			res *= int(str[idx+2])
		idx += 2
	return res

while True:
	try:
		s = input()
		d = int(input())
		idx = 0
		a = add(s, idx)[0]
		idx = 0
		b = bob(s, idx)
		if a == d:
			print("U" if b == d else "M")
		else:
			print("L" if b == d else "I")
	except:
		break


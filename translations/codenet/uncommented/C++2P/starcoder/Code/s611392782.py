# ACM-ICPC Asia Regional Contest 2014 B. Miscalculation

import sys

def mul(s, idx):
	res = ord(s[idx])-ord('0')
	while idx+1 < len(s) and s[idx+1] == '*':
		idx += 2
		res *= ord(s[idx])-ord('0')
	return res

def add(s, idx):
	res = mul(s, idx)
	while idx+1 < len(s) and s[idx+1] == '+':
		idx += 2
		res += mul(s, idx)
	return res

def bob(s, idx):
	res = ord(s[idx])-ord('0')
	while idx+1 < len(s):
		if s[idx+1] == '+': res += ord(s[idx+2])-ord('0')
		else:               res *= ord(s[idx+2])-ord('0')
		idx += 2
	return res

for line in sys.stdin:
	s, d = line.split()
	idx = 0
	a = add(s, idx)
	idx = 0
	b = bob(s, idx)
	if a == int(d):
		print "U" if b == int(d) else "M"
	else:
		print "L" if b == int(d) else "I"

# 
import sys

def get_scanner():
	return bufio.Scanner(sys.stdin)

def get_next_string(scanner):
	scanner.scan()
	return scanner.text

def get_next_int(scanner):
	return int(get_next_string(scanner))

def get_next_int64(scanner):
	return int64(get_next_string(scanner))

def get_next_uint64(scanner):
	return uint64(get_next_string(scanner))

def get_next_float64(scanner):
	return float64(get_next_string(scanner))

def main():
	scanner = get_scanner()
	writer = sys.stdout

	s = get_next_string(scanner)
	t = get_next_string(scanner)

	ns = len(s)
	nt = len(t)
	ss = [s] * ((nt-1)//ns+1)

	for i in range(len(ss)):
		ss[i] = s

	sss = "%s%s" % (" ".join(ss), " ".join(ss))

	ok = [False] * ns

	uni = [i for i in range(ns)]
	mp = MP()
	mp.init(t)
	m = 0
	for i in range(ns):
		uni[i] = i
	o = True
	for i in range(ns):
		o = True
		for m < nt:
			if t[m]!= sss[i+m]:
				o = False
				break
			m += 1
		ok[i] = o
		if o:
			i += nt - mp.table[m]
			m = mp.table[m]
		for m >= 0 and t[m]!= sss[i+m]:
			i += m - mp.table[m]
			m = mp.table[m]
		i -= 1
		m += 1

	ans = 0
	r, rr = 0, 0
	for i in range(ns):
		if ok[i] == False:
			continue
		if ok[(i+nt)%ns] == False:
			continue
		r = root(i, uni)
		rr = root((i+nt)%ns, uni)
		if rr == r:
			print(-1)
			return
		uni[rr] = r
	counter = [0] * ns
	for i in range(ns):
		r = root(i, uni)
		if ok[r] == False:
			continue
		counter[r] += 1
	for i in range(ns):
		if ans < counter[i]:
			ans = counter[i]
	print(ans)

def root(i, uni):
	if i == uni[i]:
		return i
	uni[i] = root(uni[i], uni)
	return uni[i]

class MP:
	def __init__(self):
		self.s = ""
		self.table = []

	def init(self, s):
		self.s = s
		n = len(s)
		table = [0] * (n+1)
		table[0] = -1
		j = -1
		for i in range(n):
			for j >= 0 and s[i]!= s[j]:
				j = table[j]
			j += 1
			table[i+1] = j
		self.table = table

# 
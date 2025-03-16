import sys

def main():
	sc = newScanner(sys.stdin)
	N = sc.i()
	sum = 0
	for i in range(1, N+1):
		if i%3 == 0 or i%5 == 0:
			continue
		sum += i
	print(sum)

# fmt.Println("Yes")
# fmt.Println("No")

# I/O
class scanner:
	def __init__(self, stream):
		self.stream = stream
		self.buf = ""
		self.pos = 0
		self.fill()

	def fill(self):
		self.buf = self.stream.readline()
		self.pos = 0

	def i(self):
		c = self.next()
		while c == " ":
			c = self.next()
		if c == "-":
			sign = -1
			c = self.next()
		else:
			sign = 1
		r = 0
		for ; c!= " "; c = self.next():
			r = r*10 + int(c) - int("0")
		return sign * r

	def next(self):
		if self.pos == len(self.buf):
			self.fill()
		r = self.buf[self.pos]
		self.pos += 1
		return r

def newScanner(stream):
	return scanner(stream)

def main():
	sc = newScanner(sys.stdin)
	N = sc.i()
	sum = 0
	for i in range(1, N+1):
		if i%3 == 0 or i%5 == 0:
			continue
		sum += i
	print(sum)

# fmt.Println("Yes")
# fmt.Println("No")

# I/O
class scanner:
	def __init__(self, stream):
		self.stream = stream
		self.buf = ""
		self.pos = 0
		self.fill()

	def fill(self):
		self.buf = self.stream.readline()
		self.pos = 0

	def s(self):
		c = self.next()
		while c == " ":
			c = self.next()
		r = ""
		for ; c!= " "; c = self.next():
			r += c
		return r

	def i(self):
		c = self.next()
		while c == " ":
			c = self.next()
		r = 0
		sign = 1
		if c == "-":
			sign = -1
			c = self.next()
		for ; c!= " "; c = self.next():
			r = r*10 + int(c) - int("0")
		return sign * r

	def f(self):
		c = self.next()
		while c == " ":
			c = self.next()
		r = 0
		sign = 1
		if c == "-":
			sign = -1
			c = self.next()
		for ; c!= " "; c = self.next():
			r = r*10 + int(c) - int("0")
		return sign * r

	def next(self):
		if self.pos == len(self.buf):
			self.fill()
		r = self.buf[self.pos]
		self.pos += 1
		return r

def newScanner(stream):
	return scanner(stream)

def main():
	sc = newScanner(sys.stdin)
	N = sc.i()
	sum = 0
	for i in range(1, N+1):
		if i%3 == 0 or i%5 == 0:
			continue
		sum += i
	print(sum)

# fmt.Println("Yes")
# fmt.Println("No")

# I/O
class scanner:
	def __init__(self, stream):
		self.stream = stream
		self.buf = ""
		self.pos = 0
		self.fill()

	def fill(self):
		self.buf = self.stream.readline()
		self.pos = 0

	def s(self):
		c = self.next()
		while c == " ":
			c = self.next()
		r = ""
		for ; c!= " "; c = self.next():
			r += c
		return r

	def i(self):
		c = self.next()
		while c == " ":
			c = self.next()
		r = 0
		sign = 1
		if c == "-":
			sign = -1
			c = self.next()
		for ; c!= " "; c = self.next():
			r = r*10 + int(c) - int("0")
		return sign * r

	def f(self):
		c = self.next()
		while c == " ":
			c = self.next()
		r = 0
		sign = 1
		if c == "-":
			sign = -1
			c = self.next()
		for ; c!= " "; c = self.next():
			r = r*10 + int(c) - int("0")
		return sign * r

	def next(self):
		if self.pos == len(self.buf):
			self.fill()
		r = self.buf[self.pos]
		self.pos += 1
		return r

def newScanner(stream):
	return scanner(stream)

def main():
	sc = newScanner(sys.stdin)
	N = sc.i()
	sum = 0
	for i in range(1, N+1):
		if i%3 == 0 or i%5 == 0:
			continue
		sum += i
	print(sum)

# fmt.Println("Yes")
# fmt.Println("No")

# I/O
class scanner:
	def __init__(self, stream):
		self.stream = stream
		self.buf = ""
		self.pos = 0
		self.fill()

	def fill(self):
		self.buf = self.stream.readline()
		self.pos = 0

	def s(self):
		c = self.next()
		while c == " ":
			c = self.next()
		r = ""
		for ; c!= " "; c = self.next():
			r += c
		return r

	def i(self):
		c = self.next()
		while c == " ":
			c = self.next()
		r = 0
		sign = 1
		if c == "-":
			sign = -1
			c = self.next()
		for ; c!= " "; c = self.next():
			r = r*10 + int(c) - int("0")
		return sign * r

	def f(self):
		c = self.next()
		while c == " ":
			c = self.next()
		r = 0
		sign = 1
		if c == "-":
			sign = -1
			c = self.next()
		for ; c!= " "; c = self.next():
			r = r*10 + int(c) - int("0")
		return sign * r

	def next(self):
		if self.pos == len(self.buf):
			self.fill()
		r = self.buf[self.pos]
		self.pos += 1
		return r

def newScanner(stream):
	return scanner(stream)

def main():
	sc = newScanner(sys.stdin)
	N = sc.i()
	sum = 0
	for i in range(1, N+1):
		if i%3 == 0 or i%5 == 0:
			continue
		sum += i
	print(sum)

# fmt.Println("Yes")
# fmt.Println("No")

# I/O
class scanner:
	def __init__(self, stream):
		self.stream = stream
		self.buf = ""
		self.pos = 0
		self.fill()

	def fill(self):
		self.buf = self.stream.readline()
		self.pos = 0

	def s(self):
		c = self.next()
		while c == " ":
			c = self.next()
		r = ""
		for ; c!= " "; c = self.next():
			r += c
		return r

	def i(self):
		c = self.next()
		while c == " ":
			c = self.next()
		r = 0
		sign = 1
		if c == "-":
			sign = -1
			c = self.next()
		for ; c!= " "; c = self.next():
			r = r*10 + int(c) - int("0")
		return sign * r

	def f(self):
		c = self.next()
		while c == " ":
			c = self.next()
		r = 0
		sign = 1
		if c == "-":
			sign = -1
			c = self.next()
		for ; c!= " "; c = self.next():
			r = r*10 + int(c) - int("0")
		return sign * r

	def next(self):
		if self.pos == len(self.buf):
			self.fill()
		r = self.buf[self.pos]
		self.pos += 1
		return r

def newScanner(stream):
	return scanner(stream)

def main():
	sc = newScanner(sys.stdin)
	N = sc.i()
	sum = 0
	for i in range(1, N+1):
		if i%3 == 0 or i%5 == 0:
			continue
		sum += i
	print(sum)

# fmt.Println("Yes")
# fmt.Println("No")

# I/O
class scanner:
	def __init__(self, stream):
		self.stream = stream
		self.buf = ""
		self.pos = 0
		self.fill()

	def fill(self):
		self.buf = self.stream.readline()
		self.pos = 0

	def s(self):
		c = self.next()
		while c == " ":
			c = self.next()
		r = ""
		for ; c!= " "; c = self.next():
			r += c
		return r

	def i(self):
		c = self.next()
		while c == " ":
			c = self.next()
		r = 0
		sign = 1
		if c == "-":
			sign = -1
			c = self.next()
		for ; c!= " "; c = self.next():
			r = r*10 + int(c) - int("0")
		return sign * r

	def f(self):
		c = self.next()
		while c == " ":
			c = self.next()
		r = 0
		sign = 1
		if c == "-":
			sign = -1
			c = self.next()
		for ; c!= " "; c = self.next():
			r = r*10 + int(c) - int("0")
		return sign * r

	def next(self):
		if self.pos == len(self.buf):
			self.fill()
		r = self.buf[self.pos]
		self.pos += 1
		return r

def newScanner(stream):
	return scanner(stream)

def main():
	sc = newScanner(sys.stdin)
	N = sc.i()
	sum = 0
	for i in range(1, N+1):
		if i%3 == 0 or i%5 == 0:
			continue
		sum += i
	print(sum)

# fmt.Println("Yes")
# fmt.Println("No")

# I/O
class scanner:
	def __init__(self, stream):
		self.stream = stream
		self.buf = ""
		self.pos = 0
		self.fill()

	def fill(self):
		self.buf = self.stream.readline()
		self.pos = 0

	def s(self):
		c = self.next()
		while c == " ":
			c = self.next()
		r = ""
		for ; c!= " "; c = self.next():
			r += c
		return r

	def i(self):
		c = self.next()
		while c == " ":
			c = self.next()
		r = 0
		sign = 1
		if c == "-":
			sign = -1
			c = self.next()
		for ; c!= " "; c = self.next():
			r = r*10 + int(c) - int("0")
		return sign * r

	def f(self):
		c = self.next()
		while c == " ":
			c = self.next()
		r = 0
		sign = 1
		if c == "-":
			sign = -1
			c = self.next()
		for ; c!= " "; c = self.next():
			r = r*10 + int(c) - int("0")
		return sign * r

	def next(self):
		if self.pos == len(self.buf):
			self.fill()
		r = self.buf[self.pos]
		self.pos += 1
		return r

def newScanner(stream):
	return scanner(stream)

def main():
	sc = newScanner(sys.stdin)
	N = sc.i()
	sum = 0
	for i in range(1, N+1):
		if i%3 == 0 or i%5 == 0:
			continue
		sum += i
	print(sum)

# fmt.Println("Yes")
# fmt.Println("No")

# I/O
class scanner:
	def __init__(self, stream):
		self.stream = stream
		self.buf = ""
		self.pos = 0
		self.fill()

	def fill(self):
		self.buf = self.stream.readline()
		self.pos = 0

	def s(self):
		c = self.next()
		while c == " ":
			c = self.next()
		r = ""
		for ; c!= " "; c = self.next():
			r += c
		return r

	def i(self):
		c = self.next()
		while c == " ":
			c = self.next()
		r = 0
		sign = 1
		if c == "-":
			sign = -1
			c = self.next()
		for ; c!= " "; c = self.next():
			r = r*10 + int(c) - int("0")
		return sign * r

	def f(self):
		c = self.next()
		while c == " ":
			c = self.next()
		r = 0
		sign = 1
		if c == "-":
			sign = -1
			c = self.next()
		for ; c!= " "; c = self.next():
			r = r*10 + int(c) - int("0")
		return sign * r

	def next(self):
		if self.pos == len(self.buf):
			self.fill()
		r = self.buf[self.pos]
		self.pos += 1
		return r

def newScanner(stream):
	return scanner(stream)

def main():
	sc = newScanner(sys.stdin)
	N = sc.i()
	sum = 0
	for i in range(1, N+1):
		if i%3 == 0 or i%5 == 0:
			continue
		sum += i
	print(sum)

# fmt.Println("Yes")
# fmt.Println("No")

# I/O
class scanner:
	def __init__(self, stream):
		self.stream = stream
		self.buf = ""
		self.pos = 0
		self.fill()

	def fill(self):
		self.buf = self.stream.readline()
		self.pos = 0

	def s(self):
		c = self.next()
		while c == " ":
			c = self.next()
		r = ""
		for ; c!= " "; c = self.next():
			r += c
		return r

	def i(self):
		c = self.next()
		while c == " ":
			c = self.next()
		r = 0
		sign = 1
		if c == "-":
			sign = -1
			c = self.next()
		for ; c!= " "; c = self.next():
			r = r*10 + int(c) - int("0")
		return sign * r

	def f(self):
		c = self.next()
		while c == " ":
			c = self.next()
		r = 0
		sign = 1
		if c == "-":
			sign = -1
			c = self.next()
		for ; c!= " "; c = self.next():
			r = r*10 + int(c) - int("0")
		return sign * r

	def next(self):
		if self.pos == len(self.buf):
			self.fill()
		r = self.buf[self.pos]
		self.pos += 1
		return r

def newScanner(stream):
	return scanner(stream)

def main():
	sc = newScanner(sys.stdin)
	N = sc.i()
	sum = 0
	for i in range(1, N+1):
		if i%3 == 0 or i%5 == 0:
			continue
		sum += i
	print(sum)

# fmt.Println("Yes")
# fmt.Println("No")

# I/O
class scanner:
	def __init__(self, stream):
		self.stream = strea
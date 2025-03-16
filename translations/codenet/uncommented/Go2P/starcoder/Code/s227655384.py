import sys

#  長い入力を読む
def ReadLongLines(times):
	result = []
	for i in range(times):
		line = sys.stdin.readline()
		if line == "":
			break
		result.append(line)
	return result

# 出力 for 競プロ
class Console:
	def __init__(self):
		self.buffer = ""
	def Printf(self, format, a):
		self.buffer += format % a
	def Println(self, s):
		self.buffer += s + "\n"
	def Flush(self):
		print(self.buffer)
		self.buffer = ""

def PrintList(list):
	con = Console()
	for i in range(len(list)):
		if i == 0:
			con.Printf("%d", list[i])
		else:
			con.Printf(" %d", list[i])
	con.Println("")

def main():
	con = Console()
	m = {}
	lines = ReadLongLines(4)
	a = lines[1].split(" ")
	for i in range(len(a)):
		n = int(a[i])
		m[n] = True

	result = []
	b = lines[3].split(" ")
	for i in range(len(b)):
		n = int(b[i])
		if n in m:
			del m[n]
		else:
			m[n] = True
	for k, _ in m.items():
		result.append(k)
	result.sort()
	for j in range(len(result)):
		con.Printf("%d\n", result[j])

if __name__ == "__main__":
	main()



class Cube:
	def __init__(self):
		self.f = [0, 0, 0, 0, 0, 0]
	def roll_z(self):
		t = self.f[1]
		self.f[1] = self.f[2]
		self.f[2] = self.f[4]
		self.f[4] = self.f[3]
		self.f[3] = t
	def roll_y(self):
		t = self.f[0]
		self.f[0] = self.f[2]
		self.f[2] = self.f[5]
		self.f[5] = self.f[3]
		self.f[3] = t
	def roll_x(self):
		t = self.f[0]
		self.f[0] = self.f[1]
		self.f[1] = self.f[5]
		self.f[5] = self.f[4]
		self.f[4] = t
	def roll(self, i, j, k, l):
		t = self.f[i]
		self.f[i] = self.f[j]
		self.f[j] = self.f[k]
		self.f[k] = self.f[l]
		self.f[l] = t

def eq(c1, c2):
	for i in range(6):
		if c1.f[i]!= c2.f[i]:return False
	return True

def equal(c1, c2):
	for i in range(6):
		for j in range(4):
			if eq(c1, c2):return True
			c1.roll_z()
		if i % 2 == 0:c1.roll_y()
		else c1.roll_x()
	return False

c1 = Cube()
c2 = Cube()

for i in range(6):
	c1.f[i] = int(input())
for i in range(6):
	c2.f[i] = int(input())

if equal(c1, c2):print("Yes")
else:print("No")

#
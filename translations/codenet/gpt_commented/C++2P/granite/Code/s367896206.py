
class Cube:
    def __init__(self, faces):
        self.f = faces

    def roll_z(self):
        self.roll(1, 2, 4, 3)

    def roll_y(self):
        self.roll(0, 2, 5, 3)

    def roll_x(self):
        self.roll(0, 1, 5, 4)

    def roll(self, i, j, k, l):
        t = self.f[i]
        self.f[i] = self.f[j]
        self.f[j] = self.f[k]
        self.f[k] = self.f[l]
        self.f[l] = t

def eq(c1, c2):
    for i in range(6):
        if c1.f[i]!= c2.f[i]:
            return False
    return True

def equal(c1, c2):
    for i in range(6):
        for j in range(4):
            if eq(c1, c2):
                return True
            c1.roll_z()
        if i % 2 == 0:
            c1.roll_y()
        else:
            c1.roll_x()
    return False

# Input values for the first cube's faces
c1_faces = [int(input()) for _ in range(6)]
c1 = Cube(c1_faces)

# Input values for the second cube's faces
c2_faces = [int(input()) for _ in range(6)]
c2 = Cube(c2_faces)

# Check if the two cubes can be made equal and print the result
if equal(c1, c2):
    print("Yes")
else:
    print("No")


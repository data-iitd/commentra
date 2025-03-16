class Cube:
    def __init__(self):
        self.f = [0, 0, 0, 0, 0, 0]

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


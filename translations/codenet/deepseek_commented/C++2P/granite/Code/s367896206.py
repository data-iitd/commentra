
class Cube:
    def __init__(self):
        self.f = [0] * 6

    # Rotates the cube around the z-axis.
    def roll_z(self):
        self.roll(1, 2, 4, 3)

    # Rotates the cube around the y-axis.
    def roll_y(self):
        self.roll(0, 2, 5, 3)

    # Rotates the cube around the x-axis.
    def roll_x(self):
        self.roll(0, 1, 5, 4)

    # Helper method to rotate the cube by swapping the values of the faces.
    def roll(self, i, j, k, l):
        t = self.f[i]
        self.f[i] = self.f[j]
        self.f[j] = self.f[k]
        self.f[k] = self.f[l]
        self.f[l] = t


class Vector3D:
    def __init__(self, x=0, y=0, z=0):
        self.x = x
        self.y = y
        self.z = z

    def magnitude(self):
        return (self.x ** 2 + self.y ** 2 + self.z ** 2) ** 0.5

    def dot_product(self, other):
        return self.x * other.x + self.y * other.y + self.z * other.z

    def cross_product(self, other):
        x = self.y * other.z - self.z * other.y
        y = -(self.x * other.z - self.z * other.x)
        z = self.x * other.y - self.y * other.x
        return Vector3D(x, y, z)

    def display_vector(self):
        print(f"x: {self.x}, y: {self.y}, z: {self.z}")


def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    # Read first vector
    x1 = int(data[0])
    y1 = int(data[1])
    z1 = int(data[2])
    a = Vector3D(x1, y1, z1)

    # Read second vector
    x2 = int(data[3])
    y2 = int(data[4])
    z2 = int(data[5])
    b = Vector3D(x2, y2, z2)

    # Determine cross product
    cross_prod = a.cross_product(b)
    print("Cross Product of the two vectors:")
    cross_prod.display_vector()

    # Determine dot product
    dot_prod = a.dot_product(b)
    print("Dot Product of the two vectors:", dot_prod)

    # Display magnitudes
    print("Magnitude of the first vector: {:.2f}".format(a.magnitude()))
    print("Magnitude of the second vector: {:.2f}".format(b.magnitude()))


if __name__ == "__main__":
    main()

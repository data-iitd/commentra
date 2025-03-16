class Main:
    def __init__(self, x=0, y=0, z=0):
        self.x = x
        self.y = y
        self.z = z

    def magnitude(self):
        return (self.x ** 2 + self.y ** 2 + self.z ** 2) ** 0.5

    def dot_product(self, b):
        return self.x * b.x + self.y * b.y + self.z * b.z

    def cross_product(self, b):
        return Main(self.y * b.z - self.z * b.y, -(self.x * b.z - self.z * b.x), self.x * b.y - self.y * b.x)

    def display_vector(self):
        print(f"x : {self.x}\ty : {self.y}\tz : {self.z}")


if __name__ == "__main__":
    print("Enter the components of the first vector (x y z): ")
    x1, y1, z1 = map(int, input().split())
    a = Main(x1, y1, z1)
    print("Enter the components of the second vector (x y z): ")
    x2, y2, z2 = map(int, input().split())
    b = Main(x2, y2, z2)
    cross_prod = a.cross_product(b)
    print("Cross Product of the two vectors:")
    cross_prod.display_vector()
    dot_prod = a.dot_product(b)
    print("Dot Product of the two vectors:", dot_prod)
    print(f"Magnitude of the first vector: {a.magnitude():.2f}")
    print(f"Magnitude of the second vector: {b.magnitude():.2f}")

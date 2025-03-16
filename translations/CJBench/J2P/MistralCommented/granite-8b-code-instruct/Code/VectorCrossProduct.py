

import math

class Main:
    def __init__(self, vectorX, vectorY, vectorZ):
        self.x = vectorX
        self.y = vectorY
        self.z = vectorZ

    def magnitude(self):
        return math.sqrt(self.x**2 + self.y**2 + self.z**2)

    def dotProduct(self, b):
        return self.x * b.x + self.y * b.y + self.z * b.z

    def crossProduct(self, b):
        product = Main(0, 0, 0)
        product.x = (self.y * b.z) - (self.z * b.y)
        product.y = -((self.x * b.z) - (self.z * b.x))
        product.z = (self.x * b.y) - (self.y * b.x)
        return product

    def displayVector(self):
        print(f"x : {self.x}\ty : {self.y}\tz : {self.z}")

if __name__ == "__main__":
    x1, y1, z1 = map(int, input("Enter the components of the first vector (x y z): ").split())
    a = Main(x1, y1, z1)
    x2, y2, z2 = map(int, input("Enter the components of the second vector (x y z): ").split())
    b = Main(x2, y2, z2)
    crossProd = a.crossProduct(b)
    print("Cross Product of the two vectors:")
    crossProd.displayVector()
    dotProd = a.dotProduct(b)
    print(f"Dot Product of the two vectors: {dotProd}")
    print(f"Magnitude of the first vector: {a.magnitude():.2f}")
    print(f"Magnitude of the second vector: {b.magnitude():.2f}")


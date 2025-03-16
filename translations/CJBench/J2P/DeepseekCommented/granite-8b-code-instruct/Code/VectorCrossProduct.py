
import math

class Main:
    def __init__(self, x=0, y=0, z=0):
        self.x = x
        self.y = y
        self.z = z

    def magnitude(self):
        return math.sqrt(self.x**2 + self.y**2 + self.z**2)

    def dotProduct(self, b):
        return self.x * b.x + self.y * b.y + self.z * b.z

    def crossProduct(self, b):
        product = Main()
        product.x = (self.y * b.z) - (self.z * b.y)
        product.y = -((self.x * b.z) - (self.z * b.x))
        product.z = (self.x * b.y) - (self.y * b.x)
        return product

    def displayVector(self):
        print(f"x : {self.x}\ty : {self.y}\tz : {self.z}")

if __name__ == "__main__":
    x1, y1, z1 = map(int, input("Enter the components of the first vector (x y z): ").split())
    a = Main(x1, y1, z1)  # Create first vector
    x2, y2, z2 = map(int, input("Enter the components of the second vector (x y z): ").split())
    b = Main(x2, y2, z2)  # Create second vector
    crossProd = a.crossProduct(b)  # Calculate cross product
    print("Cross Product of the two vectors:")
    crossProd.displayVector()  # Display cross product
    dotProd = a.dotProduct(b)  # Calculate dot product
    print(f"Dot Product of the two vectors: {dotProd}")  # Display dot product
    print(f"Magnitude of the first vector: {a.magnitude():.2f}")  # Display magnitude of first vector
    print(f"Magnitude of the second vector: {b.magnitude():.2f}")  # Display magnitude of second vector


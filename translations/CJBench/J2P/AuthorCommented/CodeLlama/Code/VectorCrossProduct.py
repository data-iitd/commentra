
import math

class Vector:
    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def magnitude(self):
        return math.sqrt(self.x**2 + self.y**2 + self.z**2)

    def dot_product(self, b):
        return self.x * b.x + self.y * b.y + self.z * b.z

    def cross_product(self, b):
        product = Vector(0, 0, 0)
        product.x = (self.y * b.z) - (self.z * b.y)
        product.y = -((self.x * b.z) - (self.z * b.x))
        product.z = (self.x * b.y) - (self.y * b.x)
        return product

    def display_vector(self):
        print("x : " + str(self.x) + "\ty : " + str(self.y) + "\tz : " + str(self.z))

def main():
    # Input first vector
    print("Enter the components of the first vector (x y z): ")
    x1 = int(input())
    y1 = int(input())
    z1 = int(input())
    a = Vector(x1, y1, z1)

    # Input second vector
    print("Enter the components of the second vector (x y z): ")
    x2 = int(input())
    y2 = int(input())
    z2 = int(input())
    b = Vector(x2, y2, z2)

    # Determine cross product
    cross_prod = a.cross_product(b)
    print("Cross Product of the two vectors:")
    cross_prod.display_vector()

    # Determine dot product
    dot_prod = a.dot_product(b)
    print("Dot Product of the two vectors: " + str(dot_prod))

    # Display magnitudes
    print("Magnitude of the first vector: " + str(a.magnitude()))
    print("Magnitude of the second vector: " + str(b.magnitude()))

if __name__ == "__main__":
    main()


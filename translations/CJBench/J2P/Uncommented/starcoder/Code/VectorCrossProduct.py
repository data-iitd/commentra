
import math
class Main:
    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z
    def magnitude(self):
        return math.sqrt(self.x * self.x + self.y * self.y + self.z * self.z)
    def dotProduct(self, b):
        return self.x * b.x + self.y * b.y + self.z * b.z
    def crossProduct(self, b):
        product = Main(0, 0, 0)
        product.x = (self.y * b.z) - (self.z * b.y)
        product.y = -((self.x * b.z) - (self.z * b.x))
        product.z = (self.x * b.y) - (self.y * b.x)
        return product
    def displayVector(self):
        print("x : " + str(self.x) + "\ty : " + str(self.y) + "\tz : " + str(self.z))

if __name__ == "__main__":
    a = Main(0, 0, 0)
    b = Main(0, 0, 0)
    print("Enter the components of the first vector (x y z): ")
    a.x = int(input())
    a.y = int(input())
    a.z = int(input())
    print("Enter the components of the second vector (x y z): ")
    b.x = int(input())
    b.y = int(input())
    b.z = int(input())
    crossProd = a.crossProduct(b)
    print("Cross Product of the two vectors:")
    crossProd.displayVector()
    dotProd = a.dotProduct(b)
    print("Dot Product of the two vectors: " + str(dotProd))
    print("Magnitude of the first vector: " + str(a.magnitude()))
    print("Magnitude of the second vector: " + str(b.magnitude()))



import math

class Main:
    def __init__(self, vectorX=0, vectorY=0, vectorZ=0):
        self.x = vectorX
        self.y = vectorY
        self.z = vectorZ

    def magnitude(self):
        return math.sqrt(self.x ** 2 + self.y ** 2 + self.z ** 2)

    def dotProduct(self, b):
        return self.x * b.x + self.y * b.y + self.z * b.z

    def crossProduct(self, b):
        product = Main()
        product.x = (self.y * b.z) - (self.z * b.y)
        product.y = -((self.x * b.z) - (self.z * b.x))
        product.z = (self.x * b.y) - (self.y * b.x)
        return product

    def displayVector(self):
        print("x : " + str(self.x) + "\ty : " + str(self.y) + "\tz : " + str(self.z))

def main():
    scanner = input("Enter the components of the first vector (x y z): ")
    x1 = int(scanner.split(" ")[0])
    y1 = int(scanner.split(" ")[1])
    z1 = int(scanner.split(" ")[2])
    a = Main(x1, y1, z1)
    scanner = input("Enter the components of the second vector (x y z): ")
    x2 = int(scanner.split(" ")[0])
    y2 = int(scanner.split(" ")[1])
    z2 = int(scanner.split(" ")[2])
    b = Main(x2, y2, z2)
    crossProd = a.crossProduct(b)
    print("Cross Product of the two vectors:")
    crossProd.displayVector()
    dotProd = a.dotProduct(b)
    print("Dot Product of the two vectors: " + str(dotProd))
    print("Magnitude of the first vector: " + str(a.magnitude()))
    print("Magnitude of the second vector: " + str(b.magnitude()))

if __name__ == "__main__":
    main()


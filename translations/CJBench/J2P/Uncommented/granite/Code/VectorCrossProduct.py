

class Main:
    def __init__(self, vectorX=0, vectorY=0, vectorZ=0):
        self.x = vectorX
        self.y = vectorY
        self.z = vectorZ

    def magnitude(self):
        return (self.x ** 2 + self.y ** 2 + self.z ** 2) ** 0.5

    def dotProduct(self, b):
        return self.x * b.x + self.y * b.y + self.z * b.z

    def crossProduct(self, b):
        product = Main()
        product.x = self.y * b.z - self.z * b.y
        product.y = - (self.x * b.z - self.z * b.x)
        product.z = self.x * b.y - self.y * b.x
        return product

    def displayVector(self):
        print("x : " + str(self.x) + " y : " + str(self.y) + " z : " + str(self.z))

if __name__ == "__main__":
    import sys
    from math import sqrt
    scanner = sys.stdin
    print("Enter the components of the first vector (x y z): ")
    x1 = int(scanner.readline())
    y1 = int(scanner.readline())
    z1 = int(scanner.readline())
    a = Main(x1, y1, z1)
    print("Enter the components of the second vector (x y z): ")
    x2 = int(scanner.readline())
    y2 = int(scanner.readline())
    z2 = int(scanner.readline())
    b = Main(x2, y2, z2)
    crossProd = a.crossProduct(b)
    print("Cross Product of the two vectors:")
    crossProd.displayVector()
    dotProd = a.dotProduct(b)
    print("Dot Product of the two vectors: " + str(dotProd))
    print("Magnitude of the first vector: " + str(a.magnitude()))
    print("Magnitude of the second vector: " + str(b.magnitude()))
    scanner.close()


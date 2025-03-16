
class Main:
    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def magnitude(self):
        return (self.x ** 2 + self.y ** 2 + self.z ** 2) ** 0.5

    def dotProduct(self, b):
        return self.x * b.x + self.y * b.y + self.z * b.z

    def crossProduct(self, b):
        return Main(self.y * b.z - self.z * b.y, - (self.x * b.z - self.z * b.x), self.x * b.y - self.y * b.x)

    def displayVector(self):
        print("x : " + str(self.x) + "\ty : " + str(self.y) + "\tz : " + str(self.z))


if __name__ == '__main__':
    a = Main(0, 0, 0)
    b = Main(0, 0, 0)
    a.displayVector()
    b.displayVector()
    print("Enter the components of the first vector (x y z): ")
    a.x = int(input())
    a.y = int(input())
    a.z = int(input())
    a.displayVector()
    print("Enter the components of the second vector (x y z): ")
    b.x = int(input())
    b.y = int(input())
    b.z = int(input())
    b.displayVector()
    crossProd = a.crossProduct(b)
    crossProd.displayVector()
    dotProd = a.dotProduct(b)
    print("Dot Product of the two vectors: " + str(dotProd))
    print("Magnitude of the first vector: " + str(a.magnitude()))
    print("Magnitude of the second vector: " + str(b.magnitude()))


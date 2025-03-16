
# This class calculates the cross product, dot product, and magnitude of two 3D vectors.
class Main:

    def __init__(self, vectorX, vectorY, vectorZ):
        self.x = vectorX
        self.y = vectorY
        self.z = vectorZ

    # Returns the magnitude of the vector
    def magnitude(self):
        return math.sqrt(self.x * self.x + self.y * self.y + self.z * self.z)

    # Returns the dot product of the current vector with a given vector
    def dotProduct(self, b):
        return self.x * b.x + self.y * b.y + self.z * b.z

    # Returns the cross product of the current vector with a given vector
    def crossProduct(self, b):
        product = Main(0, 0, 0)
        product.x = (self.y * b.z) - (self.z * b.y)
        product.y = -((self.x * b.z) - (self.z * b.x))
        product.z = (self.x * b.y) - (self.y * b.x)
        return product

    # Display the vector
    def displayVector(self):
        print("x : " + str(self.x) + "\ty : " + str(self.y) + "\tz : " + str(self.z))


if __name__ == '__main__':
    # Input first vector
    print("Enter the components of the first vector (x y z): ")
    x1 = int(input())
    y1 = int(input())
    z1 = int(input())
    a = Main(x1, y1, z1)

    # Input second vector
    print("Enter the components of the second vector (x y z): ")
    x2 = int(input())
    y2 = int(input())
    z2 = int(input())
    b = Main(x2, y2, z2)

    # Determine cross product
    crossProd = a.crossProduct(b)
    print("Cross Product of the two vectors:")
    crossProd.displayVector()

    # Determine dot product
    dotProd = a.dotProduct(b)
    print("Dot Product of the two vectors: " + str(dotProd))

    # Display magnitudes
    print("Magnitude of the first vector: " + str(a.magnitude()))
    print("Magnitude of the second vector: " + str(b.magnitude()))


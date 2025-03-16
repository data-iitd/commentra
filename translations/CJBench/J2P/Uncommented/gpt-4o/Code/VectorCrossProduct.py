import math

class Vector:
    def __init__(self, vectorX=0, vectorY=0, vectorZ=0):
        self.x = vectorX
        self.y = vectorY
        self.z = vectorZ

    def magnitude(self):
        return math.sqrt(self.x ** 2 + self.y ** 2 + self.z ** 2)

    def dot_product(self, b):
        return self.x * b.x + self.y * b.y + self.z * b.z

    def cross_product(self, b):
        product = Vector()
        product.x = (self.y * b.z) - (self.z * b.y)
        product.y = -((self.x * b.z) - (self.z * b.x))
        product.z = (self.x * b.y) - (self.y * b.x)
        return product

    def display_vector(self):
        print(f"x : {self.x}\ty : {self.y}\tz : {self.z}")

if __name__ == "__main__":
    x1, y1, z1 = map(int, input("Enter the components of the first vector (x y z): ").split())
    a = Vector(x1, y1, z1)
    
    x2, y2, z2 = map(int, input("Enter the components of the second vector (x y z): ").split())
    b = Vector(x2, y2, z2)
    
    cross_prod = a.cross_product(b)
    print("Cross Product of the two vectors:")
    cross_prod.display_vector()
    
    dot_prod = a.dot_product(b)
    print("Dot Product of the two vectors:", dot_prod)
    
    print(f"Magnitude of the first vector: {a.magnitude():.2f}")
    print(f"Magnitude of the second vector: {b.magnitude():.2f}")

# <END-OF-CODE>

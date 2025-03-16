class Vector3D:
    def __init__(self, x=0, y=0, z=0):
        self.x = x
        self.y = y
        self.z = z

    def magnitude(self):
        return (self.x ** 2 + self.y ** 2 + self.z ** 2) ** 0.5

    def dot_product(self, other):
        return self.x * other.x + self.y * other.y + self.z * other.z

    def cross_product(self, other):
        x = self.y * other.z - self.z * other.y
        y = -(self.x * other.z - self.z * other.x)
        z = self.x * other.y - self.y * other.x
        return Vector3D(x, y, z)

    def display_vector(self):
        print(f"x: {self.x}, y: {self.y}, z: {self.z}")


def main():
    print("Enter the components of the first vector (x y z): ")
    x1, y1, z1 = map(int, input().split())
    vector_a = Vector3D(x1, y1, z1)
    print("Enter the components of the second vector (x y z): ")
    x2, y2, z2 = map(int, input().split())
    vector_b = Vector3D(x2, y2, z2)
    cross_prod = vector_a.cross_product(vector_b)
    print("Cross Product of the two vectors:")
    cross_prod.display_vector()
    dot_prod = vector_a.dot_product(vector_b)
    print("Dot Product of the two vectors:", dot_prod)
    print(f"Magnitude of the first vector: {vector_a.magnitude():.2f}")
    print(f"Magnitude of the second vector: {vector_b.magnitude():.2f}")


main()

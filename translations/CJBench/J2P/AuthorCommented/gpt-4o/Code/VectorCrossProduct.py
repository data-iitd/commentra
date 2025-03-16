import math

class Vector3D:
    def __init__(self, vector_x=0, vector_y=0, vector_z=0):
        self.x = vector_x
        self.y = vector_y
        self.z = vector_z

    def magnitude(self):
        return math.sqrt(self.x ** 2 + self.y ** 2 + self.z ** 2)

    def dot_product(self, other):
        return self.x * other.x + self.y * other.y + self.z * other.z

    def cross_product(self, other):
        return Vector3D(
            self.y * other.z - self.z * other.y,
            -(self.x * other.z - self.z * other.x),
            self.x * other.y - self.y * other.x
        )

    def display_vector(self):
        print(f"x : {self.x}\ty : {self.y}\tz : {self.z}")

def main():
    # Input first vector
    x1, y1, z1 = map(int, input("Enter the components of the first vector (x y z): ").split())
    a = Vector3D(x1, y1, z1)

    # Input second vector
    x2, y2, z2 = map(int, input("Enter the components of the second vector (x y z): ").split())
    b = Vector3D(x2, y2, z2)

    # Determine cross product
    cross_prod = a.cross_product(b)
    print("Cross Product of the two vectors:")
    cross_prod.display_vector()

    # Determine dot product
    dot_prod = a.dot_product(b)
    print("Dot Product of the two vectors:", dot_prod)

    # Display magnitudes
    print(f"Magnitude of the first vector: {a.magnitude():.2f}")
    print(f"Magnitude of the second vector: {b.magnitude():.2f}")

if __name__ == "__main__":
    main()

# <END-OF-CODE>

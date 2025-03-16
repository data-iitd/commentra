import math

class Vector:
    def __init__(self, vector_x=0, vector_y=0, vector_z=0):
        # Initialize vector components
        self.x = vector_x
        self.y = vector_y
        self.z = vector_z

    def magnitude(self):
        # Calculate and return the magnitude of the vector
        return math.sqrt(self.x ** 2 + self.y ** 2 + self.z ** 2)

    def dot_product(self, other):
        # Calculate and return the dot product of this vector with another vector
        return self.x * other.x + self.y * other.y + self.z * other.z

    def cross_product(self, other):
        # Calculate and return the cross product of this vector with another vector
        return Vector(
            self.y * other.z - self.z * other.y,
            -(self.x * other.z - self.z * other.x),
            self.x * other.y - self.y * other.x
        )

    def display_vector(self):
        # Display the vector components
        print(f"x : {self.x}\ty : {self.y}\tz : {self.z}")

def main():
    # Prompt user to enter the components of the first vector
    x1, y1, z1 = map(int, input("Enter the components of the first vector (x y z): ").split())
    a = Vector(x1, y1, z1)

    # Prompt user to enter the components of the second vector
    x2, y2, z2 = map(int, input("Enter the components of the second vector (x y z): ").split())
    b = Vector(x2, y2, z2)

    # Calculate and display the cross product of the two vectors
    cross_prod = a.cross_product(b)
    print("Cross Product of the two vectors:")
    cross_prod.display_vector()

    # Calculate and display the dot product of the two vectors
    dot_prod = a.dot_product(b)
    print("Dot Product of the two vectors:", dot_prod)

    # Calculate and display the magnitude of the first vector
    print(f"Magnitude of the first vector: {a.magnitude():.2f}")

    # Calculate and display the magnitude of the second vector
    print(f"Magnitude of the second vector: {b.magnitude():.2f}")

if __name__ == "__main__":
    main()

# <END-OF-CODE>


import math

# Class to represent a 3D vector
class Vector3D:
    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    # Method to calculate and return the magnitude of the vector
    def magnitude(self):
        return math.sqrt(self.x**2 + self.y**2 + self.z**2)

    # Method to calculate and return the dot product of this vector with another vector
    def dot_product(self, other):
        return self.x * other.x + self.y * other.y + self.z * other.z

    # Method to calculate and return the cross product of this vector with another vector
    def cross_product(self, other):
        x = self.y * other.z - self.z * other.y
        y = - (self.x * other.z - self.z * other.x)
        z = self.x * other.y - self.y * other.x
        return Vector3D(x, y, z)

    # Method to display the vector components
    def display_vector(self):
        print(f"x : {self.x}\ty : {self.y}\tz : {self.z}")

# Main function to execute the program
def main():
    # Create a scanner object for user input
    scanner = input("Enter the components of the first vector (x y z): ")
    x1, y1, z1 = map(int, scanner.split())

    # Create the first vector using user input
    a = Vector3D(x1, y1, z1)

    # Prompt user to enter the components of the second vector
    scanner = input("Enter the components of the second vector (x y z): ")
    x2, y2, z2 = map(int, scanner.split())

    # Create the second vector using user input
    b = Vector3D(x2, y2, z2)

    # Calculate and display the cross product of the two vectors
    cross_prod = a.cross_product(b)
    print("Cross Product of the two vectors:")
    cross_prod.display_vector()

    # Calculate and display the dot product of the two vectors
    dot_prod = a.dot_product(b)
    print(f"Dot Product of the two vectors: {dot_prod}")

    # Calculate and display the magnitude of the first vector
    print(f"Magnitude of the first vector: {a.magnitude():.2f}")

    # Calculate and display the magnitude of the second vector
    print(f"Magnitude of the second vector: {b.magnitude():.2f}")

# Call the main function to execute the program
if __name__ == "__main__":
    main()


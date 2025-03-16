import math

class Vector3D:
    # Constructor to initialize the vector components
    def __init__(self, x=0, y=0, z=0):
        self.x = x
        self.y = y
        self.z = z

    # Method to calculate and return the magnitude of the vector
    def magnitude(self):
        return math.sqrt(self.x ** 2 + self.y ** 2 + self.z ** 2)

    # Method to calculate and return the dot product of this vector with another vector
    def dot_product(self, other):
        return self.x * other.x + self.y * other.y + self.z * other.z

    # Method to calculate and return the cross product of this vector with another vector
    def cross_product(self, other):
        x = self.y * other.z - self.z * other.y
        y = -(self.x * other.z - self.z * other.x)
        z = self.x * other.y - self.y * other.x
        return Vector3D(x, y, z)

    # Method to display the vector components
    def display_vector(self):
        print(f"x: {self.x}, y: {self.y}, z: {self.z}")

# Main function to execute the program
def main():
    # Create a scanner object for user input (using input function for simplicity)
    print("Enter the components of the first vector (x y z): ")
    x1, y1, z1 = map(int, input().split())
    vector_a = Vector3D(x1, y1, z1)
    
    print("Enter the components of the second vector (x y z): ")
    x2, y2, z2 = map(int, input().split())
    vector_b = Vector3D(x2, y2, z2)
    
    # Calculate and display the cross product of the two vectors
    cross_prod = vector_a.cross_product(vector_b)
    print("Cross Product of the two vectors:")
    cross_prod.display_vector()
    
    # Calculate and display the dot product of the two vectors
    dot_prod = vector_a.dot_product(vector_b)
    print("Dot Product of the two vectors:", dot_prod)
    
    # Calculate and display the magnitude of the first vector
    print("Magnitude of the first vector: {:.2f}".format(vector_a.magnitude()))
    
    # Calculate and display the magnitude of the second vector
    print("Magnitude of the second vector: {:.2f}".format(vector_b.magnitude()))

# Call the main function
main()

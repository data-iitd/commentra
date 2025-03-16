import math  # Importing the math module for mathematical functions

class Vector:  # Defining the Vector class
    def __init__(self, vectorX=0, vectorY=0, vectorZ=0):  # Constructor with default values
        self.x = vectorX  # Initializing x, y, and z with the given values
        self.y = vectorY
        self.z = vectorZ

    def magnitude(self):  # Method to calculate the magnitude of the vector
        return math.sqrt(self.x ** 2 + self.y ** 2 + self.z ** 2)  # Calculating the square of each component and then taking the square root

    def dot_product(self, b):  # Method to calculate the dot product of two vectors
        return self.x * b.x + self.y * b.y + self.z * b.z  # Multiplying corresponding components and summing them up

    def cross_product(self, b):  # Method to calculate the cross product of two vectors
        product = Vector()  # Creating a new Vector object to store the result
        product.x = (self.y * b.z) - (self.z * b.y)  # Calculating the x component using the cross product formula
        product.y = -((self.x * b.z) - (self.z * b.x))  # Calculating the y component using the cross product formula
        product.z = (self.x * b.y) - (self.y * b.x)  # Calculating the z component using the cross product formula
        return product  # Returning the result

    def display_vector(self):  # Method to display the components of the vector
        print(f"x : {self.x}\ty : {self.y}\tz : {self.z}")  # Printing the components of the vector

if __name__ == "__main__":  # Main block
    x1, y1, z1 = map(int, input("Enter the components of the first vector (x y z): ").split())  # Reading the components of the first vector from user input
    a = Vector(x1, y1, z1)  # Creating a new Vector object 'a' with the given components
    x2, y2, z2 = map(int, input("Enter the components of the second vector (x y z): ").split())  # Reading the components of the second vector from user input
    b = Vector(x2, y2, z2)  # Creating a new Vector object 'b' with the given components
    cross_prod = a.cross_product(b)  # Calculating the cross product of vectors 'a' and 'b'
    print("Cross Product of the two vectors:")  # Printing the header for the cross product result
    cross_prod.display_vector()  # Displaying the components of the cross product result
    dot_prod = a.dot_product(b)  # Calculating the dot product of vectors 'a' and 'b'
    print(f"Dot Product of the two vectors: {dot_prod}")  # Printing the dot product result
    print(f"Magnitude of the first vector: {a.magnitude():.2f}")  # Printing the magnitude of vector 'a' with two decimal places
    print(f"Magnitude of the second vector: {b.magnitude():.2f}")  # Printing the magnitude of vector 'b' with two decimal places

# <END-OF-CODE>

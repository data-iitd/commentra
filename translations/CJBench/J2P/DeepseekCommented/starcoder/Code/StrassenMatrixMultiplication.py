# Importing Scanner class for reading input
import java.util.Scanner;

class Main:
    # Method to multiply two matrices using Strassen's algorithm
    def multiply(self, a, b):
        n = a.length; # Get the size of the matrix
        mat = [[0 for i in range(n)] for j in range(n)]; # Initialize the result matrix
        if n == 1:
            mat[0][0] = a[0][0] * b[0][0]; # Base case: single element multiplication
        else:
            # Divide the matrix into four quadrants
            a11 = [[0 for i in range(n / 2)] for j in range(n / 2)];
            a12 = [[0 for i in range(n / 2)] for j in range(n / 2)];
            a21 = [[0 for i in range(n / 2)] for j in range(n / 2)];
            a22 = [[0 for i in range(n / 2)] for j in range(n / 2)];
            b11 = [[0 for i in range(n / 2)] for j in range(n / 2)];
            b12 = [[0 for i in range(n / 2)] for j in range(n / 2)];
            b21 = [[0 for i in range(n / 2)] for j in range(n / 2)];
            b22 = [[0 for i in range(n / 2)] for j in range(n / 2)];
            # Split the matrices into submatrices
            self.split(a, a11, 0, 0);
            self.split(a, a12, 0, n / 2);
            self.split(a, a21, n / 2, 0);
            self.split(a, a22, n / 2, n / 2);
            self.split(b, b11, 0, 0);
            self.split(b, b12, 0, n / 2);
            self.split(b, b21, n / 2, 0);
            self.split(b, b22, n / 2, n / 2);
            # Recursively compute the seven products
            m1 = self.multiply(self.add(a11, a22), self.add(b11, b22));
            m2 = self.multiply(self.add(a21, a22), b11);
            m3 = self.multiply(a11, self.sub(b12, b22));
            m4 = self.multiply(a22, self.sub(b21, b11));
            m5 = self.multiply(self.add(a11, a12), b22);
            m6 = self.multiply(self.sub(a21, a11), self.add(b11, b12));
            m7 = self.multiply(self.sub(a12, a22), self.add(b21, b22));
            # Compute the four quadrants of the resulting matrix
            c11 = self.add(self.sub(self.add(m1, m4), m5), m7);
            c12 = self.add(m3, m5);
            c21 = self.add(m2, m4);
            c22 = self.add(self.sub(self.add(m1, m3), m2), m6);
            # Join the quadrants back into the result matrix
            self.join(c11, mat, 0, 0);
            self.join(c12, mat, 0, n / 2);
            self.join(c21, mat, n / 2, 0);
            self.join(c22, mat, n / 2, n / 2);
        return mat; # Return the resultant matrix

    # Method to perform element-wise subtraction of two matrices
    def sub(self, a, b):
        n = a.length; # Get the size of the matrix
        c = [[0 for i in range(n)] for j in range(n)]; # Initialize the result matrix
        for i in range(n):
            for j in range(n):
                c[i][j] = a[i][j] - b[i][j]; # Subtract corresponding elements
        return c; # Return the resultant matrix

    # Method to perform element-wise addition of two matrices
    def add(self, a, b):
        n = a.length; # Get the size of the matrix
        c = [[0 for i in range(n)] for j in range(n)]; # Initialize the result matrix
        for i in range(n):
            for j in range(n):
                c[i][j] = a[i][j] + b[i][j]; # Add corresponding elements
        return c; # Return the resultant matrix

    # Method to split a matrix into four submatrices
    def split(self, p, c, iB, jB):
        for i1 in range(c.length):
            for j1 in range(c.length):
                c[i1][j1] = p[i1 + iB][j1 + jB]; # Copy elements to submatrices
    # Method to join four submatrices back into a single matrix
    def join(self, c, p, iB, jB):
        for i1 in range(c.length):
            for j1 in range(c.length):
                p[i1 + iB][j1 + jB] = c[i1][j1]; # Copy elements from submatrices

# Main method to read input, call the multiply method, and print the result
if __name__ == "__main__":
    scanner = Scanner(System.in); # Create a Scanner object
    n = scanner.nextInt(); # Read the size of the matrix
    a = [[0 for i in range(n)] for j in range(n)]; # Initialize the first matrix
    b = [[0 for i in range(n)] for j in range(n)]; # Initialize the second matrix
    for i in range(n):
        for j in range(n):
            a[i][j] = scanner.nextInt(); # Read elements of the first matrix
    for i in range(n):
        for j in range(n):
            b[i][j] = scanner.nextInt(); # Read elements of the second matrix
    strassen = Main(); # Create an instance of the Main class
    result = strassen.multiply(a, b); # Call the multiply method
    print("Resultant Matrix:"); # Print the result
    for i in range(n):
        for j in range(n):
            print(result[i][j] + " "); # Print elements of the resultant matrix
        print(); # Move to the next line
    scanner.close(); # Close the Scanner object


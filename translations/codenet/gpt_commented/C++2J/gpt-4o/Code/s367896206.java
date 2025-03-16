import java.util.Scanner;

// Class representing a Cube with 6 faces
class Cube {
    int[] f = new int[6]; // Array to hold the values of the cube's faces

    // Default constructor
    public Cube() {}

    // Method to roll the cube around the Z-axis
    public void rollZ() { roll(1, 2, 4, 3); }

    // Method to roll the cube around the Y-axis
    public void rollY() { roll(0, 2, 5, 3); }

    // Method to roll the cube around the X-axis
    public void rollX() { roll(0, 1, 5, 4); }

    // Method to perform a roll operation on specified faces
    private void roll(int i, int j, int k, int l) {
        int t = f[i]; // Store the value of face i temporarily
        f[i] = f[j];  // Move value of face j to face i
        f[j] = f[k];  // Move value of face k to face j
        f[k] = f[l];  // Move value of face l to face k
        f[l] = t;     // Assign the temporary value to face l
    }
}

// Class to check if two cubes are equal
public class CubeEqualityChecker {

    // Function to check if two cubes are equal
    public static boolean eq(Cube c1, Cube c2) {
        for (int i = 0; i < 6; i++)
            if (c1.f[i] != c2.f[i]) return false; // Return false if any face differs
        return true; // Return true if all faces are equal
    }

    // Function to check if two cubes can be made equal through rotations
    public static boolean equal(Cube c1, Cube c2) {
        for (int i = 0; i < 6; i++) { // Iterate through each face of the cube
            for (int j = 0; j < 4; j++) { // Try 4 rotations around the Z-axis
                if (eq(c1, c2)) return true; // Check if cubes are equal after rotation
                c1.rollZ(); // Roll the cube around the Z-axis
            }
            // Alternate rolling around Y and X axes based on the iteration index
            if (i % 2 == 0) c1.rollY(); // Roll around Y-axis for even indices
            else c1.rollX(); // Roll around X-axis for odd indices
        }
        return false; // Return false if no configuration matches
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Cube c1 = new Cube(); // Create the first Cube object
        Cube c2 = new Cube(); // Create the second Cube object

        // Input values for the first cube's faces
        for (int i = 0; i < 6; i++) c1.f[i] = scanner.nextInt();
        // Input values for the second cube's faces
        for (int i = 0; i < 6; i++) c2.f[i] = scanner.nextInt();

        // Check if the two cubes can be made equal and print the result
        if (equal(c1, c2)) System.out.println("Yes"); // Print "Yes" if they are equal
        else System.out.println("No"); // Print "No" if they are not equal

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>

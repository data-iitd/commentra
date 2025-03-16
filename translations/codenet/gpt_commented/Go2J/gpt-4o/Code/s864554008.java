import java.util.Scanner;

// Define a class to hold the dimensions and images
class Data {
    int n, m; // n: number of rows in the first image, m: number of rows in the second image
    String[] nImg, mImg; // nImg: first image as an array of strings, mImg: second image as an array of strings

    // Constructor to initialize the Data object
    public Data(int n, int m, String[] nImg, String[] mImg) {
        this.n = n;
        this.m = m;
        this.nImg = nImg;
        this.mImg = mImg;
    }

    // Method to check if the second image exists within the first image
    public boolean exist() {
        // Iterate over possible starting positions in the first image
        for (int i = 0; i <= n - m; i++) {
            for (int j = 0; j <= n - m; j++) {
                // Check if the second image matches the first image at the current position
                if (match(i, j)) {
                    return true; // Return true if a match is found
                }
            }
        }
        // Return false if no match is found after checking all positions
        return false;
    }

    // Method to check if the second image matches the first image at a specific position
    public boolean match(int x, int y) {
        // Iterate over each cell of the second image
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                // Compare the corresponding cells of the two images
                if (nImg[x + i].charAt(y + j) != mImg[i].charAt(j)) {
                    return false; // Return false if any cell does not match
                }
            }
        }
        // Return true if all cells match
        return true;
    }
}

public class Main {
    public static void main(String[] args) {
        // Create a new Data instance and check for the existence of a match
        Data d = newData();
        if (d.exist()) {
            System.out.println("Yes"); // Print "Yes" if a match exists
        } else {
            System.out.println("No");  // Print "No" if no match is found
        }
    }

    // Function to read input dimensions and images, returning a Data instance
    public static Data newData() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        // Load the first image and the second image based on the dimensions
        String[] nImg = load(scanner, n);
        String[] mImg = load(scanner, m);
        scanner.close();

        // Return a Data instance containing the dimensions and images
        return new Data(n, m, nImg, mImg);
    }

    // Function to load an image of given count from standard input
    public static String[] load(Scanner scanner, int cnt) {
        String[] ret = new String[cnt]; // Create an array to hold the image strings
        for (int i = 0; i < cnt; i++) {
            ret[i] = scanner.next(); // Read each line of the image into the array
        }
        // Return the loaded image
        return ret;
    }
}

// <END-OF-CODE>

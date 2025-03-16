import java.util.Scanner;

// Define a class to hold the data for the images
class Data {
    int n, m; // Dimensions of the images and their slices
    String[] nImg, mImg; // Arrays to hold the image data

    // Constructor to initialize the data
    public Data(int n, int m, String[] nImg, String[] mImg) {
        this.n = n;
        this.m = m;
        this.nImg = nImg;
        this.mImg = mImg;
    }

    // Method to check if the smaller image exists within the larger image
    public boolean exist() {
        // Iterate over all possible positions where the smaller image could fit within the larger image
        for (int i = 0; i <= n - m; i++) {
            for (int j = 0; j <= n - m; j++) {
                if (match(i, j)) { // Check if the smaller image matches the corresponding part of the larger image at the current position
                    return true;
                }
            }
        }
        return false;
    }

    // Method to check if the smaller image matches the corresponding part of the larger image at a given position
    public boolean match(int x, int y) {
        // Iterate over each pixel in the smaller image and compare it with the corresponding pixel in the larger image
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (nImg[x + i].charAt(y + j) != mImg[i].charAt(j)) { // If any pixel does not match, return false
                    return false;
                }
            }
        }
        return true; // If all pixels match, return true
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the dimensions of the images
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character

        // Load the images from standard input
        String[] nImg = load(scanner, n);
        String[] mImg = load(scanner, m);

        // Create a new data instance
        Data d = new Data(n, m, nImg, mImg);
        
        // Check if the smaller image exists within the larger image and print the result
        if (d.exist()) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
        
        scanner.close();
    }

    // Function to read a specified number of strings from standard input and return them as an array of strings
    private static String[] load(Scanner scanner, int cnt) {
        String[] ret = new String[cnt];
        for (int i = 0; i < cnt; i++) {
            ret[i] = scanner.nextLine(); // Read each string from standard input
        }
        return ret;
    }
}

// <END-OF-CODE>

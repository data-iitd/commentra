import java.util.Scanner;

// Define a custom data structure
class Data {
    int n, m; // dimensions of the images
    String[] nImg, mImg; // image data as strings

    // Constructor to initialize the data object
    public Data(int n, int m, String[] nImg, String[] mImg) {
        this.n = n;
        this.m = m;
        this.nImg = nImg;
        this.mImg = mImg;
    }

    // Check if data already exists in the larger image
    public boolean exist() {
        // Iterate through all possible positions in larger image
        for (int i = 0; i <= n - m; i++) {
            for (int j = 0; j <= n - m; j++) {
                // Check if current position matches the smaller image
                if (match(i, j)) {
                    // If match is found, return true
                    return true;
                }
            }
        }
        // If no match is found, return false
        return false;
    }

    // Check if smaller image matches at current position in larger image
    public boolean match(int x, int y) {
        // Iterate through each pixel in smaller image
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                // Check if corresponding pixel in larger image matches
                if (nImg[x + i].charAt(y + j) != mImg[i].charAt(j)) {
                    // If mismatch is found, return false
                    return false;
                }
            }
        }
        // If all pixels match, return true
        return true;
    }
}

// Main class
public class Main {
    public static void main(String[] args) {
        // Initialize a new data object
        Data d = newData();
        // Check if data already exists
        if (d.exist()) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }

    // Initialize a new data object
    public static Data newData() {
        Scanner scanner = new Scanner(System.in);
        // Read dimensions from user input
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        scanner.nextLine(); // Consume the newline

        // Load image data as strings
        String[] nImg = load(scanner, n);
        String[] mImg = load(scanner, m);

        // Initialize data object with loaded data
        return new Data(n, m, nImg, mImg);
    }

    // Load image data as strings
    public static String[] load(Scanner scanner, int cnt) {
        // Allocate memory for image data
        String[] ret = new String[cnt];
        // Read image data from user input
        for (int i = 0; i < cnt; i++) {
            ret[i] = scanner.nextLine();
        }
        // Return loaded image data
        return ret;
    }
}

// <END-OF-CODE>

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

// Main function
public class Main {
    public static void main(String[] args) {
        // Read dimensions from user input
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        // Load image data as strings
        String[] nImg = new String[n];
        String[] mImg = new String[m];
        for (int i = 0; i < n; i++) {
            nImg[i] = scanner.next();
        }
        for (int i = 0; i < m; i++) {
            mImg[i] = scanner.next();
        }

        // Initialize data object with loaded data
        Data data = new Data(n, m, nImg, mImg);

        // Check if data already exists
        if (data.exist()) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}



import java.util.Scanner;

// Define a custom data structure
class Data {
    int n, m;
    String[] nImg, mImg;

    // s864554008 function
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
    private static Data newData() {
        // Read dimensions from user input
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        // Load image data as strings
        String[] nImg = load(n);
        String[] mImg = load(m);

        // Initialize data object with loaded data
        return new Data(n, m, nImg, mImg);
    }

    // Load image data as strings
    private static String[] load(int cnt) {
        // Allocate memory for image data
        String[] ret = new String[cnt];
        // Read image data from user input
        Scanner scanner = new Scanner(System.in);
        for (int i = 0; i < cnt; i++) {
            ret[i] = scanner.next();
        }

        // Return loaded image data
        return ret;
    }

    // Check if data already exists in the larger image
    private boolean exist() {
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
    private boolean match(int x, int y) {
        // Iterate through each pixel in smaller image
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                // Check if corresponding pixel in larger image matches
                if (!nImg[x + i].equals(mImg[i].charAt(j))) {
                    // If mismatch is found, return false
                    return false;
                }
            }
        }

        // If all pixels match, return true
        return true;
    }
}

// END-OF-CODE
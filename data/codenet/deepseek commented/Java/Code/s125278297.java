
import java.util.*;

public class Main {
    static Scanner scanner = new Scanner(System.in); // Importing Scanner for input

    public static void main(String[]$) {
        int h = scanner.nextInt(); // Reading the height of the rectangle
        int w = scanner.nextInt(); // Reading the width of the rectangle
        String[] ans = new String[h]; // Creating an array to store the input lines with borders

        // Looping to read input and add borders
        for (int i = 0; i < h; i++) {
            ans[i] = "#" + scanner.next() + "#"; // Reading each line and adding borders
        }

        // Printing the top border of the rectangle
        System.out.println(String.valueOf(new char[w + 2]).replace('\0', '#'));

        // Printing each line from the array with borders
        for (String s : ans) {
            System.out.println(s);
        }

        // Printing the bottom border of the rectangle
        System.out.println(String.valueOf(new char[w + 2]).replace('\0', '#'));
    }
}


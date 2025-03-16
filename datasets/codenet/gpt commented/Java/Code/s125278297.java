import java.util.*;

public class Main {
    // Create a Scanner object for reading input
    static Scanner scanner = new Scanner(System.in);

    public static void main(String[]$) {
        // Read the height (h) and width (w) of the rectangle from input
        int h = scanner.nextInt();
        int w = scanner.nextInt();
        
        // Initialize an array to hold the strings that represent each row of the rectangle
        String[] ans = new String[h];
        
        // Loop through each row to read the input strings and format them with '#' on both sides
        for (int i = 0; i < h; i++) {
            ans[i] = "#" + scanner.next() + "#"; // Add '#' to the beginning and end of each input string
        }
        
        // Print the top border of the rectangle, which consists of '#' characters
        System.out.println(String.valueOf(new char[w + 2]).replace('\0', '#'));
        
        // Print each formatted row of the rectangle
        for (String s : ans) {
            System.out.println(s);
        }
        
        // Print the bottom border of the rectangle, which is the same as the top border
        System.out.println(String.valueOf(new char[w + 2]).replace('\0', '#'));
    }
}

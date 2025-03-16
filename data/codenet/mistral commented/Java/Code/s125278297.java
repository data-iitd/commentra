
import java.util.*;

public class Main {
    static Scanner scanner = new Scanner(System.in); // Initialize Scanner for reading input

    public static void main(String[] args) {
        int height = scanner.nextInt(); // Read the height of the grid from the input
        int width = scanner.nextInt(); // Read the width of the grid from the input

        String[] answer = new String[height]; // Initialize an array of strings to store each row of the grid

        for (int i = 0; i < height; i++) { // Iterate through each row of the grid
            answer[i] = "#" + scanner.next() + "#"; // Read the row data from the input and add '#' at the beginning and end
        }

        System.out.println(new String(new char[width + 2]).replace('\0', '#')); // Print the top border of the grid

        for (String row : answer) { // Iterate through each row of the grid and print it
            System.out.println(row);
        }

        System.out.println(new String(new char[width + 2]).replace('\0', '#')); // Print the bottom border of the grid
    }
}


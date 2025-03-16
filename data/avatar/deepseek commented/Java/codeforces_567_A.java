import java.util.Scanner; // Importing Scanner class for taking input from the user
import javax.swing.JOptionPane; // Importing JOptionPane for displaying graphical dialogs (not used in this code)

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in); // Creating a Scanner object to read input from the user
        int a = s.nextInt(); // Reading the size of the array from the user
        int ar[] = new int[a]; // Initializing the array with the size read from the user
        int max = 0, min = 0; // Initializing max and min to 0

        // Filling the array with integers read from the user
        for (int i = 0; i < ar.length; i++) {
            ar[i] = s.nextInt();
        }

        // Calculating the minimum and maximum differences between consecutive elements of the array
        for (int i = 0; i < ar.length; i++) {
            max = Math.max(ar[i] - ar[0], ar[ar.length - 1] - ar[i]); // Calculating the maximum difference
            if (i == 0) {
                min = ar[i + 1] - ar[i]; // Calculating the minimum difference for the first element
            } else if (i == ar.length - 1) {
                min = ar[i] - ar[i - 1]; // Calculating the minimum difference for the last element
            } else {
                min = Math.min(ar[i] - ar[i - 1], ar[i + 1] - ar[i]); // Calculating the minimum difference for other elements
            }
            System.out.println(min + " " + max); // Displaying the minimum and maximum differences
        }
    }
}

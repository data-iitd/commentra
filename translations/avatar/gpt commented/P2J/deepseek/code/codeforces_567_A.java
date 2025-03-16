import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read an integer input (not used later in the code)
        int inp = scanner.nextInt();

        // Initialize an empty list to store integers
        List<Integer> lista = new ArrayList<>();

        // Read a line of input, split it into strings, convert each string to an integer, and store it in lista
        Scanner lineScanner = new Scanner(scanner.nextLine().trim());
        while (lineScanner.hasNext()) {
            lista.add(lineScanner.nextInt());
        }

        // Iterate through the indices of the lista
        for (int i = 0; i < lista.size(); i++) {
            // Handle the first element in the list
            if (i == 0) {
                // Calculate and print the difference between the second and first elements,
                // and the difference between the last and first elements
                System.out.println((lista.get(i + 1) - lista.get(i)) + " " + (lista.get(lista.size() - 1) - lista.get(i)));
                continue; // Skip to the next iteration
            }

            // Handle the last element in the list
            else if (i == lista.size() - 1) {
                // Calculate and print the difference between the last and second-to-last elements,
                // and the difference between the last and the first elements
                System.out.println((lista.get(lista.size() - 1) - lista.get(lista.size() - 2)) + " " + (lista.get(lista.size() - 1) - lista.get(0)));
                continue; // Skip to the next iteration
            }

            // For elements in the middle of the list
            else if (lista.get(i) - lista.get(i - 1) > lista.get(i + 1) - lista.get(i)) {
                // If the difference to the next element is smaller, print that difference
                System.out.print((lista.get(i + 1) - lista.get(i)) + " ");
            } else {
                // Otherwise, print the difference to the previous element
                System.out.print((lista.get(i) - lista.get(i - 1)) + " ");
            }

            // Compare the difference to the last element with the difference to the first element
            if (lista.get(lista.size() - 1) - lista.get(i) > lista.get(i) - lista.get(0)) {
                // If the difference to the last element is larger, print that difference
                System.out.println(lista.get(lista.size() - 1) - lista.get(i));
            } else {
                // Otherwise, print the difference to the first element
                System.out.println(lista.get(i) - lista.get(0));
            }
        }
    }
}

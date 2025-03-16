import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Take an integer input from the user
        int inp = scanner.nextInt();
        
        // Create a list to store the input integers
        List<Integer> lista = new ArrayList<>();
        
        // Populate the list 'lista' with integers input by the user, separated by spaces
        for (int i = 0; i < inp; i++) {
            lista.add(scanner.nextInt());
        }
        
        // Iterate through each index 'i' in the list 'lista'
        for (int i = 0; i < lista.size(); i++) {
            // If 'i' is the first index
            if (i == 0) {
                // Print the difference between the second and first elements and the difference between the last and first elements
                System.out.print((lista.get(i + 1) - lista.get(i)) + " " + (lista.get(lista.size() - 1) - lista.get(i)));
                System.out.println();
                continue;
            }
            
            // If 'i' is the last index
            else if (i == lista.size() - 1) {
                // Print the difference between the last and second last element and the difference between the last and first element
                System.out.print((lista.get(lista.size() - 1) - lista.get(lista.size() - 2)) + " " + (lista.get(lista.size() - 1) - lista.get(0)));
                System.out.println();
                continue;
            }
            
            // If the difference between the current index and the previous index is greater than the difference between the next index and the current index
            else if (lista.get(i) - lista.get(i - 1) > lista.get(i + 1) - lista.get(i)) {
                // Print the difference between the next index and the current index
                System.out.print((lista.get(i + 1) - lista.get(i)) + " ");
            }
            // If the difference between the current index and the previous index is less than or equal to the difference between the next index and the current index
            else {
                // Print the difference between the current index and the previous index and the difference between the current index and the first index
                System.out.print((lista.get(i) - lista.get(i - 1)) + " ");
                if (lista.get(lista.size() - 1) - lista.get(i) > lista.get(i) - lista.get(0)) {
                    System.out.println(lista.get(lista.size() - 1) - lista.get(i));
                } else {
                    System.out.println(lista.get(i) - lista.get(0));
                }
            }
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>

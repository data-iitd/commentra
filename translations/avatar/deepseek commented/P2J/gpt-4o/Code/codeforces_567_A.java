import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int inp = scanner.nextInt();  // Taking an integer input from the user
        int[] lista = new int[inp];  // Creating an array to hold the integers
        
        // Converting the input string into an array of integers
        for (int i = 0; i < inp; i++) {
            lista[i] = scanner.nextInt();
        }
        
        // Iterating through the array of integers
        for (int i = 0; i < lista.length; i++) {
            // For the first element in the array
            if (i == 0) {
                System.out.print((lista[i + 1] - lista[i]) + " " + (lista[lista.length - 1] - lista[i]));  // Printing the differences
                System.out.println();  // Move to the next line
                continue;
            }
            // For the last element in the array
            else if (i == lista.length - 1) {
                System.out.print((lista[lista.length - 1] - lista[lista.length - 2]) + " " + (lista[lista.length - 1] - lista[0]));  // Printing the differences
                System.out.println();  // Move to the next line
                continue;
            }
            // For other elements in the array
            else if (lista[i] - lista[i - 1] > lista[i + 1] - lista[i]) {
                System.out.print((lista[i + 1] - lista[i]) + " ");  // Printing the difference between the next and current integer
            } else {
                System.out.print((lista[i] - lista[i - 1]) + " ");  // Printing the difference between the current and previous integer
            }
            // Printing the difference between the last and current integer or the first and current integer
            if (lista[lista.length - 1] - lista[i] > lista[i] - lista[0]) {
                System.out.println(lista[lista.length - 1] - lista[i]);  // Printing the difference between the last and current integer
            } else {
                System.out.println(lista[i] - lista[0]);  // Printing the difference between the first and current integer
            }
        }
        
        scanner.close();  // Closing the scanner
    }
}

// <END-OF-CODE>

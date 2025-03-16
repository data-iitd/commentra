

import java.util.Scanner;

public class codeforces_567_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int inp = scanner.nextInt();  // Taking an integer input from the user
        int[] lista = new int[inp];
        for (int i = 0; i < inp; i++) {
            lista[i] = scanner.nextInt();  // Storing the input integers in an array
        }
        scanner.close();

        // Iterating through the array of integers
        for (int i = 0; i < inp; i++) {
            // For the first element in the array
            if (i == 0) {
                System.out.print((lista[i + 1] - lista[i]) + " " + (lista[inp - 1] - lista[i]));  // Printing the differences
                continue;
            }
            // For the last element in the array
            if (i == inp - 1) {
                System.out.print((lista[inp - 1] - lista[inp - 2]) + " " + (lista[inp - 1] - lista[0]));  // Printing the differences
                continue;
            }
            // For other elements in the array
            if (lista[i] - lista[i - 1] > lista[i + 1] - lista[i]) {
                System.out.print((lista[i + 1] - lista[i]) + " ");  // Printing the difference between the next and current integer
            } else {
                System.out.print((lista[i] - lista[i - 1]) + " ");  // Printing the difference between the current and previous integer
            }
            // Printing the difference between the last and current integer or the first and current integer
            if (lista[inp - 1] - lista[i] > lista[i] - lista[0]) {
                System.out.println(lista[inp - 1] - lista[i]);  // Printing the difference between the last and current integer
            } else {
                System.out.println(lista[i] - lista[0]);  // Printing the difference between the first and current integer
            }
        }
    }
}

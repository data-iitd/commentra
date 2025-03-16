import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Assigning the values of input variables to n, a, and b
        int n = scanner.nextInt();
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        
        // Creating two arrays, lista and listb, from the input
        int[] lista = new int[a];
        for (int i = 0; i < a; i++) {
            lista[i] = scanner.nextInt();
        }
        
        int[] listb = new int[b];
        for (int i = 0; i < b; i++) {
            listb[i] = scanner.nextInt();
        }
        
        // Iterating through the range of n
        for (int k = 0; k < n; k++) {
            boolean found = false;
            // Checking if k+1 is present in the lista array
            for (int value : lista) {
                if (value == k + 1) {
                    found = true;
                    break;
                }
            }
            // Printing 1 if k+1 is present in the lista array
            if (found) {
                System.out.print(1 + " ");
            } else {
                // Printing 2 if k+1 is not present in the lista array
                System.out.print(2 + " ");
            }
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Step 1: Take two integers as input and assign them to x and y.
        int x = scanner.nextInt();
        int y = scanner.nextInt();
        
        // Step 2: Calculate the maximum value between x + y - 3 and 0, with an additional condition based on (y - x) % 3.
        int result = Math.max(x + y - 3 + ((y - x) % 3 > 0 ? 1 : 0), 0);
        System.out.println(result);
        
        // Step 3: Define methods for taking different types of inputs.
        // num_inp
        int numInp() {
            return scanner.nextInt();
        }
        
        // arr_inp
        int[] arrInp() {
            int n = scanner.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = scanner.nextInt();
            }
            return arr;
        }
        
        // sp_inp
        int[] spInp() {
            return new int[] {scanner.nextInt(), scanner.nextInt()}; // Example for two integers
        }
        
        // str_inp
        String strInp() {
            return scanner.next();
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>

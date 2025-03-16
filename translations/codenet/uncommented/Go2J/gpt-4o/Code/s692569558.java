import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the first line (not used)
        scanner.nextLine();
        
        // Read the second line
        String ds = scanner.nextLine();
        
        // Split the input string into an array of strings
        String[] dd = ds.split(" ");
        int[] dn = new int[dd.length];
        
        // Convert the string array to an integer array
        for (int i = 0; i < dd.length; i++) {
            dn[i] = Integer.parseInt(dd[i]);
        }
        
        // Calculate the sum of products
        int sum = 0;
        for (int i = 0; i < dn.length; i++) {
            for (int j = i + 1; j < dn.length; j++) {
                sum += dn[i] * dn[j];
            }
        }
        
        // Print the result
        System.out.println(sum);
        
        scanner.close();
    }
}

// <END-OF-CODE>

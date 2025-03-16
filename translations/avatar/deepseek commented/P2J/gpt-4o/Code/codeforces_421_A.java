import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // The first line takes three integers n, a, and b as input, separated by spaces.
        int n = scanner.nextInt();
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        
        // The second line takes a list of integers lista as input, separated by spaces.
        int[] lista = new int[n];
        for (int i = 0; i < n; i++) {
            lista[i] = scanner.nextInt();
        }
        
        // The third line takes a list of integers listb as input, separated by spaces.
        int[] listb = new int[n];
        for (int i = 0; i < n; i++) {
            listb[i] = scanner.nextInt();
        }
        
        // Convert lista to a Set for faster lookup
        java.util.HashSet<Integer> set = new java.util.HashSet<>();
        for (int num : lista) {
            set.add(num);
        }
        
        // The for loop iterates over the range n.
        for (int k = 0; k < n; k++) {
            // If the current index k + 1 is in the list lista,
            if (set.contains(k + 1)) {
                // print 1 to the console.
                System.out.print(1 + " ");
            } else {
                // Otherwise,
                // print 2 to the console.
                System.out.print(2 + " ");
            }
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Reading input
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[] a = new int[N];
        
        for (int i = 0; i < N; i++) {
            a[i] = scanner.nextInt();
        }
        
        // Calculating the XOR of all elements in the array 'a'
        int total = 0;
        for (int num : a) {
            total ^= num;
        }
        
        // Printing the result
        StringBuilder result = new StringBuilder();
        for (int num : a) {
            result.append(num ^ total).append(" ");
        }
        
        System.out.println(result.toString().trim());
        
        scanner.close();
    }
}
// <END-OF-CODE>

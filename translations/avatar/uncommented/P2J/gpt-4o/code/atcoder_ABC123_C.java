import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int N = scanner.nextInt();
        int[] A = new int[5];
        
        for (int i = 0; i < 5; i++) {
            A[i] = scanner.nextInt();
        }
        
        int minA = A[0];
        for (int i = 1; i < A.length; i++) {
            if (A[i] < minA) {
                minA = A[i];
            }
        }
        
        int result = (int) Math.ceil((double) N / minA) + 4;
        System.out.println(result);
        
        scanner.close();
    }
}
// <END-OF-CODE>

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int minA = (int) Math.pow(10, 9) + 1;
        int num = 0;
        
        int n = scanner.nextInt();
        int t = scanner.nextInt();
        int[] A = new int[n];
        
        for (int i = 0; i < n; i++) {
            A[i] = scanner.nextInt();
        }
        
        int f = 0;
        for (int i = 0; i < n; i++) {
            if (minA > A[i]) {
                minA = A[i];
            } else {
                if (f == A[i] - minA) {
                    num++;
                } else if (f < A[i] - minA) {
                    num = 1;
                    f = A[i] - minA;
                }
            }
        }
        
        System.out.println(num);
        scanner.close();
    }
}

// <END-OF-CODE>

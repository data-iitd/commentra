import java.util.Scanner;

public class Main {
    public static int task4(int A, int B, int n) {
        for (int X = -1000; X <= 1000; X++) {
            if (A * Math.pow(X, n) == B) {
                return X;
            }
        }
        return Integer.MIN_VALUE; // Indicating no solution
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] input = scanner.nextLine().split(" ");
        int A = Integer.parseInt(input[0]);
        int B = Integer.parseInt(input[1]);
        int n = Integer.parseInt(input[2]);
        
        int result = task4(A, B, n);
        if (result == Integer.MIN_VALUE) {
            System.out.println("No solution");
        } else {
            System.out.println(result);
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>

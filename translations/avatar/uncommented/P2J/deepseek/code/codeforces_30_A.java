import java.util.Scanner;

public class Task4 {
    public static int task4(int A, int B, int n) {
        for (int X = -1000; X <= 1001; X++) {
            if (A * Math.pow(X, n) == B) {
                return X;
            }
        }
        return -1; // Changed "No solution" to -1 to indicate no solution
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] input = scanner.nextLine().split(" ");
        int A = Integer.parseInt(input[0]);
        int B = Integer.parseInt(input[1]);
        int n = Integer.parseInt(input[2]);
        System.out.println(task4(A, B, n));
    }
}

public class Task4 {
    public static int task4(int A, int B, int n) {
        for (int X = -1000; X <= 1000; X++) {
            if (A * Math.pow(X, n) == B) {
                return X;
            }
        }
        return -1; // Return -1 to indicate no solution
    }

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int A = scanner.nextInt();
        int B = scanner.nextInt();
        int n = scanner.nextInt();
        int result = task4(A, B, n);
        if (result == -1) {
            System.out.println("No solution");
        } else {
            System.out.println(result);
        }
    }
}

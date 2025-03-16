public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int K = scanner.nextInt();
        int X = scanner.nextInt();
        
        // Loop from X-K+1 to X+K-1
        for (int i = X - K + 1; i <= X + K - 1; i++) {
            System.out.print(i);
            // Print a space after each number except the last one
            if (i < X + K - 1) System.out.print(" ");
        }
        // Print a newline character to move to the next line
        System.out.println();
    }
}

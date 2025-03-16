public class Main {
    public static void main(String[] args) {
        // Declare variables
        int[] x = new int[10000];
        int i = 0;

        // Read the first input value into the array
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        x[i] = scanner.nextInt();

        // Continue reading input values until a zero is encountered
        while (x[i] != 0) {
            i++;
            x[i] = scanner.nextInt();
        }

        // Print the case number and the corresponding value from the array
        for (int j = 0; j < i; j++) {
            System.out.println("Case " + (j + 1) + ": " + x[j]);
        }
    }
}

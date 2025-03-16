public class Main {
    public static void main(String[] args) {
        int A, B;
        int ans = 0;
        int out = 1; // Initialize out to 1

        java.util.Scanner scanner = new java.util.Scanner(System.in);
        A = scanner.nextInt(); // Read the first integer A from the standard input
        B = scanner.nextInt(); // Read the second integer B from the standard input

        while (out < B) { // Continue the loop as long as out is less than B
            out--; // Decrement out by 1
            out += A; // Increment out by A
            ans++; // Increment ans by 1
        }
        System.out.println(ans); // Print the value of ans to the standard output
    }
}

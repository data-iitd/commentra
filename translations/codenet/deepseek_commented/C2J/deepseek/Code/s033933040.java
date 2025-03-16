public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in); // Step 1: Initialize the scanner
        int a = scanner.nextInt(); // Step 2: Read input value for a
        int b = scanner.nextInt(); // Step 3: Read input value for b
        int mawari = 2 * (a + b); // Step 4: Calculate mawari
        int menseki = a * b; // Step 5: Calculate menseki
        System.out.println(menseki + " " + mawari); // Step 6: Print the results
    }
}

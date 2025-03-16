import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Take the number of test cases as input
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume the newline

        // Read the first list 'a' of numbers from the standard input
        String[] aInput = scanner.nextLine().split(" ");
        int[] a = new int[aInput.length];
        for (int i = 0; i < aInput.length; i++) {
            a[i] = Integer.parseInt(aInput[i]);
        }

        // Read the second list 'b' of numbers from the standard input
        String[] bInput = scanner.nextLine().split(" ");
        int[] b = new int[bInput.length];
        for (int i = 0; i < bInput.length; i++) {
            b[i] = Integer.parseInt(bInput[i]);
        }

        // Read the third list 'c' of numbers from the standard input
        String[] cInput = scanner.nextLine().split(" ");
        int[] c = new int[cInput.length];
        for (int i = 0; i < cInput.length; i++) {
            c[i] = Integer.parseInt(cInput[i]);
        }

        // Initialize variables x, y, and z to 0
        int x = 0;
        int y = 0;
        int z = 0;

        // Iterate through each number in list 'a' and add it to the variable 'x'
        for (int i : a) {
            x += i;
        }

        // Iterate through each number in list 'b' and add it to the variable 'y'
        for (int i : b) {
            y += i;
        }

        // Iterate through each number in list 'c' and add it to the variable 'z'
        for (int i : c) {
            z += i;
        }

        // Print the absolute difference between 'x' and 'y'
        System.out.println(Math.abs(x - y));

        // Print the absolute difference between 'y' and 'z'
        System.out.println(Math.abs(y - z));

        scanner.close();
    }
}
// <END-OF-CODE>

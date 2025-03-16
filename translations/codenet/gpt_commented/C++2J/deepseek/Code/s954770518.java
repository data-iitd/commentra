public class Main {
    public static void main(String[] args) {
        // Declare an array to hold 10 integers
        int[] s = new int[10];
        int i;

        // Input 10 integers from the user
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        for(i = 0; i < 10; i++) {
            s[i] = scanner.nextInt();
        }

        // Sort the array of integers in ascending order
        java.util.Arrays.sort(s);

        // Print the three largest integers from the sorted array
        for(i = 9; i > 6; i--) {
            System.out.println(s[i]);
        }
    }
}

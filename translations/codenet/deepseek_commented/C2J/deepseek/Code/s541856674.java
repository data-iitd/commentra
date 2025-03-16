public class Main {
    public static void main(String[] args) {
        int N = 0; // Step 3: Declare variables
        int R = 0;

        java.util.Scanner scanner = new java.util.Scanner(System.in); // Step 4: Read input values
        N = scanner.nextInt();
        R = scanner.nextInt();

        if(N >= 10) { // Step 5: Implement conditional logic
            System.out.println(R); // If true, print the value of R
        } else {
            System.out.println(R + 100*(10-N)); // Otherwise, calculate and print the adjusted value of R
        }
    }
}

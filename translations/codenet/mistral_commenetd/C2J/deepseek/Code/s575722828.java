public class Main {
    public static void main(String[] args) {
        int S; // Declare an integer variable named S

        // Initialize an integer variable named S with a value read from the standard input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        S = scanner.nextInt();

        // Print the hours, minutes, and seconds of the given number of seconds
        System.out.println(S / 3600 + ":" + (S % 3600) / 60 + ":" + S % 60);

        // Return 0 to indicate successful execution of the program
    }
}

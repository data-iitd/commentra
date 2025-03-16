import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from stdin
        Scanner sc = new Scanner(System.in);

        // Read an integer input from the user representing seconds
        int S = sc.nextInt();

        // Check if the input seconds are less than 60
        if (S < 60) {
            // If less than 60 seconds, print the time in the format 0:0:seconds
            System.out.printf("0:0:%d\n", S);
        }
        // Check if the input seconds are less than 3600 (1 hour)
        else if (S < 3600) {
            // If less than 1 hour, print the time in the format 0:minutes:seconds
            System.out.printf("0:%d:%d\n", S / 60, S % 60);
        }
        // If the input seconds are 3600 or more (1 hour or more)
        else {
            // Print the time in the format hours:minutes:seconds
            System.out.printf("%d:%d:%d\n", S / 3600, S % 3600 / 60, S % 60);
        }
    }
}

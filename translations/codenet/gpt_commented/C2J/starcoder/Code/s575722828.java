import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Declare an integer variable to store the total seconds
        int S;

        // Read the total seconds from user input
        Scanner sc = new Scanner(System.in);
        S = sc.nextInt();

        // Calculate hours, minutes, and seconds from the total seconds
        // and print them in the format HH:MM:SS
        System.out.printf("%d:%d:%d\n", 
                (int)(S / 3600),                // Calculate hours
                (int)((S % 3600) / 60),        // Calculate minutes
                S % 60);                       // Calculate remaining seconds
    }
}

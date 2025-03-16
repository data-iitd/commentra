
import java.util.Scanner; // Step 1: Import necessary classes

public class Main {
    public static void main(String[] args) { // Step 2: Define the main function
        Scanner sc = new Scanner(System.in); // Step 3: Create a Scanner object to read input from the user

        int S = sc.nextInt(); // Step 4: Read an integer value from the user and store it in S

        System.out.printf("%d:%d:%d\n", S / 3600, (S % 3600) / 60, S % 60); // Step 5: Calculate hours, minutes, and seconds from the total seconds S
                                                                            // Step 6: Print the calculated hours, minutes, and seconds in the format "HH:MM:SS"
    }
}


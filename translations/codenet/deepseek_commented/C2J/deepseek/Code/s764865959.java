import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Step 2: Create a Scanner object to read input.
        int x = scanner.nextInt(); // Step 3: Read an integer value from the user and store it in x.
        x = x * x * x; // Step 4: Calculate the cube of the value stored in x.
        System.out.println(x); // Step 5: Print the result.
    }
}


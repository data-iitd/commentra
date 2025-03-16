import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the first line from standard input
        String sage = scanner.nextLine();

        // Use a switch statement to determine the action based on the first line read
        switch (sage) {
            case "1":
                // Print "Hello World" if the first line is "1"
                System.out.println("Hello World");
                break;
            case "2":
                // Initialize a variable named 'sum' to store the sum of two numbers
                int sum = 0;

                // Use a for loop to read and sum two numbers
                for (int i = 0; i < 2; i++) {
                    // Read the next line from standard input
                    String numStr = scanner.nextLine();

                    // Convert the next line to an integer and store it in a variable named 'num'
                    int num = Integer.parseInt(numStr);

                    // Add the current number to the sum
                    sum += num;
                }

                // Print the sum of the two numbers
                System.out.println(sum);
                break;
        }
    }
}


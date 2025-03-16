import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Prompt the user for input and read the input string
        String userInput = scanner.nextLine();

        // Replace all commas in the input string with spaces
        String modifiedInput = userInput.replace(",", " ");

        // Print the modified input string
        System.out.println(modifiedInput);
    }
}

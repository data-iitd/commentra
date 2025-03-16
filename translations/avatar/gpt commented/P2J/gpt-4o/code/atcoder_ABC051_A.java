import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Prompt the user for input
        Scanner scanner = new Scanner(System.in);
        String userInput = scanner.nextLine();

        // Replace all commas in the input string with spaces
        String modifiedInput = userInput.replace(",", " ");

        // Print the modified input string
        System.out.println(modifiedInput);
        
        scanner.close();
    }
}

// <END-OF-CODE>

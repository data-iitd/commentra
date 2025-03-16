import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String stdin = scanner.nextLine();  // Take input from the user and store it in the variable stdin
        String s = stdin;  // Assign the input to the variable s

        // Check if the string s contains both "A" and "B"
        String result = (s.contains("A") && s.contains("B")) ? "Yes" : "No";

        System.out.println(result);  // Print the result
    }
}


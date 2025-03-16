import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Read a string from the standard input and store it in the variable 's'.
        String s = scanner.nextLine();
        // Replace all occurrences of "2017" with "2018" in the string 's' and print the result.
        System.out.println(s.replace("2017", "2018"));
        scanner.close();
    }
}

// <END-OF-CODE>

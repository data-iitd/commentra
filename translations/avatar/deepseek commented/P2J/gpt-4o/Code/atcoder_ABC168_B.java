import java.util.Scanner;

public class Main {
    public static String mainFunction() {
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Read the value of K from the user
        int K = Integer.parseInt(scanner.nextLine());
        
        // Read the string S from the user
        String S = scanner.nextLine();
        
        // Check if the length of S is less than or equal to K
        if (S.length() <= K) {
            // If the length of S is less than or equal to K, return S as it is
            return S;
        }
        
        // If the length of S is greater than K, return the first K characters of S followed by '...'
        return S.substring(0, K) + "...";
    }

    public static void main(String[] args) {
        // Print the result of the main function
        System.out.println(mainFunction());
    }
}

// <END-OF-CODE>

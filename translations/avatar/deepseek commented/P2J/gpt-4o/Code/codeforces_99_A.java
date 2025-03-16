import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Taking an input from the user
        String l = scanner.nextLine();
        
        // Splitting the input into a list of strings separated by a period (.)
        String[] parts = l.split("\\.");
        
        // Converting the first part of the split input into a list of characters
        char[] s = parts[0].toCharArray();
        
        // Converting the second part of the split input into a list of characters
        char[] p = parts[1].toCharArray();
        
        // Converting the first character of the second part into an integer
        int i = Character.getNumericValue(p[0]);
        
        // Checking if the last character of the first part is '9'
        if (s[s.length - 1] == '9') {
            System.out.println("GOTO Vasilisa.");  // Printing "GOTO Vasilisa." if the last character is '9'
        }
        // Checking if the last character of the first part is not '9' and the integer from the second part is less than 5
        else if (s[s.length - 1] != '9' && i < 5) {
            System.out.println(new String(s));  // Printing the joined string
        }
        // If the last character of the first part is not '9' and the integer from the second part is 5 or more
        else {
            String incrementedString = String.valueOf(Integer.parseInt(new String(s)) + 1);  // Incrementing the first part by 1
            System.out.println(incrementedString);  // Printing the incremented string
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>

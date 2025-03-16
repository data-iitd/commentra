import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        
        // Split the input string into two parts using '.' as the delimiter
        String[] parts = input.split("\\.");
        
        // Extract the first part and convert it to a character array
        char[] s = parts[0].toCharArray();
        
        // Extract the second part and get the first character, convert it to an integer
        int i = Character.getNumericValue(parts[1].charAt(0));
        
        // Check if the last character of the first part is '9'
        if (s[s.length - 1] == '9') {
            // If it is '9', print the message "GOTO Vasilisa."
            System.out.println("GOTO Vasilisa.");
        } else if (s[s.length - 1] != '9' && i < 5) {
            // If both conditions are true, print the first part as a string
            System.out.println(new String(s));
        } else {
            // If the last character is not '9' and i is 5 or more
            // Convert the first part to an integer, increment it by 1, and convert it back to a string
            int num = Integer.parseInt(parts[0]);
            num += 1;
            System.out.println(num);
        }
    }
}

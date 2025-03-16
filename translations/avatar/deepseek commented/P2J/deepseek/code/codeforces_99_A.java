import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String l = scanner.nextLine();  // Taking an input from the user
        String[] parts = l.split("\\.");  // Splitting the input into an array of strings separated by a period (.)
        char[] s = parts[0].toCharArray();  // Converting the first part of the split input into a list of characters
        char[] p = parts[1].toCharArray();  // Converting the second part of the split input into a list of characters
        int i = p[0] - '0';  // Converting the first character of the second part into an integer

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
            int num = Integer.parseInt(parts[0]);  // Converting the first part to an integer
            num += 1;  // Incrementing the first part by 1
            System.out.println(num);  // Printing the incremented integer
        }
    }
}

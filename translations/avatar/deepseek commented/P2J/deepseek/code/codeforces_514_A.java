import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String ip = scanner.nextLine();  // Taking an input from the user and storing it in the variable `ip`.
        String st = "";  // Initializing an empty string `st`.
        if (ip.length() != 1) {  // Checking if the length of the input `ip` is not equal to 1.
            if (ip.charAt(0) == '9') {  // Checking if the first character of `ip` is "9".
                st = "9";  // Assigning "9" to `st`.
                ip = ip.substring(1);  // Removing the first character from `ip`.
            }
            for (int i = 0; i < ip.length(); i++) {  // Iterating over the remaining characters in `ip`.
                int n = ip.charAt(i) - '0';  // Converting the character to its integer value.
                if (n > 4) {  // Checking if the integer value is greater than 4.
                    n = 9 - n;  // Calculating the difference between 9 and the integer value.
                    st += String.valueOf(n);  // Converting it to a string and appending it to `st`.
                } else {  // If the integer value is not greater than 4.
                    st += ip.charAt(i);  // Simply appending the character to `st`.
                }
            }
        } else {  // If the length of `ip` is 1.
            st = ip;  // Assigning `ip` directly to `st`.
        }
        System.out.println(Integer.parseInt(st));  // Printing the integer value of `st`.
    }
}

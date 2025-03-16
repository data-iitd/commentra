import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String str = scanner.nextLine();
        
        // Convert the string to a character array to modify specific indices
        char[] charArray = str.toCharArray();
        
        // Modify the specified indices
        if (charArray.length > 5) {
            charArray[5] = ' ';
        }
        if (charArray.length > 13) {
            charArray[13] = ' ';
        }
        
        // Convert back to string and print
        String modifiedStr = new String(charArray);
        System.out.println(modifiedStr);
        
        scanner.close();
    }
}

// <END-OF-CODE>

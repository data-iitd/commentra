
import java.util.Scanner;

public class s844285682{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt(); // Take an integer input from the user and store it in variable a
        
        System.out.println(a/(60*60) + ":" + a%(60*60)/60 + ":" + a%(60*60)%60); // Calculate and output the hours, minutes, and seconds
        
        scanner.close(); // Close the scanner
    }
}
// 
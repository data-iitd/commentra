
import java.util.Scanner;  // Importing the Scanner class for user input.

public class codeforces_379_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);  // Creating a Scanner object to read user input.
        
        // Taking two integer inputs and assigning them to candeleIntere and b.
        int candeleIntere = scanner.nextInt();
        int b = scanner.nextInt();
        
        // Initializing the sum variable s and the remainder variable restoSciolte to 0.
        int s = 0;
        int restoSciolte = 0;
        
        // Starting a while loop that continues as long as candeleIntere is greater than 0 or restoSciolte is greater than or equal to b.
        while (candeleIntere > 0 || restoSciolte >= b) {
            // Updating candeleIntere by adding the integer division of restoSciolte by b.
            candeleIntere += restoSciolte / b;
            
            // Updating restoSciolte to be the remainder of the division of restoSciolte by b.
            restoSciolte %= b;
            
            // Adding candeleIntere to s.
            s += candeleIntere;
            
            // Updating restoSciolte by adding the remainder of candeleIntere divided by b.
            restoSciolte += candeleIntere % b;
            
            // Updating candeleIntere by performing integer division of candeleIntere by b.
            candeleIntere /= b;
        }
        
        // Printing the value of s after the loop completes.
        System.out.println(s);
    }
}

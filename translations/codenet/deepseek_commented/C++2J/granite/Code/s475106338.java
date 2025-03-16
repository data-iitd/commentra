
import java.util.Scanner;

public class s475106338{
    public static void main(String[] args) {
        // Declare variables to store loop index, transaction type, and number of items
        int i, t, n;

        // Create a Scanner object to read input from standard input
        Scanner scanner = new Scanner(System.in);

        // Loop through four transactions
        for(i = 0; i < 4; i++){
            // Read the transaction type and number of items from standard input
            t = scanner.nextInt();
            n = scanner.nextInt();

            // Check the transaction type and calculate the total cost
            if(t == 1){
                System.out.println(6000 * n); // If transaction type is 1, calculate cost for 6000 per item
            }
            else if(t == 2){
                System.out.println(4000 * n); // If transaction type is 2, calculate cost for 4000 per item
            }
            else if(t == 3){
                System.out.println(3000 * n); // If transaction type is 3, calculate cost for 3000 per item
            }
            else if(t == 4){
                System.out.println(2000 * n); // If transaction type is 4, calculate cost for 2000 per item
            }
        }

        // Close the Scanner object
        scanner.close();
    }
}

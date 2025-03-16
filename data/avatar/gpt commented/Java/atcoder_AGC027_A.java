import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in);
        
        // Read the number of sweet items (N) and the initial amount of money (x)
        int N = sc.nextInt();
        long x = sc.nextInt();
        
        // Initialize a list to store the sweetness values of the items
        List<Long> sweet = new ArrayList<Long>();
        
        // Read the sweetness values and add them to the list
        for (int i = 0; i < N; i++) {
            long a = sc.nextInt();
            sweet.add(a);
        }
        
        // Sort the list of sweetness values in ascending order
        Collections.sort(sweet);
        
        // Initialize a counter for the number of sweet items that can be bought
        int num = 0;
        
        // Iterate through the sorted sweetness values
        for (int i = 0; i < N; i++) {
            // Check if the current sweetness value can be bought with the remaining money
            if (x - sweet.get(num) >= 0) {
                // Deduct the sweetness value from the total money
                x = x - sweet.get(num);
                // Increment the count of items bought
                num++;
            } else {
                // If the current item cannot be bought, exit the loop
                break;
            }
        }
        
        // Adjust the count if all items were bought but there is still money left
        if ((num == N) && (x > 0)) {
            num -= 1;
        }
        
        // Print the total number of sweet items that can be bought
        System.out.println(num);
    }
}

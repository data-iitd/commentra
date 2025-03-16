import java.util.HashMap;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a HashMap to store string key-value pairs
        HashMap<String, String> map = new HashMap<String, String>();
        
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in);
        
        // Read the number of entries to be added to the HashMap
        int n = sc.nextInt();
        
        // Consume the newline character left after reading the integer
        String str = sc.nextLine();
        
        // Loop to read 'n' strings from the input and add them to the HashMap
        for (int i = 0; i < n; i++) {
            // Read a line of input and put it into the HashMap with an empty string as the value
            map.put(sc.nextLine(), "");
        }
        
        // Close the Scanner to free up resources
        sc.close();

        // Print the size of the HashMap, which represents the number of unique keys added
        System.out.println(map.size());
    }
}

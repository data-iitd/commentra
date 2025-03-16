import java.util.*; 

public class Main { 
    public static void main(String[] args) { 
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in); 
        
        // Read the number of strings to be processed
        int num = sc.nextInt(); 
        
        // Initialize counters for occurrences of 'C' and the total fine
        int counter = 0; 
        int fine = 0; 
        
        // Create an ArrayList to store the input strings
        ArrayList<String> arr = new ArrayList<>(); 
        
        // Read 'num' strings from input and add them to the ArrayList
        for (int i = 0; i < num; i++) { 
            String s = sc.next(); 
            arr.add(s); 
        } 
        
        // Calculate fines based on occurrences of 'C' in each column
        for (int i = 0; i < num; i++) { 
            for (int k = 0; k < num; k++) { 
                // Count occurrences of 'C' in the current column
                if (arr.get(k).charAt(i) == 'C') { 
                    counter++; 
                } 
            } 
            // Update the fine based on the number of 'C's found in this column
            fine += (counter * (counter - 1)) / 2; 
            // Reset counter for the next column
            counter = 0; 
        } 
        
        // Calculate fines based on occurrences of 'C' in each row
        for (int i = 0; i < num; i++) { 
            for (int k = 0; k < num; k++) { 
                // Count occurrences of 'C' in the current row
                if (arr.get(i).charAt(k) == 'C') { 
                    counter++; 
                } 
            } 
            // Update the fine based on the number of 'C's found in this row
            fine += (counter * (counter - 1)) / 2; 
            // Reset counter for the next row
            counter = 0; 
        } 
        
        // Output the total fine calculated
        System.out.println(fine); 
    } 
}

import java.util.*; 

public class Main { 
    // Variable to store the minimum result found
    static long min; 

    public static void main(String[] args) { 
        // Create a Scanner object for user input
        Scanner sc = new Scanner(System.in); 
        
        // Initialize min to the maximum possible value
        min = Long.MAX_VALUE; 
        
        // Create an ArrayList to store the input numbers
        ArrayList<Long> arr = new ArrayList<>(); 
        
        // Read 4 long integers from user input and add them to the list
        for (int i = 0; i < 4; i++) { 
            arr.add(sc.nextLong()); 
        } 
        
        // Create an array to store the operations
        String[] ops = new String[3]; 
        
        // Read 3 operations from user input
        for (int i = 0; i < 3; i++) { 
            ops[i] = sc.next(); 
        } 
        
        // Call the utility function to compute the minimum result
        util(arr, ops, 0); 
        
        // Print the minimum result found
        System.out.println(min); 
    } 

    // Recursive utility function to perform operations and find the minimum result
    public static void util(ArrayList<Long> arr, String[] ops, int idx) { 
        // Base case: if all operations have been used, update the minimum result
        if (idx == 3) { 
            min = Math.min(min, arr.get(0)); 
            return; 
        } 
        
        // Iterate through all pairs of numbers in the list
        for (int i = 0; i < arr.size(); i++) { 
            for (int j = i + 1; j < arr.size(); j++) { 
                // Create a new list to hold the remaining numbers after the operation
                ArrayList<Long> a = new ArrayList<>(); 
                
                // Add the remaining numbers to the new list
                for (int k = 0; k < arr.size(); k++) { 
                    if (k != j && k != i) { 
                        a.add(arr.get(k)); 
                    } 
                } 
                
                long res; 
                // Perform the operation based on the current operation in the ops array
                if (idx < 3 && ops[idx].equals("+")) { 
                    res = arr.get(i) + arr.get(j); // Addition operation
                } else { 
                    res = arr.get(i) * arr.get(j); // Multiplication operation
                } 
                
                // Add the result of the operation to the new list
                a.add(res); 
                
                // Recursively call util with the new list and the next operation index
                util(a, ops, idx + 1); 
            } 
        } 
    } 
}

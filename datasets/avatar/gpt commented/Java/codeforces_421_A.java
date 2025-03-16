import java.math.BigInteger; 
import java.nio.charset.IllegalCharsetNameException; 
import java.util.*; 

public class Main { 
    public static void main(String[] args) { 
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in); 
        
        // Declare variables for the number of elements and sizes of the two lists
        int n, a, b; 
        
        // Read the values for n, a, and b from the input
        n = sc.nextInt(); 
        a = sc.nextInt(); 
        b = sc.nextInt(); 
        
        // Initialize two ArrayLists to store the elements of the two lists
        ArrayList<Integer> list1 = new ArrayList<>(); 
        ArrayList<Integer> list2 = new ArrayList<>(); 
        
        // Read 'a' integers into list1
        for (int i = 0; i < a; i++) { 
            list1.add(sc.nextInt()); 
        } 
        
        // Read 'b' integers into list2
        for (int i = 0; i < b; i++) { 
            list2.add(sc.nextInt()); 
        } 
        
        // Iterate from 0 to n-1 to check the presence of each index in list1
        for (int i = 0; i < n; i++) { 
            // If the current index + 1 is in list1, print 1
            if (list1.contains(i + 1)) { 
                System.out.print(1 + " "); 
            } else { 
                // Otherwise, print 2
                System.out.print(2 + " "); 
            } 
        } 
    } 
}

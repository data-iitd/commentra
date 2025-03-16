import java.io.*; 
import java.util.*; 
import java.util.stream.Collectors; 

public class Main { 
    public static void main(String[] args) { 
        // Use try-with-resources to ensure Scanner and PrintWriter are closed automatically
        try (Scanner in = new Scanner(System.in); PrintWriter out = new PrintWriter(System.out)) { 
            // Read the number of integers from input
            int n = in.nextInt(); 
            // Initialize a list to store the integers
            List<Integer> a = new ArrayList<>(); 
            
            // Read n integers from input and add them to the list
            for (int i = 0; i < n; i++) { 
                int value = in.nextInt(); 
                a.add(value); 
            } 
            
            // Remove duplicates, sort the list, and collect it back into a list
            a = a.stream().distinct().sorted().collect(Collectors.toList()); 
            
            // Initialize a flag to check for consecutive triplets
            boolean found = false; 
            
            // Check for three consecutive integers in the sorted list
            for (int i = 0; i < a.size(); i++) { 
                // Ensure there are at least three elements to check
                if (i + 1 < a.size() && i + 2 < a.size()) { 
                    // Check if the current, next, and the one after next integers are consecutive
                    if (a.get(i) + 1 == a.get(i + 1) && a.get(i + 1) + 1 == a.get(i + 2)) { 
                        found = true; // Set found to true if consecutive triplet is found
                    } 
                } 
            } 
            
            // Output "YES" if a triplet was found, otherwise output "NO"
            out.println(found? "YES" : "NO"); 
        } 
    } 
}

import java.util.*; 
import java.io.*; 

public class Main { 
    public static void main(String[] args) throws Exception { 
        // Define a constant number for modulo operations
        int num = 998244353; 
        
        // Initialize BufferedReader to read input from standard input
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in)); 
        
        // Initialize PrintWriter to output results to standard output
        PrintWriter out = new PrintWriter(System.out); 
        
        // Read the number of pairs (n) from input
        int n = Integer.parseInt(bf.readLine()); 
        
        // Create two ArrayLists to store the two sets of integers
        ArrayList<Integer> ai = new ArrayList<Integer>(); 
        ArrayList<Integer> bi = new ArrayList<Integer>(); 
        
        // Read n pairs of integers from input
        for (int i = 0; i < n; i++) { 
            StringTokenizer st = new StringTokenizer(bf.readLine()); 
            // Add the first integer of the pair to the first list
            ai.add(Integer.parseInt(st.nextToken())); 
            // Add the second integer of the pair to the second list
            bi.add(Integer.parseInt(st.nextToken())); 
        } 
        
        // Sort both lists to prepare for median calculation
        Collections.sort(ai); 
        Collections.sort(bi); 
        
        // Check if the number of elements is odd
        if (n % 2 == 1) { 
            // Calculate the result for odd n using the median values
            out.println(bi.get(bi.size() / 2) - ai.get(ai.size() / 2) + 1); 
            out.close(); 
        } else { 
            // Calculate the average of the two middle values for even n
            double b = (ai.get(ai.size() / 2) + ai.get(ai.size() / 2 - 1) + 0.0) / 2; 
            double c = (bi.get(bi.size() / 2) + bi.get(bi.size() / 2 - 1) + 0.0) / 2; 
            // Calculate the result for even n and print it
            out.println((int)(2 * (c - b) + 1)); 
            out.close(); 
        } 
    } 
}

import java.io.*; 
import java.util.*; 
import java.util.stream.*; 

public class Main { 
    // BufferedReader to read input from the console
    private static BufferedReader br = null; 

    public static void main(String[] args) { 
        // Read the first input as an integer
        int n = Integer.parseInt(read(1)[0]); 
        
        // Check if the input is 1
        if (n == 1) { 
            // If the input is 1, print "Hello World"
            System.out.println("Hello World"); 
        } else { 
            // If the input is not 1, read two more strings
            String[] strs = read(2); 
            // Parse the two strings as integers and print their sum
            System.out.println(Integer.parseInt(strs[0]) + Integer.parseInt(strs[1])); 
        } 
    } 

    // Method to read a specified number of lines from input
    private static String[] read(int len) { 
        List<String> strList = new ArrayList<>(); 
        try { 
            // Initialize BufferedReader if it is null
            if (br == null) { 
                br = new BufferedReader(new InputStreamReader(System.in)); 
            } 
            // Read 'len' lines from input
            for (int i = 0; i < len; i++) { 
                strList.add(br.readLine()); 
            } 
        } catch (IOException e) { 
            // Handle potential IO exceptions
        } 
        // Convert the list to an array and return it
        return strList.toArray(new String[0]); 
    } 

    // Method to close the BufferedReader
    private static void close() { 
        try { 
            // Close the BufferedReader if it is not null
            if (br != null) { 
                br.close(); 
            } 
        } catch (IOException e) { 
            // Handle potential IO exceptions
        } 
    } 
}

import java.io.BufferedReader; 
import java.io.InputStreamReader; 
import java.io.IOException; 
import java.util.*; 

public class Main { 
    public static void main(String[] args) throws IOException { 
        // Create a BufferedReader to read input from the standard input stream
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in)); 
        
        // Read a line of input, split it by spaces, and store it in an array
        String[] str = in.readLine().split(" "); 
        
        // Create a StringTokenizer to read the next line of input
        StringTokenizer st = new StringTokenizer(in.readLine()); 
        
        // Parse the first token as an integer and store it in variable 'a'
        int a = Integer.parseInt(st.nextToken()); 
        
        // Parse the second token as an integer and store it in variable 'b'
        int b = Integer.parseInt(st.nextToken()); 
        
        // Read another line of input and store it in variable 'u'
        String u = in.readLine(); 
        
        // Compare the string 'u' with the first element of the array 'str'
        // Print the result based on the comparison
        System.out.println(u.equals(str[0]) ? (a - 1) + " " + b : a + " " + (b - 1)); 
    } 
}

import java.io.*; 
import java.util.StringTokenizer; 

public class Main { 
    public static void main(String[] args) { 
        // Set up input and output streams
        InputStream inputStream = System.in; 
        OutputStream outputStream = System.out; 
        
        // Create an InputReader to read input from the input stream
        InputReader in = new InputReader(inputStream); 
        
        // Create a PrintWriter to write output to the output stream
        PrintWriter out = new PrintWriter(outputStream); 
        
        // Instantiate the Task class to solve the problem
        Task solver = new Task(); 
        
        // Call the solve method to process the input and produce output
        solver.solve(in, out); 
        
        // Close the PrintWriter to flush and release resources
        out.close(); 
    } 
    
    static class Task { 
        public void solve(InputReader in, PrintWriter out) { 
            // Read the number of elements
            int n = in.nextInt(); 
            
            // Initialize an array to count occurrences of each index (up to 1000)
            int[] array = new int[1001]; 
            
            // Read n integers and count their occurrences
            for (int i = 0; i < n; i++) { 
                int index = in.nextInt(); 
                array[index]++; 
            } 
            
            // Determine the maximum count of any index
            int countMax = -1; 
            for (int i = 1; i < array.length; i++) { 
                if (countMax < array[i]) 
                    countMax = array[i]; 
            } 
            
            // Check if the maximum count is within allowed limits based on n being even or odd
            if (n % 2 == 0) { 
                // For even n, check if the maximum count is less than or equal to n/2
                if (countMax <= n / 2) { 
                    out.println("YES"); 
                } else { 
                    out.println("NO"); 
                } 
            } else { 
                // For odd n, check if the maximum count is less than or equal to n/2 + 1
                if (countMax <= n / 2 + 1) { 
                    out.println("YES"); 
                } else { 
                    out.println("NO"); 
                } 
            } 
        } 
    } 
    
    static class InputReader { 
        BufferedReader reader; 
        StringTokenizer tokenizer; 
        
        // Constructor to initialize the BufferedReader
        public InputReader(InputStream stream) { 
            reader = new BufferedReader(new InputStreamReader(stream), 32768); 
        } 
        
        // Method to read the next token from input
        String next() { 
            // Read a new line if the tokenizer is empty
            while (tokenizer == null || !tokenizer.hasMoreElements()) { 
                try { 
                    tokenizer = new StringTokenizer(reader.readLine()); 
                } catch (IOException e) { 
                    throw new RuntimeException(e); 
                } 
            } 
            return tokenizer.nextToken(); 
        } 
        
        // Method to read the next integer from input
        int nextInt() { 
            return Integer.parseInt(next()); 
        } 
        
        // Method to read the next long from input
        long nextLong() { 
            return Long.parseLong(next()); 
        } 
        
        // Method to read the next double from input
        double nextDouble() { 
            return Double.parseDouble(next()); 
        } 
        
        // Method to read the next line from input
        String nextLine() { 
            String str = ""; 
            try { 
                str = reader.readLine(); 
            } catch (IOException e) { 
                e.printStackTrace(); 
            } 
            return str; 
        } 
    } 
}

import java.util.* ; 
import java.io.* ; 
import static java.lang.Math.* ; 

public class Main { 
    // FastReader object to read input efficiently
    public static FastReader in = new FastReader(); 
    // PrintWriter object to output the result
    public static PrintWriter out = new PrintWriter(System.out); 

    public static void main(String[] args) { 
        // Read the dimensions of the grid
        int n = in.nextInt(); 
        // Read the number of banned cells
        int m = in.nextInt(); 

        // Initialize sets to keep track of banned rows and columns
        Set<Integer> bannedRows, bannedCols; 
        bannedRows = new HashSet<>(); 
        bannedCols = new HashSet<>(); 

        // Read each banned cell and add it to the appropriate set if it's not on the border
        for (int i = 0; i < m; i++) { 
            int r = in.nextInt(); 
            if (r > 1 && r < n) bannedRows.add(r); 
            int c = in.nextInt(); 
            if (c > 1 && c < n) bannedCols.add(c); 
        } 

        // Calculate the number of cells that can be reached, accounting for banned rows and columns
        int answer = (n - 2) * 2; 
        answer -= bannedRows.size(); 
        answer -= bannedCols.size(); 

        // Adjust the answer if the grid size is odd and the center cell is not banned
        if (n % 2 != 0) { 
            int mid = (n + 1) / 2; 
            if (!bannedRows.contains(mid) && !bannedCols.contains(mid)) { 
                answer--; 
            } 
        } 

        // Output the final answer
        out.println(answer); 
        // Close the output stream
        out.close(); 
    } 

    // FastReader class to read input efficiently
    public static class FastReader { 
        BufferedReader br; 
        StringTokenizer st; 

        public FastReader() { 
            br = new BufferedReader(new InputStreamReader(System.in)); 
        } 

        // Method to read the next token
        String next() { 
            while (st == null || !st.hasMoreElements()) { 
                try { 
                    st = new StringTokenizer(br.readLine()); 
                } catch (IOException e) { 
                    e.printStackTrace(); 
                } 
            } 
            return st.nextToken(); 
        } 

        // Method to read the next integer
        int nextInt() { 
            return Integer.parseInt(next()); 
        } 

        // Method to read the next long
        long nextLong() { 
            return Long.parseLong(next()); 
        } 

        // Method to read the next double
        double nextDouble() { 
            return Double.parseDouble(next()); 
        } 

        // Method to read the next line
        String nextLine() { 
            String str = ""; 
            try { 
                str = br.readLine(); 
            } catch (IOException e) { 
                e.printStackTrace(); 
            } 
            return str; 
        } 
    } 
}

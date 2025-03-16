
import java.util.* ;  // Importing necessary utility classes
import java.io.* ;
import static java.lang.Math.* ;

public class Main {
    // Main class declaration

    public static FastReader in = new FastReader() ;  // Creating an instance of FastReader class for reading input
    public static PrintWriter out = new PrintWriter(System.out) ;  // Creating an instance of PrintWriter class for writing output

    public static void main(String[] args) {
        // Main method declaration

        int n = in.nextInt() ;  // Reading the number of rows in the grid
        int m = in.nextInt() ;  // Reading the number of banned cells

        Set<Integer> bannedRows = new HashSet<>() ;  // Creating a Set to store banned rows
        Set<Integer> bannedCols = new HashSet<>() ;  // Creating a Set to store banned columns

        for (int i = 0 ; i < m ; i ++ ) {
            // Reading banned cells and adding them to the respective Sets

            int r = in.nextInt() ;
            if (r > 1 && r < n) bannedRows.add(r) ;

            int c = in.nextInt() ;
            if (c > 1 && c < n) bannedCols.add(c) ;
        }

        int answer = (n - 2) * 2 ;  // Initializing answer as the total number of cells in the grid minus the banned cells
        answer -= bannedRows.size() ;  // Subtracting the number of banned rows
        answer -= bannedCols.size() ;  // Subtracting the number of banned columns

        if (n % 2 != 0) {
            // Special case when the number of rows is odd

            int mid = (n + 1) / 2 ;
            if (!bannedRows.contains(mid) && !bannedCols.contains(mid)) {
                // If the middle cell is not banned, decrement the answer
                answer-- ;
            }
        }

        out.println(answer) ;  // Writing the answer to the output stream
        out.close() ;  // Closing the output stream
    }

    public static class FastReader {
        // FastReader class declaration

        BufferedReader br ;  // Creating a BufferedReader for reading input
        StringTokenizer st ;  // Creating a StringTokenizer for parsing input

        public FastReader() {
            // Constructor declaration

            br = new BufferedReader(new InputStreamReader(System.in)) ;  // Initializing the BufferedReader
        }

        String next() {
            // Method for reading the next token from the input

            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine()) ;  // Creating a new StringTokenizer for the current line
                } catch (IOException e) {
                    e.printStackTrace() ;  // Printing an error message if an I/O error occurs
                }
            }
            return st.nextToken() ;  // Returning the next token
        }

        int nextInt() {
            // Method for reading the next integer from the input

            return Integer.parseInt(next()) ;  // Converting the next token to an integer and returning it
        }

        long nextLong() {
            // Method for reading the next long integer from the input

            return Long.parseLong(next()) ;  // Converting the next token to a long integer and returning it
        }

        double nextDouble() {
            // Method for reading the next double from the input

            return Double.parseDouble(next()) ;  // Converting the next token to a double and returning it
        }

        String nextLine() {
            // Method for reading the next line from the input

            String str = "" ;
            try {
                str = br.readLine() ;  // Reading the next line
            } catch (IOException e) {
                e.printStackTrace() ;  // Printing an error message if an I/O error occurs
            }
            return str ;  // Returning the next line
        }
    }
}

These comments should provide a clear understanding of the code logic for anyone who reads it.
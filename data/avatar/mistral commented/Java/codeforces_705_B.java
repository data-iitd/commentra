
import java.util.* ;  // Importing necessary utility classes
import java.io.* ;

public class Main {
    static class FastReader {
        BufferedReader br ;
        StringTokenizer st ;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

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

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "" ;
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str ;
        }
    }

    static FastReader scan = new FastReader();  // Creating an instance of FastReader

    public static void main(String[] args) {
        int t = 1 ;  // Initializing the test case counter

        while (t-- > 0) {  // Running the solution process for all test cases
            solve();
        }
    }

    public static void solve() {
        int t = scan.nextInt();  // Reading the number of test cases
        int[] arr = new int[t];  // Creating an integer array of size 't' to store the input

        for (int i = 0; i < arr.length; i++) {  // Iterating through the array
            arr[i] = scan.nextInt();  // Reading each element

            if (arr[i] == 1) {  // Checking if the current element is 1
                if (prevWinner == 0) {  // If the previous winner was 0
                    prevWinner = 2;  // Update the 'prevWinner' variable to 2
                }

                if ((arr[i] - 1) % 2 == 0) {  // Checking the parity of the current element's index
                    System.out.println(prevWinner == 0 ? 2 : 1);  // Printing the output based on the 'prevWinner' value
                    prevWinner = (prevWinner == 0 ? 2 : 1);  // Updating the 'prevWinner' variable for the next iteration
                }
            }
        }
    }

    static int prevWinner = 0;  // Initializing the 'prevWinner' variable to 0
}
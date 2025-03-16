import java.io.*; // Importing java.io for input/output operations
import java.util.*; // Importing java.util for utility classes

public class Main {
    // Declare static members for output stream and print writer
    static OutputStream outputStream = System.out;
    static PrintWriter out = new PrintWriter(outputStream);

    public static void main(String[] args) throws IOException {
        // Initialize BufferedReader to read input from System.in
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        // Read the number of test cases
        int t = Integer.parseInt(br.readLine());
        
        // Initialize priority queues for max and min values
        PriorityQueue<Integer> pqmax = new PriorityQueue<>();
        PriorityQueue<Integer> pqmin = new PriorityQueue<>(new Comparator<Integer>() {
            public int compare(Integer x, Integer y) {
                return y - x; // Custom comparator for max heap
            }
        });
        
        // Initialize variables to keep track of sums and the minimum value
        long sumMin = 0, sumMax = 0, sumb = 0;
        int min = 0;
        
        // Process each test case
        while (t-- > 0) {
            // Read the input for the current test case
            String[] s = br.readLine().split(" ");
            
            // If the command is '2', calculate and print the result
            if (s[0].charAt(0) == '2') {
                long ans = min;
                ans *= pqmin.size();
                ans -= sumMin;
                long ans1 = min;
                ans1 *= pqmax.size();
                ans1 = sumMax - ans1;
                out.println(min + " " + (ans + ans1 + sumb));
            } 
            // If the command is '1', add the new value to the appropriate priority queue
            else {
                int in = Integer.parseInt(s[1]);
                sumb += Long.parseLong(s[2]);
                
                if (in > min) {
                    pqmax.add(in);
                    sumMax += in;
                } else {
                    pqmin.add(in);
                    sumMin += in;
                }
                
                // Balance the priority queues
                if (pqmin.size() > pqmax.size()) {
                    sumMax += pqmin.peek();
                    sumMin -= pqmin.peek();
                    pqmax.add(pqmin.poll());
                }
                
                if (pqmin.size() < pqmax.size()) {
                    sumMax -= pqmax.peek();
                    sumMin += pqmax.peek();
                    pqmin.add(pqmax.poll());
                }
                
                // Update the minimum value
                min = pqmin.peek();
            }
        }
        
        // Close the print writer to flush the output
        out.close();
    }
}

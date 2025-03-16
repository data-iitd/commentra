import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Read the number of test cases and solve each case
        for (int i = 0; i < sc.nextInt(); i++) {
            solve();
        }
    }
    
    // Function to read a single line of input and convert it to a tuple of integers
    public static int[] value() {
        return Arrays.stream(sc.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
    }
    
    // Function to read a single line of input from stdin and convert it to a tuple of integers
    public static int[] values() {
        return Arrays.stream(System.in.readline().split(" ")).mapToInt(Integer::parseInt).toArray();
    }
    
    // Function to read a single line of input and return a list of integers
    public static List<Integer> inlst() {
        return Arrays.stream(sc.nextLine().split(" ")).map(Integer::parseInt).collect(Collectors.toList());
    }
    
    // Function to read a single line of input from stdin and return a list of integers
    public static List<Integer> inlsts() {
        return Arrays.stream(System.in.readline().split(" ")).map(Integer::parseInt).collect(Collectors.toList());
    }
    
    // Function to read a single integer from input
    public static int inp() {
        return Integer.parseInt(sc.nextLine());
    }
    
    // Function to read a single integer from stdin
    public static int inps() {
        return Integer.parseInt(System.in.readline());
    }
    
    // Function to read a single line of input and return it as a string
    public static String instr() {
        return sc.nextLine();
    }
    
    // Function to read a single line of input and return it as a list of strings
    public static List<String> stlst() {
        return Arrays.asList(sc.nextLine().split(" "));
    }
    
    // Helper function to determine if a specific arrangement is possible
    public static boolean help(int a, int b, List<Integer> l) {
        List<List<Integer>> tot = new ArrayList<>();
        
        // Create sublists of length 'a' from the list 'l'
        for (int i = 0; i < b; i++) {
            tot.add(l.subList(i * a, i * a + a));
        }
        
        // Check if any combination of the sublists sums to 'b'
        for (List<Integer> i : tot) {
            if (i.stream().mapToInt(Integer::intValue).sum() == b) {
                return true;
            }
        }
        return false;
    }
    
    // Main function to solve the problem
    public static void solve() {
        List<Integer> tot = new ArrayList<>();
        String x = instr();  // Read the input string
        List<Integer> s = new ArrayList<>();
        
        // Convert the input string into a list of integers (0 for 'O', 1 for 'X')
        for (char i : x.toCharArray()) {
            if (i == 'O') {
                s.add(0);
            } else {
                s.add(1);
            }
        }
        
        // Check for all divisors of 12 to find valid arrangements
        for (int i = 1; i <= 12; i++) {
            if (12 % i == 0) {  // Check if 'i' is a divisor of 12
                if (help(i, 12 / i, s)) {  // Use the helper function to check arrangements
                    tot.add(12 / i);  // Store valid arrangements as integers
                }
            }
        }
        
        // Print the number of valid arrangements
        System.out.print(tot.size() + " ");
        
        // Print each valid arrangement in sorted order
        Collections.sort(tot);
        for (int a : tot) {
            System.out.print(a + " ");
        }
        System.out.println();  // Print a newline at the end
    }
}


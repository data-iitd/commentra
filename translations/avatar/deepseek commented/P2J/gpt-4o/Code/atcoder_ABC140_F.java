import java.util.*;

public class Main {
    
    // Function to read an integer from standard input
    public static int I() {
        Scanner scanner = new Scanner(System.in);
        return scanner.nextInt();
    }

    // Function to read a list of integers from standard input
    public static List<Integer> LI() {
        Scanner scanner = new Scanner(System.in);
        List<Integer> list = new ArrayList<>();
        while (scanner.hasNextInt()) {
            list.add(scanner.nextInt());
        }
        return list;
    }

    public static String mainLogic() {
        // Read the number of elements N
        int N = I();
        
        // Read the list of integers S, sort them in descending order
        List<Integer> S = LI();
        Collections.sort(S, Collections.reverseOrder());
        
        // Initialize a flag array to keep track of used elements
        boolean[] flag = new boolean[S.size()];
        Arrays.fill(flag, true);
        
        // Initialize the current list with the first element of S
        List<Integer> cur = new ArrayList<>();
        cur.add(S.get(0));
        
        // Set the flag for the first element to False
        flag[0] = false;
        
        // Loop through N times
        for (int i = 0; i < N; i++) {
            int j = 0;
            int jM = cur.size();
            
            // Iterate over the elements of S
            for (int k = 0; k < S.size(); k++) {
                if (flag[k] && S.get(k) < cur.get(j)) {
                    // Add the element to cur, set its flag to False, and increment j
                    cur.add(S.get(k));
                    j++;
                    flag[k] = false;
                    if (j == jM) {
                        break;
                    }
                }
            }
            
            // If no such element is found, return "No"
            if (j < jM) {
                return "No";
            }
            
            // Sort cur in descending order
            Collections.sort(cur, Collections.reverseOrder());
        }
        
        // Return "Yes" if the condition is satisfied
        return "Yes";
    }

    public static void main(String[] args) {
        // Print the result of the main logic function
        System.out.println(mainLogic());
    }
}

// <END-OF-CODE>

public class Main {
    public static void main(String[] args) {
        // Read the number of elements in round_complexity and george_complexity
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        
        // Read the complexities of the rounds
        int[] round_complexity = new int[n];
        for (int i = 0; i < n; i++) {
            round_complexity[i] = in.nextInt();
        }
        
        // Read the complexities of George's challenges
        int[] george_complexity = new int[m];
        for (int i = 0; i < m; i++) {
            george_complexity[i] = in.nextInt();
        }
        
        // Initialize counters for both lists
        int i = 0;
        int j = 0;
        
        // Loop through both lists to compare complexities
        while (i < n && j < m) {
            // Increment i if the current round complexity is less than or equal to George's complexity
            i += 1 * (round_complexity[i] <= george_complexity[j]);
            
            // Increment j to move to the next element in george_complexity
            j += 1;
        }
        
        // Print the number of rounds George can solve
        System.out.println(n - i);
    }
}


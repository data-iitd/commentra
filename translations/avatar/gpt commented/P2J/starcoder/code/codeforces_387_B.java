public class Main {
    public static void main(String[] args) {
        // Read the number of rounds (n) and the number of George's complexities (m)
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        
        // Read the complexities for each round into a list
        int[] round_complexity = new int[n];
        for (int i = 0; i < n; i++) {
            round_complexity[i] = sc.nextInt();
        }
        
        // Read George's complexities into another list
        int[] george_complexity = new int[m];
        for (int i = 0; i < m; i++) {
            george_complexity[i] = sc.nextInt();
        }
        
        // Initialize indices for both lists
        int i = 0;
        int j = 0;
        
        // Iterate through both lists to compare complexities
        while (i < n && j < m) {
            // If the current round's complexity is less than or equal to George's complexity,
            // move to the next round
            i += 1 * (round_complexity[i] <= george_complexity[j]);
            
            // Always move to the next complexity of George
            j += 1;
        }
        
        // Output the number of rounds that George cannot handle
        System.out.println(n - i);
    }
}


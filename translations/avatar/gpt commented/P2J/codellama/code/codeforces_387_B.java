public class Main {
    public static void main(String[] args) {
        // Read the number of rounds (n) and the number of George's complexities (m)
        int n, m;
        String[] input = new Scanner(System.in).nextLine().split(" ");
        n = Integer.parseInt(input[0]);
        m = Integer.parseInt(input[1]);
        
        // Read the complexities for each round into a list
        int[] round_complexity = new int[n];
        input = new Scanner(System.in).nextLine().split(" ");
        for (int i = 0; i < n; i++) {
            round_complexity[i] = Integer.parseInt(input[i]);
        }
        
        // Read George's complexities into another list
        int[] george_complexity = new int[m];
        input = new Scanner(System.in).nextLine().split(" ");
        for (int i = 0; i < m; i++) {
            george_complexity[i] = Integer.parseInt(input[i]);
        }
        
        // Initialize indices for both lists
        int i = 0, j = 0;
        
        // Iterate through both lists to compare complexities
        while (i < n && j < m) {
            // If the current round's complexity is less than or equal to George's complexity,
            // move to the next round
            if (round_complexity[i] <= george_complexity[j]) {
                i++;
            }
            
            // Always move to the next complexity of George
            j++;
        }
        
        // Output the number of rounds that George cannot handle
        System.out.println(n - i);
    }
}

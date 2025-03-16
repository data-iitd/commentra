public class Main {
    public static void main(String[] args) {
        // Declare arrays for storing team names and initialize scores
        String[] t, h;
        int n, taro = 0, hanako = 0, i;

        // Read the number of rounds (n) from input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextInt();

        // Allocate memory for team names for both players
        t = new String[n];
        h = new String[n];
        
        // Loop through each round to read team names and calculate scores
        for (i = 0; i < n; i++) {
            // Read team names for both players
            t[i] = scanner.next();
            h[i] = scanner.next();
            
            // Compare team names and update scores based on the comparison
            if (t[i].compareTo(h[i]) < 0) {
                // If Hanako's team name is lexicographically smaller, she gets 3 points
                hanako += 3;
            }
            if (t[i].compareTo(h[i]) > 0) {
                // If Taro's team name is lexicographically larger, he gets 3 points
                taro += 3;
            }
            if (t[i].compareTo(h[i]) == 0) {
                // If both team names are the same, both players get 1 point
                taro += 1;
                hanako += 1;
            }
        }
        
        // Output the final scores of Taro and Hanako
        System.out.println(taro + " " + hanako);
        

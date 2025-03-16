import java.util.*;

public class Main {
    // Define a pair type to hold an integer and a string
    static class P implements Comparable<P> {
        int first;
        String second;

        P(int first, String second) {
            this.first = first;
            this.second = second;
        }

        @Override
        public int compareTo(P other) {
            return Integer.compare(other.first, this.first); // Sort in descending order
        }
    }

    // Array to hold pairs of scores and names
    static P[] v = new P[22];

    // List to hold lists of indices for each number
    static List<Integer>[] d = new ArrayList[33];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Initialize the lists
        for (int i = 0; i < 33; i++) {
            d[i] = new ArrayList<>();
        }

        int n; // Variable to hold the number of participants

        // Read the number of participants until a zero is encountered
        while ((n = scanner.nextInt()) != 0) {
            int m; // Variable to hold the number of scores for each participant

            // Clear the previous data in the list of lists
            for (int i = 0; i < 33; i++) {
                d[i].clear();
            }

            // Loop through each participant
            for (int i = 0; i < n; i++) {
                v[i] = new P(0, ""); // Initialize the score of the participant to zero

                // Read the participant's name and the number of scores
                v[i].second = scanner.next();
                m = scanner.nextInt();

                // Loop through each score for the current participant
                for (int j = 0; j < m; j++) {
                    int a; // Variable to hold the score value
                    a = scanner.nextInt(); // Read the score

                    // Update the score of the current participant
                    v[i].first += n - d[a].size();

                    // Decrease the score of participants who have already received this score
                    for (int k = 0; k < d[a].size(); k++) {
                        v[d[a].get(k)].first--;
                    }

                    // Add the current participant's index to the list for this score
                    d[a].add(i);
                }
            }

            // Sort the participants based on their scores
            Arrays.sort(v, 0, n);

            // Output the participant with the highest score
            System.out.println(v[0].first + " " + v[0].second);
        }

        scanner.close();
    }
}
// <END-OF-CODE>

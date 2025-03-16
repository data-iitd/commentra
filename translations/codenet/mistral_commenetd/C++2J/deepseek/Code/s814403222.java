import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            if (n == 0) break;
            
            // Initialize d array for each test case
            List<Integer>[] d = new ArrayList[33];
            for (int i = 0; i < 33; i++) {
                d[i] = new ArrayList<>();
            }
            
            // Initialize an array of pairs v with size n
            P[] v = new P[22];
            for (int i = 0; i < 22; i++) {
                v[i] = new P(0, "");
            }
            
            // Process each test case
            for (int i = 0; i < n; i++) {
                // Read the name and number of students m for the current test case
                int m = scanner.nextInt();
                String name = scanner.next();
                v[i].second = name;
                
                // For each student, read the number of absences a and update the scores accordingly
                for (int j = 0; j < m; j++) {
                    int a = scanner.nextInt();
                    
                    // Calculate the effect of the current student's absences on the scores of other students
                    v[i].first += n - d[a].size();
                    
                    // Update the scores of students who have the same number of absences as the current student
                    for (int k = 0; k < d[a].size(); k++) {
                        // Decrease the score of the student whose index is in d[a] by 1
                        v[d[a].get(k)].first--;
                    }
                    
                    // Add the index of the current student to the vector d[a]
                    d[a].add(i);
                }
            }
            
            // Sort the pairs in the array v in ascending order based on their first elements
            Arrays.sort(v, 0, n, (a, b) -> Integer.compare(a.first, b.first));
            
            // Print the name and the highest score of the student with the highest score
            System.out.println(v[0].first + " " + v[0].second);
        }
    }
    
    // Define a pair type with first integer and second string
    static class P {
        int first;
        String second;
        
        P(int first, String second) {
            this.first = first;
            this.second = second;
        }
    }
}

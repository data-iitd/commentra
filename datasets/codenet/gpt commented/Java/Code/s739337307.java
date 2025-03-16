import java.util.*;
import java.math.*;

class Main {
    public static void main(String[] args) {
        
        // Create a Scanner object for input
        try (Scanner sc = new Scanner(System.in)) {

            // Read the number of questions (n) and the number of submissions (m)
            int n = Integer.parseInt(sc.next());
            int m = Integer.parseInt(sc.next());

            // Initialize a HashMap to track the status of each question
            HashMap<Integer, Integer> map = new HashMap<>();

            // Initialize counters for accepted submissions and total wrong attempts
            int countAc = 0; // Count of accepted submissions
            int countWaAll = 0; // Total count of wrong attempts across all questions

            // Process each submission
            for (int i = 0; i < m; i++) {
                // Read the question number and the result (WA or AC)
                int question = Integer.parseInt(sc.next());
                String waOrAc = sc.next();

                // If the question is not yet in the map, add it
                if (!map.containsKey(question)) {
                    // If the result is WA (Wrong Answer), initialize the count to 1
                    if (waOrAc.equals("WA")) map.put(question, 1);
                    else {
                        // If the result is AC (Accepted), mark it with -1 and increment the accepted count
                        map.put(question, -1);
                        countAc++;
                    }
                } else {
                    // If the question is already in the map, retrieve its current count
                    int countWa = map.get(question);
                    // If the question has already been accepted (countWa < 0), do nothing
                    if (countWa < 0);
                    else {
                        // If the result is WA, increment the wrong attempt count
                        if (waOrAc.equals("WA")) map.replace(question, countWa, countWa + 1);
                        else {
                            // If the result is AC, mark it as accepted and update counts
                            map.replace(question, countWa, -countWa);
                            countAc++;
                            countWaAll += countWa; // Add the number of wrong attempts to the total
                        }
                    }
                }
            }

            // Output the total number of accepted submissions and total wrong attempts
            System.out.println(countAc + " " + countWaAll);

        } catch (Exception e) {
            // Print the stack trace in case of an exception
            e.printStackTrace();
        }        
    }
}

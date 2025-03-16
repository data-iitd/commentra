import java.util.*;

public class Main {
    // Function to convert date, hour and minute to total minutes
    static int time2min(int month, int day, int hour, int min) {
        final int[] total_day_of_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // Total days in each month
        int total = 0;
        for (int i = 1; i < month; i++) { // Calculate total minutes for each month before the current one
            total += total_day_of_month[i - 1] * 24 * 60;
        }
        for (int i = 1; i < day; i++) { // Calculate total minutes for each day before the current one
            total += 24 * 60;
        }
        total += hour * 60 + min; // Calculate total minutes for the current hour and minute
        return total;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            int N = scanner.nextInt(); // Read the number of logs from the standard input
            if (N == 0) break; // If the number of logs is zero, break the loop

            Map<Integer, List<Integer>> log = new HashMap<>(); // Create a map to store logs for each id
            for (int i = 0; i < N; i++) { // Iterate through each log
                int month = scanner.nextInt();
                int day = scanner.nextInt();
                int hour = scanner.nextInt();
                int min = scanner.nextInt();
                String action = scanner.next(); // Read the action (add or remove)
                int id = scanner.nextInt(); // Read the id

                int t = time2min(month, day, hour, min); // Calculate the total minutes for the log
                log.putIfAbsent(id, new ArrayList<>()); // Ensure the list exists for the id
                log.get(id).add(t); // Add the total minutes to the list of logs for the id
            }

            int[] total = new int[1000]; // Create an array to store the total time spent for each id

            for (int i = 0; i + 1 < log.getOrDefault(0, Collections.emptyList()).size(); i += 2) { // Iterate through each pair of logs for the id 0
                int god_start = log.get(0).get(i); // Get the start time of the first log
                int god_end = log.get(0).get(i + 1); // Get the end time of the first log

                for (Map.Entry<Integer, List<Integer>> entry : log.entrySet()) { // Iterate through each id and its logs
                    int id = entry.getKey(); // Get the id
                    if (id == 0) continue; // If the id is 0, skip the iteration
                    List<Integer> schedule = entry.getValue(); // Get the list of logs for the id
                    for (int j = 0; j + 1 < schedule.size(); j += 2) { // Iterate through each pair of logs for the current id
                        int ppl_start = schedule.get(j); // Get the start time of the first log
                        int ppl_end = schedule.get(j + 1); // Get the end time of the first log
                        int start = Math.max(god_start, ppl_start); // Get the maximum start time between the logs of god and people
                        int end = Math.min(god_end, ppl_end); // Get the minimum end time between the logs of god and people
                        total[id] += Math.max(0, end - start); // Calculate and add the total time spent for the current id
                    }
                }
            }

            int max_v = 0; // Initialize the maximum total time spent to zero
            for (int id = 0; id < 1000; id++) { // Iterate through each id and find the maximum total time spent
                max_v = Math.max(total[id], max_v);
            }
            System.out.println(max_v); // Print the maximum total time spent
        }
        scanner.close();
    }
}
// <END-OF-CODE>

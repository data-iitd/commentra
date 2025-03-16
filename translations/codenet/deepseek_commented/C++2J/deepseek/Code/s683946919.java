import java.util.*;

public class LogAnalyzer {
    // Function to convert date and time into total minutes from the start of the year
    public static int time2min(int month, int day, int hour, int min) {
        // Array containing the total days in each month
        int[] total_day_of_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int total = 0;

        // Calculate total minutes for the months before the given month
        for (int i = 1; i < month; i++) {
            total += total_day_of_month[i - 1] * 24 * 60;
        }

        // Add total minutes for the days before the given day
        for (int i = 1; i < day; i++) {
            total += 24 * 60;
        }

        // Add minutes for the given hour and minute
        total += hour * 60 + min;

        return total; // Return total minutes
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNextInt()) {
            int N = scanner.nextInt();
            if (N == 0) break; // Exit if N is zero

            // Map to store the log entries for each ID
            Map<Integer, List<Integer>> log = new HashMap<>();
            for (int i = 0; i < N; i++) {
                int month = scanner.nextInt();
                int day = scanner.nextInt();
                int hour = scanner.nextInt();
                int min = scanner.nextInt();
                int id = scanner.nextInt();
                scanner.next(); // Read the space and the action

                // Convert the date and time to total minutes and store in the log
                int t = time2min(month, day, hour, min);
                log.computeIfAbsent(id, k -> new ArrayList<>()).add(t);
            }

            // Array to keep track of total overlap time for each ID
            int[] total = new int[1000];

            // Calculate overlap time for the "god" (ID 0) and other IDs
            List<Integer> godLog = log.getOrDefault(0, new ArrayList<>());
            for (int i = 0; i + 1 < godLog.size(); i += 2) {
                int godStart = godLog.get(i); // Start time for god
                int godEnd = godLog.get(i + 1); // End time for god

                // Iterate through each log entry
                for (Map.Entry<Integer, List<Integer>> entry : log.entrySet()) {
                    int id = entry.getKey(); // Get the ID
                    if (id == 0) continue; // Skip the god's own log

                    List<Integer> schedule = entry.getValue(); // Get the schedule for the current ID
                    // Calculate overlap time for each pair of start and end times
                    for (int j = 0; j < schedule.size(); j += 2) {
                        int pplStart = schedule.get(j); // Start time for the person
                        int pplEnd = schedule.get(j + 1); // End time for the person
                        int start = Math.max(godStart, pplStart); // Calculate the maximum start time
                        int end = Math.min(godEnd, pplEnd); // Calculate the minimum end time
                        total[id] += Math.max(0, end - start); // Add the overlap time to the total
                    }
                }
            }

            // Find the maximum overlap time among all IDs
            int maxV = 0;
            for (int value : total) {
                maxV = Math.max(value, maxV); // Update maxV if current total is greater
            }

            // Output the maximum overlap time
            System.out.println(maxV);
        }
        scanner.close();
    }
}

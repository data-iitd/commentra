import java.util.*;

public class LogAnalyzer {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNextInt()) {
            int N = scanner.nextInt();
            if (N == 0) break;

            Map<Integer, List<Integer>> log = new HashMap<>();
            for (int i = 0; i < N; i++) {
                int month = scanner.nextInt();
                int day = scanner.nextInt();
                int hour = scanner.nextInt();
                int minute = scanner.nextInt();
                int id = scanner.nextInt();
                scanner.next(); // Read the action (not used)

                int t = time2min(month, day, hour, minute);
                log.computeIfAbsent(id, k -> new ArrayList<>()).add(t);
            }

            int[] total = new int[1000];
            List<Integer> godLogs = log.getOrDefault(0, Collections.emptyList());
            for (int i = 0; i + 1 < godLogs.size(); i += 2) {
                int godStart = godLogs.get(i);
                int godEnd = godLogs.get(i + 1);

                for (Map.Entry<Integer, List<Integer>> entry : log.entrySet()) {
                    int id = entry.getKey();
                    if (id == 0) continue;
                    List<Integer> schedule = entry.getValue();
                    for (int j = 0; j < schedule.size(); j += 2) {
                        int pplStart = schedule.get(j);
                        int pplEnd = schedule.get(j + 1);
                        int start = Math.max(godStart, pplStart);
                        int end = Math.min(godEnd, pplEnd);
                        total[id] += Math.max(0, end - start);
                    }
                }
            }

            int maxV = 0;
            for (int value : total) {
                maxV = Math.max(value, maxV);
            }
            System.out.println(maxV);
        }
        scanner.close();
    }

    private static int time2min(int month, int day, int hour, int minute) {
        int[] totalDaysOfMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int total = 0;
        for (int i = 1; i < month; i++) {
            total += totalDaysOfMonth[i - 1] * 24 * 60;
        }
        for (int i = 1; i < day; i++) {
            total += 24 * 60;
        }
        total += hour * 60 + minute;
        return total;
    }
}

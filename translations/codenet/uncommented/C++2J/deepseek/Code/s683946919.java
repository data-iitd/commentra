import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input;
        while ((input = br.readLine()) != null) {
            int N = Integer.parseInt(input);
            if (N == 0) break;

            Map<Integer, List<Integer>> log = new HashMap<>();
            for (int i = 0; i < N; i++) {
                String[] parts = br.readLine().split(" ");
                String[] dateTime = parts[0].split("/");
                String[] time = parts[1].split(":");
                int month = Integer.parseInt(dateTime[0]);
                int day = Integer.parseInt(dateTime[1]);
                int hour = Integer.parseInt(time[0]);
                int minute = Integer.parseInt(time[1]);
                int id = Integer.parseInt(parts[3]);
                int t = time2min(month, day, hour, minute);
                log.putIfAbsent(id, new ArrayList<>());
                log.get(id).add(t);
            }

            int[] total = new int[1000];
            Arrays.fill(total, 0);

            List<Integer> godSchedule = log.get(0);
            for (int i = 0; i + 1 < godSchedule.size(); i += 2) {
                int godStart = godSchedule.get(i);
                int godEnd = godSchedule.get(i + 1);

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
    }

    public static int time2min(int month, int day, int hour, int minute) {
        int[] totalDayOfMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int total = 0;
        for (int i = 1; i < month; i++) {
            total += totalDayOfMonth[i - 1] * 24 * 60;
        }
        for (int i = 1; i < day; i++) {
            total += 24 * 60;
        }
        total += hour * 60 + minute;
        return total;
    }
}

import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            int N = sc.nextInt();
            if (N == 0) break;

            Map<Integer, List<Integer>> log = new HashMap<Integer, List<Integer>>();
            for (int i = 0; i < N; i++) {
                int month = sc.nextInt();
                int day = sc.nextInt();
                int hour = sc.nextInt();
                int min = sc.nextInt();
                String action = sc.next();
                int id = sc.nextInt();

                int t = time2min(month, day, hour, min);
                if (!log.containsKey(id)) log.put(id, new ArrayList<Integer>());
                log.get(id).add(t);
            }

            int[] total = new int[1000];
            Arrays.fill(total, 0);

            for (int i = 0; i + 1 < log.get(0).size(); i += 2) {
                int god_start = log.get(0).get(i);
                int god_end = log.get(0).get(i + 1);

                for (Map.Entry<Integer, List<Integer>> entry : log.entrySet()) {
                    int id = entry.getKey();
                    if (id == 0) continue;

                    List<Integer> schedule = entry.getValue();
                    for (int j = 0; j < schedule.size(); j += 2) {
                        int ppl_start = schedule.get(j);
                        int ppl_end = schedule.get(j + 1);
                        int start = Math.max(god_start, ppl_start);
                        int end = Math.min(god_end, ppl_end);
                        total[id] += Math.max(0, end - start);
                    }
                }
            }

            int max_v = 0;
            for (int id = 0; id < 1000; id++) {
                max_v = Math.max(total[id], max_v);
            }

            System.out.println(max_v);
        }
    }

    public static int time2min(int month, int day, int hour, int min) {
        int[] total_day_of_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int total = 0;

        for (int i = 1; i < month; i++) {
            total += total_day_of_month[i] * 24 * 60;
        }

        for (int i = 1; i < day; i++) {
            total += 24 * 60;
        }

        total += hour * 60 + min;

        return total;
    }
}


import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Map;
import java.util.HashMap;

public class Task {
    public static void main(String[] args) {
        int n = Integer.parseInt(args[0]);
        int b = Integer.parseInt(args[1]);

        Queue<Task> remaining = new PriorityQueue<Task>(new TaskComparator());
        Map<Integer, Integer> result = new HashMap<Integer, Integer>();
        boolean running = false;
        int finishTime = 0;

        for (int i = 0; i < n; i++) {
            String[] input = args[i + 2].split(" ");
            int time = Integer.parseInt(input[0]);
            int duration = Integer.parseInt(input[1]);

            Task task = new Task(time, duration, i);
            result.put(i, 0);

            if (task.time > finishTime && remaining.isEmpty()) {
                running = true;
                finishTime = task.time + task.duration;
                result.put(i, finishTime);
            } else {
                if (task.time >= finishTime &&!remaining.isEmpty()) {
                    finishTime = runTask(remaining, finishTime);
                }

                if (remaining.size() < b) {
                    remaining.add(task);
                } else {
                    result.put(i, -1);
                }
            }
        }

        while (!remaining.isEmpty()) {
            finishTime = runTask(remaining, finishTime);
        }

        for (int key : result.keySet()) {
            System.out.println(result.get(key));
        }
    }

    public static int runTask(Queue<Task> remaining, int finishTime) {
        Task task = remaining.poll();
        finishTime = Math.max(finishTime, task.time) + task.duration;
        result.put(task.index, finishTime);
        return finishTime;
    }
}

class TaskComparator implements Comparator<Task> {
    public int compare(Task a, Task b) {
        return a.time - b.time;
    }
}



import java.util.Queue;
import java.util.LinkedList;
import java.util.HashMap;

public class codeforces_644_B{
    public static void main(String[] args) {
        Queue<Task> remaining = new LinkedList<>();
        boolean running = false;
        int finishTime = 0;

        int n = 5; // Replace with actual value
        int b = 2; // Replace with actual value

        int[][] tasks = new int[n][3]; // Replace with actual values

        for (int i = 0; i < n; i++) {
            int time = tasks[i][0];
            int duration = tasks[i][1];
            int index = tasks[i][2];

            Task task = new Task(time, duration, index);

            if (task.time > finishTime && remaining.isEmpty()) {
                running = true;
                finishTime = task.time + task.duration;
            } else {
                if (task.time >= finishTime &&!remaining.isEmpty()) {
                    finishTime = Math.max(finishTime, task.time) + task.duration;
                }
                if (remaining.size() < b) {
                    remaining.add(task);
                } else {
                    task.result = -1;
                }
            }
        }

        while (!remaining.isEmpty()) {
            Task task = remaining.poll();
            finishTime = Math.max(finishTime, task.time) + task.duration;
        }

        HashMap<Integer, Integer> result = new HashMap<>();
        for (int i = 0; i < n; i++) {
            result.put(i, finishTime);
        }

        for (int key : result.keySet()) {
            System.out.println(result.get(key));
        }
    }
}

class Task {
    int time;
    int duration;
    int index;
    int result;

    public Task(int time, int duration, int index) {
        this.time = time;
        this.duration = duration;
        this.index = index;
    }
}

// Translate the above Java code to Python and end with comment "
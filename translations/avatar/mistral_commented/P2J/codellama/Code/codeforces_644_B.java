
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int b = sc.nextInt();
        Queue<Task> remaining = new LinkedList<>();
        int finish_time = 0;
        boolean running = false;
        int[] result = new int[n];
        for (int i = 0; i < n; i++) {
            int time = sc.nextInt();
            int duration = sc.nextInt();
            Task task = new Task(time, duration, i);
            result[i] = 0;
            if (task.time > finish_time && remaining.isEmpty()) {
                running = true;
                finish_time = task.time + task.duration;
                result[i] = finish_time;
            } else if (task.time >= finish_time && !remaining.isEmpty()) {
                finish_time = runTask(remaining, finish_time);
                if (remaining.size() < b) {
                    remaining.add(task);
                } else {
                    result[i] = -1;
                }
            }
        }
        while (!remaining.isEmpty()) {
            finish_time = runTask(remaining, finish_time);
        }
        for (int i = 0; i < n; i++) {
            System.out.println(result[i]);
        }
    }

    public static int runTask(Queue<Task> remaining, int finish_time) {
        Task task_to_run = remaining.remove();
        finish_time = Math.max(finish_time, task_to_run.time) + task_to_run.duration;
        result[task_to_run.index] = finish_time;
        return finish_time;
    }

    public static class Task {
        int time;
        int duration;
        int index;

        public Task(int time, int duration, int index) {
            this.time = time;
            this.duration = duration;
            this.index = index;
        }
    }
}


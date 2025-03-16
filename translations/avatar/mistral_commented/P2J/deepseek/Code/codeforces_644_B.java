import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Task {
    int time;
    int duration;
    int index;

    Task(int time, int duration, int index) {
        this.time = time;
        this.duration = duration;
        this.index = index;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int b = scanner.nextInt();

        Queue<Task> remaining = new LinkedList<>();
        int[] result = new int[n];
        boolean running = false;
        int finish_time = 0;

        for (int i = 0; i < n; i++) {
            int time = scanner.nextInt();
            int duration = scanner.nextInt();
            Task task = new Task(time, duration, i);
            result[i] = 0;

            if (time > finish_time && remaining.isEmpty()) {
                running = true;
                finish_time = time + duration;
                result[i] = finish_time;
            } else if (time >= finish_time && !remaining.isEmpty()) {
                finish_time = runTask(remaining, finish_time, result);
                if (remaining.size() < b) {
                    remaining.add(task);
                } else {
                    result[i] = -1;
                }
            }
        }

        while (!remaining.isEmpty()) {
            finish_time = runTask(remaining, finish_time, result);
        }

        for (int time : result) {
            System.out.println(time);
        }
    }

    private static int runTask(Queue<Task> remaining, int finish_time, int[] result) {
        Task taskToRun = remaining.poll();
        finish_time = Math.max(finish_time, taskToRun.time) + taskToRun.duration;
        result[taskToRun.index] = finish_time;
        return finish_time;
    }
}

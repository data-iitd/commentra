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
        int finishTime = 0;
        int[] result = new int[n];

        for (int i = 0; i < n; i++) {
            int time = scanner.nextInt();
            int duration = scanner.nextInt();
            Task task = new Task(time, duration, i);
            if (time > finishTime && remaining.isEmpty()) {
                finishTime = time + duration;
                result[i] = finishTime;
            } else {
                if (time >= finishTime && !remaining.isEmpty()) {
                    finishTime = runTask(remaining, finishTime);
                }
                if (remaining.size() < b) {
                    remaining.add(task);
                } else {
                    result[i] = -1;
                }
            }
        }

        while (!remaining.isEmpty()) {
            finishTime = runTask(remaining, finishTime);
        }

        for (int i = 0; i < n; i++) {
            System.out.println(result[i]);
        }
    }

    private static int runTask(Queue<Task> remaining, int finishTime) {
        Task taskToRun = remaining.poll();
        finishTime = Math.max(finishTime, taskToRun.time) + taskToRun.duration;
        int[] result = new int[taskToRun.index];
        result[taskToRun.index] = finishTime;
        return finishTime;
    }
}

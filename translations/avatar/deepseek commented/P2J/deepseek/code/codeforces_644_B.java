import java.util.HashMap;
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
        HashMap<Integer, Integer> result = new HashMap<>();
        int finishTime = 0;
        boolean running = false;

        for (int i = 0; i < n; i++) {
            int time = scanner.nextInt();
            int duration = scanner.nextInt();
            Task task = new Task(time, duration, i);
            result.put(i, 0);
            if (task.time > finishTime && remaining.isEmpty()) {
                running = true;
                finishTime = task.time + task.duration;
                result.put(i, finishTime);
            } else {
                if (task.time >= finishTime && !remaining.isEmpty()) {
                    finishTime = processTask(remaining, finishTime, result);
                }
                if (remaining.size() < b) {
                    remaining.add(task);
                } else {
                    result.put(i, -1);
                }
            }
        }

        while (!remaining.isEmpty()) {
            finishTime = processTask(remaining, finishTime, result);
        }

        for (int key : result.keySet()) {
            System.out.println(result.get(key));
        }
    }

    private static int processTask(Queue<Task> remaining, int finishTime, HashMap<Integer, Integer> result) {
        Task taskToRun = remaining.poll();
        finishTime = Math.max(finishTime, taskToRun.time) + taskToRun.duration;
        result.put(taskToRun.index, finishTime);
        return finishTime;
    }
}

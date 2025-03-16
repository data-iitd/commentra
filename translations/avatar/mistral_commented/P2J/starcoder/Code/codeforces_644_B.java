
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Map;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int b = sc.nextInt();
        Queue<Task> remaining = new PriorityQueue<Task>(new TaskComparator());
        Map<Integer, Integer> result = new HashMap<Integer, Integer>();
        int finishTime = 0;
        boolean running = false;
        for (int i = 0; i < n; i++) {
            int time = sc.nextInt();
            int duration = sc.nextInt();
            Task task = new Task(time, duration, i);
            result.put(i, 0);
            if (task.time > finishTime && remaining.isEmpty()) {
                running = true;
                finishTime = task.time + task.duration;
                result.put(i, finishTime);
            } else if (task.time >= finishTime &&!remaining.isEmpty()) {
                finishTime = executeTask(remaining, finishTime, result);
                if (remaining.size() < b) {
                    remaining.add(task);
                } else {
                    result.put(i, -1);
                }
            }
        }
        while (!remaining.isEmpty()) {
            finishTime = executeTask(remaining, finishTime, result);
        }
        for (int key : result.keySet()) {
            System.out.println(result.get(key));
        }
    }

    public static int executeTask(Queue<Task> remaining, int finishTime, Map<Integer, Integer> result) {
        Task task = remaining.poll();
        finishTime = Math.max(finishTime, task.time) + task.duration;
        result.put(task.index, finishTime);
        return finishTime;
    }
}

class Task {
    int time;
    int duration;
    int index;

    public Task(int time, int duration, int index) {
        this.time = time;
        this.duration = duration;
        this.index = index;
    }
}

class TaskComparator implements Comparator<Task> {
    @Override
    public int compare(Task t1, Task t2) {
        return t1.time - t2.time;
    }
}


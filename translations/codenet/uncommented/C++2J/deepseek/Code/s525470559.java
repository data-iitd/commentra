public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        int q = scanner.nextInt();
        int elaps = 0;
        java.util.Queue<Task> queue = new java.util.LinkedList<>();

        for (int i = 0; i < n; i++) {
            Task task = new Task();
            task.name = scanner.next();
            task.time = scanner.nextInt();
            queue.add(task);
        }

        while (!queue.isEmpty()) {
            Task task = queue.poll();
            if (task.time <= q) {
                elaps += task.time;
                System.out.println(task.name + " " + elaps);
            } else {
                task.time -= q;
                elaps += q;
                queue.add(task);
            }
        }
    }

    static class Task {
        String name;
        int time;
    }
}

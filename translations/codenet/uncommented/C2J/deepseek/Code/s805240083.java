public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        int q = scanner.nextInt();
        java.util.Queue<Process> queue = new java.util.LinkedList<>();

        for (int i = 0; i < n; i++) {
            String name = scanner.next();
            int time = scanner.nextInt();
            queue.add(new Process(name, time));
        }

        int totalTime = 0;
        while (!queue.isEmpty()) {
            Process process = queue.poll();
            if (process.time > q) {
                process.time -= q;
                totalTime += q;
                queue.add(process);
            } else {
                totalTime += process.time;
                System.out.println(process.name + " " + totalTime);
                n--;
            }
        }
    }

    static class Process {
        String name;
        int time;

        Process(String name, int time) {
            this.name = name;
            this.time = time;
        }
    }
}

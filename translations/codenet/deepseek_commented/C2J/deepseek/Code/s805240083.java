public class ProcessScheduler {
    static class Process {
        String name;
        int time;

        Process(String name, int time) {
            this.name = name;
            this.time = time;
        }
    }

    public static void main(String[] args) {
        java.util.Queue<Process> queue = new java.util.LinkedList<>();
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        int q = scanner.nextInt();
        scanner.nextLine(); // Consume newline

        for (int i = 0; i < n; i++) {
            String[] input = scanner.nextLine().split(" ");
            queue.add(new Process(input[0], Integer.parseInt(input[1])));
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
            }
        }
    }
}

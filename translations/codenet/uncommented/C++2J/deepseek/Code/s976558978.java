public class Main {
    public static void main(String[] args) {
        // RUN_LOCAL("dataabc155A.txt");
        int a = readi();
        int b = readi();
        if (a < b) {
            for (int i = 0; i < b; i++) {
                System.out.print(a);
            }
            System.out.println();
        } else {
            for (int i = 0; i < a; i++) {
                System.out.print(b);
            }
            System.out.println();
        }
    }

    // Assuming these methods are defined somewhere in the code
    public static int readi() {
        // Implementation to read an integer from standard input
        return 0;
    }


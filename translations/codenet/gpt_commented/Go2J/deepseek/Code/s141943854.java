public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String sage = scanner.nextLine();

        switch (sage) {
            case "1":
                System.out.println("Hello World");
                break;
            case "2":
                int sum = 0;
                for (int i = 0; i < 2; i++) {
                    int num = scanner.nextInt();
                    sum += num;
                }
                System.out.println(sum);
                break;
        }
    }
}

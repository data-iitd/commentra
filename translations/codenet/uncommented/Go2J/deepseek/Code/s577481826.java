public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = Integer.parseInt(scanner.nextLine());
        int b = Integer.parseInt(scanner.nextLine());

        int ret = a + b;

        if (ret < (a - b)) {
            ret = a - b;
        }
        if (ret < (a * b)) {
            ret = a * b;
        }

        System.out.println(ret);
    }
}

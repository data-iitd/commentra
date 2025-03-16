public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String s = scanner.nextLine();

        int n = countOccurrences(s, "o");
        System.out.println(700 + n * 100);
    }

    public static int countOccurrences(String str, String target) {
        if (str == null || target == null) {
            return 0;
        }
        int count = 0;
        int index = 0;
        while ((index = str.indexOf(target, index)) != -1) {
            count++;
            index += target.length();
        }
        return count;
    }
}

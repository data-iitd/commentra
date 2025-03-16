public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String s = scanner.nextLine();

        int max_tmp = 0;
        int max = 0;
        for (int i = 0; i < s.length(); i++) {
            boolean flag = false;
            char c = s.charAt(i);
            switch (c) {
                case 'A':
                case 'C':
                case 'T':
                case 'G':
                    max_tmp++;
                    break;
                default:
                    flag = true;
            }

            if (i == s.length() - 1) {
                flag = true;
            }
            if (flag) {
                if (max < max_tmp) {
                    max = max_tmp;
                }
                max_tmp = 0;
            }
        }
        System.out.println(max);
    }
}

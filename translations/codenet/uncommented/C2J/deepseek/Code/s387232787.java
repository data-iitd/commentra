public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int[] c = new int[26];
        while (scanner.hasNext()) {
            String str = scanner.next();
            for (char ch : str.toCharArray()) {
                if ('a' <= ch && ch <= 'z') {
                    c[ch - 'a']++;
                } else if ('A' <= ch && ch <= 'Z') {
                    c[ch - 'A']++;
                }
            }
        }
        for (int i = 0; i < 26; i++) {
            System.out.println((char) ('a' + i) + " : " + c[i]);
        }
    }
}

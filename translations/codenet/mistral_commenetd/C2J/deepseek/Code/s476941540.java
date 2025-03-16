public class Main {
    public static void main(String[] args) {
        int[] alpha = new int[26];
        int i;
        char ch;

        for (i = 0; i < 26; i++) {
            alpha[i] = 0;
        }

        while (true) {
            ch = (char) System.in.read();
            if (ch == -1) break;

            if (Character.isLetter(ch)) {
                if (Character.isUpperCase(ch)) {
                    alpha[ch - 'A']++;
                } else {
                    alpha[ch - 'a']++;
                }
            }
        }

        ch = 'a';
        for (i = 0; i < 26; i++, ch++) {
            System.out.println(ch + " : " + alpha[i]);
        }
    }
}

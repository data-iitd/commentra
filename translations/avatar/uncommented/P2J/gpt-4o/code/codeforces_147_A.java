import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        List<String> res = new ArrayList<>();
        char[] punctuation = {',', '.', '!', '?'};

        for (int i = 0; i < s.length(); i++) {
            char currentChar = s.charAt(i);
            if (i >= 1) {
                if (currentChar == ' ') {
                    if (!res.isEmpty() && !res.get(res.size() - 1).equals(" ")) {
                        res.add(" ");
                    }
                } else {
                    boolean isPunctuation = false;
                    for (char p : punctuation) {
                        if (currentChar == p) {
                            isPunctuation = true;
                            break;
                        }
                    }
                    if (isPunctuation) {
                        if (!res.isEmpty() && res.get(res.size() - 1).equals(" ")) {
                            res.remove(res.size() - 1);
                        }
                        res.add(String.valueOf(currentChar));
                        res.add(" ");
                    } else {
                        res.add(String.valueOf(currentChar));
                    }
                }
            } else {
                if (currentChar == ' ') {
                    continue;
                }
                if (new String(punctuation).indexOf(currentChar) >= 0) {
                    continue;
                } else {
                    res.add(String.valueOf(currentChar));
                }
            }
        }
        System.out.print(String.join("", res));
        scanner.close();
    }
}
// <END-OF-CODE>

public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String str = scanner.next();
        String p = scanner.next();
        
        String tmp = str;
        str = str + tmp;
        
        int slen = str.length();
        int plen = p.length();
        
        boolean flag = false;
        for (int i = 0; i < slen - plen; i++) {
            if (str.substring(i, i + plen).equals(p)) flag = true;
        }
        
        if (flag) System.out.println("Yes");
        else System.out.println("No");
    }
}

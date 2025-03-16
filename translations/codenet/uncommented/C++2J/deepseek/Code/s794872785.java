import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        List<String> strList = new ArrayList<>();
        String input;
        
        while ((input = br.readLine()) != null) {
            strList.add(input);
        }
        
        int maxSize = 0;
        int maxCount = 0;
        String ansNum = "";
        String ansNum2 = "";
        
        for (int i = 0; i < strList.size(); i++) {
            String s = strList.get(i);
            if (maxSize < s.length()) {
                maxSize = s.length();
                ansNum = s;
            }
        }
        
        for (int i = 0; i < strList.size(); i++) {
            String s = strList.get(i);
            int count = 0;
            for (int j = 0; j < strList.size(); j++) {
                if (strList.get(j).equals(s)) {
                    count++;
                }
            }
            if (maxCount < count) {
                maxCount = count;
                ansNum2 = s;
            }
        }
        
        System.out.println(ansNum2 + " " + ansNum);
    }
}


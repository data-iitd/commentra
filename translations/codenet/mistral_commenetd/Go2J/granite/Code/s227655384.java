
// Package main is the entry point of the program
package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

// ReadLongLines function reads long lines from standard input
public class s227655384{
    public static List<String> readLongLines(int times) throws IOException {
        List<String> result = new ArrayList<>();
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder buffer = new StringBuilder();
        int readBytes = 2;

        for (int i = 0; i < times; i++) {
            while (true) {
                String readLine = reader.readLine();
                if (readLine == null) {
                    System.out.println("EOF");
                    break;
                }
                buffer.append(readLine);
                if (!reader.ready()) {
                    result.add(buffer.toString());
                    buffer.setLength(0);
                    break;
                }
            }
            reader.reset();
        }
        return result;
    }
}

// Console class is used to manage the standard output
public class s227655384{
    private java.io.BufferedWriter writer;

    public Console() {
        this.writer = new java.io.BufferedWriter(new java.io.OutputStreamWriter(System.out));
    }

    public void printf(String format, Object... args) {
        try {
            this.writer.write(String.format(format, args));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void println(String s) {
        try {
            this.writer.write(s + "\n");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void close() {
        try {
            this.writer.flush();
            this.writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

// s227655384 class is the entry point of the program
public class s227655384{
    public static void main(String[] args) {
        Console con = new Console();
        List<String> lines;
        try {
            lines = ReadLongLines.readLongLines(4);
            String[] a = lines.get(1).split(" ");
            List<Integer> list = new ArrayList<>();
            for (String s : a) {
                list.add(Integer.parseInt(s));
            }
            String[] b = lines.get(3).split(" ");
            for (String s : b) {
                int n = Integer.parseInt(s);
                if (!list.contains(n)) {
                    list.add(n);
                }
            }
            Collections.sort(list);
            for (int i : list) {
                con.printf("%d\n", i);
            }
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            con.close();
        }
    }
}

// 


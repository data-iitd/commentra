
package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    // Direction vectors for 8 possible movements (up, down, left, right, and diagonals)
    private static final int[] dx = {0, 1, 1, 1, 0, -1, -1, -1, 0};
    private static final int[] dy = {1, 1, 0, -1, -1, -1, 0, 1, 0};

    // Define an infinite value for comparison
    private static final int inf = Integer.MAX_VALUE;

    // Initialize a new scanner for input
    private static Scanner next = new Scanner();

    // ---------------------------------------------------------
    // init function to set up logging and random seed
    static {
        System.setProperty("java.util.logging.SimpleFormatter.format", "%5$s %n");
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.format=" + System.getProperty("java.util.logging.SimpleFormatter.format"));
        System.out.println("java.util.logging.SimpleFormatter.form
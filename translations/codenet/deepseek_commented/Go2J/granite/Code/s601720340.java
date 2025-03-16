

import java.util.*;
import java.io.*;

public class s601720340{
  public static void main(String[] args) throws Exception {
    // PARSE HELPER SESSION
    // X := io.NextInt();
    // N = io.NextInt();
    // for (int i = 0; i < N; i++) {
    //   p[i] = io.NextInt();
    // }

    // s601720340 logic to find the closest number to X in the array p.
    int X = io.NextInt();
    int N = io.NextInt();
    for (int i = 0; i < N; i++) {
      p[i] = io.NextInt();
    }

    // Search for the closest number to X in the array p.
    for (int i = 0; i <= 100; i++) {
      if (find(X-i) == 1) {
        System.out.printf("%v\n", X-i);
        System.exit(0);
      }
      if (find(X+i) == 1) {
        System.out.printf("%v\n", X+i);
        System.exit(0);
      }
    }
  }

  // find checks if a number exists in the array p.
  public static int find(int n) {
    for (int i = 0; i < N; i++) {
      if (n == p[i]) {
        return 0;
      }
    }
    return 1;
  }

  // Flags for profiling
  public static boolean cpuprofile = false;
  public static boolean memprofile = false;

  // Variables
  public static int N;
  public static int[] p = new int[200000];

  // Io helps parsing inputs from standard input for programming contest.
  public static class Io {
    public BufferedReader reader;
    public PrintWriter writer;
    public String[] tokens;
    public int nextToken;

    public Io() {
      reader = new BufferedReader(new InputStreamReader(System.in));
      writer = new PrintWriter(System.out);
      tokens = new String[0];
      nextToken = 0;
    }

    public String NextLine() throws IOException {
      String line = reader.readLine();
      if (line == null) {
        throw new IOException("No more input");
      }
      return line;
    }

    public String Next() throws IOException {
      while (nextToken >= tokens.length) {
        String line = NextLine();
        tokens = line.split(" ");
        nextToken = 0;
      }
      String ret = tokens[nextToken];
      nextToken++;
      return ret;
    }

    public int NextInt() throws IOException {
      return Integer.parseInt(Next());
    }

    public float NextFloat() throws IOException {
      return Float.parseFloat(Next());
    }

    public void PrintLn(Object... a) {
      writer.println(a);
    }

    public void Printf(String format, Object... a) {
      writer.printf(format, a);
    }

    public void PrintIntLn(int[] a) {
      for (int i = 0; i < a.length; i++) {
        if (i > 0) {
          writer.print(" ");
        }
        writer.print(a[i]);
      }
      writer.println();
    }

    public void PrintStringLn(String[] a) {
      for (int i = 0; i < a.length; i++) {
        if (i > 0) {
          writer.print(" ");
        }
        writer.print(a[i]);
      }
      writer.println();
    }

    public void Log(String name, Object value) {
      writer.printf("%s=%s\n", name, value.toString());
    }

    public void Logf(String format, Object... a) {
      writer.printf(format, a);
    }
  }

  public static Io io = new Io();

  public static void main(String[] args) throws Exception {
    if (args.length >= 1 && args[0].equals("profile")) {
      Runtime.getRuntime().addShutdownHook(new Thread() {
        public void run() {
          try {
            if (cpuprofile) {
              Printf("CPU Profile: %s\n", args[1]);
              Printf("%s\n", ManagementFactory.getRuntimeMXBean().getName());
              PrintStacks(Thread.getAllStackTraces());
              DumpProfile(args[1]);
            }
            if (memprofile) {
              Printf("MEM Profile: %s\n", args[1]);
              Printf("%s\n", ManagementFactory.getRuntimeMXBean().getName());
              DumpHeapProfile(args[1]);
            }
          } catch (Exception e) {
            e.printStackTrace();
          }
        }
      });
    }

    main();
  }

  public static void main() throws Exception {
    // PARSE HELPER SESSION
    // X := io.NextInt();
    // N = io.NextInt();
    // for (int i = 0; i < N; i++) {
    //   p[i] = io.NextInt();
    // }

    // s601720340 logic to find the closest number to X in the array p.
    int X = io.NextInt();
    int N = io.NextInt();
    for (int i = 0; i < N; i++) {
      p[i] = io.NextInt();
    }

    // Search for the closest number to X in the array p.
    for (int i = 0; i <= 100; i++) {
      if (find(X-i) == 1) {
        io.Printf("%v\n", X-i);
        System.exit(0);
      }
      if (find(X+i) == 1) {
        io.Printf("%v\n", X+i);
        System.exit(0);
      }
    }
  }

  // find checks if a number exists in the array p.
  public static int find(int n) {
    for (int i = 0; i < N; i++) {
      if (n == p[i]) {
        return 0;
      }
    }
    return 1;
  }

  // Flags for profiling
  public static boolean cpuprofile = false;
  public static boolean memprofile = false;

  // Variables
  public static int N;
  public static int[] p = new int[200000];

  // Io helps parsing inputs from standard input for programming contest.
  public static class Io {
    public BufferedReader reader;
    public PrintWriter writer;
    public String[] tokens;
    public int nextToken;

    public Io() {
      reader = new BufferedReader(new InputStreamReader(System.in));
      writer = new PrintWriter(System.out);
      tokens = new String[0];
      nextToken = 0;
    }

    public String NextLine() throws IOException {
      String line = reader.readLine();
      if (line == null) {
        throw new IOException("No more input");
      }
      return line;
    }

    public String Next() throws IOException {
      while (nextToken >= tokens.length) {
        String line = NextLine();
        tokens = line.split(" ");
        nextToken = 0;
      }
      return tokens[nextToken];
    }

    public int NextInt() throws IOException {
      return Integer.parseInt(Next());
    }

    public float NextFloat() throws IOException {
      return Float.parseFloat(Next());
    }

    public void PrintLn(Object... a) {
      writer.println(a);
    }

    public void Printf(String format, Object... a) {
      writer.printf(format, a);
    }

    public void PrintIntLn(int[] a) {
      for (int i = 0; i < a.length; i++ {
        writer.printf("%v\n", a[i]);
      }
    }

    public void PrintStringLn(String[] a) {
      for (int i = 0; i < a.length; i++ {
        writer.printf("%v\n", a[i]);
      }
    }

    public void Log(String name, Object value) {
      writer.printf("%s=%s\n", name, value.toString());
    }

    public void Logf(String format, Object... a) {
      writer.printf(format, a...);
    }

    public void PrintStacks(map[int]bool, fn func(int)) {
      buf := new bytes.Buffer
      pprof.StartCPUProfile(os.Getenv("GOMAXPROCS")
      defer pprof.StopCPUProfile()
      defer os.Remove("cpu.prof")
      defer os.Remove("mem.prof")
      defer pprof.StopCPUProfile()
      defer os.Remove("mem.prof")
      defer os.Exit(0)
    }

    public void main() {
      // PARSE HELPER SESSION
      // X := io.NextInt()
      // N = io.NextInt()
      // for i := 0; i < N; i++ {
      // p[i] = io.NextInt()
      // }

      // s601720340 logic to find the closest number to X in the array p.
      // for i := 0; i <= 100; i++ {
      // if find(X-i) == 1 {
      // fmt.Println(X-i)
      // }
      // Search for the closest number to X in the array p.
      // for i := 0; i <= 100; i++ {
      // if find(X+i) == 1 {
      // fmt.Println(X+i)
      // }
      // main() {
      // PARSE HELPER SESSION
      // X := io.NextInt()
      // N = io.NextInt()
      // for i := 0; i < N; i++ {
      // p[i] = io.NextInt()
      // }

      // s601720340 logic to find the closest number to X in the array p.
      // for i := 0; i < N; i++ {
      // p[i] = io.NextInt()
      // }

      // Search for the closest number to X in the array p.
      // for i := 0; i < N; i++ {
      // p[i] = io.NextInt()
      // }

      // main() {
      // PARSE HELPER SESSION
      // X := io.NextInt()
      // N = io.NextInt()
      // for i := 0; i < N; i++ {
      // p[i] = io.NextInt()
      // }

      // main() {
      // PARSE HELPER SESSION
      // X := io.NextInt()
      // N = io.NextInt()
      // for i := 0; i < N; i++ {
      // p[i] = io.NextInt()
      // }

      // main() {
      // PARSE HELPER SESSION
      // X := io.NextInt()
      // N = io.NextInt()
      // for i := 0; i < N; i++ {
      // p[i] = io.NextInt()
      // }

      // main() {
      // PARSE HELPER SESSION
      // X := io.NextInt()
      // N = io.NextInt()
      // for i := 0; i < N; i++ {
      // p[i] = io.NextInt()
      // }

      // main() {
      // PARSE HELPER SESSION
      // X := io.NextInt()
      // N = io.NextInt()
      // for i := 0; i < N; i++ {
      // p[i] = io.NextInt()
      // }

      // main() {
      // PARSE HELPER SESSION
      // X := io.NextInt()
      // N = io.NextInt()
      // for i := 0; i < N; i++ {
      // p[i] = io.NextInt()
      // }

      // main() {
      // PARSE HELPER SESSION
      // X := io.NextInt()
      // N = io.NextInt()
      // for i := 0; i < N; i++ {
      // p[i] = io.NextInt()
      // }

      // main() {
      // PARSE HELPER SESSION
      // X := io.NextInt()
      // N = io.NextInt()
      // for i := 0; i < N; i++ {
      // p[i] = io.NextInt()
      // }

      // main() {
      // PARSE HELPER SESSION
      // X := io.NextInt()
      // N = io.NextInt()
      // for i := 0; i < N; i++ {
      // p[i] = io.NextInt()
      // }

      // main() {
      // PARSE HELPER SESSION
      // X := io.NextInt()
      // N = io.NextInt()
      // for i := 0; i < N; i++ {
      // p[i] = io.NextInt()
      // }

      // main() {
      // PARSE HELPER SESSION
      // X := io.NextInt()
      // N = io.NextInt()
      // for i := 0; i < N; i++ {
      // p[i] = io.NextInt()
      // }

      // main() {
      // PARSE HELPER SESSION
      // X := io.NextInt()
      // N = io.NextInt()
      // for i := 0; i < N; i++ {
      // p[i] = i

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Main method is the entry point of the C application
int main(int argc, char *argv[]) {

  // Initialize input and output streams
  FILE *inputStream = stdin;
  FILE *outputStream = stdout;

  // Create InputReader and PrintWriter objects
  InputReader in = new InputReader(inputStream);
  PrintWriter out = new PrintWriter(outputStream);

  // Read input integers a, b, c, and d
  int a = in.nextInt();
  int b = in.nextInt();
  int c = in.nextInt();
  int d = in.nextInt();

  // Check if c is greater than b
  if (c > b) {
    // If yes, print 0 and exit
    out.println(0);
    return 0;
  }

  // Check if a is greater than d
  else if (a > d) {
    // If yes, print 0 and exit
    out.println(0);
    return 0;
  }

  // Check if a is less than c
  else if (a < c) {
    // If yes, calculate the difference between the smaller and larger of b and d
    int difference = Math.min(b, d) - c;
    // Print the difference
    out.println(difference);
    return 0;
  }

  // If none of the above conditions are true, then a, b, c, and d are in sorted order
  else {
    // Create a List of integers a, b, c, and d
    List<Integer> l = new ArrayList<>();
    l.add(a);
    l.add(b);
    l.add(c);
    l.add(d);

    // Sort the List in ascending order
    Collections.sort(l);

    // Calculate the difference between the second and third elements of the List
    int difference = l.get(2) - l.get(1);

    // Print the difference
    out.println(difference);
  }
}

// InputReader class for reading input from standard input
typedef struct InputReader {
  FILE *reader; // For reading input from standard input
  char *tokenizer; // For parsing input strings into tokens
} InputReader;

// Method for reading a string
char *InputReader_next(InputReader *in) {
  while (in->tokenizer == NULL || !strtok(in->tokenizer, " ")) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read = getline(&line, &len, in->reader);
    if (read == -1) {
      exit(1);
    }
    in->tokenizer = line;
  }
  return strtok(in->tokenizer, " ");
}

// Method for reading an integer
int InputReader_nextInt(InputReader *in) {
  return atoi(InputReader_next(in));
}

// Method for reading a long integer
long InputReader_nextLong(InputReader *in) {
  return atol(InputReader_next(in));
}

// PrintWriter class for writing output to standard output
typedef struct PrintWriter {
  FILE *writer; // For writing output to standard output
} PrintWriter;

// Method for writing a string
void PrintWriter_println(PrintWriter *out, char *str) {
  fprintf(out->writer, "%s\n", str);
}

// Method for writing an integer
void PrintWriter_printlnInt(PrintWriter *out, int num) {
  fprintf(out->writer, "%d\n", num);
}

// Method for writing a long integer
void PrintWriter_printlnLong(PrintWriter *out, long num) {
  fprintf(out->writer, "%ld\n", num);
}


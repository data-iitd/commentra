
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Scanner;

public class Main {
    // Declare constants and instance variables
    private static final int DEFAULT_BUFFER_SIZE = 5;
    private int bufferSize;
    private final byte[] buffer;
    private int posRead = 0;
    private int bufferPos = 0;
    private boolean foundEof = false;
    private InputStream input;

    // Constructor for byte array input
    public Main(byte[] input, int bufferSize) throws IOException {
        this(new ByteArrayInputStream(input), bufferSize);
    }

    // Constructor for InputStream input
    public Main(InputStream input, int bufferSize) throws IOException {
        this.input = input;
        // Check if the stream is empty or already closed
        if (input.available() == -1) {
            throw new IOException("Empty or already closed stream provided");
        }
        // Initialize buffer size
        this.bufferSize = bufferSize;
        // Initialize buffer
        buffer = new byte[bufferSize];
    }

    // Read a single byte from the input stream
    public int read() throws IOException {
        // Check if the buffer needs to be refilled
        if (needsRefill()) {
            // If end of file is reached, return -1
            if (foundEof) {
                return -1;
            }
            // Refill the buffer
            refill();
        }
        // Return the next byte from the buffer
        return posRead < bufferPos ? buffer[posRead++] & 0xff : -1;
    }

    // Get the number of bytes available to read from the input stream
    public int available() throws IOException {
        // Get the number of bytes available from the input stream
        int available = input.available();
        // If the buffer needs to be refilled, return the number of bytes available from the input stream
        if (needsRefill()) {
            return available;
        }
        // Otherwise, return the number of bytes remaining in the buffer and the number of bytes available from the input stream
        return bufferPos - posRead + available;
    }

    // Read a block of bytes from the input stream into a byte array
    public byte[] readBlock() throws IOException {
        // Save the current buffer position and number of bytes read
        pushRefreshData();
        // Create a new byte array with the same size as the buffer
        byte[] cloned = new byte[bufferSize];
        // Copy the contents of the buffer into the new byte array, if there are any
        if (bufferPos > 0) {
            System.arraycopy(buffer, 0, cloned, 0, bufferPos);
        }
        // Refill the buffer
        refill();
        // Return the cloned byte array
        return cloned;
    }

    // Check if the buffer needs to be refilled
    private boolean needsRefill() {
        // Return true if the number of bytes read from the buffer is equal to the number of bytes in the buffer
        return posRead == bufferPos;
    }

    // Refill the buffer with new data from the input stream
    private void refill() throws IOException {
        // Reset the buffer position and number of bytes read
        posRead = 0;
        bufferPos = 0;
        // Read bytes from the input stream into the buffer until it is full or the end of the stream is reached
        while (bufferPos < bufferSize) {
            int read = input.read();
            if (read == -1) {
                // If the end of the stream is reached, set the foundEof flag and break the loop
                foundEof = true;
                break;
            }
            // Store the read byte in the buffer
            buffer[bufferPos++] = (byte) read;
        }
    }

    // Save the current buffer position and number of bytes read, and refill the buffer
    private void pushRefreshData() throws IOException {
        // Calculate the number of bytes read from the buffer
        int length = bufferPos - posRead;
        // Copy the contents of the buffer from the current position to the beginning of the buffer
        System.arraycopy(buffer, posRead, buffer, 0, length);
        // Reset the buffer position and number of bytes read
        bufferPos = length;
        posRead = 0;
        // Refill the buffer
        refill();
    }

    // Close the input stream
    public void close() throws IOException {
        // Close the input stream, if it is not null
        if (input != null) {
            try {
                input.close();
            } finally {
                // Set the input stream to null
                input = null;
            }
        }
    }

    // Main method to test the implementation
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            // Read the buffer size from the standard input
            int bufferSize = scanner.nextInt();
            // Read the rest of the line from the standard input and discard it
            scanner.nextLine();
            // Read a line from the standard input and convert it to a byte array
            String inputString = scanner.nextLine();
            byte[] inputBytes = inputString.getBytes();
            // Create a new instance of the Main class with the byte array input and the specified buffer size
            Main bufferedReader = new Main(inputBytes, bufferSize);
            // Read bytes from the input stream and print them to the standard output until the end of the stream is reached
            int readByte;
            while ((readByte = bufferedReader.read()) != -1) {
                System.out.print((char) readByte);
            }
            // Close the input stream
            bufferedReader.close();
        } catch (IOException e) {
            // Print an error message if an error occurs
            System.err.println("An error occurred: " + e.getMessage());
        }
    }
}
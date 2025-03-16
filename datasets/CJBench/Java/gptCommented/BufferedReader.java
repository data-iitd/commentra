import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Scanner;

public class Main {
    // Default buffer size if none is provided
    private static final int DEFAULT_BUFFER_SIZE = 5;
    
    // Instance variables for buffer size, buffer array, read positions, and EOF flag
    private int bufferSize;
    private final byte[] buffer;
    private int posRead = 0; // Position to read from the buffer
    private int bufferPos = 0; // Current position in the buffer
    private boolean foundEof = false; // Flag to indicate end of stream
    private InputStream input; // Input stream to read data from

    // Constructor that initializes the input stream from a byte array
    public Main(byte[] input, int bufferSize) throws IOException {
        this(new ByteArrayInputStream(input), bufferSize);
    }

    // Constructor that initializes the input stream and buffer size
    public Main(InputStream input, int bufferSize) throws IOException {
        this.input = input;
        // Check if the input stream is empty or closed
        if (input.available() == -1) {
            throw new IOException("Empty or already closed stream provided");
        }
        this.bufferSize = bufferSize; // Set the buffer size
        buffer = new byte[bufferSize]; // Initialize the buffer array
    }

    // Method to read a single byte from the buffer or input stream
    public int read() throws IOException {
        // Check if the buffer needs to be refilled
        if (needsRefill()) {
            // If EOF has been found, return -1 to indicate no more data
            if (foundEof) {
                return -1;
            }
            refill(); // Refill the buffer
        }
        // Return the next byte from the buffer, or -1 if no more data
        return posRead < bufferPos ? buffer[posRead++] & 0xff : -1;
    }

    // Method to check how many bytes are available to read
    public int available() throws IOException {
        int available = input.available(); // Get available bytes from the input stream
        // If the buffer needs to be refilled, return available bytes
        if (needsRefill()) {
            return available;
        }
        // Return the total available bytes from the buffer and input stream
        return bufferPos - posRead + available;
    }

    // Method to read a block of bytes from the input stream
    public byte[] readBlock() throws IOException {
        pushRefreshData(); // Ensure any remaining data in the buffer is pushed to the front
        byte[] cloned = new byte[bufferSize]; // Create a new byte array for the block
        // Copy data from the buffer to the new array if there are bytes available
        if (bufferPos > 0) {
            System.arraycopy(buffer, 0, cloned, 0, bufferPos);
        }
        refill(); // Refill the buffer for the next read
        return cloned; // Return the block of bytes read
    }

    // Method to check if the buffer needs to be refilled
    private boolean needsRefill() {
        return posRead == bufferPos; // Return true if all bytes have been read from the buffer
    }

    // Method to refill the buffer with data from the input stream
    private void refill() throws IOException {
        posRead = 0; // Reset the read position
        bufferPos = 0; // Reset the buffer position
        // Read bytes from the input stream until the buffer is full or EOF is reached
        while (bufferPos < bufferSize) {
            int read = input.read(); // Read a byte from the input stream
            if (read == -1) { // Check for EOF
                foundEof = true; // Set EOF flag
                break; // Exit the loop if EOF is reached
            }
            buffer[bufferPos++] = (byte) read; // Store the byte in the buffer
        }
    }

    // Method to push remaining data in the buffer to the front for further processing
    private void pushRefreshData() throws IOException {
        int length = bufferPos - posRead; // Calculate remaining data length
        System.arraycopy(buffer, posRead, buffer, 0, length); // Shift remaining data to the front
        bufferPos = length; // Update the buffer position
        posRead = 0; // Reset the read position
        refill(); // Refill the buffer with new data
    }

    // Method to close the input stream
    public void close() throws IOException {
        if (input != null) {
            try {
                input.close(); // Close the input stream
            } finally {
                input = null; // Set input to null to avoid further access
            }
        }
    }

    // Main method to execute the program
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            // Read the buffer size from user input
            int bufferSize = scanner.nextInt();
            scanner.nextLine(); // Consume the newline character
            // Read the input string from user input
            String inputString = scanner.nextLine();
            // Create an instance of Main with the input string as bytes
            Main bufferedReader = new Main(inputString.getBytes(), bufferSize);
            int readByte;
            // Read bytes from the bufferedReader and print them as characters
            while ((readByte = bufferedReader.read()) != -1) {
                System.out.print((char) readByte);
            }
            bufferedReader.close(); // Close the bufferedReader
        } catch (IOException e) {
            // Handle any IO exceptions that occur during execution
            System.err.println("An error occurred: " + e.getMessage());
        }
    }
}

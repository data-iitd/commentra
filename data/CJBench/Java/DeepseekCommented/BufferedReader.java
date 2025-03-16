import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Scanner;
public class Main {
    // Default buffer size
    private static final int DEFAULT_BUFFER_SIZE = 5;
    
    // Fields to manage the buffer and input stream
    private int bufferSize;
    private final byte[] buffer;
    private int posRead = 0;
    private int bufferPos = 0;
    private boolean foundEof = false;
    private InputStream input;
    
    // Constructor that takes a byte array and buffer size
    public Main(byte[] input, int bufferSize) throws IOException {
        this(new ByteArrayInputStream(input), bufferSize);
    }
    
    // Constructor that takes an InputStream and buffer size
    public Main(InputStream input, int bufferSize) throws IOException {
        this.input = input;
        if (input.available() == -1) {
            throw new IOException("Empty or already closed stream provided");
        }
        this.bufferSize = bufferSize;
        buffer = new byte[bufferSize];
    }
    
    // Reads a single byte from the buffer or input stream
    public int read() throws IOException {
        if (needsRefill()) {
            if (foundEof) {
                return -1;
            }
            refill();
        }
        return posRead < bufferPos ? buffer[posRead++] & 0xff : -1;
    }
    
    // Returns the number of bytes available in the buffer or input stream
    public int available() throws IOException {
        int available = input.available();
        if (needsRefill()) {
            return available;
        }
        return bufferPos - posRead + available;
    }
    
    // Reads a block of data from the buffer and refills it if necessary
    public byte[] readBlock() throws IOException {
        pushRefreshData();
        byte[] cloned = new byte[bufferSize];
        if (bufferPos > 0) {
            System.arraycopy(buffer, 0, cloned, 0, bufferPos);
        }
        refill();
        return cloned;
    }
    
    // Checks if the buffer needs to be refilled
    private boolean needsRefill() {
        return posRead == bufferPos;
    }
    
    // Refills the buffer from the input stream
    private void refill() throws IOException {
        posRead = 0;
        bufferPos = 0;
        while (bufferPos < bufferSize) {
            int read = input.read();
            if (read == -1) {
                foundEof = true;
                break;
            }
            buffer[bufferPos++] = (byte) read;
        }
    }
    
    // Refills the buffer and pushes the read data to the front
    private void pushRefreshData() throws IOException {
        int length = bufferPos - posRead;
        System.arraycopy(buffer, posRead, buffer, 0, length);
        bufferPos = length;
        posRead = 0;
        refill();
    }
    
    // Closes the input stream
    public void close() throws IOException {
        if (input != null) {
            try {
                input.close();
            } finally {
                input = null;
            }
        }
    }
    
    // Main method to read input from the console, initialize the buffer, and read/print characters
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            int bufferSize = scanner.nextInt();
            scanner.nextLine(); 
            String inputString = scanner.nextLine();
            Main bufferedReader = new Main(inputString.getBytes(), bufferSize);
            int readByte;
            while ((readByte = bufferedReader.read()) != -1) {
                System.out.print((char) readByte);
            }
            bufferedReader.close();
        } catch (IOException e) {
            System.err.println("An error occurred: " + e.getMessage());
        }
    }
}

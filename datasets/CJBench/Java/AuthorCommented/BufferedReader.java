
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Scanner;

/**
 * Mimics the actions of the Original buffered reader
 * implements other actions, such as peek(n) to lookahead,
 * block() to read a chunk of size {BUFFER SIZE}
 * <p>
 * Author: Kumaraswamy B.G (Xoma Dev)
 */
public class BufferedReader {

    private static final int DEFAULT_BUFFER_SIZE = 5;

    /**
     * The maximum number of bytes the buffer can hold.
     * Value is changed when encountered Eof to not
     * cause overflow read of 0 bytes
     */
    private int bufferSize;
    private final byte[] buffer;

    /**
     * posRead -> indicates the next byte to read
     */
    private int posRead = 0;
    private int bufferPos = 0;

    private boolean foundEof = false;

    private InputStream input;

    public BufferedReader(byte[] input, int bufferSize) throws IOException {
        this(new ByteArrayInputStream(input), bufferSize);
    }

    public BufferedReader(InputStream input, int bufferSize) throws IOException {
        this.input = input;
        if (input.available() == -1) {
            throw new IOException("Empty or already closed stream provided");
        }

        this.bufferSize = bufferSize;
        buffer = new byte[bufferSize];
    }

    /**
     * Reads a single byte from the stream
     */
    public int read() throws IOException {
        if (needsRefill()) {
            if (foundEof) {
                return -1;
            }
            // the buffer is empty, or the buffer has
            // been completely read and needs to be refilled
            refill();
        }
        return posRead < bufferPos ? buffer[posRead++] & 0xff : -1;
    }

    /**
     * Number of bytes not yet been read
     */
    public int available() throws IOException {
        int available = input.available();
        if (needsRefill()) {
            return available;
        }
        return bufferPos - posRead + available;
    }

    /**
     * Reads one complete block of size {bufferSize}
     * if found eof, the total length of an array will
     * be that of what's available
     *
     * @return a completed block
     */
    public byte[] readBlock() throws IOException {
        pushRefreshData();

        byte[] cloned = new byte[bufferSize];
        // arraycopy() function is better than clone()
        if (bufferPos > 0) {
            System.arraycopy(buffer, 0, cloned, 0, bufferPos);
            // important to note that, bufferSize does not stay constant
            // once the class is defined. See justRefill() function
        }
        // we assume that already a chunk
        // has been read
        refill();
        return cloned;
    }

    private boolean needsRefill() {
        return posRead == bufferPos;
    }

    private void refill() throws IOException {
        posRead = 0;
        bufferPos = 0;
        // try to fill in the maximum we can until
        // we reach EOF
        while (bufferPos < bufferSize) {
            int read = input.read();
            if (read == -1) {
                // reached end-of-file, no more data left
                // to be read
                foundEof = true;
                // rewrite the BUFFER_SIZE, to know that we've reached
                // EOF when requested refill
                break;
            }
            buffer[bufferPos++] = (byte) read;
        }
    }

    private void pushRefreshData() throws IOException {
        int length = bufferPos - posRead;
        System.arraycopy(buffer, posRead, buffer, 0, length);
        bufferPos = length;
        posRead = 0;
        refill();
    }

    public void close() throws IOException {
        if (input != null) {
            try {
                input.close();
            } finally {
                input = null;
            }
        }
    }

    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            int bufferSize = scanner.nextInt();
            scanner.nextLine(); // Consume newline

            String inputString = scanner.nextLine();

            BufferedReader bufferedReader = new BufferedReader(inputString.getBytes(), bufferSize);

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

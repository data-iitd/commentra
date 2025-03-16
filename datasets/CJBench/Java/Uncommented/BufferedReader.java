
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Scanner;
public class BufferedReader {
    private static final int DEFAULT_BUFFER_SIZE = 5;
    private int bufferSize;
    private final byte[] buffer;
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
    public int read() throws IOException {
        if (needsRefill()) {
            if (foundEof) {
                return -1;
            }
            refill();
        }
        return posRead < bufferPos ? buffer[posRead++] & 0xff : -1;
    }
    public int available() throws IOException {
        int available = input.available();
        if (needsRefill()) {
            return available;
        }
        return bufferPos - posRead + available;
    }
    public byte[] readBlock() throws IOException {
        pushRefreshData();
        byte[] cloned = new byte[bufferSize];
        if (bufferPos > 0) {
            System.arraycopy(buffer, 0, cloned, 0, bufferPos);
        }
        refill();
        return cloned;
    }
    private boolean needsRefill() {
        return posRead == bufferPos;
    }
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
            System.out.println("Enter buffer size:");
            int bufferSize = scanner.nextInt();
            scanner.nextLine(); 
            System.out.println("Enter input string:");
            String inputString = scanner.nextLine();
            BufferedReader bufferedReader = new BufferedReader(inputString.getBytes(), bufferSize);
            System.out.println("Reading byte-by-byte:");
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



DEBUG = False

def SetInteractive(w, r):
    global InputBuffer, OutputBuffer, OutputWriter
    InputBuffer = []
    OutputBuffer = []
    OutputWriter = w

    def nextToken():
        while len(InputBuffer) == 0:
            InputBuffer = input().split()
        return InputBuffer.pop(0)

    def nextLine():
        return input()

    def SetInput(r):
        global nextToken, nextLine
        InputBuffer = []
        nextToken = lambda: InputBuffer.pop(0) if len(InputBuffer) == 0 else InputBuffer[0]
        nextLine = lambda: input()

    def SetOutput(w):
        global OutputBuffer, OutputWriter
        OutputBuffer = []
        OutputWriter = w

    def flush():
        global OutputBuffer, OutputWriter
        OutputWriter.write(''.join(OutputBuffer))
        OutputBuffer = []

    def printf(f, *args):
        global OutputBuffer, OutputWriter
        OutputBuffer.append(f.format(*args))
        OutputBuffer.append('\n')

    def println(*args):
        global OutputBuffer, OutputWriter
        OutputBuffer.append(''.join(args))
        OutputBuffer.append('\n')

    def eprintf(f, *args):
        global OutputBuffer, OutputWriter
        OutputBuffer.append(''.join(args))
        OutputBuffer.append('\n')

    def eprintln(*args):
        global OutputBuffer, OutputWriter
        OutputBuffer.append(''.join(args))
        OutputBuffer.append('\n')

    def debugf(f, *args):
        global DEBUG
        if DEBUG:
            OutputWriter.write(f.format(*args))
            OutputWriter.write('\n')

    def debug(*args):
        global DEBUG
        if DEBUG:
            OutputWriter.write(''.join(args))
            OutputWriter.write('\n')

    def readb():
        return nextToken()

    def reads():
        return nextLine()

    def readll():
        return int( reads() )

    def readi():
        return int( readToken() )

    def readf():
        return float( reads() )

    def readline():
        return readLine()

    def main():
        h, w, k = readi(), readi(), readi()
        m = [[0] * h for _ in range(h):
            m[i] = [0] * w for _ in range(w):
                m[i][j] = int( readToken() )

    def flush():
        global OutputBuffer, OutputWriter
        OutputWriter.write(''.join(OutputBuffer))
        OutputBuffer = []
        OutputWriter = w

    def printf(f, *args):
        OutputBuffer.append(f.format(*args))
        OutputBuffer.append('\n')

    def println(*args):
        OutputBuffer.append(''.join(args))
        OutputBuffer.append('\n')

    def eprintf(f, *args):
        OutputBuffer.append(f.format(*args))
        OutputBuffer.append('\n')

    def eprintln(*args):
        OutputBuffer.append(''.join(args))
        OutputBuffer.append('\n')

    def debugf(f, *args):
        global DEBUG
        if DEBUG:
            OutputBuffer.append(f.format(*args))
            OutputBuffer.append('\n')

    def debug(*args):
        global DEBUG
        if DEBUG:
            OutputBuffer.append(''.join(args))
            OutputBuffer.append('\n')

    def SetInteractive(w, r):
        global InputBuffer, OutputBuffer, OutputWriter
        InputBuffer = []
        OutputBuffer = []
        OutputWriter = w

    def SetInput(r):
        global InputBuffer
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer = []
        InputBuffer
# <START-OF-CODE>
import sys

class Task:
    def __init__(self):
        pass

    def solve(self, in_stream, out_stream):
        n = int(in_stream.readline())
        array = [0] * 1001
        for i in range(n):
            index = int(in_stream.readline())
            array[index] += 1

        count_max = -1
        for i in range(1, len(array)):
            if count_max < array[i]:
                count_max = array[i]

        if n % 2 == 0:
            if count_max <= n / 2:
                out_stream.write("YES\n")
            else:
                out_stream.write("NO\n")
        else:
            if count_max <= n / 2 + 1:
                out_stream.write("YES\n")
            else:
                out_stream.write("NO\n")

class InputReader:
    def __init__(self, stream):
        self.reader = stream
        self.tokenizer = None

    def next(self):
        while self.tokenizer == None or not self.tokenizer.hasMoreTokens():
            self.tokenizer = StringTokenizer(self.reader.readLine())
        return self.tokenizer.nextToken()

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return long(self.next())

    def nextDouble(self):
        return float(self.next())

    def nextLine(self):
        str = ""
        try:
            str = self.reader.readLine()
        except IOException as e:
            e.printStackTrace()
        return str

if __name__ == '__main__':
    task = Task()
    task.solve(InputReader(sys.stdin), PrintWriter(sys.stdout))
# 
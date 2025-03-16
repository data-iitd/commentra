
import sys

inputStream = sys.stdin
outputStream = sys.stdout
in = inputStream.readline()
s = in.strip()
if "A" in s and "B" in s:
    outputStream.write("Yes\n")
else:
    outputStream.write("No\n")

# END-OF-CODE
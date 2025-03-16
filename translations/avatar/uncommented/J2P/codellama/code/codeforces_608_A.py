
import sys
import math

def main ( ):
    in = FastScanner ( )
    sc = Scanner ( sys.stdin )
    o = PrintWriter ( sys.stdout )
    n = sc.nextInt ( )
    s = sc.nextInt ( )
    max = 0
    while n > 0:
        f = sc.nextInt ( )
        t = sc.nextInt ( )
        if max < f + t:
            max = f + t
    o.println ( max )
    o.close ( )

class FastScanner:
    def __init__ ( self ):
        self.br = BufferedReader ( InputStreamReader ( System.in ) )
        self.st = StringTokenizer ( "" )

    def next ( self ):
        while not self.st.hasMoreElements ( ):
            try:
                self.st = StringTokenizer ( self.br.readLine ( ) )
            except MalformedInputException:
                self.st = StringTokenizer ( "" )
        return self.st.nextToken ( )

    def nextLine ( self ):
        str = ""
        try:
            str = self.br.readLine ( )
        except MalformedInputException:
            str = ""
        return str

    def nextByte ( self ):
        return Byte.parseByte ( self.next ( ) )

    def nextShort ( self ):
        return Short.parseShort ( self.next ( ) )

    def nextInt ( self ):
        return Integer.parseInt ( self.next ( ) )

    def nextLong ( self ):
        return java.lang.Long.parseLong ( self.next ( ) )

    def nextDouble ( self ):
        return Double.parseDouble ( self.next ( ) )

class Scanner:
    def __init__ ( self , in ):
        self.in = in

    def next ( self ):
        return self.in.next ( )

    def nextLine ( self ):
        return self.in.nextLine ( )

    def nextByte ( self ):
        return self.in.nextByte ( )

    def nextShort ( self ):
        return self.in.nextShort ( )

    def nextInt ( self ):
        return self.in.nextInt ( )

    def nextLong ( self ):
        return self.in.nextLong ( )

    def nextDouble ( self ):
        return self.in.nextDouble ( )

class PrintWriter:
    def __init__ ( self , out ):
        self.out = out

    def println ( self , x ):
        self.out.write ( str ( x ) + "\n" )

    def close ( self ):
        self.out.close ( )

class BufferedReader:
    def __init__ ( self , in ):
        self.in = in

    def readLine ( self ):
        return self.in.readLine ( )

class InputStreamReader:
    def __init__ ( self , in ):
        self.in = in

class System:
    def __init__ ( self ):
        self.in = FastScanner ( )
        self.out = PrintWriter ( )

    def stdin ( self ):
        return self.in

    def stdout ( self ):
        return self.out

class Byte:
    def __init__ ( self ):
        pass

    def parseByte ( self , s ):
        return int ( s )

class Short:
    def __init__ ( self ):
        pass

    def parseShort ( self , s ):
        return int ( s )

class Integer:
    def __init__ ( self ):
        pass

    def parseInt ( self , s ):
        return int ( s )

class Long:
    def __init__ ( self ):
        pass

    def parseLong ( self , s ):
        return int ( s )

class Double:
    def __init__ ( self ):
        pass

    def parseDouble ( self , s ):
        return float ( s )

class StringTokenizer:
    def __init__ ( self , s ):
        self.s = s

    def hasMoreElements ( self ):
        return len ( self.s ) > 0

    def nextToken ( self ):
        return self.s

class MalformedInputException:
    def __init__ ( self ):
        pass

class String:
    def __init__ ( self , s ):
        self.s = s

    def __str__ ( self ):
        return self.s

class BufferedWriter:
    def __init__ ( self , out ):
        self.out = out

    def write ( self , s ):
        self.out.write ( s )

class OutputStreamWriter:
    def __init__ ( self , out ):
        self.out = out

class FileWriter:
    def __init__ ( self , out ):
        self.out = out

class File:
    def __init__ ( self , out ):
        self.out = out

class PrintStream:
    def __init__ ( self , out ):
        self.out = out

    def write ( self , s ):
        self.out.write ( s )

class ByteArrayOutputStream:
    def __init__ ( self ):
        pass

    def toByteArray ( self ):
        return []

class ByteArrayInputStream:
    def __init__ ( self , b ):
        pass

class InputStream:
    def __init__ ( self ):
        pass

class FileInputStream:
    def __init__ ( self , f ):
        pass

class FileOutputStream:
    def __init__ ( self , f ):
        pass

class IOException:
    def __init__ ( self ):
        pass

class Exception:
    def __init__ ( self ):
        pass

class RuntimeException:
    def __init__ ( self ):
        pass

class IllegalArgumentException:
    def __init__ ( self ):
        pass

class IllegalStateException:
    def __init__ ( self ):
        pass

class IndexOutOfBoundsException:
    def __init__ ( self ):
        pass

class NullPointerException:
    def __init__ ( self ):
        pass

class NumberFormatException:
    def __init__ ( self ):
        pass

class ArithmeticException:
    def __init__ ( self ):
        pass

class ArrayIndexOutOfBoundsException:
    def __init__ ( self ):
        pass

class StringIndexOutOfBoundsException:
    def __init__ ( self ):
        pass

class UnsupportedOperationException:
    def __init__ ( self ):
        pass

class ClassCastException:
    def __init__ ( self ):
        pass

class NoSuchMethodException:
    def __init__ ( self ):
        pass

class NoSuchFieldException:
    def __init__ ( self ):
        pass

class NoClassDefFoundError:
    def __init__ ( self ):
        pass

class NoSuchMethodError:
    def __init__ ( self ):
        pass

class AbstractMethodError:
    def __init__ ( self ):
        pass

class ClassCircularityError:
    def __init__ ( self ):
        pass

class ClassFormatError:
    def __init__ ( self ):
        pass

class Error:
    def __init__ ( self ):
        pass

class ExceptionInInitializerError:
    def __init__ ( self ):
        pass

class IllegalAccessError:
    def __init__ ( self ):
        pass

class IncompatibleClassChangeError:
    def __init__ ( self ):
        pass

class InstantiationError:
    def __init__ ( self ):
        pass

class InternalError:
    def __init__ ( self ):
        pass

class LinkageError:
    def __init__ ( self ):
        pass

class NoSuchFieldError:
    def __init__ ( self ):
        pass

class NoSuchMethodError:
    def __init__ ( self ):
        pass

class OutOfMemoryError:
    def __init__ ( self ):
        pass

class StackOverflowError:
    def __init__ ( self ):
        pass

class UnknownError:
    def __init__ ( self ):
        pass

class UnsatisfiedLinkError:
    def __init__ ( self ):
        pass

class VerifyError:
    def __init__ ( self ):
        pass

class VirtualMachineError:
    def __init__ ( self ):
        pass

class ThreadDeath:
    def __init__ ( self ):
        pass

class Thread:
    def __init__ ( self ):
        pass

class Runnable:
    def __init__ ( self ):
        pass

class ThreadGroup:
    def __init__ ( self ):
        pass

class SecurityManager:
    def __init__ ( self ):
        pass

class AccessControlContext:
    def __init__ ( self ):
        pass

class AccessController:
    def __init__ ( self ):
        pass

class ProtectionDomain:
    def __init__ ( self ):
        pass

class DomainCombiner:
    def __init__ ( self ):
        pass

class Policy:
    def __init__ ( self ):
        pass

class Permission:
    def __init__ ( self ):
        pass

class PermissionCollection:
    def __init__ ( self ):
        pass

class AllPermission:
    def __init__ ( self ):
        pass

class AuthPermission:
    def __init__ ( self ):
        pass

class FilePermission:
    def __init__ ( self ):
        pass

class RuntimePermission:
    def __init__ ( self ):
        pass

class SocketPermission:
    def __init__ ( self ):
        pass

class AWTPermission:
    def __init__ ( self ):
        pass

class PrintJobPermission:
    def __init__ ( self ):
        pass

class PropertyPermission:
    def __init__ ( self ):
        pass

class NetPermission:
    def __init__ ( self ):
        pass

class ReflectPermission:
    def __init__ ( self ):
        pass

class SQLPermission:
    def __init__ ( self ):
        pass

class URLLoaderPermission:
    def __init__ ( self ):
        pass

class AWTKeyStroke:
    def __init__ ( self ):
        pass

class AWTEvent:
    def __init__ ( self ):
        pass

class ActionEvent:
    def __init__ ( self ):
        pass

class AdjustmentEvent:
    def __init__ ( self ):
        pass

class ItemEvent:
    def __init__ ( self ):
        pass

class TextEvent:
    def __init__ ( self ):
        pass

class InputEvent:
    def __init__ ( self ):
        pass

class KeyEvent:
    def __init__ ( self ):
        pass

class MouseEvent:
    def __init__ ( self ):
        pass

class MouseWheelEvent:
    def __init__ ( self ):
        pass

class WindowEvent:
    def __init__ ( self ):
        pass

class ComponentEvent:
    def __init__ ( self ):
        pass

class ContainerEvent:
    def __init__ ( self ):
        pass

class FocusEvent:
    def __init__ ( self ):
        pass

class HierarchyEvent:
    def __init__ ( self ):
        pass

class HierarchyBoundsListener:
    def __init__ ( self ):
        pass

class HierarchyListener:
    def __init__ ( self ):
        pass

class InputMethodEvent:
    def __init__ ( self ):
        pass

class InputMethodListener:
    def __init__ ( self ):
        pass

class KeyListener:
    def __init__ ( self ):
        pass

class MouseListener:
    def __init__ ( self ):
        pass

class MouseMotionListener:
    def __init__ ( self ):
        pass

class WindowFocusListener:
    def __init__ ( self ):
        pass

class WindowStateListener:
    def __init__ ( self ):
        pass

class WindowListener:
    def __init__ ( self ):
        pass

class ActionListener:
    def __init__ ( self ):
        pass

class AdjustmentListener:
    def __init__ ( self ):
        pass

class ItemListener:
    def __init__ ( self ):
        pass

class TextListen
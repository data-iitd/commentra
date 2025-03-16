

#include <stdio.h> // Header file for input and output operations
#include <stdlib.h> // Header file for memory allocation and deallocation
#include <string.h> // Header file for string manipulation functions
#include <math.h> // Header file for mathematical functions
#include <time.h> // Header file for time-related functions
#include <assert.h> // Header file for asserting conditions
#include <ctype.h> // Header file for character classification functions
#include <limits.h> // Header file for limits of data types
#include <stdarg.h> // Header file for variable argument lists
#include <stddef.h> // Header file for size of data types
#include <stdint.h> // Header file for fixed-width integer types
#include <stdio_ext.h> // Header file for extensions to standard input/output functions
#include <inttypes.h> // Header file for formatted printing and scanning of integer types
#include <float.h> // Header file for floating-point constants and functions
#include <iso646.h> // Header file for logical operators
#include <unistd.h> // Header file for Unix-specific functions
#include <sys/stat.h> // Header file for file status information
#include <sys/types.h> // Header file for file types and identifiers
#include <sys/time.h> // Header file for time-related functions
#include <sys/times.h> // Header file for times() and other time-related functions
#include <sys/mman.h> // Header file for memory-mapped files
#include <sys/file.h> // Header file for file-related operations
#include <sys/socket.h> // Header file for socket-related operations
#include <sys/un.h> // Header file for Unix domain sockets
#include <sys/select.h> // Header file for select() and related functions
#include <sys/ioctl.h> // Header file for I/O control operations
#include <sys/ipc.h> // Header file for inter-process communication
#include <sys/shm.h> // Header file for shared memory operations
#include <sys/msg.h> // Header file for message queue operations
#include <sys/sem.h> // Header file for semaphore operations
#include <sys/wait.h> // Header file for waitpid() and related functions
#include <sys/resource.h> // Header file for resource limits and usage
#include <sys/prctl.h> // Header file for process control operations
#include <sys/sendfile.h> // Header file for sendfile() and related functions
#include <sys/epoll.h> // Header file for epoll() and related functions
#include <sys/eventfd.h> // Header file for eventfd() and related functions
#include <sys/timerfd.h> // Header file for timerfd() and related functions
#include <sys/inotify.h> // Header file for inotify() and related functions
#include <sys/mount.h> // Header file for mount() and related functions
#include <sys/personality.h> // Header file for personality() and related functions
#include <sys/ptrace.h> // Header file for ptrace() and related functions
#include <sys/reboot.h> // Header file for reboot() and related functions
#include <sys/sysinfo.h> // Header file for sysinfo() and related functions
#include <sys/ugetrlimit.h> // Header file for getrlimit() and setrlimit()
#include <sys/user.h> // Header file for user-space operations
#include <sys/utsname.h> // Header file for uname() and related functions
#include <sys/vfs.h> // Header file for virtual file system operations
#include <sys/statfs.h> // Header file for statfs() and fstatfs()
#include <sys/sendfile.h> // Header file for sendfile() and related functions
#include <sys/epoll.h> // Header file for epoll() and related functions
#include <sys/eventfd.h> // Header file for eventfd() and related functions
#include <sys/timerfd.h> // Header file for timerfd() and related functions
#include <sys/inotify.h> // Header file for inotify() and related functions
#include <sys/mount.h> // Header file for mount() and related functions
#include <sys/personality.h> // Header file for personality() and related functions
#include <sys/ptrace.h> // Header file for ptrace() and related functions
#include <sys/reboot.h> // Header file for reboot() and related functions
#include <sys/sysinfo.h> // Header file for sysinfo() and related functions
#include <sys/ugetrlimit.h> // Header file for getrlimit() and setrlimit()
#include <sys/user.h> // Header file for user-space operations
#include <sys/utsname.h> // Header file for uname() and related functions
#include <sys/vfs.h> // Header file for virtual file system operations
#include <sys/statfs.h> // Header file for statfs() and fstatfs()
#include <sys/sendfile.h> // Header file for sendfile() and related functions
#include <sys/epoll.h> // Header file for epoll() and related functions
#include <sys/eventfd.h> // Header file for eventfd() and related functions
#include <sys/timerfd.h> // Header file for timerfd() and related functions
#include <sys/inotify.h> // Header file for inotify() and related functions
#include <sys/mount.h> // Header file for mount() and related functions
#include <sys/personality.h> // Header file for personality() and related functions
#include <sys/ptrace.h> // Header file for ptrace() and related functions
#include <sys/reboot.h> // Header file for reboot() and related functions
#include <sys/sysinfo.h> // Header file for sysinfo() and related functions
#include <sys/ugetrlimit.h> // Header file for getrlimit() and setrlimit()
#include <sys/user.h> // Header file for user-space operations
#include <sys/utsname.h> // Header file for uname() and related functions
#include <sys/vfs.h> // Header file for virtual file system operations
#include <sys/statfs.h> // Header file for statfs() and fstatfs()
#include <sys/sendfile.h> // Header file for sendfile() and related functions
#include <sys/epoll.h> // Header file for epoll() and related functions
#include <sys/eventfd.h> // Header file for eventfd() and related functions
#include <sys/timerfd.h> // Header file for timerfd() and related functions
#include <sys/inotify.h> // Header file for inotify() and related functions
#include <sys/mount.h> // Header file for mount() and related functions
#include <sys/personality.h> // Header file for personality() and related functions
#include <sys/ptrace.h> // Header file for ptrace() and related functions
#include <sys/reboot.h> // Header file for reboot() and related functions
#include <sys/sysinfo.h> // Header file for sysinfo() and related functions
#include <sys/ugetrlimit.h> // Header file for getrlimit() and setrlimit()
#include <sys/user.h> // Header file for user-space operations
#include <sys/utsname.h> // Header file for uname() and related functions
#include <sys/vfs.h> // Header file for virtual file system operations
#include <sys/statfs.h> // Header file for statfs() and fstatfs()
#include <sys/sendfile.h> // Header file for sendfile() and related functions
#include <sys/epoll.h> // Header file for epoll() and related functions
#include <sys/eventfd.h> // Header file for eventfd() and related functions
#include <sys/timerfd.h> // Header file for timerfd() and related functions
#include <sys/inotify.h> // Header file for inotify() and related functions
#include <sys/mount.h> // Header file for mount() and related functions
#include <sys/personality.h> // Header file for personality() and related functions
#include <sys/ptrace.h> // Header file for ptrace() and related functions
#include <sys/reboot.h> // Header file for reboot() and related functions
#include <sys/sysinfo.h> // Header file for sysinfo() and related functions
#include <sys/ugetrlimit.h> // Header file for getrlimit() and setrlimit()
#include <sys/user.h> // Header file for user-space operations
#include <sys/utsname.h> // Header file for uname() and related functions
#include <sys/vfs.h> // Header file for virtual file system operations
#include <sys/statfs.h> // Header file for statfs() and fstatfs()
#include <sys/sendfile.h> // Header file for sendfile() and related functions
#include <sys/epoll.h> // Header file for epoll() and related functions
#include <sys/eventfd.h> // Header file for eventfd() and related functions
#include <sys/timerfd.h> // Header file for timerfd() and related functions
#include <sys/inotify.h> // Header file for inotify() and related functions
#include <sys/mount.h> // Header file for mount() and related functions
#include <sys/personality.h> // Header file for personality() and related functions
#include <sys/ptrace.h> // Header file for ptrace() and related functions
#include <sys/reboot.h> // Header file for reboot() and related functions
#include <sys/sysinfo.h> // Header file for sysinfo() and related functions
#include <sys/ugetrlimit.h> // Header file for getrlimit() and setrlimit()
#include <sys/user.h> // Header file for user-space operations
#include <sys/utsname.h> // Header file for uname() and related functions
#include <sys/vfs.h> // Header file for virtual file system operations
#include <sys/statfs.h> // Header file for statfs() and fstatfs()
#include <sys/sendfile.h> // Header file for sendfile() and related functions
#include <sys/epoll.h> // Header file for epoll() and related functions
#include <sys/eventfd.h> // Header file for eventfd() and related functions
#include <sys/timerfd.h> // Header file for timerfd() and related functions
#include <sys/inotify.h> // Header file for inotify() and related functions
#include <sys/mount.h> // Header file for mount() and related functions
#include <sys/personality.h> // Header file for personality() and related functions
#include <sys/ptrace.h> // Header file for ptrace() and related functions
#include <sys/reboot.h> // Header file for reboot() and related functions
#include <sys/sysinfo.h> // Header file for sysinfo() and related functions
#include <sys/ugetrlimit.h> // Header file for getrlimit() and setrlimit()
#include <sys/user.h> // Header file for user-space operations
#include <sys/utsname.h> // Header file for uname() and related functions
#include <sys/vfs.h> // Header file for virtual file system operations
#include <sys/statfs.h> // Header file for statfs() and fstatfs()
#include <sys/sendfil
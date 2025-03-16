#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <limits.h>
#include <ctype.h>
#include <float.h>
#include <time.h>
#include <assert.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <pthread.h>
#include <semaphore.h>
#include <errno.h>
#include <signal.h>
#include <pwd.h>
#include <grp.h>
#include <dirent.h>
#include <locale.h>
#include <langinfo.h>
#include <monetary.h>
#include <nl_types.h>
#include <getopt.h>
#include <regex.h>
#include <glob.h>
#include <sys/ioctl.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include <sys/sem.h>
#include <sys/statvfs.h>
#include <sys/vfs.h>
#include <sys/file.h>
#include <sys/mman.h>
#include <sys/mount.h>
#include <sys/resource.h>
#include <sys/select.h>
#include <sys/sendfile.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/times.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/un.h>
#include <sys/wait.h>
#include <sys/xattr.h>
#include <termios.h>
#include <utime.h>
#include <wchar.h>
#include <wordexp.h>

#define MAX_SIZE 1000000

int main ( ) { 
    // Step 1: Read the input value N, which represents the number of elements.
    int N ; 
    scanf ( "%d" , & N ) ; 

    // Step 2: Create a map idorder to store the elements and their corresponding positions.
    int idorder [ MAX_SIZE ] ; 
    memset ( idorder , 0 , sizeof ( idorder ) ) ; 

    // Step 3: Read each element and store its value and position in the map.
    for ( int i = 1 ; i <= N ; i ++ ) { 
        int A ; 
        scanf ( "%d" , & A ) ; 
        idorder [ A ] = i ; 
    } 

    // Step 4: Print the positions of the elements in the order they were read.
    for ( int i = 1 ; i <= N ; i ++ ) { 
        printf ( "%d " , idorder [ i ] ) ; 
    } 

    return 0 ; 
}


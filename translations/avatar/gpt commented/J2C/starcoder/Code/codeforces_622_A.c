#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERSIZE 512000

int main() {
    // Initialize a Scanner for reading input with a buffered reader for efficiency
    struct __sFILE {
        unsigned char *_p;
        int _r;
        int _w;
        short _flags;
        short _file;
        struct __sbuf _bf;
        int _lbfsize;
        void *_cookie;
        int (*_close)(void *);
        int (*_read) (void *, char *, int);
        fpos_t (*_seek) (void *, fpos_t, int);
        int (*_write)(void *, const char *, int);
        struct __sbuf _ub;
        struct __sbuf _lb;
        struct __sbuf _mb;
        struct __sbuf _ubuf;
        struct __sbuf _nbuf;
        struct __sbuf _bbuf;
        int _lineno;
        char *_lineptr;
        int _filelen;
        int _size;
        int _offset;
        char *_buf;
        fpos_t _lock;
        char *_tmpfname;
    } _in = {
       ._p = (unsigned char *) 0,
       ._r = 0,
       ._w = 0,
       ._flags = 0,
       ._file = 0,
       ._bf = {
           ._base = (unsigned char *) 0,
           ._size = 0,
           ._nextc = (unsigned char *) 0,
           ._file = 0,
           ._charbuf = 0,
           ._bufsiz = 0,
           ._tmpfname = (char *) 0
        },
       ._lbfsize = 0,
       ._cookie = (void *) 0,
       ._close = (int (*)()) 0,
       ._read = (int (*)()) 0,
       ._seek = (fpos_t (*)()) 0,
       ._write = (int (*)()) 0,
       ._ub = {
           ._base = (unsigned char *) 0,
           ._size = 0,
           ._nextc = (unsigned char *) 0,
           ._file = 0,
           ._charbuf = 0,
           ._bufsiz = 0,
           ._tmpfname = (char *) 0
        },
       ._lb = {
           ._base = (unsigned char *) 0,
           ._size = 0,
           ._nextc = (unsigned char *) 0,
           ._file = 0,
           ._charbuf = 0,
           ._bufsiz = 0,
           ._tmpfname = (char *) 0
        },
       ._mb = {
           ._base = (unsigned char *) 0,
           ._size = 0,
           ._nextc = (unsigned char *) 0,
           ._file = 0,
           ._charbuf = 0,
           ._bufsiz = 0,
           ._tmpfname = (char *) 0
        },
       ._ubuf = {
           ._base = (unsigned char *) 0,
           ._size = 0,
           ._nextc = (unsigned char *) 0,
           ._file = 0,
           ._charbuf = 0,
           ._bufsiz = 0,
           ._tmpfname = (char *) 0
        },
       ._nbuf = {
           ._base = (unsigned char *) 0,
           ._size = 0,
           ._nextc = (unsigned char *) 0,
           ._file = 0,
           ._charbuf = 0,
           ._bufsiz = 0,
           ._tmpfname = (char *) 0
        },
       ._bbuf = {
           ._base = (unsigned char *) 0,
           ._size = 0,
           ._nextc = (unsigned char *) 0,
           ._file = 0,
           ._charbuf = 0,
           ._bufsiz = 0,
           ._tmpfname = (char *) 0
        },
       ._lineno = 0,
       ._lineptr = (char *) 0,
       ._filelen = 0,
       ._size = 0,
       ._offset = 0,
       ._buf = (char *) 0,
       ._lock = 0,
       ._tmpfname = (char *) 0
    };
    struct __sFILE *_in_p = &_in;
    int _out_r = 0;
    int _out_w = 0;
    struct __sbuf _out_buf = {
       ._base = (unsigned char *) 0,
       ._size = 0,
       ._nextc = (unsigned char *) 0,
       ._file = 0,
       ._charbuf = 0,
       ._bufsiz = 0,
       ._tmpfname = (char *) 0
    };
    struct __sFILE _out = {
       ._p = (unsigned char *) 0,
       ._r = 0,
       ._w = 0,
       ._flags = 0,
       ._file = 0,
       ._bf = _out_buf,
       ._lbfsize = 0,
       ._cookie = (void *) 0,
       ._close = (int (*)()) 0,
       ._read = (int (*)()) 0,
       ._seek = (fpos_t (*)()) 0,
       ._write = (int (*)()) 0,
       ._ub = {
           ._base = (unsigned char *) 0,
           ._size = 0,
           ._nextc = (unsigned char *) 0,
           ._file = 0,
           ._charbuf = 0,
           ._bufsiz = 0,
           ._tmpfname = (char *) 0
        },
       ._lb = {
           ._base = (unsigned char *) 0,
           ._size = 0,
           ._nextc = (unsigned char *) 0,
           ._file = 0,
           ._charbuf = 0,
           ._bufsiz = 0,
           ._tmpfname = (char *) 0
        },
       ._mb = {
           ._base = (unsigned char *) 0,
           ._size = 0,
           ._nextc = (unsigned char *) 0,
           ._file = 0,
           ._charbuf = 0,
           ._bufsiz = 0,
           ._tmpfname = (char *) 0
        },
       ._ubuf = {
           ._base = (unsigned char *) 0,
           ._size = 0,
           ._nextc = (unsigned char *) 0,
           ._file = 0,
           ._charbuf = 0,
           ._bufsiz = 0,
           ._tmpfname = (char *) 0
        },
       ._nbuf = {
           ._base = (unsigned char *) 0,
           ._size = 0,
           ._nextc = (unsigned char *) 0,
           ._file = 0,
           ._charbuf = 0,
           ._bufsiz = 0,
           ._tmpfname = (char *) 0
        },
       ._bbuf = {
           ._base = (unsigned char *) 0,
           ._size = 0,
           ._nextc = (unsigned char *) 0,
           ._file = 0,
           ._charbuf = 0,
           ._bufsiz = 0,
           ._tmpfname = (char *) 0
        },
       ._lineno = 0,
       ._lineptr = (char *) 0,
       ._filelen = 0,
       ._size = 0,
       ._offset = 0,
       ._buf = (char *) 0,
       ._lock = 0,
       ._tmpfname = (char *) 0
    };
    struct __sFILE *_out_p = &_out;
    struct __sbuf _in_buf = {
       ._base = (unsigned char *) 0,
       ._size = 0,
       ._nextc = (unsigned char *) 0,
       ._file = 0,
       ._charbuf = 0,
       ._bufsiz = 0,
       ._tmpfname = (char *) 0
    };
    fpos_t _pos = 0;
    int _eof = 0;
    int _tmp_eof = 0;
    unsigned char _buf[BUFFERSIZE];
    int _n = 0;
    int _i = 0;
    int _j = 0;
    int _k = 0;
    int _tmp_w = 0;
    int _tmp_r = 0;
    int _out_c = 0;
    int _out_w = 0;
    int _out_r = 0;
    int _out_flags = 0;
    int _out_file = 0;
    int _out_lbfsize = 0;
    char *_out_tmpfname = (char *) 0;
    struct __sbuf _out_bf = {
       ._base = (unsigned char *) 0,
       ._size = 0,
       ._nextc = (unsigned char *) 0,
       ._file = 0,
       ._charbuf = 0,
       ._bufsiz = 0,
       ._tmpfname = (char *) 0
    };
    struct __sFILE _out_p = {
       ._p = (unsigned char *) 0,
       ._r = 0,
       ._w = 0,
       ._flags = 0,
       ._file = 0,
       ._bf = _out_bf,
       ._lbfsize = 0,
       ._cookie = (void *) 0,
       ._close = (int (*)()) 0,
       ._read = (int (*)()) 0,
       ._seek = (fpos_t (*)()) 0,
       ._write = (int (*)()) 0,
       ._ub = {
           ._base = (unsigned char *) 0,
           ._size = 0,
           ._nextc = (unsigned char *) 0,
           ._file = 0,
           ._charbuf = 0,
           ._bufsiz = 0,
           ._tmpfname = (char *) 0
        },
       ._lb = {
           ._base = (unsigned char *) 0,
           ._size = 0,
           ._nextc = (unsigned char *) 0,
           ._file = 0,
           ._charbuf = 0,
           ._bufsiz = 0,
           ._tmpfname = (char *) 0
        },
       ._mb = {
           ._base = (unsigned char *) 0,
           ._size = 0,
           ._nextc = (unsigned char *) 0,
           ._file = 0,
           ._charbuf = 0,
           ._bufsiz = 0,
           ._tmpfname = (char *) 0
        },
       ._ubuf = {
           ._base = (unsigned char *) 0,
           ._size = 0,
           ._nextc = (unsigned char *) 0,
           ._file = 0,
           ._charbuf = 0,
           ._bufsiz = 0,
           ._tmpfname = (char *) 0
        },
       ._nbuf = {
           ._base = (unsigned char *) 0,
           ._size = 0,
           ._nextc = (unsigned char *) 0,
           ._file = 0,
           ._charbuf = 0,
           ._bufsiz = 0,
           ._tmpfname = (char *) 0
        },
       ._bbuf = {
           ._base = (unsigned char *) 0,
           ._size = 0,
           ._nextc = (unsigned char *) 0,
           ._file = 0,
           ._charbuf = 0,
           ._bufsiz = 0,
           ._tmpfname = (char *) 0
        },
       ._lineno = 0,
       ._lineptr = (char *) 0,
       ._filelen = 0,
       ._size = 0,
       ._offset = 0,
       ._buf = (char *) 0,
       ._lock = 0,
       ._tmpfname = (char *) 0
    };
    struct __sFILE *_out_p = &_out;
    struct __sbuf _in_buf = {
       ._base = (unsigned char *) 0,
       ._size = 0,
       ._nextc = (unsigned char *) 0,
       ._file = 0,
       ._charbuf = 0,
       ._bufsiz = 0,
       ._tmpfname = (char *) 0
    };
    fpos_t _pos = 0;
    int _eof = 0;
    int _tmp_eof = 0;
    unsigned char _buf[BUFFERSIZE];
    int _n = 0;
    int _i = 0;
    int _j = 0;
    int _k = 0;
    int _tmp_w = 0;
    int _tmp_r = 0;
    int _out_c = 0;
    int _out_w = 0;
    int _out_r = 0;
    int _out_flags = 0;
    int _out_file = 0;
    int _out_lbfsize = 0;
    char *_out_tmpfname = (char *) 0;
    struct __sbuf _out_bf = {
       ._base = (unsigned char *) 0,
       ._size = 0,
       ._nextc = (unsigned char *) 0,
       ._file = 0,
       ._charbuf = 0,
       ._bufsiz = 0,
       ._tmpfname = (char *) 0
    };
    struct __sFILE _out_p = {
       ._p = (unsigned char *) 0,
       ._r = 0,
       ._w = 0,
       ._flags = 0,
       ._file = 0,
       ._bf = _out_bf,
       ._lbfsize = 0,
       ._cookie = (void *) 0,
       ._close = (int (*)()) 0,
       ._read = (int (*)()) 0,
       ._seek = (fpos_t (*)()) 0,
       ._write = (int (*)()) 0,
       ._ub = {
           ._base = (unsigned char *) 0,
           ._size = 0,
           ._nextc = (unsigned char *) 0,
           ._file = 0,
           ._charbuf = 0,
           ._bufsiz = 0,
           ._tmpfname = (char *) 0
        },
       ._lb = {
           ._base = (unsigned char *) 0,
           ._size = 0,
           ._nextc = (unsigned char *) 0,
           ._file = 0,
           ._charbuf = 0,
           ._bufsiz = 0,
           ._tmpfname = (char *) 0
        },
       ._mb = {
           ._base = (unsigned char *) 0,
           ._size = 0,
      
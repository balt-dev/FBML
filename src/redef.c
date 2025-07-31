#include <stdint.h>
#include <windows.h>
#include <stdio.h>

static HMODULE g_original_dll;

#define REDEF(name, ret, args, vars)                                           \
  typedef ret(*PROXY_##name##_FUNC) args;                                      \
  __declspec(dllexport) ret name args {                                        \
    printf("Calling " #name);                                                  \
    static PROXY_##name##_FUNC orig = NULL;                                    \
    orig = orig ? orig                                                         \
                : (PROXY_##name##_FUNC)GetProcAddress(g_original_dll, #name);  \
    return orig vars;                                                          \
  }

typedef unsigned long uLong;
typedef uLong uLongf;
typedef unsigned int  uInt;
typedef void * gz_headerp;
typedef void * z_streamp;
typedef void * voidp;
typedef void * voidpc;
typedef void * gzFile;
typedef long long z_off_t;
typedef unsigned long z_crc_t;
typedef unsigned char Byte;
typedef unsigned char Bytef;
typedef int (*out_func)(void *, unsigned char *, unsigned);

REDEF(zlibVersion, const char *, (void), ());
REDEF(deflate, int, (z_streamp strm, int flush), (strm, flush));
REDEF(deflateEnd, int, (z_streamp strm), (strm));
REDEF(inflate, int, (z_streamp strm, int flush), (strm, flush));
REDEF(inflateEnd, int, (z_streamp strm), (strm));
REDEF(deflateSetDictionary, int, (z_streamp strm, uInt dictLength), (strm, dictLength));
REDEF(deflateCopy, int, (z_streamp dest, z_streamp source), (dest, source));
REDEF(deflateReset, int, (z_streamp strm), (strm));
REDEF(deflateParams, int, (z_streamp strm, int strategy), (strm, strategy));
REDEF(deflateTune, int, (z_streamp strm, int max_chain), (strm, max_chain));
REDEF(deflateBound, uLong, (z_streamp strm, uLong sourceLen), (strm, sourceLen));
REDEF(deflatePrime, int, (z_streamp strm, int value), (strm, value));
REDEF(deflateSetHeader, int, (z_streamp strm, gz_headerp head), (strm, head));
REDEF(inflateSetDictionary, int, (z_streamp strm, uInt dictLength), (strm, dictLength));
REDEF(inflateSync, int, (z_streamp strm), (strm));
REDEF(inflateCopy, int, (z_streamp dest, z_streamp source), (dest, source));
REDEF(inflateReset, int, (z_streamp strm), (strm));
REDEF(inflatePrime, int, (z_streamp strm, int value), (strm, value));
REDEF(inflateGetHeader, int, (z_streamp strm, gz_headerp head), (strm, head));
REDEF(inflateBack, int, (z_streamp strm, out_func out, void *out_desc), (strm, out, out_desc));
REDEF(inflateBackEnd, int, (z_streamp strm), (strm));
REDEF(zlibCompileFlags, uLong, (void), ());
REDEF(compress, int, (Bytef *dest, uLongf *destLen, const Bytef *source, uLong sourceLen), (dest, destLen, source, sourceLen));
REDEF(compress2, int, (Bytef *dest, uLongf *destLen, int level), (dest, destLen, level));
REDEF(compressBound, uLong, (uLong sourceLen), (sourceLen));
REDEF(uncompress, int, (Bytef *dest, uLongf *destLen, const Bytef *source, uLong sourceLen), (dest, destLen, source, sourceLen));
REDEF(gzopen, gzFile, (const char *path, const char *mode), (path, mode));
REDEF(gzdopen, gzFile, (int fd, const char *mode), (fd, mode));
REDEF(gzsetparams, int, (gzFile file, int level, int strategy), (file, level, strategy));
REDEF(gzread, int, (gzFile file, voidp buf, unsigned len), (file, buf, len));
REDEF(gzwrite, int, (gzFile file, voidpc buf, unsigned len), (file, buf, len));
REDEF(gzputs, int, (gzFile file, const char *s), (file, s));
REDEF(gzgets, char *, (gzFile file, char *buf, int len), (file, buf, len));
REDEF(gzputc, int, (gzFile file, int c), (file, c));
REDEF(gzgetc, int, (gzFile file), (file));
REDEF(gzungetc, int, (int c, gzFile file), (c, file));
REDEF(gzflush, int, (gzFile file, int flush), (file, flush));
REDEF(gzseek, z_off_t, (gzFile file, z_off_t t, int i), (file, t, i));
REDEF(gzrewind, int, (gzFile file), (file));
REDEF(gztell, z_off_t, (gzFile file), (file));
REDEF(gzeof, int, (gzFile file), (file));
REDEF(gzdirect, int, (gzFile file), (file));
REDEF(gzclose, int, (gzFile file), (file));
REDEF(gzerror, const char *, (gzFile file, int *errnum), (file, errnum));
REDEF(gzclearerr, void, (gzFile file), (file));
REDEF(adler32, uLong, (uLong adler, const Bytef *buf, uInt len), (adler, buf, len));
REDEF(crc32, uLong, (uLong crc, const Bytef *buf, uInt len), (crc, buf, len));
REDEF(crc32_combine, uLong, (uLong crc1, uLong crc2, z_off_t len2), (crc1, crc2, len2));
REDEF(deflateInit_, int, (z_streamp strm, int level, const char *version, int stream_size), (strm, level, version, stream_size));
REDEF(inflateInit_, int, (z_streamp strm, const char *version, int stream_size), (strm, version, stream_size));
REDEF(deflateInit2_, int, (z_streamp strm, int level, int method, int stream_size), (strm, level, method, stream_size));
REDEF(inflateInit2_, int, (z_streamp strm, int windowBits, const char *version, int stream_size), (strm, windowBits, version, stream_size));
REDEF(inflateBackInit_, int, (z_streamp strm, int windowBits, int stream_size), (strm, windowBits, stream_size));
REDEF(zError, const char *, (int i), (i));
REDEF(inflateSyncPoint, int, (z_streamp p), (p));
REDEF(get_crc_table, const z_crc_t *, (void), ());
REDEF(gzvprintf, int, (gzFile file, va_list va), (file, va));

int gzprintf(gzFile file, ...) {
  va_list argp;
  va_start(argp, file);
  return gzvprintf(file, argp);
}

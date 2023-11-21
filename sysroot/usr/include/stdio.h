#ifndef _STDIO_H
# ifdef __cplusplus
extern "C" {
# endif
#define _STDIO_H
#define _FSTDIO
#define __need_size_t
#include <stddef.h>

#define __need___va_list
#include <stdarg.h>

typedef struct __sFile
{
	int unused;
} FILE;


#define	__SLBF	0x0001	/* Line buffered */
#define	__SNBF	0x0002	/* unbuffered */
#define	__SRD	0x0004	/* OK to read */
#define	__SWR	0x0008	/* OK to write */
/*RD & WR are never simultaneously asserted, obviously*/
#define	__SRW	0x0010	/* Open for reading & writing*/
#define	__SEOF	0x0020	/* found EOF */
#define	__SERR	0x0040	/* found error */
#define	__SMBF	0x0080	/* _buf is from malloc */
#define	__SAPP	0x0100	/* fdopen()ed in append mode - so must write to end */
#define	__SSTR	0x0200	/* this is an sprintf/snprintf string */
#define	__SOPT 	0x0400	/* do fseek() optimisation */
#define	__SNPT 	0x0800	/* do NOT do fseek() optimisation*/
#define	__SOFF	0x1000	/* set iff _offset is in fact correct */
#define	__SMOD	0x2000	/* true => fgetline modified _p text */
#if defined(__CYGWIN__) || defined(__CYGWWIN__)
#define __SCLE	0x4000
#endif

/*following 3 for ANSI C, whatever*/
#define	_IOFBF	0	/* setvbuf should set fully buffered */
#define	_IOLBF	1	/* setvbuf should set line buffered */
#define	_IONBF	2	/* setvbuf should set unbuffered */

#ifndef NULL
#define	NULL	0
#endif

#define	BUFSIZ	1024
#define EOF (-1)

#define FOPEN_MAX	20
#define FILENAME_MAX	1024
#define	L_tmpnam	1024
#ifndef __STRICT_ANSI__
#define P_tmpdir	"/tmp"
#endif

#ifndef	SEEK_SET
#define	SEEK_SET	0
#endif
#ifndef	SEEK_CUR
#define	SEEK_CUR	1
#endif
#ifndef	SEEK_END
#define	SEEK_END	2
#endif

#define	TMP_MAX		26

#define stdin 		(_impure_ptr->_stdin)
#define stdout		(_impure_ptr->_stdout)
#define stderr		(_impure_ptr->_stderr)

#define	_stdin_r(x)	((x)->_stdin)
#define _stdout_r(x)	((x)->_stdout)
#define _stderr_r(x)	((x)->_stderr)

/*ANSI C standard function*/

#ifdef __GNUC__
#define	__VALIST	__gnuc_va_list
#else
#define	_VALIST		char*
#endif

#ifndef	_EXFUN
#define	_EXFUN(N,P) N P
#endif

int	_EXFUN(printf, (const char* __restrict, ...));
int	_EXFUN(putchar, (int));
int	_EXFUN(puts, (const char*));


#ifdef __cplusplus
}
#endif

#endif /* _STDIO_H*/

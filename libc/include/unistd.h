#ifndef _UNISTD_H_
#define _UNISTD_H_

#include <sys/_null>
#include <sys/types>
#include <sys/unistd>

#define SDTIN_FILENO	0
#define STDOUT_FILENO 	1
#define STDERR_FILENO	2

#if __XPG_VISIBLE || __POSIX_VISIBLE >= 200112
# define F_ULOCK	0
# define F_LOCK		1
# define F_TLOCK	2
# define F_TEST		3
#endif



/* Here you can define system variable*/

__BEGIN_DECLS



END_C_DECLS

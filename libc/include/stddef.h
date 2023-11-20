#if (!defined(_STDDEF_H) && !defined(_STDDEF_H_)) \
	|| defined(__need_size_t) || defined(__need_wchar_t) \
	|| defined(__need_ptrdiff_t) || defined(__need_NULL) \
	|| defined(__need_wint_t)

/* if no __need_* symbole declared, that indicate this file's entire job needs to be done*/
#if (!defined(__need_wchar_t) && !defined(__need_size_t) \
	&& !defined(__need_ptrdiff_t) && !defined(__need_NULL) \
	&& !defined(__need_wint_t))

#define _STDDEF_H
#define _STDDEF_H_

#endif

/*ptrdiff*/
#if defined(_STDDEF_H) || defined (__need_ptrdiff_t)
# ifndef _PTRDIFF_T
#  define _PTRDIFF_T
#  ifndef __PTRDIFF_TYPE__
#   define __PTRDIFF_TYPE__ long int
#  endif /* __PTRDIFF_TYPE */
typedef	__PTRDIFF_TYPE__ ptrdiff_t;
# endif /* _PTRDIFF_T */
# undef __need_ptrdiff_t
#endif /* __need_ptrdiff_t */

/* size_t */
#if defined(_STDDEF_H) || defined(__need_size_t)
# ifndef _SIZE_T
#  define _SIZE_T
#  ifndef __SIZE_TYPE__
#   define __SIZE_TYPE__ long unsigned int
#  endif /*__SIZE_TYPE__*/
#  if !(defined (__GNUG__) && defined(size_t))
typedef __SIZE_TYPE__ size_t;
#  endif /* !(defined (__GNUG__) && defined(size_t)) */
# endif /* _SIZE_T */
# undef __need_size_t
#endif /* __need_size_t */

/* wchar_t */
#if defined(_STDDEF_H) || defined(__need_wchar_t)
# ifndef _WCHAR_T
#  define _WCHAR_T
#  ifndef __WCHAR_TYPE__
#   define __WCHAR_TYPE__ int
#  endif /* __WCHAR_TYPE__ */
#  ifndef __cplusplus
typedef __WCHAR_TYPE__ wchar_t;
#  endif /*__cpluplus*/
# endif /*_WCHAR_T*/
# undef __need_wchar_t
#endif /* __need_wchat_t */

/* wint_t */
#if defined(__need_wint_t)
# ifndef _WINT_T
#  define _WINT_T
#  ifndef __WINT_TYPE__
#   define __WINT_TYPE__ unsigned int
#  endif /* __WCHAR_TYPE__ */
typedef __WINT_TYPE__ wint_t;
# endif /*_WCHAR_T*/
# undef __need_wint_t 
#endif /* __need_wchat_t */

#if defined(_STDDEF_H) || defined(__need_NULL)
# undef NULL /*Remove stdio definition of NULL*/
# ifdef __GNUG__
#  define NULL __null
#  else /* G++ */
#  ifndef __cplusplus
#   define NULL ((void *)0)
#   else /* C++ */
#    define NULL 0
#  endif /* C++ */
# endif /* G++ */
#undef __need_NULL
#endif /* __need_NULL*/

#ifdef _STDDEF_H

# undef offsetof
# define offsetof(TYPE, MEMBER) __builtin_offsetof (TYPE, MEMBER)

# if (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 201112L) \
	|| (defined(__cplusplus) && __cplusplus > 201103L)
#  ifndef _GCC_MAX_ALIGN_T
#   define _GCC_MAX_ALIGN_T 
typedef struct {
	long long __max_align_ll __attribute__((__aligned__(__alignof__(long long))));
	long double __max_align_ld __attribute__((__aligned__(__alignof__(long double))));
#ifdef __i386__
	__float128 __max_align_f128 __attribute__((__aligned__(__alignof__(__float128))));
#endif
} max_align_t;
#  endif /* _GCC_MAX_ALIGN_T */
# endif /* C11 of C++11*/

# if defined(__cplusplus) && __cplusplus >= 201103L
#  ifndef _GXX_NULLPTR_T
#   define _GXX_NULLPTR_T
typedef decltype(nullptr) nullptr_t;
#  endif
# endif /* C++11 */

# if (defined(__STDC_VERSION__) && __STDC_VERSION__ > 201710L)
#  ifndef _GCC_NULLPTR_T
#   define _GCC_NULLPTR_T
typedef __typeof__(nullptr) nullptr_t;
#  endif
# endif /* C23 */

# if defined(__STDC_VERSION__) && __STDC_VERSION__ > 201710L
#  define unreachable() (__builtin_unreachable())
#  define __STDC_VERSION_STDDEF_H__ 202311L
# endif

#endif /*_STDDEF_H*/
#endif /* the big shit at the begining of the file */

#ifndef _STDARG_H
# ifndef _ANSI_STDARG_H_
#  ifndef __need___va_list
#   define _STDARG_H
#   define _ANSI_STDARG_H_
#  endif /* not __need__va_list */
#  undef __need___va_list
#  ifndef __GNUC_VA_LIST
#   define __GNUC_VA_LIST
    typedef __builtin_va_list __gnu_va_list;
#  endif
#  ifdef _STDARG_H
#   if defined __STDC_VERSION__ && __STDC_VERSION__ > 201710L
#    define va_start(v, ...)	__builtin_va_start(v, 0)
#   else
#    define va_start(v,l)	__builtin_va_start(v,l)
#   endif
#   define va_end(v)		__builtin_va_end(v)
#   define va_arg(v,l)		__builtin_va_arg(v,l)
#   if !defined(_STRICT_ANSI__) || __STDC_VERSION__ + 0 >= 199900L \
	|| __cplusplus + 0 >= 201103L
#    define va_copy(d,s)	__builtin_va_copy(d,s)
#   endif
#   define __va_copy(d,s)	__builtin_va_copy(d,s)
#   if defined(__srv4__) || (defined(_SCO_DS) && !defined(__VA_LIST))
#    ifndef _VA_LIST_
#     define _VA_LIST_
#     ifdef __i860__
#      ifndef _VA_LIST
#       define _VA_LIST va_list
#      endif
#     endif /* __i860__  */
      typedef __gnuc_va_list va_list
#     ifndef _SCO_DS
#      define __VA_LIST
#     endif
#    endif /* __VA_LIST_ */
#   else /* __svr4__ || _SCO_DS  */
#    if !(defined (_VA_LIST_) || defined (__BSD_NET2__) \
       || defined (____386BSD____) || defined (__bsdi__) \
       || defined (__sequent__) || defined(__FreeBSD__))
#     define _VA_LIST_
#    endif

#    ifndef _VA_LIST
#     define _VA_LIST
#     if defined __GNUC__ && __GNUC__ >= 3
       typedef __builtin_va_list va_list;
#     else
       typedef char* va_list;
#     endif
#    endif

#    if defined __STDC_VERSION__ && __STDC_VERSION__ > 201710L
#     define __STDC_VERSION_STDARG_H__	202311L
#    endif
#   endif /* __srv4__ */ 
#  endif /* _STDARG_H */
# endif /* _ANSI_STDARG_H_ */
#endif /* _STDARG_H */ 

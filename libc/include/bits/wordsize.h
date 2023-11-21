#if defined __x86_64__
# define	__WORDSIZE		64
# define	__WORDSIZE_COMPAT32	1
#elif (defined __386__ || defined __i386__ )
# define	__WORDSIZE		32
# define	__WORDSIZE32_SIZE_ULONG 1
# define	__WORDSIZE32_PTRDIFF_LONG 1
# define	__WORDSIZE_TIM64_COMPAT32 1
#endif

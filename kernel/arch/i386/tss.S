.extern test_user_function

.section .text

[global flush_tss]
flush_tss:
	mov ax, (5 * 8) | 0
	ltr ax
	ret

[global jump_usermode]
jump_usermode:
	mov ax, (4 * 8) | 3
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	
	xor edx, edx
	mov eax, 0x8
	mov ecx, 0x174
	wrmsr

	mov edx, test_user_function
	mov ecx, esp
	sysexit

section .text
	global _ft_read
	extern ___error		; we call to ___error to handle errno

_ft_read:
	mov rax, 0x2000003	; set call to read
	syscall				; if error it sets the carry flag to 1
	jc error			; jump if carry flag = 1; rax = errno
	ret

error:
	mov r15, rax		; save errno in other register
	push rbp			
    mov rbp, rsp		;these two lines are the function prologue: prepare stack fot the function
    call ___error
    mov rsp, rbp		;these  next 2 instructions are the function epilogue: reverse actions and return control to calling function
    pop rbp
	mov [rax], r15		; put errno in return value of ___error (pointer to errno)
	mov rax, -1			; set return to -1
	ret
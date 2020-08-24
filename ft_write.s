section .text
	global _ft_write
	extern ___error

_ft_write:
	mov rax, 0x2000004	; set call to write
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
	mov [rax], r15		; put errno error value in memory adress pointed by ___error
	mov rax, -1			; set return to -1
	ret
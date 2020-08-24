section .text
	global _ft_strdup
	extern _malloc
	extern _ft_strlen
	extern _ft_strcpy
	extern ___error

_ft_strdup:
	push rdi			; save value of 1st argument in stack to avoid being overwritten
	call _ft_strlen		;
	inc rax				; increment rax (len return value of previous call) to include space for '\0'
	mov rdi, rax		; size for malloc [remember, rdi equal 1st argument of function]
	call _malloc
	cmp rax, 0			; we compare to zero to check if malloc asignation worked
	je error			; if cmp condition is true, jump to error
	pop rsi				; we save argument in stack to rsi to work as 2nd argument of strcpy
	mov rdi, rax		; move pointer result of malloc to rdi register to work as  1st argument of strcpy
	call _ft_strcpy		; dest = rdi   src = rsi
	ret

error:
	pop rdi				; bring back from stack to a register that won't be used
	mov r15, rax		; save errno in other register
	push rbp			
    mov rbp, rsp		;these two lines are the function prologue: prepare stack fot the function
    call ___error
    mov rsp, rbp		;these  next 2 instructions are the function epilogue: reverse actions and return control to calling function
    pop rbp
	mov [rax], r15		; put errno in return value of ___error (pointer to errno)
	mov rax, 0			; set return to 0
	ret

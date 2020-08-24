section .text
	global _ft_strlen

_ft_strlen:
	mov	rax, -1				; put -1 in RAX. It will be the returned value
	
loop:
	inc rax 				; inc increments RAX register value by 1
	cmp byte [rdi + rax], 0	; RDI is a pointer to the passed str. 
	jne	loop				; jne = jump if condition is not met (this case, references cmp instruction != 0)
	ret						; returns value in RAX



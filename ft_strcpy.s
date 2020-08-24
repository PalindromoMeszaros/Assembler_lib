section .text
	global _ft_strcpy

_ft_strcpy:
    mov rax, rdi                ; rdi = first argument. We move it to the rax register - rax will be returned           
    mov rcx, -1                 ; counter initialized in -1
    
loop:
    inc rcx                     ; increment counter by 1
    mov dl, byte [rsi + rcx]    ; move byte -character- from rsi (2nd argument, source str) to dl 8bit subregister
    mov byte [rax + rcx], dl    ; move from dl to current char position of destination
    cmp byte [rsi + rcx], 0     ; compare if source string character is equal to '\0'
    jne loop                    ; if cmp condition not true, jump to loop:
    ret



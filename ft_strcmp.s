section .text
	global _ft_strcmp

_ft_strcmp:
    mov rcx, -1                 ; counter initialized in -1

loop:
    inc rcx                     ; increase counter by 1
    mov al, byte[rdi + rcx]     ; we move current character of s1 to al 8bit register
	mov dl, byte[rsi + rcx]     ; we move current character of s2 to dl 8bit register
    cmp al, 0                   ; compare current s1 character with '\0'
    je exit                     ; if it's equal to 0 jump to exit
    cmp dl, 0                   ; compare current s2 character with '\0'
    je exit                     ; if it's equal to 0 jump to exit
    cmp al, dl                  ; compare current character in both strings
    jne exit                    ; if they're NOT equal, jump to exit
    jmp loop                    ; repeat loop                 

exit:
    movzx rax, al               ; movzx = copy a register of inferior size in a bigger and fill the other bits with 0
    movzx rdx, dl  
    sub rax, rdx                ; substracts the 2nd operand to the 1st and saves the difference in the 1st operand 
    ret 


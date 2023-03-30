section .data
message db 'Hello, Holberton', 0
format db '%s', 10, 0

section .text
extern printf
global _start

_start:
; prepare arguments for printf function
push format
push message
call printf
add esp, 8

; exit program with status code 0
xor eax, eax
mov ebx, eax
inc eax
int 0x80

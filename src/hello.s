section .comment ; Unnecesary, but ok!
; Hello !
; Sections are the units of the resulting object file.
; Here it's used to separate the data from the instructions

; write(int fd, const void buf[.count], size_t count);
; exit(int code);

; Order of parameters: ebx, ecx, edx, esi, edi, ebp. result: eax

section .text; Instructions
global _start ; Label (Entry point)
_start: ; Entry point
    mov ebx, 1 ; File descriptor (1) in the ebx register
    mov ecx, msg  ; msg pointer in the ecx register
    mov edx, len  ; len in the edx register
    mov eax, 4 ; Write instruction in the eax register (For Systemcalls, must place instructions in EAX)
    int 0x80 ; Call the kernel to execute the instruction (or 'syscall')
    mov ebx, eax ; Move result into first argument (To see bytes written with $?)
    mov eax, 1 ; Exit instruction in the eax register. (For Systemcalls, must place instruction in EAX)
    int 0x80 ; Call the kernel to execute the instruction (or 'syscall')

section .data ; Read-write (.data1 too)
    msg        db "Hello world!", 0xa ; In the msg variable, store the data in the executable. (0xa is \n)
    len        equ $ -msg ; $ is the location of this variable on the file. msg is the location of msg on the file. Substracting them gives the length.

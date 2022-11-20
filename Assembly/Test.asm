assume cs:code,ss:stack,ds:data
data segment
    db 'Welcome to masm!'
    db '----------------'
data ends 

stack segment
    dw 0,0,0,0
    dw 0,0,0,0
    dw 0,0,0,0
    dw 0,0,0,0
stack ends

code segment
    start:
        mov ax, data
        mov ds,ax
        
        mov si,0
        
        mov cx,8

    copy:
        push ds:[si]
        pop ds:[si+16]
        add si,2
        loop copy

        mov ax,4C00H
        int 21H
code ends
end start
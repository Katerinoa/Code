ASSUME CS:code

code SEGMENT
start:
    mov ax,0ffffh
    mov ds,AX

    MOV AX,20H
    MOV ES,AX

    mov cx,16
    mov BX,0
    mov AX,0

setNumber:
    mov AX,[BX]
    MOV ES:[BX],AL
    INC BX
    LOOP setNumber

    MOV AX,4C00H
    INT 21H
code ENDS
END start
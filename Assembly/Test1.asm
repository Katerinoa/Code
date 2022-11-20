ASSUME CS:code
code SEGMENT
    DW 0123H,0456H,0789H,0ABCH,0DEFH,0FEDH,0CBAH,0987H
    DW 0,0,0,0,0,0,0,0
start:
    MOV AX,CS
    MOV SS,AX
    MOV SP,32

    MOV AX,0
    MOV DS,AX
    MOV AX,CS
    MOV ES,AX
    MOV BX,0

    MOV CX,8

s:
    push DS:[BX]
    POP ES:[BX]
    ADD BX,2
    LOOP s

    MOV AX,4C00H
    INT 21H
code ends
end start
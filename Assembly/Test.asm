data SEGMENT	
    array DB 31H,21H,42H,52H,87H,23H,98H,01H
    up DB 0
    equa DB 0
    down DB 0
    UPSTRING  DB        0AH,0DH,'UP Number:$'
    DOWNSTRING  DB        0AH,0DH,'Down Number:$'
    EQUASTRING  DB        0AH,0DH,'Eqau Number:$'
data ENDS

code SEGMENT
    ASSUME CS:code, DS:data
start:
    MOV AX,0H
    DEC AL
    CMP AL,0BCH
    SUB AL,0BCH
    MOV AX, DATA
    MOV DS, AX

    MOV CX, 8
    MOV SI, 0

S:  cmp byte ptr [si] , 42H
    JA up_inc
    JE equa_inc
    JB down_inc

up_inc: 
    INC up
    JMP nextNum
equa_inc: 
    INC equa
    JMP nextNum
down_inc:
    INC down
    JMP nextNum
nextNum:
    INC SI
    LOOP S

    mov dx,data
    mov ds,dx

    add up, 30H
    add equa, 30H
    add down, 30H

    mov dx, offset UPSTRING
    mov ah, 09H
    int 21H
    mov dl,up
    mov ah,02H
    int 21H

    mov dx, offset EQUASTRING
    mov ah, 09H
    int 21H
    mov dl,equa
    mov ah,02H
    int 21H
        
    mov dx, offset DOWNSTRING
    mov ah, 09H
    int 21H
    mov dl,down
    mov ah,02H
    int 21H

    MOV AX ,4C00H
    INT 21H
code ENDS
END start



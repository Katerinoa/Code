data SEGMENT	
    array DB 31H,21H,42H,52H,87H,23H,98H,01H
    up DB 0
    equa DB 0
    down DB 0
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

    MOV AX ,4C00H
    INT 21H
code ENDS
END start



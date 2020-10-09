org 0x7c00
call reader
jmp 0:0x8000
ret

reader:
mov ah, 2 
mov al,3 
mov ch,0 
mov cl,2 
mov dh, 0 
mov dl, 0x80 
mov bx, 0x8000 
int 0x13 
ret

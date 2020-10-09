org 0x7C00
call reader
;подготовка к защищенному режиму
cli
mov ax,0
mov ss,ax
mov ds,ax
mov fs,ax
mov gs,ax
mov es,ax
mov sp, 0xfffc
lgdt[globalTable];load global description table
;переход в защищенный режим
mov eax, cr0
or eax,1
mov cr0,eax

jmp MyCode: 0x8000
ret
reader:
	mov ah,2
	mov al,3
	mov dh,0
	mov dl,0x80
	mov bx, 0x8000
	mov ch, 0
	mov cl,2
	int 0x13
ret

dTableBegin:
	null_d:
		dd 0; 4 bytes
		dd 0; 8 bytes
	code_d:
		dw 0xffff; limit alocated memory 2 byte
		dw 0; phys adr
		db 0; phys adr
		db 0b10011010;descript flag v tetradi
		db 0b11001111
		db 0; last part of 32-razr addr
	data_d:
		dw 0xffff
		dw 0; phys adr
		db 0; phys adr
		db 0b10010010;descript flag v tetradi
		db 0
	dTableEnd:
	globalTable:
		dw dTableEnd-dTableBegin
		dd dTableBegin
	MyCode equ code_d-dTableBegin
	Mydata equ data_d-dTableBegin
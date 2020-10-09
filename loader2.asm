call initms
org 0x7c00
call enableMemShift
call readProgram
call setVESAMode
cli;отключение возможных прерывание clear interupt - нажатие клавиши в момент запуска режима и тд.
mov sp, 0xfffc;выделили 4 байта памяти в стеке, стек 16-битный
mov ax, 0
call segnull
lgdt[gdt];считывание таблицы - копироване с десрипторную таблицу
;переход в защищенный режим. cr0-системный регистр
mov eax, cr0
or eax, 1; выбор режима работы
mov cr0, eax
mov eax, [buf+0x28];получаем адрес фреймбуфера
mov dword[0x8000],eax
jmp MyCode : 0x8004
ret

readProgram:
    mov ax, 0x026D
    mov dx, 0x0080
    mov cx, 0x0002
    mov ebx, 0x8004
    int 0x13
    ret

	

enableMemShift:
	mov cx, 0x7FFF
	mov ah, 0x87; режим 15-го прерывания
	mov si, gdt2 ; перенос указателя на таблицу
	int 0x15	
	ret
	
initms:
	;перейти в сегмент 0x10, понять как
    mov ax, 0x0280
    mov dx, 0x0080
    mov cx, 0x006E
	mov bx,0x1000
	mov ds,bx
    mov bx, 0x0000; FF:FFFF
    int 0x13
	;mov ds, bx
    ret

segnull:;Обнуление сегментных регистров
    mov ss, ax
    mov ds, ax
    mov fs, ax
    mov es, ax
    mov gs, ax
    ret

setVESAMode:;VESA стандарты телеобработки и тд; переключение в продвинутый видеорежим
    mov ax, 0x4f01;4f - что-то делать с видоадаптером, 01-получить информацию: взять из видеоадаптера информацию, соотв граф разрешения
    mov cx, 0x118 ;1024x768
    mov di, buf
    int 0x10
    mov ax, 0x4f02;переключение видеорежима
    mov bx, 0x4118;переключение видеорежима
    int 0x10
    ret




gd_table:
    Null_d:
        Dd 0
        Dd 0
    Code_d:
        Dw 0xffff;предел памяти, в которую может расширяться
        Dw 0;младшая часть базового адреса
        Db 0;адрес
        Db 0b10011010; флаги -> p ->dpl(2 бита) -> s -> e -> ed/c -> r/w -> a
            ;p определяет что сегмент содержит верные код и данные -> сегмент заполнен
            ;dpl - содержит уровень привилегий, присваемый сегменту
            ;s - системный дескриптор или дескриптор программы
            ;e - определяет тип дескриптора (содержит данные или исполняемый код(1))
            ;ed/c - будет ли происходить расширение сегмента к области данных или к области стека(1)
            ;r/w - чтение/запись
            ;a - был ли доступ к дескриптору
            ;Дескриптор, описывающий свою область кода, содержит правило работы с этим кодом
        Db 0b11001111;гранулярность (размер страницы, которые описываются дискриптором)
        Db 0;адрес, появилось позже
    Data_d:
        Dw 0xffff;65000 кб
        Dw 0
        Db 0
        Db 0b10010010
        Db 0b11001111;гранулярность (размер страницы, которые описываются дискриптором)
    gd_table_end:
    gdt:
        Dw gd_table_end-gd_table;размер таблицы
        Dd gd_table
MyCode equ Code_d-gd_table;присвоение (эквивалент)
;MyData equ Data_d-gd_table
buf dd 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 ;104 байта

gdt2:
    times 16 db 0
    ;dw 0xffff ; segment limit
    .src:
    dw 0xffff ; segment limit
    dw 0x0000 ; first 2 bytes of source
    db 0x1 ; 3rd/last byte of source address, so 0x10000 = 128 KiB
    db 0x93 ; data access rights
    dw 0
    .dest:
    dw 0xffff ; segment limit
	dw 0x0
    db 0x10 ; load protected-mode kernel to 0x100 000 ; 0x10 is the highest byte of 3 see int15/ah=87
    db 0x93 ; data access rights
    dw 0
    times 16 db 0


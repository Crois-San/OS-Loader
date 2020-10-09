/*
This code made by AntonSemenov
If u clear this message I'll come to u and kill u
*/
const int fontAdrs = 0x8000; //менять если изменять boot.asm
const int fontCount = 87; //менять если изменять font.c
const int fontWidth = 6; //менять если изменять font.c
const int fontHeight = 11; //менять если изменять font.c
const int pixelWidth = 5; //менять если хотите
const int pixelHeight = 5; //менять если хотите
const int width = 1024; //ширина экрана
const int height = 768; //высота экрана

void drawChar (char, int, int); //вывод символа <символ>,<х>,<у>
void drawString (char*, int, int, int,int); //вывод символа <строка>,<х>,<у>,<расстояние между букв>
void drawRect(int, int, int, int); 
void putPixel(int, int, int);
int getKey();
int hitKey();
void clearkbd(int);

int start() {
    
	int i,ii,j;
	
		int x=10,y=10;
		while(1){
			 
			int key_code = getKey();
			/*if(key_code == 0x02)
			{
				drawString("Image placeholder",200,200,3,17);
				clearkbd(key_code);
			}
			if(key_code == 0x03)
			{
				clearkbd(key_code);
				return 0;
			}  */
			if(key_code == 30)
			{
				drawChar('A',x+= 50,y);
				clearkbd(key_code);
			}
		} 
		
		
	//while(1);
    return 0;
}

void drawString (char *arr, int x, int y, int space,int length) {
    int i = 0;
        while(i<length) {
            drawChar(*arr, x, y);
            x += space+fontWidth*pixelWidth;
            i++;
            arr++; 
        }
}

void drawChar (char ch, int x, int y) {
    int positionChar;
    char *p = fontAdrs;
	int j=0;
	
    if( (int)ch == 48) positionChar = 0;
    if( (int)ch == 49) positionChar = 1;
    if( (int)ch == 50) positionChar = 2;
    if( (int)ch == 51) positionChar = 3;
    if( (int)ch == 52) positionChar = 4;
    if( (int)ch == 53) positionChar = 5;
    if( (int)ch == 54) positionChar = 6;
    if( (int)ch == 55) positionChar = 7;
    if( (int)ch == 56) positionChar = 8;
    if( (int)ch == 57) positionChar = 9;
    // A-Z
    if( (int)ch == 65) positionChar = 10;
    if( (int)ch == 66) positionChar = 11; 
    if( (int)ch == 67) positionChar = 12; 
    if( (int)ch == 68) positionChar = 13; 
    if( (int)ch == 69) positionChar = 14;  
    if( (int)ch == 70) positionChar = 15;    
    if( (int)ch == 71) positionChar = 16;    
    if( (int)ch == 72) positionChar = 17;    
    if( (int)ch == 73) positionChar = 18;     
    if( (int)ch == 74) positionChar = 19;     
    if( (int)ch == 75) positionChar = 20;     
    if( (int)ch == 76) positionChar = 21;    
    if( (int)ch == 77) positionChar = 22;   
    if( (int)ch == 78) positionChar = 23;  
    if( (int)ch == 79) positionChar = 24; 
    if( (int)ch == 80) positionChar = 25;
    if( (int)ch == 81) positionChar = 26;
    if( (int)ch == 82) positionChar = 27;
    if( (int)ch == 83) positionChar = 28;
    if( (int)ch == 84) positionChar = 29;
    if( (int)ch == 85) positionChar = 30;
    if( (int)ch == 86) positionChar = 31;
    if( (int)ch == 87) positionChar = 32;
    if( (int)ch == 88) positionChar = 33;
    if( (int)ch == 89) positionChar = 34;
    if( (int)ch == 90) positionChar = 35;
    // a-z
    if( (int)ch == 97) positionChar = 36;
    if( (int)ch == 98) positionChar = 37;
    if( (int)ch == 99) positionChar = 38;
    if( (int)ch == 100) positionChar = 39;
    if( (int)ch == 101) positionChar = 40;
    if( (int)ch == 102) positionChar = 41;
    if( (int)ch == 103) positionChar = 42;
    if( (int)ch == 104) positionChar = 43;
    if( (int)ch == 105) positionChar = 44;
    if( (int)ch == 106) positionChar = 45;
    if( (int)ch == 107) positionChar = 46;
    if( (int)ch == 108) positionChar = 47;
    if( (int)ch == 109) positionChar = 48;
    if( (int)ch == 110) positionChar = 49;
    if( (int)ch == 111) positionChar = 50;
    if( (int)ch == 112) positionChar = 51;
    if( (int)ch == 113) positionChar = 52;
    if( (int)ch == 114) positionChar = 53;
    if( (int)ch == 115) positionChar = 54;
    if( (int)ch == 116) positionChar = 55;
    if( (int)ch == 117) positionChar = 56;
    if( (int)ch == 118) positionChar = 57;
    if( (int)ch == 119) positionChar = 58;
    if( (int)ch == 120) positionChar = 59;
    if( (int)ch == 121) positionChar = 60;
    if( (int)ch == 122) positionChar = 61;
    // Symbols
    if( (int)ch == 46) positionChar = 62; // .
    if( (int)ch == 44) positionChar = 63; // ,
    if( (int)ch == 59) positionChar = 64; // ;
    if( (int)ch == 58) positionChar = 65; // :
    if( (int)ch == 60) positionChar = 66; // <
    if( (int)ch == 62) positionChar = 67; // >
    if( (int)ch == 124) positionChar = 68; // |
    if( (int)ch == 47) positionChar = 69; // /
    if( (int)ch == 92) positionChar = 70; // "\"
    if( (int)ch == 33) positionChar = 71; // !
    if( (int)ch == 45) positionChar = 72; // -
    if( (int)ch == 32) positionChar = 73; // пробел
    if( (int)ch == 61) positionChar = 74; // =
    if( (int)ch == 43) positionChar = 75; // +
    if( (int)ch == 42) positionChar = 76; // *
    if( (int)ch == 91) positionChar = 77; // [
    if( (int)ch == 93) positionChar = 78; // ]
    if( (int)ch == 40) positionChar = 79; // (
    if( (int)ch == 41) positionChar = 80; // )
    if( (int)ch == 123) positionChar = 81; // {
    if( (int)ch == 125) positionChar = 82; // }
    if( (int)ch == 34) positionChar = 83; // "
    if( (int)ch == 63) positionChar = 84; // ?
    if( (int)ch == 38) positionChar = 85; // &
    if( (int)ch == 37) positionChar = 86; // %

    for(int i=0; i<positionChar; i++) p += fontWidth*fontHeight;

    for(int i=y; i<y+fontHeight*pixelHeight; i+=pixelHeight) {
        for(int j=x; j<x+fontWidth*pixelWidth; j+=pixelWidth) {
            if(*p == 1)
                drawRect(j,i,pixelWidth,pixelHeight);
            p++;
        }
    }
}

void drawRect(int x, int y, int pixelWidth, int pixelHeight) {
    for(int i=y; i<y+pixelHeight; i++)
        for(int j=x; j<x+pixelWidth; j++)
            putPixel(j,i,0xffffff);
}

void putPixel(int x,int y,int color){
    int *p = 0x8000;
    char *c=*p;
    c+=((y*1024)+x)*3;
    *(int*)c=color;
}

int getKey(){
asm("mov eax, 0");
asm("in al, 0x60");
}

int hitKey(){
asm("mov eax, 0");
asm("in al, 0x64");
}

void clearkbd(int key){
asm("mov eax, 0");
asm("mov al, [ebp+4]");
asm("out 0x60, al");
}
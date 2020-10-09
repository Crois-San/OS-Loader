const int fontAdrs = 0x8004; //менять если изменять boot.asm
const int imgWidth = 400;
const int imgHeight = 400;
const int fontCount = 87; //менять если изменять font.c
const int fontWidth = 6; //менять если изменять font.c
const int fontHeight = 11; //менять если изменять font.c
//const int pixelWidth = 8; //менять если хотите
//const int pixelHeight = 8; //менять если хотите
const int width = 1024; //ширина экрана
const int height = 768; //высота экрана
const int color = 0xffffff;


void imgMenu(int);
void mainMenu(int);
void endMenu();
void drawChar (char, int, int,int,int,int); //вывод символа <символ>,<х>,<у>
void drawString (char*, int, int, int,int,int,int,int); //вывод символа <строка>,<х>,<у>,<расстояние между букв>
void drawRect(int, int, int, int ,int); 
void putPixel(int, int, int);
void drawcircle(int, int, int, int);
void drawearth(int, int, int, int, int);
void drawfullcircle(int, int, int, int);
int getKey();
int hitKey();
void clearkbd(int);
void clearScreen();
void drawImg(int,int,int);
char*  binToArr (char);

int start() {
    char str[] = "SolarSystem";
	int coords [8][2]=
	{
		{162,384},
		{292,181},
		{512,114},
		{740,181},
		{862,384},
		{740,593},
		{512,654},
		{292,593},
	}; 
	
	int i,ii,j;
	drawfullcircle(133,512,384,0xfff000);
	
	 while(1)
	 {
		
		for (i=0;i<8;i++)
		{
			drawString(str, 240, 330, 4,11,8,8,color);
			if(i==7){
				drawearth(40,coords[7][0],coords[7][1],0x00a2ff,0x00ff00);
				drawfullcircle(40,coords[6][0],coords[6][1],0);
				for(ii = 0; ii < 50000000; ii++){}
				drawearth(40,coords[0][0],coords[0][1],0x00a2ff,0x00ff00);
				drawfullcircle(40,coords[7][0],coords[7][1],0);
			}
			else{
				drawearth(40,coords[i][0],coords[i][1],0x00a2ff,0x00ff00);
			
			if(i!=0)
				drawfullcircle(40,coords[i-1][0],coords[i-1][1],0);
			
			for(ii = 0; ii < 50000000; ii++){}
			}
			
		}
		int key_code = getKey();
		if(key_code == 57)
			{
				clearkbd(key_code);
				break;
			}
		
	 }
		int key_code;
		mainMenu(key_code);
		
		
	while(1);
    return 0;
}

void imgMenu(int key_code)
{
	char lbl[] ="Esc";
	int b=0,a=0;
	int k=0;
	clearScreen();
	drawRect(75,568,225,100, color);
	drawString(lbl,85,578,3,3,7,7,0);
	drawRect(350,568,225,100, color);
				
	for(int i=0;i<185;i++)
		drawRect(i+370,618,1,10,0);
	for(int i=0;i<30;i++)
	{
		drawRect(i+370,i+618,1,10,0);
		drawRect(i+370,618-i,1,10,0);
	}
				
	drawRect(650,568,225,100, color);
				
	for(int i=0;i<185;i++)
		drawRect(i+670,618,1,10,0);
	for(int i=30;i>0;i--)
	{
		drawRect(855-i,i+618,1,10,0);
		drawRect(855-i,618-i,1,10,0);
	}
	drawImg(400,100,0);
	while(1)
	{
		key_code = getKey();
		if(key_code == 158 || key_code == 75)
		{
			if(k == 0)
				k=1;
			else
				k--;
		drawImg(400,100,k);
		clearkbd(key_code);
		}
		if(key_code == 160 || key_code == 77)
		{
			if(k == 1)
				k=0;
			else
				k++;
			drawImg(400,100,k);
			clearkbd(key_code);
		}
		if(key_code == 1)
		{
			clearkbd(key_code);
			mainMenu(key_code);
			break;
		}
	}
			
		clearkbd(key_code);
}
void mainMenu(int key_code)
{
	char menu1[]="1. Open slideshow";
	char menu2[]="2. Exit";
		
	clearScreen();
	drawString(menu1,200,264,3,17,5,5,color);
	drawString(menu2,200,364,3,7,5,5,color);
	int x=10,y=10;
	while(1){
			 
		key_code = getKey();
		if(key_code == 0x02)
		{
			imgMenu(key_code);
		}
		if(key_code == 0x03)
		{
			endMenu();
			clearkbd(key_code);
			break;
		} 
	} 
}
void endMenu()
{
	char end[]="Goodbye!";
	clearScreen();
	drawString(end,(width/2) -150,(height/2)-50,3,8,5,5,color);
}
 void drawImg(int x,int y, int imgIndex)
{
	char* byteArr;
	char *p;
	p=(char*) fontAdrs + 0x3600+20992*imgIndex;
	for (int i=y; i<y+imgHeight;i++)
	{
		for(int j=0;j<52;j++)
		{
			if(j<50)
			{
				byteArr=binToArr(*p);
				for(int k=0;k<8;k++)
				{
					if(byteArr[8-k-1]==1)
					{
						putPixel(x+j*8+k,y*2+400-i,0xffffff);
					}
					else
					{
						putPixel(x+j*8+k,y*2+400-i,0);
					}
				}
			}
			p++;
			
		}
	}
	
} 
char*  binToArr (char B)
{
	char static Out[8];
	int i,k;
	for(i=0; i<8; i++) {
	  k = ((B>>i)&1);
	  Out[i] = k;
	}
	return Out;
}
void drawString (char *arr, int x, int y, int space,int length, int pixelWidth, int pixelHeight, int color) {
    int i = 0;
        while(i<length) {
            drawChar(*arr, x, y,pixelWidth,pixelHeight, color);
            x += space+fontWidth*pixelWidth;
            i++;
            arr++; 
        }
}

void drawChar (char ch, int x, int y, int pixelWidth, int pixelHeight,int color) {
    int positionChar;
    char *p = fontAdrs + 0x2000;
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
                drawRect(j,i,pixelWidth,pixelHeight,color);
            p++;
        }
    }
}

void drawRect(int x, int y, int pixelWidth, int pixelHeight, int color) {
    for(int i=y; i<y+pixelHeight; i++)
        for(int j=x; j<x+pixelWidth; j++)
            putPixel(j,i,color);
}

void putPixel(int x,int y,int color){
    int *p = 0x8000;
    char *c=*p;
    c+=((y*1024)+x)*3;
    *(int*)c=color;
}

void drawcircle(int R, int X, int Y, int c)
{
	int x=0;
	int y=R;
	int delta = 1 - 2*R;
	int error =0;
	while (y>=0)
	{
		putPixel(X+x,Y+y,c);
		putPixel(X+x,Y-y,c);
		putPixel(X-x,Y+y,c);
		putPixel(X-x,Y-y,c);
		error = 2*(delta+y)-1;
		if ((delta <0) || (error <=0))
		{
			delta +=2* ++x+1;
			continue;
		}
		if ((delta >0) || (error >0))
		{
			delta -= 2* --y +1;
			continue;
		}
		delta += 2* (++x - y--);
	}
}

void drawearth(int r, int x, int y, int c1, int c2)
{
	int i;
	for(i=r;i>=0;i--)
	{
		if(i%3==1)
			drawcircle(i,x,y,c2);
		else
			drawcircle(i,x,y,c1);
	}
}

void drawfullcircle(int r, int x, int y, int c)
{
	int i;
	for(i=r;i>=0;i--)
	{
		drawcircle(i,x,y,c);
	}
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
void clearScreen()
{
	for(int i=0;i<height;i++)
			for(int j=0;j<width;j++)
				putPixel(j,i,0x3b3b3b);
}
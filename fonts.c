/*
This code made by AntonSemenov
If u clear this message I'll come to u and kill u
*/
asm(".code16gcc \n");
const int fontAdrs = 0x8000; //менять если изменять boot.asm
const int fontCount = 81; //менять если изменять font.c
const int fontWidth = 5; //менять если изменять font.c
const int fontHeight = 7; //менять если изменять font.c
const int pixelWidth = 10; //менять если хотите
const int pixelHeight = 10; //менять если хотите
const int width = 320; //ширина экрана
const int height = 200; //высота экрана

void drawChar (char, int, int); //вывод символа <символ>,<х>,<у>
void drawString (char*, int, int, int); //вывод символа <строка>,<х>,<у>,<расстояние между букв>
void drawRect(int, int, int, int); 
void putPixel(int, int, int);

void drawcircle(int R, int X, int Y, int c);
void drawearth(int r, int x, int y, int c1, int c2);
void drawfullcircle(int r, int x, int y, int c);

int start() {
	/* char str[] = "HELLO";
	drawString(str, width/2, height/2, 4);
	drawChar('A',width/2,height/2+pixelHeight*fontHeight+5); */
	
	int coords [8][2]=
	{
		{50,100},
		{91,47},
		{160,30},
		{231,47},
		{270,100},
		{231,154},
		{160,170},
		{91,154}
	}; 
	int i,ii,j;
	drawfullcircle(40,160,100,0xfff000);
	//for(j=0;j<4;j++)
	while(1)
		for (i=0;i<8;i++)
		{
			if(i==7){
				drawearth(10,coords[7][0],coords[7][1],0x002aff,0x2aff00);
				drawfullcircle(10,coords[6][0],coords[6][1],0x000000);
				for(ii = 0; ii < 40000000; ii++){}
				drawearth(10,coords[0][0],coords[0][1],0x002aff,0x2aff00);
				drawfullcircle(10,coords[7][0],coords[7][1],0x000000);
			}
			else{
				drawearth(10,coords[i][0],coords[i][1],0x002aff,0x2aff00);
			
			if(i!=0)
				drawfullcircle(10,coords[i-1][0],coords[i-1][1],0x000000);
			
			for(ii = 0; ii < 40000000; ii++){}
			}
			
		}
	
	while(1);
	return 0;
}

void drawString (char *arr, int x, int y, int space) {
	int i = 0;
		while(i<5) {
			drawChar(*arr, x, y);
			x += space+fontWidth*pixelWidth;
			i++;
			arr++; 
		}
}

void drawChar (char ch, int x, int y) {
	int positionChar;
	char *p = (char*)fontAdrs+0x2018;

	//U can delete this and remake switch() as if() below, sorry mne len'
	if( (int)ch == 65) positionChar = 0;
	if( (int)ch == 66) positionChar = 1;
	if( (int)ch == 67) positionChar = 2;
	if( (int)ch == 68) positionChar = 3;
	if( (int)ch == 69) positionChar = 4;
	if( (int)ch == 70) positionChar = 5;
	if( (int)ch == 71) positionChar = 6;
	if( (int)ch == 72) positionChar = 7;
	if( (int)ch == 73) positionChar = 8;
	if( (int)ch == 74) positionChar = 8;
	if( (int)ch == 75) positionChar = 10;
	if( (int)ch == 76) positionChar = 11; 
	if( (int)ch == 77) positionChar = 12; 
	if( (int)ch == 78) positionChar = 13; 
	if( (int)ch == 79) positionChar = 14;  
	if( (int)ch == 80) positionChar = 15;    
	if( (int)ch == 81) positionChar = 16;    
	if( (int)ch == 82) positionChar = 17;    
	if( (int)ch == 83) positionChar = 18;     
	if( (int)ch == 84) positionChar = 19;     
	if( (int)ch == 85) positionChar = 20;     
	if( (int)ch == 86) positionChar = 21;    
	if( (int)ch == 87) positionChar = 22;   
	if( (int)ch == 88) positionChar = 23;  
	if( (int)ch == 89) positionChar = 24; 
	if( (int)ch == 90) positionChar = 25;	
	// switch (ch) {
	// 	case 0x61: 
	// 		positionChar = 0;
	// 		break;
	// 	case 0x62: 
	// 		positionChar = 1;
	// 		break;
	// 	case 0x63: 
	// 		positionChar = 2;
	// 		break;
	// 	case 0x64: 
	// 		positionChar = 3;
	// 		break;
	// 	case 0x65: 
	// 		positionChar = 4;
	// 		break;
	// 	case 0x66: 
	// 		positionChar = 5;
	// 		break;
	// 	case 0x67: 
	// 		positionChar = 6;
	// 		break;
	// 	case 0x68: 
	// 		positionChar = 7;
	// 		break;
	// 	case 0x69: 
	// 		positionChar = 8;
	// 		break;
	// 	case 0x6A: 
	// 		positionChar = 9;
	// 		break;
	// 	case 0x6B: 
	// 		positionChar = 10;
	// 		break;
	// 	case 0x6C: 
	// 		positionChar = 11;
	// 		break;
	// 	case 0x6D: 
	// 		positionChar = 12;
	// 		break;
	// 	case 0x6E: 
	// 		positionChar = 13;
	// 		break;
	// 	case 0x6F: 
	// 		positionChar = 14;
	// 		break;
	// 	case 0x70: 
	// 		positionChar = 15;
	// 		break;
	// 	case 0x71: 
	// 		positionChar = 16;
	// 		break;
	// 	case 0x72: 
	// 		positionChar = 17;
	// 		break;
	// 	case 0x73: 
	// 		positionChar = 18;
	// 		break;
	// 	case 0x74: 
	// 		positionChar = 19;
	// 		break;
	// 	case 0x75: 
	// 		positionChar = 20;
	// 		break;
	// 	case 0x76: 
	// 		positionChar = 21;
	// 		break;
	// 	case 0x77: 
	// 		positionChar = 22;
	// 		break;
	// 	case 0x78: 
	// 		positionChar = 23;
	// 		break;
	// 	case 0x79: 
	// 		positionChar = 24;
	// 		break;
	// 	case 0x7A: 
	// 		positionChar = 25;
	// 		break;
	// 	default:
	// 		positionChar = 0;
	// 		break;
	// }

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
	int *p = (int*)0x8000;
	char *c=(char*)*p;
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
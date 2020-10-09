/*
This code made by AntonSemenov
If u clear this message I'll come to u and kill u
*/
const int fontAdrs = 0x8000; //менять если изменять boot.asm
const int fontCount = 81; //менять если изменять font.c
const int fontWidth = 5; //менять если изменять font.c
const int fontHeight = 7; //менять если изменять font.c
const int pixelWidth = 10; //менять если хотите
const int pixelHeight = 10; //менять если хотите
const int width = 1024; //ширина экрана
const int height = 768; //высота экрана

void drawChar (char, int, int); //вывод символа <символ>,<х>,<у>
void drawString (char*, int, int, int); //вывод символа <строка>,<х>,<у>,<расстояние между букв>
void drawRect(int, int, int, int); 
void putPixel(int, int, int);
void drawcircle(int, int, int, int);
void drawearth(int, int, int, int, int);
void drawfullcircle(int, int, int, int);
/* void earth(int, int);
void mercury(int, int);
void venus(int, int);
void mars(int, int);
void jupiter(int, int);
void neptune(int, int);
void uranus(int, int); */


int start() {


	int coords [8][2]=
	{
		{323,384},
		{378,250},
		{512,194},
		{646,250},
		{701,384},
		{645,517},
		{512,572},
		{379,517},
	};
	
		int merc [8][2]=
	{
		{393,384},
		{428,300},
		{512,265},
		{596,300},
		{631,384},
		{596,468},
		{512,503},
		{428,468},
	};
	
		int ven [8][2]=
	{
		{353,384},
		{400,497},
		{512,543},
		{624,498},
		{671,384},
		{625,272},
		{512,225},
		{400,272},
	};
	
		int mar [8][2]=
	{
		{303,384},
		{365,237},
		{512,175},
		{660,237},
		{721,384},
		{660,532},
		{512,593},
		{364,532},
	};
	
		int jup [8][2]=
	{
		{233,384},
		{315,187},
		{512,105},
		{709,186},
		{791,384},
		{710,581},
		{512,663},
		{315,582},
	};
	
		int nep [8][2]=
	{
		{193,384},
		{286,159},
		{512,65},
		{737,159},
		{831,384},
		{737,609},
		{512,703},
		{286,609},
	};
	
		int uran [8][2]=
	{
		{113,384},
		{245,117},
		{512,25},
		{779,117},
		{911,384},
		{779,651},
		{512,743},
		{245,651},
	};
	
	int i,ii;
	drawfullcircle(80,512,384,0xfff000);
	while(1)
		for (i=0;i<8;i++)
		{
			//меркурий
			
			if(i==7){
				drawfullcircle(5,merc[7][0],merc[7][1],0xb5a494);
				drawfullcircle(5,merc[6][0],merc[6][1],0);
				for(ii = 0; ii < 50000000; ii++){}
				drawfullcircle(5,merc[7][0],merc[7][1],0xb5a494);
				drawfullcircle(5,merc[7][0],merc[7][1],0);
			}
			else{
				drawfullcircle(5,merc[7][0],merc[7][1],0xb5a494);
			
			if(i!=0)
				drawfullcircle(5,merc[i-1][0],merc[i-1][1],0);
			
			for(ii = 0; ii < 50000000; ii++){}
			}
			
			//венера
			
			if(i==7){
				drawfullcircle(10,ven[7][0],ven[7][1],0xea9a4f);
				drawfullcircle(10,ven[6][0],ven[6][1],0);
				for(ii = 0; ii < 75000000; ii++){}
				drawfullcircle(10,ven[7][0],ven[7][1],0xea9a4f);
				drawfullcircle(10,ven[7][0],ven[7][1],0);
			}
			else{
				drawfullcircle(10,ven[7][0],ven[7][1],0xea9a4f);
			
			if(i!=0)
				drawfullcircle(10,ven[i-1][0],ven[i-1][1],0);
			
			for(ii = 0; ii < 75000000; ii++){}
			}
			
			//земля
			
			if(i==7){
				drawearth(10,coords[7][0],coords[7][1],0x00a2ff,0x00ff00);
				drawfullcircle(10,coords[6][0],coords[6][1],0);
				for(ii = 0; ii < 77000000; ii++){}
				drawearth(10,coords[0][0],coords[0][1],0x00a2ff,0x00ff00);
				drawfullcircle(10,coords[7][0],coords[7][1],0);
			}
			else{
				drawearth(10,coords[i][0],coords[i][1],0x00a2ff,0x00ff00);
			
			if(i!=0)
				drawfullcircle(10,coords[i-1][0],coords[i-1][1],0);
			
			for(ii = 0; ii < 77000000; ii++){}
			}
			
			//марс
			
			if(i==7){
				drawfullcircle(9,mar[7][0],mar[7][1],0xf4947f);
				drawfullcircle(9,mar[6][0],mar[6][1],0);
				for(ii = 0; ii < 80000000; ii++){}
				drawfullcircle(9,mar[7][0],mar[7][1],0xf4947f);
				drawfullcircle(9,mar[7][0],mar[7][1],0);
			}
			else{
				drawfullcircle(9,mar[7][0],mar[7][1],0xf4947f);
			
			if(i!=0)
				drawfullcircle(9,mar[i-1][0],mar[i-1][1],0);
			
			for(ii = 0; ii < 80000000; ii++){}
			}
			
			//юпитер
			
			if(i==7){
				drawfullcircle(25,jup[7][0],jup[7][1],0xd89b5b);
				drawfullcircle(25,jup[6][0],jup[6][1],0);
				for(ii = 0; ii < 100000000; ii++){}
				drawfullcircle(25,jup[7][0],jup[7][1],0xd89b5b);
				drawfullcircle(25,jup[7][0],jup[7][1],0);
			}
			else{
				drawfullcircle(25,jup[7][0],jup[7][1],0xd89b5b);
			
			if(i!=0)
				drawfullcircle(25,jup[i-1][0],jup[i-1][1],0);
			
			for(ii = 0; ii < 100000000; ii++){}
			}
			
			//нептун
			
			if(i==7){
				drawfullcircle(15,nep[7][0],nep[7][1],0xb3efef);
				drawfullcircle(15,nep[6][0],nep[6][1],0);
				for(ii = 0; ii < 120000000; ii++){}
				drawfullcircle(15,nep[7][0],nep[7][1],0xb3efef);
				drawfullcircle(15,nep[7][0],nep[7][1],0);
			}
			else{
				drawfullcircle(15,nep[7][0],nep[7][1],0xb3efef);
			
			if(i!=0)
				drawfullcircle(15,nep[i-1][0],nep[i-1][1],0);
			
			for(ii = 0; ii < 120000000; ii++){}
			}
			
			//уран
			
			if(i==7){
				drawfullcircle(15,uran[7][0],uran[7][1],0x383ae0);
				drawfullcircle(15,uran[6][0],uran[6][1],0);
				for(ii = 0; ii < 150000000; ii++){}
				drawfullcircle(15,uran[7][0],uran[7][1],0x383ae0);
				drawfullcircle(15,uran[7][0],uran[7][1],0);
			}
			else{
				drawfullcircle(15,uran[7][0],uran[7][1],0x383ae0);
			
			if(i!=0)
				drawfullcircle(15,uran[i-1][0],uran[i-1][1],0);
			
			for(ii = 0; ii < 150000000; ii++){}
			}
			
		}
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
    char *p = fontAdrs+0x2018;
	int j=0;
	
	for(int i=33;i<125;i++)
	{
		if((i==33)||(i==37)||(i>=40&&i<=59)||(i==63)||(i==63)||(i>=65&&i<=93)||(i>=97&&i<=123)||(i==125))
		{
			if( (int)ch == i) positionChar = j;
			j++;
		}
		
	}
    

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
/* void earth(int i, int ii)
{
	if(i==7){
				drawearth(10,coords[7][0],coords[7][1],0x00a2ff,0x00ff00);
				drawfullcircle(10,coords[6][0],coords[6][1],0);
				for(ii = 0; ii < 77000000; ii++){}
				drawearth(10,coords[0][0],coords[0][1],0x00a2ff,0x00ff00);
				drawfullcircle(10,coords[7][0],coords[7][1],0);
			}
			else{
				drawearth(10,coords[i][0],coords[i][1],0x00a2ff,0x00ff00);
			
			if(i!=0)
				drawfullcircle(10,coords[i-1][0],coords[i-1][1],0);
			
			for(ii = 0; ii < 77000000; ii++){}
			}
}
void mercury(int i, int ii)
{
	if(i==7){
				drafullcircle(5,merc[7][0],merc[7][1],0xb5a494);
				drawfullcircle(5,merc[6][0],merc[6][1],0);
				for(ii = 0; ii < 50000000; ii++){}
				drafullcircle(5,merc[7][0],merc[7][1],0xb5a494);
				drawfullcircle(5,merc[7][0],merc[7][1],0);
			}
			else{
				drafullcircle(5,merc[7][0],merc[7][1],0xb5a494);
			
			if(i!=0)
				drawfullcircle(5,merc[i-1][0],merc[i-1][1],0);
			
			for(ii = 0; ii < 50000000; ii++){}
			}
}
void venus(int i, int ii)
{
	if(i==7){
				drafullcircle(10,ven[7][0],ven[7][1],0xea9a4f);
				drawfullcircle(10,ven[6][0],ven[6][1],0);
				for(ii = 0; ii < 75000000; ii++){}
				drafullcircle(10,ven[7][0],ven[7][1],0xea9a4f);
				drawfullcircle(10,ven[7][0],ven[7][1],0);
			}
			else{
				drafullcircle(10,ven[7][0],ven[7][1],0xea9a4f);
			
			if(i!=0)
				drawfullcircle(10,ven[i-1][0],ven[i-1][1],0);
			
			for(ii = 0; ii < 75000000; ii++){}
			}
}
void mars(int i, int ii)
{
	if(i==7){
				drafullcircle(9,mar[7][0],mar[7][1],0xf4947f);
				drawfullcircle(9,mar[6][0],mar[6][1],0);
				for(ii = 0; ii < 80000000; ii++){}
				drafullcircle(9,mar[7][0],mar[7][1],0xf4947f);
				drawfullcircle(9,mar[7][0],mar[7][1],0);
			}
			else{
				drafullcircle(9,mar[7][0],mar[7][1],0xf4947f);
			
			if(i!=0)
				drawfullcircle(9,mar[i-1][0],mar[i-1][1],0);
			
			for(ii = 0; ii < 80000000; ii++){}
			}
}
void jupiter(int i, int ii)
{
	if(i==7){
				drafullcircle(25,jup[7][0],jup[7][1],0xd89b5b);
				drawfullcircle(25,jup[6][0],jup[6][1],0);
				for(ii = 0; ii < 100000000; ii++){}
				drafullcircle(25,jup[7][0],jup[7][1],0xd89b5b);
				drawfullcircle(25,jup[7][0],jup[7][1],0);
			}
			else{
				drafullcircle(25,jup[7][0],jup[7][1],0xd89b5b);
			
			if(i!=0)
				drawfullcircle(25,jup[i-1][0],jup[i-1][1],0);
			
			for(ii = 0; ii < 100000000; ii++){}
			}
}
void neptune(int i, int ii)
{
	if(i==7){
				drafullcircle(15,nep[7][0],nep[7][1],0xb3efef);
				drawfullcircle(15,nep[6][0],nep[6][1],0);
				for(ii = 0; ii < 120000000; ii++){}
				drafullcircle(15,nep[7][0],nep[7][1],0xb3efef);
				drawfullcircle(15,nep[7][0],nep[7][1],0);
			}
			else{
				drafullcircle(15,nep[7][0],nep[7][1],0xb3efef);
			
			if(i!=0)
				drawfullcircle(15,nep[i-1][0],nep[i-1][1],0);
			
			for(ii = 0; ii < 120000000; ii++){}
			}
}
void uranus(int i, int ii)
{
	if(i==7){
				drafullcircle(15,uran[7][0],uran[7][1],0x383ae0);
				drawfullcircle(15,uran[6][0],uran[6][1],0);
				for(ii = 0; ii < 150000000; ii++){}
				drafullcircle(15,uran[7][0],uran[7][1],0x383ae0);
				drawfullcircle(15,uran[7][0],uran[7][1],0);
			}
			else{
				drafullcircle(15,uran[7][0],uran[7][1],0x383ae0);
			
			if(i!=0)
				drawfullcircle(15,uran[i-1][0],uran[i-1][1],0);
			
			for(ii = 0; ii < 150000000; ii++){}
			}
} */


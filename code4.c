asm(".code16gcc \n");
void setpixel (int, int, char);
void drawcircle(int R, int X, int Y, int c);
void drawearth(int r, int x, int y, int c1, int c2);
void drawfullcircle(int r, int x, int y, int c);
int start ()
{
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
	drawfullcircle(40,160,100,14);
	//for(j=0;j<4;j++)
	while(1)
		for (i=0;i<8;i++)
		{
			if(i==7){
				drawearth(10,coords[7][0],coords[7][1],1,2);
				drawfullcircle(10,coords[6][0],coords[6][1],0);
				for(ii = 0; ii < 40000000; ii++){}
				drawearth(10,coords[0][0],coords[0][1],1,2);
				drawfullcircle(10,coords[7][0],coords[7][1],0);
			}
			else{
				drawearth(10,coords[i][0],coords[i][1],1,2);
			
			if(i!=0)
				drawfullcircle(10,coords[i-1][0],coords[i-1][1],0);
			
			for(ii = 0; ii < 40000000; ii++){}
			}
			
		}
	//drawfullcircle(10,20,20,1);
	//while(1);
	return 0;
}

void setpixel (int x, int y, char c)
{
	char *p=(char*) 0xA0000;
	p+=(y*320)+x;
	*p=c;
}

void drawcircle(int R, int X, int Y, int c)
{
	int x=0;
	int y=R;
	int delta = 1 - 2*R;
	int error =0;
	while (y>=0)
	{
		setpixel(X+x,Y+y,c);
		setpixel(X+x,Y-y,c);
		setpixel(X-x,Y+y,c);
		setpixel(X-x,Y-y,c);
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
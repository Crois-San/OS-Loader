asm(".code16gcc \n");
//void setpixel (int, int, char*);
void setpixel (int, int, char);
int getBytes(char *pointer);
int start ()
{
	int i,j,width=0,height=0;
	 char color=' ';
	
	char *imgp=(char*) 0x8000;
	width=getBytes(imgp);
	imgp=(char*)0x8004;
	height=getBytes(imgp); 
	
	imgp=(char*)0x8008; 
	for(i=0; i<height; i++)
	{
		for(j=0;j<width;j++)
		{
			color=(char)getBytes(imgp); 
			setpixel(j,i,color);
			//setpixel(j,i,imgp);
			imgp+=4;
		}
	}
	
	while(1);
	return 0;
}
/* 
void setpixel (int x, int y, char *colorp)
{
	int c=0;
	char *buff=colorp+4;
	int mul=0x1000000;
	char *p=(char*) 0xA0000;
	for(int i=1;i<=4;i++)
	{
		c=(int)(*colorp)*mul;
		mul/=100;
		buff--;
		p+=(y*320)+x+i;
		*p=c;
	}
} */
void setpixel (int x, int y, char c)
{
	char *p=(char*) 0xA0000;
	p+=(y*320)+x;
	*p=c;
}

 int getBytes(char *pointer)
{
	int bytes=0;
	char *buff=pointer;
	int mul=0x1;
	for(int i=0;i<4;i++)
	{
		bytes+=(int)(*pointer)*mul;
		mul*=0x100;
		buff++;
	}
	return bytes;
} 
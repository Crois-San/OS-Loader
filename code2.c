asm(".code16gcc \n");
void setpixel (int, int, char);
int start ()
{
	int i;
	for(i=0; i<90; i++)
		setpixel(i,i,4);
	while(1);
	return 0;
}

void setpixel (int x, int y, char c)
{
	char *p=(char*) 0xA0000;
	p+=(y*320)+x;
	*p=c;
}
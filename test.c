asm(".code16gcc\n");
void print(char,char,int,int);
int start(){
char mytext[]="Hello C";
int i;
for(i=0; mytext[i];i++)
print(mytext[i],4,i,0);
while(1);
return 0;
}
void print(char s, char c, int x, int y)
{
char *p=(char*)0xb8000;
p+=((y*80+x)*2);
*p=s;
p++;
*p=c;
}

#include <stdio.h>
#define ARR_NUM 81
#define WIDTH 5
#define HEIGHT 7
const char Fnt [ARR_NUM][HEIGHT][WIDTH]={
	{ //!
	{"00100"},
	{"00100"},
	{"00100"},
	{"00100"},
	{"00000"},
	{"00100"},
	{"00000"},
	},
	{ //%
	{"10010"},
	{"00010"},
	{"00100"},
	{"00100"},
	{"00100"},
	{"01000"},
	{"01001"},
	},
	{ //(
	{"00010"},
	{"00100"},
	{"00100"},
	{"00100"},
	{"00100"},
	{"00100"},
	{"00010"},
	},
	{ //)
	{"01000"},
	{"00100"},
	{"00100"},
	{"00100"},
	{"00100"},
	{"00100"},
	{"01000"},
	},
	{ //*
	{"00000"},
	{"10101"},
	{"01110"},
	{"11111"},
	{"01110"},
	{"10101"},
	{"00000"},
	},
	{ //+
	{"00000"},
	{"00100"},
	{"00100"},
	{"11111"},
	{"00100"},
	{"00100"},
	{"00000"},
	},
	{ //  ,
	{"00000"},
	{"00000"},
	{"00000"},
	{"00000"},
	{"00000"},
	{"00100"},
	{"00100"},
	},
	{ //-
	{"00000"},
	{"00000"},
	{"00000"},
	{"11111"},
	{"00000"},
	{"00000"},
	{"00000"},
	},
	{ //.
	{"00000"},
	{"00000"},
	{"00000"},
	{"00000"},
	{"00000"},
	{"00100"},
	{"00000"},
	},
	{ // /
	{"00010"},
	{"00010"},
	{"00100"},
	{"00100"},
	{"00100"},
	{"01000"},
	{"01000"},
	},
	{ //0
	{"01110"},
	{"11011"},
	{"10001"},
	{"10001"},
	{"10001"},
	{"11011"},
	{"01110"},
	},
	{ //1
	{"00100"},
	{"01100"},
	{"10100"},
	{"00100"},
	{"00100"},
	{"00100"},
	{"11111"},
	},
	{ //2
	{"01110"},
	{"10001"},
	{"00001"},
	{"01110"},
	{"10000"},
	{"10000"},
	{"11111"},
	},
	{ //3
	{"01110"},
	{"00001"},
	{"00001"},
	{"01110"},
	{"00001"},
	{"00001"},
	{"01110"},
	},
	{ //4
	{"10001"},
	{"10001"},
	{"10001"},
	{"11111"},
	{"00001"},
	{"00001"},
	{"00001"},
	},
	{ //5
	{"11111"},
	{"10000"},
	{"10000"},
	{"11110"},
	{"00001"},
	{"00001"},
	{"11110"},
	},
	{ //6
	{"01110"},
	{"10000"},
	{"10000"},
	{"11110"},
	{"10001"},
	{"10001"},
	{"01110"},
	},
	{ //7
	{"11111"},
	{"00001"},
	{"00010"},
	{"00010"},
	{"00100"},
	{"00100"},
	{"00100"},
	},
	{ //8
	{"01110"},
	{"10001"},
	{"10001"},
	{"01110"},
	{"10001"},
	{"10001"},
	{"01110"},
	},
	{ //9
	{"01110"},
	{"10001"},
	{"10001"},
	{"01111"},
	{"00001"},
	{"00001"},
	{"01110"},
	},
	{ //:
	{"00000"},
	{"00100"},
	{"00000"},
	{"00000"},
	{"00000"},
	{"00100"},
	{"00000"},
	},
	{ //;
	{"00000"},
	{"00100"},
	{"00000"},
	{"00000"},
	{"00000"},
	{"00100"},
	{"00100"},
	},
	{ //=
	{"00000"},
	{"00000"},
	{"11111"},
	{"00000"},
	{"11111"},
	{"00000"},
	{"00000"},
	},
	{ //?
	{"01110"},
	{"10001"},
	{"00110"},
	{"00100"},
	{"00000"},
	{"00100"},
	{"00000"},
	},
	{ //A
	{"00100"},
	{"01010"},
	{"10001"},
	{"11111"},
	{"10001"},
	{"10001"},
	{"10001"},
	},
	{ //B
	{"11110"},
	{"10001"},
	{"10001"},
	{"11110"},
	{"10001"},
	{"10001"},
	{"11110"},
	},
	{ //C
	{"01110"},
	{"10001"},
	{"10000"},
	{"10000"},
	{"10000"},
	{"10001"},
	{"01110"},
	},
	{ //D
	{"11110"},
	{"10001"},
	{"10001"},
	{"10001"},
	{"10001"},
	{"10001"},
	{"11110"},
	},
	{ //E
	{"11111"},
	{"10000"},
	{"10000"},
	{"11100"},
	{"10000"},
	{"10000"},
	{"10000"},
	},
	{ //F
	{"01110"},
	{"10001"},
	{"10000"},
	{"10111"},
	{"10001"},
	{"10001"},
	{"01110"},
	},
	{ //G
	{"10001"},
	{"10001"},
	{"10001"},
	{"11111"},
	{"10001"},
	{"10001"},
	{"10001"},
	},
	{ //H
	{"11111"},
	{"00100"},
	{"00100"},
	{"00100"},
	{"00100"},
	{"00100"},
	{"11111"},
	},
	{ //I
	{"01110"},
	{"00100"},
	{"00100"},
	{"00100"},
	{"00100"},
	{"00100"},
	{"11000"},
	},
	{ //K
	{"10001"},
	{"00001"},
	{"10010"},
	{"11110"},
	{"10001"},
	{"10001"},
	{"10001"},
	},
	{ //L
	{"10000"},
	{"10000"},
	{"10000"},
	{"10000"},
	{"10000"},
	{"10000"},
	{"11111"},
	},
	{ //M
	{"10001"},
	{"11011"},
	{"10101"},
	{"10001"},
	{"10001"},
	{"10001"},
	{"10001"},
	},
	{ //N
	{"10001"},
	{"11001"},
	{"11101"},
	{"10111"},
	{"10011"},
	{"10001"},
	{"10001"},
	},
	{ //O
	{"01110"},
	{"10001"},
	{"10001"},
	{"10001"},
	{"10001"},
	{"10001"},
	{"01110"},
	},
	{ //P
	{"11110"},
	{"10001"},
	{"10001"},
	{"10001"},
	{"11110"},
	{"10000"},
	{"10000"},
	},
	{ //Q
	{"01110"},
	{"10001"},
	{"10001"},
	{"10101"},
	{"10011"},
	{"10010"},
	{"01101"},
	},
	{ //R
	{"11110"},
	{"10001"},
	{"10001"},
	{"10001"},
	{"11110"},
	{"10001"},
	{"10001"},
	},
	{ //S
	{"01110"},
	{"10001"},
	{"10000"},
	{"01110"},
	{"00001"},
	{"10001"},
	{"01110"},
	},
	{ //T
	{"11111"},
	{"00100"},
	{"00100"},
	{"00100"},
	{"00100"},
	{"00100"},
	{"00100"},
	},
	{ //U
	{"10001"},
	{"10001"},
	{"10001"},
	{"10001"},
	{"10001"},
	{"10001"},
	{"01110"},
	},
	{ //V
	{"10001"},
	{"10001"},
	{"10001"},
	{"01010"},
	{"01010"},
	{"01010"},
	{"00100"},
	},
	{ //W
	{"10001"},
	{"10001"},
	{"10001"},
	{"10101"},
	{"10101"},
	{"10101"},
	{"01010"},
	},
	{ //X
	{"10001"},
	{"01010"},
	{"01010"},
	{"00100"},
	{"01010"},
	{"01010"},
	{"10001"},
	},
	{ //Y
	{"10001"},
	{"01010"},
	{"01010"},
	{"01010"},
	{"00100"},
	{"00100"},
	{"11000"},
	},
	{ //Z
	{"11111"},
	{"00001"},
	{"00010"},
	{"00100"},
	{"01000"},
	{"10000"},
	{"11111"},
	},
	{ //[
	{"00110"},
	{"00100"},
	{"00100"},
	{"00100"},
	{"00100"},
	{"00100"},
	{"00110"},
	},
	{ /* \ */
	{"01000"},
	{"01000"},
	{"00100"},
	{"00100"},
	{"00100"},
	{"00010"},
	{"00010"},
	},
	{ //]
	{"01100"},
	{"00100"},
	{"00100"},
	{"00100"},
	{"00100"},
	{"00100"},
	{"01100"},
	},
	{ //a
	{"01110"},
	{"00001"},
	{"00001"},
	{"01111"},
	{"10001"},
	{"10001"},
	{"01111"},
	},
	{ //b
	{"10000"},
	{"10000"},
	{"10000"},
	{"11110"},
	{"10001"},
	{"10001"},
	{"01110"},
	},
	{ //c
	{"00000"},
	{"00000"},
	{"00000"},
	{"01110"},
	{"10000"},
	{"10000"},
	{"01110"},
	},
	{ //d
	{"00001"},
	{"00001"},
	{"00001"},
	{"01111"},
	{"10001"},
	{"10001"},
	{"01111"},
	},
	{ //e
	{"00000"},
	{"01110"},
	{"10001"},
	{"11111"},
	{"10000"},
	{"10001"},
	{"01110"},
	},
	{ //f
	{"00100"},
	{"01010"},
	{"01000"},
	{"01000"},
	{"11100"},
	{"01000"},
	{"01000"},
	},
	{ //g
	{"00000"},
	{"01110"},
	{"10001"},
	{"01110"},
	{"00001"},
	{"10001"},
	{"01110"},
	},
	{ //h
	{"10000"},
	{"10000"},
	{"10000"},
	{"10000"},
	{"11100"},
	{"10010"},
	{"10010"},
	},
	{ //i
	{"00000"},
	{"00100"},
	{"00000"},
	{"00100"},
	{"00100"},
	{"00100"},
	{"00100"},
	},
	{ //j
	{"00000"},
	{"00100"},
	{"00000"},
	{"00100"},
	{"00100"},
	{"00100"},
	{"01000"},
	},
	{ //k
	{"00000"},
	{"01000"},
	{"01000"},
	{"01010"},
	{"01100"},
	{"01010"},
	{"01010"},
	},
	{ //l
	{"00000"},
	{"00100"},
	{"00100"},
	{"00100"},
	{"00100"},
	{"00100"},
	{"00100"},
	},
	{ //m
	{"00000"},
	{"00000"},
	{"00000"},
	{"11010"},
	{"10101"},
	{"10001"},
	{"10101"},
	},
	{ //n
	{"00000"},
	{"00000"},
	{"00000"},
	{"00000"},
	{"11100"},
	{"10010"},
	{"10010"},
	},
	{ //o
	{"00000"},
	{"00000"},
	{"01110"},
	{"10001"},
	{"10001"},
	{"10001"},
	{"01110"},
	},
	{ //p
	{"00000"},
	{"00000"},
	{"11100"},
	{"10010"},
	{"11100"},
	{"10000"},
	{"10000"},
	},
	{ //q
	{"00000"},
	{"01100"},
	{"10010"},
	{"10010"},
	{"01110"},
	{"00010"},
	{"00010"},
	},
	{ //r
	{"00000"},
	{"00000"},
	{"10110"},
	{"11000"},
	{"10000"},
	{"10000"},
	{"10000"},
	},
	{ //s
	{"00000"},
	{"00000"},
	{"01111"},
	{"10000"},
	{"01110"},
	{"00001"},
	{"11110"},
	},
	{ //t
	{"00000"},
	{"00100"},
	{"01110"},
	{"00100"},
	{"00100"},
	{"00100"},
	{"00010"},
	},
	{ //u
	{"00000"},
	{"00000"},
	{"10001"},
	{"10001"},
	{"10001"},
	{"10011"},
	{"01101"},
	},
	{ //v
	{"00000"},
	{"00000"},
	{"00000"},
	{"01010"},
	{"01010"},
	{"01010"},
	{"00100"},
	},
	{ //w
	{"00000"},
	{"00000"},
	{"00000"},
	{"10001"},
	{"10101"},
	{"10101"},
	{"01010"},
	},
	{ //x
	{"00000"},
	{"00000"},
	{"01010"},
	{"01010"},
	{"00100"},
	{"01010"},
	{"01010"},
	},
	{ //y
	{"00000"},
	{"00000"},
	{"01010"},
	{"01010"},
	{"00100"},
	{"00100"},
	{"01000"},
	},
	{ //z
	{"00000"},
	{"00000"},
	{"01110"},
	{"00010"},
	{"00100"},
	{"01000"},
	{"01110"},
	},
	{ //{
	{"00010"},
	{"00100"},
	{"00100"},
	{"01000"},
	{"00100"},
	{"00100"},
	{"00010"},
	},
	{ //}
	{"01000"},
	{"00100"},
	{"00100"},
	{"00010"},
	{"00100"},
	{"00100"},
	{"01000"},
	}
};
int main(){
	FILE *f =fopen("font.bin","wb");
	for (int i=0;i<ARR_NUM;i++)
		for(int j=0;j<HEIGHT;j++)
			for(int k=0;k<WIDTH;k++)
				fputc(Fnt[i][j][k],f);
	fclose(f);
	return 0;
}
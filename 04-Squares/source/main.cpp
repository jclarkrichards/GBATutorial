#include <stdlib.h>
#include <time.h>

#define WIDTH  240
#define HEIGHT 160
#define COLOR  32

void square(int x0, int y0, int x1, int y1, bool fill, int r, int g, int b, unsigned short *vram);

int main()
{
	*(volatile unsigned short*)0x04000000 = 0x0403;
	unsigned short *vram = (unsigned short*)0x06000000;
	
	//square(10, 10, 50, 40, false, 31, 0, 0, vram);
	//square(100, 80, 180, 100, true, 0, 31, 0, vram);
	//square(180, 100, 100, 80, true, 0, 31, 0, vram);
	srand(time(NULL));
	
	while(1)
	{
		int x0 = rand() % WIDTH;
		int y0 = rand() % HEIGHT;
		int x1 = rand() % WIDTH;
		int y1 = rand() % HEIGHT;
		int r = rand() % COLOR;
		int g = rand() % COLOR;
		int b = rand() % COLOR;
		square(x0, y0, x1, y1, false, r, g, b, vram);
	}
	return 0;
}

void square(int x0, int y0, int x1, int y1, bool fill, int r, int g, int b, unsigned short *vram)
{
	int xlow = x0;
	int xhigh = x1;
	int ylow = y0;
	int yhigh = y1;
	
	if(x0 > x1)
	{
		xlow = x1;
		xhigh = x0;
	}
	
	if(y0 > y1)
	{
		ylow = y1;
		yhigh = y0;
	}
	
	for(int y=ylow; y<=yhigh; y++)
	{
		for(int x=xlow; x<=xhigh; x++)
		{
			if(fill)
			{
				vram[x+y*WIDTH] = r | g<<5 | b<<10;
			}
			else
			{
				if(x == x0 || x == x1 || y == y0 || y == y1)
				{
					vram[x+y*WIDTH] = r | g<<5 | b<<10;
				}
			}
			
		}
	}
}
#include <stdlib.h>
#include <time.h>

#define WIDTH  240
#define HEIGHT 160
#define COLOR  32

int main()
{
	*(volatile unsigned short*)0x04000000 = 0x0403;
	
	unsigned short *vram = (unsigned short*)0x06000000;
	srand(time(NULL));
	
	while(1)
	{
		unsigned short x = rand() % WIDTH;
		unsigned short y = rand() % HEIGHT;
		unsigned short r = rand() % COLOR;
		unsigned short g = rand() % COLOR;
		unsigned short b = rand() % COLOR;
		vram[x + y * WIDTH] = r | g<<5 | b<<10;
	}
	return 0;
}
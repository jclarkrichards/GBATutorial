#define WIDTH 240
int point(int x, int y);
void line(int x0, int y0, int x1, int y1, unsigned short *vram);

int main()
{
	*(volatile unsigned short*)0x04000000 = 0x0403;
	unsigned short* vram = (unsigned short*)0x06000000;
	//vram[point(10,10)] = 0x001F;
	//*(unsigned short*)0x06000000 = 0x001F;
	line(0,1,95,82, vram);
	
	while(1);
	return 0;
}

int point(int x, int y)
{
	return y * WIDTH + x;
}

void line(int x0, int y0, int x1, int y1, unsigned short *vram)
{
	int dx = x1 - x0;
	int dy = y1 - y0;
	int D = 2*dy - dx;
	int y = y0;
	
	for(int x=x0; x<x1; x++)
	{
		vram[point(x, y)] = 0x001F;
		if(D > 0)
		{
			y++;
			D -= 2*dx;
		}
		D += 2*dy;
	}
	vram[point(x1, y1)] = 0x001F;
	
}
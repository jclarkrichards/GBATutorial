#define REG_DISP		*(volatile unsigned short*)0x04000000
#define REG_KEYINPUT	*(volatile unsigned short*)0x04000130
#define REG_VCOUNT		*(volatile unsigned short*)0x04000006
#define VRAM			((volatile unsigned short*)0x06000000)

#define KEY_RIGHT		0x0010
#define KEY_LEFT		0x0020
#define KEY_UP			0x0040
#define KEY_DOWN		0x0080
#define KEYMASK			0x03FF

int keyPressed(unsigned short KEY);
void updatePosition(volatile unsigned short *vram, unsigned short x, unsigned short y, unsigned short color);

int main()
{
	REG_DISP = 0x0403;
	*(unsigned short*)0x06000000 = 0x001F;
	//unsigned short *vram = (unsigned short*)0x06000000;
	volatile unsigned short *vram = VRAM;
	
	unsigned short x = 0;
	unsigned short y = 0;
	updatePosition(vram, x, y, 0x001F);
	
	while(1)
	{
		while(REG_VCOUNT >= 160);
		while(REG_VCOUNT < 160);
		
		if(keyPressed(KEY_RIGHT))
		{
			x++;									
		}
		else if(keyPressed(KEY_LEFT))
		{
			x--;					
		}
		
		if(keyPressed(KEY_DOWN))
		{
			y++;
		}
		else if(keyPressed(KEY_UP))
		{
			y--;
		}
		
		updatePosition(vram, x, y, 0x001F);
	}
	return 0;
}

int keyPressed(unsigned short KEY)
{
	return (~REG_KEYINPUT & KEYMASK) & KEY;
}

void updatePosition(volatile unsigned short *vram, unsigned short x, unsigned short y, unsigned short color)
{
	vram[x+y*240] = color;
}
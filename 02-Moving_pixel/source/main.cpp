#define u16			unsigned short
#define vu16 		volatile u16

#define MEM_IO 		0x04000000
#define MEM_VRAM 	0x06000000


#define REG_DISP	*(vu16*)MEM_IO
#define REG_KEY		*(vu16*)(MEM_IO + 0x0130)
#define REG_VCOUNT	*(vu16*)(MEM_IO + 0x0006)

#define VRAM16		(vu16*)MEM_VRAM

#define KEYMASK		0x03FF
#define RIGHTMASK	0x0010
#define LEFTMASK	0x0020
#define UPMASK		0x0040
#define DOWNMASK	0x0080

const int WIDTH = 240;
const int HEIGHT = 160;

int main()
{
	REG_DISP = 0x0403;
	vu16 *vram = VRAM16;
	
	//*VRAM16 = 0x001F;
	int x = 0;
	int y = 0;
	
	//vram[x+y*WIDTH] = 0x001F;
	
	while(1)
	{
		while(REG_VCOUNT >= HEIGHT);
		while(REG_VCOUNT < HEIGHT);
		
		if(~REG_KEY & UPMASK) 
		{
			y--;
			//vram[x+y*WIDTH] = 0x001F;
		}
		else if(~REG_KEY & DOWNMASK) 
		{
			y++;
			//vram[x+y*WIDTH] = 0x001F;
		}
		
		if(~REG_KEY & LEFTMASK) 
		{
			x--;
			//vram[x+y*WIDTH] = 0x001F;
		}
		else if(~REG_KEY & RIGHTMASK) 
		{
			x++;
			//vram[x+y*WIDTH] = 0x001F;
		}
		vram[x+y*WIDTH] = 0x001F;
	}
	return 0;
}
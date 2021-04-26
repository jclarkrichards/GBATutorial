#define REG_DISP		*(volatile unsigned short*)0x04000000
#define REG_KEYINPUT	*(volatile unsigned short*)0x04000130

int main()
{
	REG_DISP = 0x0403;
	*(unsigned short*)0x06000000 = 0x001F;
	//unsigned short *vram = (unsigned short*)0x06000000;
	
	
	while(1);
	return 0;
}
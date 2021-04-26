int main()
{
	*(volatile unsigned short*)0x04000000 = 0x0403;
	*(unsigned short*)0x06000000 = 0x001F;
	
	//while(1);
	return 0;
}
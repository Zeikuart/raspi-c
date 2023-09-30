#include "BCM2837.h"

// Typedef
typedef unsigned int uint;

// Write Address
void write32(void *dst, uint val) {
	uint* dst_u = (uint*)dst;

	*dst_u = val;

	return;
}

// Read Address
uint read32(void *src)
{
	uint* src_u = (uint*)src;

	return *src_u;
}


void main(void)
{   
    // Read value of Pin 21
	uint gpfsel2 = read32(BCM2837_GPFSEL2);

    // Pin 21 -> Output
	gpfsel2 |= (1<<3); 
    
	write32(BCM2837_GPFSEL2, gpfsel2);

	int i = 0;

	while(1)
	{
		// Pin 21 -> Turn ON
		write32(BCM2837_GPSET0, 1<<21);

		// Delay
		i = 0;
		while (i < 0x800000)
		{
			i++;
		}

		// Pin 21 -> Turn OFF
		write32(BCM2837_GPCLR0, 1<<21);

		// Delay
		i = 0;
		while (i < 0x800000)
		{
			i++;
		}

	}
}
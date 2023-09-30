#include "BCM2837.h"
#include <stdint.h>


// Write Address
void write32(uint32_t *dst, uint32_t val) {
	uint32_t* dst_u = (uint32_t*)dst;

	*dst_u = val;

	return;
}

// Read Address
uint32_t read32(uint32_t *src)
{
	uint32_t* src_u = (uint32_t*)src;

	return *src_u;
}


void main(void)
{   
    // Read value of Pin 21
	uint32_t gpfsel2 = read32((uint32_t *)BCM2837_GPFSEL2);

    // Pin 21 -> Output
	gpfsel2 |= (1<<3); 

	write32((uint32_t *)BCM2837_GPFSEL2, gpfsel2);

	int i = 0;

	while(1)
	{
		// Pin 21 -> Turn ON
		write32((uint32_t *)BCM2837_GPSET0, 1<<21);

		// Delay
		i = 0;
		while (i < 0x800000)
		{
			i++;
		}

		// Pin 21 -> Turn OFF
		write32((uint32_t *)BCM2837_GPCLR0, 1<<21);

		// Delay
		i = 0;
		while (i < 0x800000)
		{
			i++;
		}

	}
}
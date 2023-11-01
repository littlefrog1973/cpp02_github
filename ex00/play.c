#include <stdio.h>
#include <stdint.h>

int main() {
	float f = 0.0;
	uint32_t *f_bits;

	f_bits = (uint32_t *)&f;
	printf("Float bit pattern: 0x%08x\n", *f_bits);
	printf("Float f = %e\n", f);
	return 0;
}

#include <stdio.h>
#include <stdint.h>

typedef unsigned char byte;
typedef unsigned int uint;

void def_nothing_important(void)
{
    byte local_26[22];
    uint local_10;

    local_26[0] = 0x62;
    local_26[1] = 0x61;
    local_26[2] = 0x62;
    local_26[3] = 0x7e;
    local_26[4] = 0x55;
    local_26[5] = 0x34;
    local_26[6] = 0x40;
    local_26[7] = 0x5a;
    local_26[8] = 0x36;
    local_26[9] = 0x7d;
    local_26[10] = 0x75;
    local_26[11] = 0x69;
    local_26[12] = 0x35;
    local_26[13] = 0x34;
    local_26[14] = 0x71;
    local_26[15] = 0x60;
    local_26[16] = 0x61;
    local_26[17] = 0x5a;
    local_26[18] = 0x69;
    local_26[19] = 0x6a;
    local_26[20] = 0x69;
    local_26[21] = 0x78;

    for (local_10 = 0; local_10 < 22; local_10++) {
        local_26[local_10] ^= 5;
    }

    printf("\nYou found the hidden treasure: %s\n", local_26);
}

int main(void)
{
    def_nothing_important();
    return 0;
}

#include "pic.h"
#include "../lib/type.h"
#include "io.h"

/*
 * when we start a initialization a PIC wait a sequence of command in DATA for populate it's registers
 */
void init_pic() {
    out8(MASTER_PIC_COMMAND, 0x11);
    out8(SLAVE_PIC_COMMAND, 0x11);
    out8(MASTER_PIC_DATA, 0x20);
    out8(SLAVE_PIC_DATA, 0x28);
    out8(MASTER_PIC_DATA, 0x04);
    out8(SLAVE_PIC_DATA, 0x02);
    out8(MASTER_PIC_DATA, 0x1);
    out8(SLAVE_PIC_DATA, 0x1);
    out8(MASTER_PIC_DATA, 0x00);
    out8(SLAVE_PIC_DATA, 0x00);
}

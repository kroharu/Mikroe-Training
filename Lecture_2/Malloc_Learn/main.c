/**
 * @file main.c
 * @brief Main function for Malloc_Learn application.
 */

#include <stdint.h>


static volatile uint16_t *value_stored_in_ram;
// NOTE The difference is 'const' memory specificator.
static volatile const uint16_t *value_stored_in_rom;

void main(void)
{
    // A simple 'if' to tell the compiler not to optomize the variables out.
    if (value_stored_in_ram);
    if (value_stored_in_rom);
    
    while (1)
    {
        // TODO Add value_stored_in_ram and value_stored_in_rom
        // to watch list and see the address difference.
        // Assembler 'No operation' instruction.
        asm nop;
    }
}

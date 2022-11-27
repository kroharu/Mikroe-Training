/**
 * @file main.c
 * @brief Main function for Keywords application.
 */

// TODO First, declare the variables.
static unsigned char test_var; // One byte.
static signed char test_var2;  // One byte.
static unsigned int test_var3; // Two bytes.
static signed char test_var4;  // Two bytes.

void main(void)
{
    // TODO Add global variables to watch window.
    test_var = 10;     
    // This is OK, as max is 255
    test_var = 1010;   
    // This will set value to 242
    // Roll-over has happened.
    // 256+256+256 = 768.
    // 1010 - 768 = 242.
    
    test_var2 = 50;
    // Value will be 50.
    test_var2 = -50;
    // Value will be -50.
    test_var2 = -1050;
    // Value will be 14.
    // 8 * 128 = 1024.
    // 1024 - 1010 = 14.
    
    test_var3 = 10;
    // This should be 10.
    test_var3 = 1010;
    // This should be 1010.
    
    test_var4 = 50;
    // This should be 50.
    test_var4 = -1050;
    // This should be -1050.
    
    while (1) {
        // Assembler 'No operation' instruction.
        asm nop;
    }
}

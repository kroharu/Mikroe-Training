/**
 * @file main.c
 * @brief Main function for Statements application.
 */

signed char a = 3;
signed char b = 2;
signed char c = 0;

signed char ft_sum(void)
{
    return (a + b);
}

void main(void)
{
    // TODO Add global variables to watch window.
    
    while (1) {
        if (ft_sum() == 5)  // a + b
            c++;    // ++ is known as post-increment
        else
            c--;    // -- is known as post-decrement
        
        switch (a)
        {
            case (3):
                a--;
                break;  // PAY ATTENTION TO THIS!
                
            default:
                a++;
                break;
        }
    }
}

#line 1 "C:/Users/footb/Documents/MIKROE/Week_1/Lecture_2/Statements/main.c"
#line 6 "C:/Users/footb/Documents/MIKROE/Week_1/Lecture_2/Statements/main.c"
signed char a = 3;
signed char b = 2;
signed char c = 0;

signed char ft_sum(void)
{
    return (a + b);
}

void main(void)
{


    while (1) {
        if (ft_sum() == 5)
            c++;
        else
            c--;

        switch (a)
        {
            case (3):
                a--;
                break;

            default:
                a++;
                break;
        }
    }
}

#include <unistd.h>

void ft_putchar(char e);

int main(void){
    ft_putchar('a'+1);
}
void ft_putchar(char e)
{
    write(1, &e, 1);
}

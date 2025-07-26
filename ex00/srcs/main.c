#include "ft.h"
#include <stdio.h>

int main()
{
    t_dict *numbers = format_all("numbers.dict");
    char *test = convert_nb(numbers, 5153);
    printf("%s", test);
}
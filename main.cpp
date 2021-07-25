#include "libraries.h"
int main()
{
    int opc = 0;
    FILE *arch = NULL;
    do
    {
        principalMenu(arch);
        printf("Elija la opcion que desea->");
        scanf("%d", &opc);
    } while (opc != 1);
    return 0;
}

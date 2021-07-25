void registroz()
{
    variable1.numero = 12;
    datosC *nuevo;
    nuevo = (datosC *)malloc(sizeof(datosC));
    if (nuevo == NULL)
    {
        printf("La memoria esta llena");
    }
    else
    {
        printf("Ingrese el contacto nuevo: ");
        scanf("%s", nuevo->nombre);
        fflush(stdin);
        printf("Ingrese el nuevo numero: ");
        scanf("%d", &nuevo->numero);
        fflush(stdin);
        if (primero == NULL)
        {
            primero = nuevo;
            primero->sig = NULL;
            primero->ant = NULL;
            ultimo = nuevo;
        }
        else
        {
            ultimo->sig = nuevo;
            nuevo->sig = NULL;
            nuevo->ant = ultimo;
            ultimo = nuevo;
        }
    }
}
void imprimirLista()
{
    struct datosContacto *actual;
    actual = (struct datosContacto *)malloc(sizeof(struct datosContacto));
    actual = primero;
    if (primero != NULL)
    {
        while (actual != NULL)
        {
            printf("%s\t", actual->nombre);
            printf("%d\n", actual->numero);
            actual = actual->sig;
        }
    }
    else
    {
        printf("La lista se encuentra vacia");
    }
    free(actual);
}
void guardarArchivo(FILE *arch)
{
    if (!(arch = fopen("contactos.xls", "a+")))
    {
        printf("Hubo un error al abrir el archivo");
        exit(1);
    }
    struct datosContacto *actual;
    actual = (struct datosContacto *)malloc(sizeof(struct datosContacto));
    actual = primero;
    if (primero != NULL)
    {
        while (actual != NULL)
        {
            fprintf(arch, "%s\t", actual->nombre);
            fprintf(arch, "%d\n", actual->numero);
            actual = actual->sig;
        }
    }
    else
    {
        printf("La lista se encuentra vacia");
    }
    free(actual);
    fclose(arch);
}
void inicializarArchivo(FILE *arch)
{
    if (!(arch = fopen("contactos.xls", "r")))
    {
        printf("Hubo un error al abrir el archivo");
        exit(1);
    }

    while (!feof(arch))
    {
        struct datosContacto *actual;
        actual = (struct datosContacto *)malloc(sizeof(struct datosContacto));
        if (actual == NULL)
        {
            printf("No hay espacio suficiente");
            exit(1);
        }
        else
        {
            fscanf(arch, "%s\t", actual->nombre);
            fflush(stdin);
            fscanf(arch, "%d\n", &actual->numero);
            fflush(stdin);
            printf("%s\t", actual->nombre);
            printf("%d\n", actual->numero);
            if (primero == NULL)
            {
                primero = actual;
                primero->sig = NULL;
                primero->ant = NULL;
                ultimo = actual;
            }
            else
            {
                ultimo->sig = actual;
                actual->sig = NULL;
                actual->ant = ultimo;
                ultimo = actual;
            }
        }
    }
    fclose(arch);
}
void principalMenu(FILE *arch)
{
    int opcion = 0;
    inicializarArchivo(arch);
    system("cls");
    printf("Ingresa la opcion que desea: ");
    printf("\n1.-Registar contacto nuevo\n2.-Ver mis contactos\n3.-Salir\n");
    scanf("%d", &opcion);
    switch (opcion)
    {
    case 1:
        registro();
        break;
    case 2:
        imprimirLista();
        break;
    case 3:
        guardarArchivo(arch);
        exit(0);
        break;
    default:
        break;
    }
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dos.h>
#include <conio.h>
#include <ctype.h>

#define TAMANO 100
#define NUMERO_DE_CATEGORIAS 9
/*Variables globales*/
char codigos_agregados[TAMANO],
nombre_producto_agregados[TAMANO],
cantidad_de_producto_agregados[TAMANO],
precio_del_producto_agregados[TAMANO];

/*Cantidad de categorias*/
char categoria_producto[NUMERO_DE_CATEGORIAS][50] = {{"Productos de limpieza"},
{"Muebles y Decoracion del Hogar"},
{"Electrodomesticos"},
{"Tecnologia"},
{"Accesorios"},
{"Instrumentos musicales"},
{"Juguetes"},
{"Alimentos"},
{"Arte y manualidades"}};

/*andrea
Precio y categoria */

void mayuscula(char *palabra);
void mayuscula(char *palabra)
{
	size_t len;
	int iterable;
	len = strlen(palabra);
	for (iterable = 0; iterable < len; iterable++)
	{
		palabra[iterable] = toupper(palabra[iterable]);
	}
    return;
}

void input(char *palabra, size_t tamano);
void input(char *palabra, size_t tamano)
{
	/*El uso de sizeof(palabra) no proporcionará el 
	tamaño correcto del búfer al que apunta palabra.
	En su lugar, sizeof(palabra) dará el tamaño del puntero char*,
	que generalmente será 4 o 8 bytes en sistemas de 32 o 64 bits,
	respectivamente.*/
    fgets(palabra,tamano,stdin);
    return;
}

void eliminar_enter(char *palabra);
void eliminar_enter(char *palabra)
{   
    size_t len;
    len = strlen(palabra);
    if (len > 0 && palabra[len - 1] == '\n')
    {
       palabra[len - 1] = '\0'; 
    }
    return;
}

void borrar(void);
void borrar()
{
	system("cls");
    return;
}

void salir(void);
void salir()
{
	borrar();
	gotoxy(28,14);
	textcolor(GREEN);
	cprintf("El programa ha finalizado");
	gotoxy(31,15);
	textcolor(GREEN);
	cprintf("Gracias por usarlo");
	getch();
	exit(0);
}

void ver_si_hay_numero_y_signos(char *palabra);
void ver_si_hay_numero_y_signos(char *palabra)
{
    short int iterable,iterable_two;
    char numero[] = "0123456789!\"#$%&'()*+,-./:;<=>?@[\]^_`{|}~ ";
    size_t len = strlen(palabra),len_two = strlen(numero);
    for (iterable=0;iterable<len;iterable++)
    {
        for (iterable_two=0;iterable_two<len_two;iterable_two++)
        {   
            if (strcmp(palabra[iterable],numero[iterable_two]) == 0)
            {
                strcpy(palabra,"caracter");
                return;
            }
            else
            {
                continue;
            }
        }   
    }
    return;
}

void ver_si_hay_caracter(char *palabra);
void ver_si_hay_caracter(char *palabra)
{
    short int iterable,iterable_two;
    char caracteres[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!\"#$%&'()*+,-./:;<=>?@[\]^_`{|}~ ";
    size_t len = strlen(palabra),len_two = strlen(caracteres);
    for (iterable=0;iterable<len;iterable++)
    {
        for (iterable_two=0;iterable_two<len_two;iterable_two++)
        {   
            if (strcmp(palabra[iterable],caracteres[iterable_two]) == 0)
            {
                strcpy(palabra,"caracter");
                return;
            }
            else
            {
                continue;
            }
        }   
    }
    return;
}

void ver_largo(char *palabra);
void ver_largo(char *palabra)
{
    size_t len = strlen(palabra);
    if (len >= 3)
    {
        return;
    }
    else
    {  
        strcpy(palabra,"codigo corto");
        return;
    }
}

void ver_si_hay_flotante(char *palabra);
void ver_si_hay_flotante(char *palabra)
{
    short int iterable, iterable_two, contador = 0;
    char caracteres[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!\"#$%&'()*+,-/:;<=>?@[\]^_`{|}~ ";
    size_t len = strlen(palabra), len_two = strlen(caracteres);

    for (iterable = 0; iterable < len; iterable++)
    {
        if (palabra[iterable] == '.')
        {
            contador++;
            if (contador >= 2)
            {
                strcpy(palabra, "caracter");
                return;
            }
            else
            {
                continue;
            }
        }
    }

    for (iterable = 0; iterable < len; iterable++)
    {
        for (iterable_two = 0; iterable_two < len_two; iterable_two++)
        {
            if (palabra[iterable] == caracteres[iterable_two])
            {
                strcpy(palabra, "caracter");
                return;
            }
            else
            {
                continue;
            }
        }
    }
}




/*funcion de agregar_producto*/
void categoria_del_producto();
void categoria_del_producto()
{
    /*
    (Estas categorías ya deben de estar definidas 
    en el programa mostrara dichas categorías y
    el usuario seleccionara la categoría a
    la que pertenece el producto).yguyguuy*/
    return;

}

/*funcion de agregar_producto*/
void precio_del_producto(char *codigo_producto,char *nombre_producto,short int *cantidad,char *verificar);
void precio_del_producto(char *codigo_producto,char *nombre_producto,short int *cantidad,char *verificar)
{
    /*(Validado para monto reales).*/
    char numero_flotante[20];
    short double precio;
    strcpy(verificar,"");
    while (1)
    {
        borrar();
        gotoxy(10,3);
        textcolor(WHITE);
        cprintf("Codigo del producto: ");
        textcolor(GREEN);
        cprintf("%s",codigo_producto);

        gotoxy(10,5);
        textcolor(WHITE);
        cprintf("Nombre del producto: ");
        textcolor(GREEN);
        cprintf("%s",nombre_producto);

        gotoxy(10,7);
        textcolor(WHITE);
        cprintf("Cantidad de ingreso del producto: ");
        textcolor(GREEN);
        cprintf("%d",cantidad);

        gotoxy(10,9);
        textcolor(WHITE);
        cprintf("Precio del producto: ");
        textcolor(GREEN);
        cprintf("                                                             ");

        gotoxy(2,25);
        textcolor(LIGHTGREEN);
        cprintf("Presione la letra q para regresar al menu");

        gotoxy(31,9);
        fflush(stdin);
        input(&numero_flotante,sizeof(numero_flotante));
        if (strcmp(numero_flotante,"\n") == 0)
        {
            gotoxy(15,13);
		    textcolor(GREEN);
		    cprintf("Cantidad no valida recuerde ingresar numeros flotantes");
            getch();
            continue;
        }
        eliminar_enter(&numero_flotante);
        mayuscula(&numero_flotante);
        if (strcmp(numero_flotante,"Q") == 0)
        {
            /* Nos salimos de la funcion*/
            strcpy(verificar,"salir");
            return;
        }
        ver_si_hay_flotante(&numero_flotante);
        if (strcmp(numero_flotante,"caracter") == 0)
        {
            /*significa que el usuario ingreso caracteres*/
            gotoxy(15,13);
		    textcolor(GREEN);
		    cprintf("Cantidad no valida recuerde ingresar numeros flotantes");
            getch();
            continue;
        }
        else
        {
            break;
        }
            
        
    }
    precio = atof(numero_flotante); /*Para convertir cadena a double*/
    borrar();
    printf("%lf",precio);
    getch();
    categoria_del_producto();
    if (strcmp(verificar,"salir") == 0)
    {
        precio_del_producto(codigo_producto,nombre_producto,cantidad,verificar);
    }
    return;
    
}


/*funcion de agregar_producto*/
void cantidad_de_ingreso_de_producto(char *codigo_producto,char *nombre_producto,char *verificar); 
void cantidad_de_ingreso_de_producto(char *codigo_producto,char *nombre_producto,char *verificar)
{
    /*(validado para enteros).*/
    char numero[20];
    short int cantidad;
    strcpy(verificar,"");
    while (1)
    {
        borrar();
        gotoxy(10,3);
        textcolor(WHITE);
        cprintf("Codigo del producto: ");
        textcolor(GREEN);
        cprintf("%s",codigo_producto);

        gotoxy(10,5);
        textcolor(WHITE);
        cprintf("Nombre del producto: ");
        textcolor(GREEN);
        cprintf("%s",nombre_producto);

        gotoxy(10,7);
        textcolor(WHITE);
        cprintf("Cantidad de ingreso del producto: ");
        textcolor(GREEN);
        cprintf("                                   ");

        gotoxy(10,9);
        textcolor(WHITE);
        cprintf("Precio del producto: ");
        textcolor(GREEN);
        cprintf("                                                             ");

        gotoxy(2,25);
        textcolor(LIGHTGREEN);
        cprintf("Presione la letra q para regresar al menu");

        gotoxy(44,7);
        fflush(stdin);
        input(&numero,sizeof(numero));
        if (strcmp(numero,"\n") == 0)
        {
            gotoxy(15,13);
		    textcolor(GREEN);
		    cprintf("Cantidad no valida recuerde ingresar numeros enteros");
            getch();
            continue;
        }
        eliminar_enter(&numero);
        mayuscula(&numero);
        if (strcmp(numero,"Q") == 0)
        {
            /* Nos salimos de la funcion*/
            strcpy(verificar,"salir");
            return;
        }
        ver_si_hay_caracter(&numero);
        if (strcmp(numero,"caracter") == 0)
        {
            /*significa que el usuario ingreso caracteres*/
            gotoxy(15,13);
		    textcolor(GREEN);
		    cprintf("Cantidad no valida recuerde ingresar numeros enteros");
            getch();
            continue;
        }
        else
        {
            break;
        }
            
        
    }
    cantidad = atoi(numero);
    precio_del_producto(codigo_producto,nombre_producto,cantidad,verificar);
    if (strcmp(verificar,"salir") == 0)
    {
        cantidad_de_ingreso_de_producto(codigo_producto,nombre_producto,verificar);
    }
    return;
}

/*funcion de agregar_producto*/
void nombre_del_producto(char *codigo_producto,char *verificar);
void nombre_del_producto(char *codigo_producto,char *verificar)
{
    char nombre_producto[20];
    strcpy(verificar,"");
    while (1)
    {
        borrar();
        gotoxy(10,3);
        textcolor(WHITE);
        cprintf("Codigo del producto: ");
        textcolor(GREEN);
        cprintf("%s",codigo_producto);

        gotoxy(10,5);
        textcolor(WHITE);
        cprintf("Nombre del producto: ");
        textcolor(GREEN);
        cprintf("                                                             ");

        gotoxy(10,7);
        textcolor(WHITE);
        cprintf("Cantidad de ingreso del producto: ");
        textcolor(GREEN);
        cprintf("                            ");

        gotoxy(10,9);
        textcolor(WHITE);
        cprintf("Precio del producto: ");
        textcolor(GREEN);
        cprintf("                                                             ");

        gotoxy(2,25);
        textcolor(LIGHTGREEN);
        cprintf("Presione la letra q para regresar al menu");

        gotoxy(31,5);
        fflush(stdin);
        input(&nombre_producto,sizeof(nombre_producto));
        if (strcmp(nombre_producto,"\n") == 0)
        {
            gotoxy(23,13);
		    textcolor(GREEN);
		    cprintf("Nombre del producto no valido");
            getch();
            continue;
        }
        eliminar_enter(&nombre_producto);
        mayuscula(&nombre_producto);
        if (strcmp(nombre_producto,"Q") == 0)
        {
            /* Nos salimos de la funcion*/
            strcpy(verificar,"salir");
            return;
        }
        ver_si_hay_numero_y_signos(&nombre_producto);
        if (strcmp(nombre_producto,"caracter") == 0)
        {
            /*significa que el usuario ingreso caracteres*/
            gotoxy(23,13);
		    textcolor(GREEN);
		    cprintf("Nombre del producto no valido");
            getch();
            continue;
        }
        ver_largo(&nombre_producto);
        if (strcmp(nombre_producto,"codigo corto") == 0)
        {
            gotoxy(19,13);
            textcolor(GREEN);
            cprintf("El nombre del producto es muy corto");
            getch();
            continue;
        }
        else
        {
            break;
        }
            
        
    }
    
    cantidad_de_ingreso_de_producto(codigo_producto,nombre_producto,verificar);
    if (strcmp(verificar,"salir") == 0)
    {
        nombre_del_producto(codigo_producto,verificar);
    }
    return;
}


/*funcion de agregar_producto*/
void codigo_del_producto(void);
void codigo_del_producto()
{
    char codigo_producto[20],verificar[5];
    while (1)
    {
        borrar();
        gotoxy(10,3);
        textcolor(WHITE);
        cprintf("Codigo del producto: ");
        textcolor(GREEN);
        cprintf("                                                             ");

        gotoxy(10,5);
        textcolor(WHITE);
        cprintf("Nombre del producto: ");
        textcolor(GREEN);
        cprintf("                                                             ");

        gotoxy(10,7);
        textcolor(WHITE);
        cprintf("Cantidad de ingreso del producto: ");
        textcolor(GREEN);
        cprintf("                            ");

        gotoxy(10,9);
        textcolor(WHITE);
        cprintf("Precio del producto: ");
        textcolor(GREEN);
        cprintf("                                                             ");

        gotoxy(2,25);
        textcolor(LIGHTGREEN);
        cprintf("Presione la letra q para regresar al menu");

        gotoxy(31,3);
        fflush(stdin);
        input(&codigo_producto,sizeof(codigo_producto));
        if (strcmp(codigo_producto,"\n") == 0)
        {
            gotoxy(15,13);
		    textcolor(GREEN);
		    cprintf("Ingrese correctamente el codigo del producto");
            getch();
            continue;
        }
        eliminar_enter(&codigo_producto);
        mayuscula(&codigo_producto);
        if (strcmp(codigo_producto,"Q") == 0)
        {
            /* Nos salimos de la funcion*/
            menu_principal();
        }
        ver_si_hay_caracter(&codigo_producto);
        if (strcmp(codigo_producto,"caracter") == 0)
        {
            /*significa que el usuario ingreso caracteres*/
            gotoxy(15,13);
		    textcolor(GREEN);
		    cprintf("Ingrese correctamente el codigo del producto");
            getch();
            continue;
        }
        ver_largo(&codigo_producto);
        if (strcmp(codigo_producto,"codigo corto") == 0)
        {
            gotoxy(19,13);
            textcolor(GREEN);
            cprintf("El codigo del producto es muy corto");
            getch();
            continue;
        }
        else
        {
            break;
        }
            
        
    }
    
    nombre_del_producto(codigo_producto,&verificar);
    if (strcmp(verificar,"salir") == 0)
    {
        codigo_del_producto();
    }
    return;
}

/*opcion 1*/
void agregar_producto(void);
void agregar_producto()
{
    codigo_del_producto();
    /*
    nombre_del_producto();
    cantidad_de_ingreso_de_producto();
    precio_del_producto();
    categoria_del_producto();
    */
   return;
}

/*opcion 2*/
void actualizar_producto(void);
void actualizar_producto()
{
    return;
}

/*opcion 3*/
void eliminar_producto(void);
void eliminar_producto()
{
    return;
}

/*opcion 4*/
void buscar_producto(void);
void buscar_producto()
{
    return;
}

/*opcion 5*/
void realizar_venta(void);
void realizar_venta()
{
    return;
}

menu_principal(void);
menu_principal()
{
    char opcion;
	borrar();
	while (1)
	{
		borrar();
		gotoxy(16,5);
		textcolor(WHITE);
		cprintf("1. ");
		textcolor(CYAN);
		cprintf("Agregar Producto");

		gotoxy(16,7);
		textcolor(WHITE);
		cprintf("2. ");
		textcolor(CYAN);
		cprintf("Actualizar Producto");

		gotoxy(16,9);
		textcolor(WHITE);
		cprintf("3. ");
		textcolor(CYAN);
		cprintf("Eliminar producto");

		gotoxy(16,11);
		textcolor(WHITE);
		cprintf("4. ");
		textcolor(CYAN);
		cprintf("Buscar Producto");

		gotoxy(16,13);
		textcolor(WHITE);
		cprintf("5. ");
		textcolor(CYAN);
		cprintf("Realizar venta");

        gotoxy(16,15);
		textcolor(WHITE);
		cprintf("6. ");
		textcolor(CYAN);
		cprintf("Salir");

		gotoxy(16,17);
		textcolor(CYAN);
		cprintf("Ingrese un numero segun la accion que desea realizar");
		
		gotoxy(16,19);
		textcolor(LIGHTGREEN);
		cprintf("> ");

		opcion = getch();

		textcolor(LIGHTGREEN);
		cprintf("%c",opcion);
		getch();
		
		
		switch (opcion)
		{
			case '1':
                agregar_producto();
				break;
			case '2':
				actualizar_producto();
				break;
			case '3':
				eliminar_producto();
				break;
			case '4':
				buscar_producto();
				break;
			case '5':
				realizar_venta();
                break;
            case '6':
                salir();
			default:
				gotoxy(13,21);
				textcolor(GREEN);
				cprintf("Error Recuerde ingresar un dato dentro del rango del 1 al 6");
				getch();
				break;
		}
	}
    return;
}

void main()
{
    char codigo_producto[] = "012345",nombre_producto[] = "pan",verificar[10];
    int cantidad = 10;
    borrar();
    /*Aqui va
    - el logo
    - la barra de carga 
    - y el login
    y despues el programa sigue al menu principal
    */
   
    /*precio_del_producto(codigo_producto,nombre_producto,cantidad,verificar);
    exit(0);*/
    menu_principal();
    getch();
    return;
}
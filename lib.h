#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dos.h>
#include <conio.h>
#include <ctype.h>

#define TAMANO 100
#define NUMERO_DE_CATEGORIAS 8
/*Variables globales*/
char codigos_agregados[TAMANO][50],
nombre_producto_agregados[TAMANO][50],
categoria_producto_ingresado[NUMERO_DE_CATEGORIAS][50];

/*recuerda vaciar los campos y ademas indice;*/
short int cantidad_de_producto_agregados[TAMANO],contador_de_indices=0,indice,productos_existente=0;
short double precio_del_producto_agregados[TAMANO]; 

/*Cantidad de categorias*/
char categoria_producto[NUMERO_DE_CATEGORIAS][50] = {{"Productos de limpieza"},
{"Muebles y Decoracion del Hogar"},
{"Electrodomesticos"},
{"Tecnologia"},
{"Accesorios"},
{"Instrumentos musicales"},
{"Juguetes"},
{"Alimentos"}};


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

void inicio(void);
void inicio()
{
    int iterable,barra,loading;
    loading = 0;
    borrar();
    for (iterable = 0; iterable <2080; iterable++)
    {
      if (iterable >= 0)
      {
         textcolor(BLACK);
         cprintf("%c", 219);
      }
    }
    for (iterable = 0; iterable <30; iterable++)
    {
        
      	gotoxy(25+iterable, 13);
        textcolor(LIGHTBLUE);
        cprintf("%c", 176);
      
    }
    for (iterable=0;iterable <30; iterable++)
    {
        loading ++;
        if (loading == 1)
        {
            gotoxy(34, 11);
            textcolor(LIGHTGREEN);
            cprintf("loading .", 219);
            delay(100);
        }
        else if (loading  == 2)
        {
            gotoxy(34, 11);
            textcolor(LIGHTGREEN);
            cprintf("loading ..", 219);
            delay(100);
        }
        else
        {
            gotoxy(34, 11);
            textcolor(LIGHTGREEN);
            cprintf("loading ...", 219);
            loading = 0;
            delay(100);
            if (loading == 0 && iterable < 28)
            {
                gotoxy(34, 11);
                textcolor(LIGHTGREEN);
                cprintf("loading", 219);
                delay(50);
                textcolor(BLACK);
                cprintf("    ", 219);
            }
            else
            {
                gotoxy(34, 11);
                textcolor(LIGHTGREEN);
                cprintf("loading ...", 219);
                loading = 0;
                delay(100);  
            }
            delay(50);
            
            
        }
        gotoxy(25+iterable, 13);
        textcolor(LIGHTGREEN);
        cprintf("%c", 219);
        barra = (int)((float)iterable / 29 * 100);
        gotoxy(38, 15);
        textcolor(GREEN);
        cprintf("%d %", barra);
        delay(200);
    }
    delay(1000);
    return;
}

void logo(void);
void logo()
{  
    int i;
	borrar();
	for (i = 0; i <2080; i++)
	{
		if (i > 498 && i < 506)
		{
			textcolor(BLUE);
			cprintf("%c", 219);
		}
		else if (i > 507 && i < 534)
		{
			gotoxy(0,0);
			textcolor(BLUE);
			cprintf("%c",219);

		}
		else if (i > 535 && i < 544)
		{
			gotoxy(0,0);
			textcolor(BLUE);
			cprintf("%c",219);

		}
		else if (i > 578 && i < 586)
		{
			textcolor(BLUE);
			cprintf("%c", 219);
		}
		
		else if (i > 587 && i < 614)
		{
			gotoxy(0,0);
			textcolor(BLUE);
			cprintf("%c",219);

		}
		else if (i > 615 && i < 624)
		{
			gotoxy(0,0);
			textcolor(BLUE);
			cprintf("%c",219);

		}
		else if (i > 658 && i < 666)
		{
			textcolor(BLUE);
			cprintf("%c", 219);
		}
		else if (i > 667 && i < 694)
		{
			gotoxy(0,0);
			textcolor(BLUE);
			cprintf("%c",219);

		}
		else if (i > 695 && i < 704)
		{
			gotoxy(0,0);
			textcolor(BLUE);
			cprintf("%c",219);

		}
		else if (i > 738 && i < 746)
		{
			textcolor(BLUE);
			cprintf("%c", 219);
		}
		else if (i > 747 && i < 774)
		{
			gotoxy(0,0);
			textcolor(BLUE);
			cprintf("%c",219);

		}
		else if (i > 775 && i < 784)
		{
			gotoxy(0,0);
			textcolor(BLUE);
			cprintf("%c",219);

		}

		else if (i > 818 && i < 826)
		{
			textcolor(BLUE);
			cprintf("%c", 219);
		}
		else if (i > 827 && i < 835)
		{
			gotoxy(0,0);
			textcolor(BLUE);
			cprintf("%c",219);

		}
		else if (i > 845 && i < 854)
		{
			gotoxy(0,0);
			textcolor(BLUE);
			cprintf("%c",219);

		}
		else if (i > 898 && i < 906)
		{	gotoxy(0,0);
			textcolor(BLUE);
			cprintf("%c",219);
		}
		else if (i > 907 && i < 915)
		{
			gotoxy(0,0);
			textcolor(BLUE);
			cprintf("%c",219);

		}
		else if (i > 916 && i < 924)
		{
			gotoxy(0,0);
			textcolor(BLUE);
			cprintf("%c",219);

		}
		else if (i > 925 && i < 934)
		{
			gotoxy(0,0);
			textcolor(BLUE);
			cprintf("%c",219);

		}
		else if (i > 935 && i < 944)
		{
			gotoxy(0,0);
			textcolor(BLUE);
			cprintf("%c",219);

		}
		
		else if(i > 978 && i < 986)
		{
			gotoxy(0,0);
			textcolor(BLUE);
			cprintf("%c",219);
		}
		else if (i > 987 && i < 995)
		{
			gotoxy(0,0);
			textcolor(BLUE);
			cprintf("%c",219);

		}
		else if (i > 996 && i < 1004)
		{
			gotoxy(0,0);
			textcolor(BLUE);
			cprintf("%c",219);

		}
		else if (i > 1005 && i < 1014)
		{
			gotoxy(0,0);
			textcolor(BLUE);
			cprintf("%c",219);

		}
		else if (i > 1015 && i < 1024)
		{
			gotoxy(0,0);
			textcolor(BLUE);
			cprintf("%c",219);

		}
		else if (i > 1058 && i < 1066)
		{
			gotoxy(0,0);
			textcolor(BLUE);
			cprintf("%c",219);
		}
		else if (i > 1067 && i < 1075)
		{
			gotoxy(0,0);
			textcolor(BLUE);
			cprintf("%c",219);

		}
		else if (i > 1076 && i < 1084)
		{
			gotoxy(0,0);
			textcolor(BLUE);
			cprintf("%c",219);

		}
		else if (i > 1085 && i < 1094)
		{
			gotoxy(0,0);
			textcolor(BLUE);
			cprintf("%c",219);

		}
		else if (i > 1095 && i < 1104)
		{
			gotoxy(0,0);
			textcolor(BLUE);
			cprintf("%c",219);

		}
		else if (i > 1138 && i < 1146)
		{
			gotoxy(0,0);
			textcolor(BLUE);
			cprintf("%c",219);

		}
		
		else if (i > 1156 && i < 1164)
		{
			gotoxy(0,0);
			textcolor(BLUE);
			cprintf("%c",219);

		}
		
		else if (i > 1165 && i < 1174)
		{
			gotoxy(0,0);
			textcolor(BLUE);
			cprintf("%c",219);

		}
		else if (i > 1175 && i < 1184)
		{
			gotoxy(0,0);
			textcolor(BLUE);
			cprintf("%c",219);

		}
		
		else if (i > 1218 && i < 1244)
		{
			gotoxy(0,0);
			textcolor(BLUE);
			cprintf("%c",219);
		}
		else if (i > 1245 && i < 1264)
		{
			gotoxy(0,0);
			textcolor(BLUE);
			cprintf("%c",219);

		}
		else if (i > 1298 && i < 1324)
		{
			gotoxy(0,0);
			textcolor(BLUE);
			cprintf("%c",219);

		}
		else if (i > 1325 && i < 1344)
		{
			gotoxy(0,0);
			textcolor(BLUE);
			cprintf("%c",219);

		}
		else if (i > 1378 && i < 1404)
		{
			gotoxy(0,0);
			textcolor(BLUE);
			cprintf("%c",219);
		}
		else if (i > 1405 && i < 1424)
		{
    		textcolor(BLUE);
    		cprintf("%c", 219);
		}
		
		else
		{
			textcolor(BLACK);
			cprintf("%c", 219);
		}
			
	}
	getch();
    borrar();
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
void categoria_del_producto(char *codigo_producto,char *nombre_producto,short int *cantidad,short double precio,char *verificar);
void categoria_del_producto(char *codigo_producto,char *nombre_producto,short int *cantidad,short double precio,char *verificar)
{
    /*
    (Estas categorías ya deben de estar definidas 
    en el programa mostrara dichas categorías y
    el usuario seleccionara la categoría a
    la que pertenece el producto).*/
    short int iterable;
    char categoria[5];
    strcpy(verificar,"");
    while (1)
    {
        borrar();

        gotoxy(19,2);
        textcolor(WHITE);
        cprintf("Elija la categorias para el producto \"%s\"",nombre_producto);
        textcolor(GREEN);

        gotoxy(10,4);
        textcolor(WHITE);
        cprintf("1. ");
        textcolor(CYAN);
        cprintf("\"%s\"",categoria_producto[0]);

        gotoxy(10,6);
        textcolor(WHITE);
        cprintf("2. ");
        textcolor(CYAN);
        cprintf("\"%s\"",categoria_producto[1]);

        gotoxy(10,8);
        textcolor(WHITE);
        cprintf("3. ");
        textcolor(CYAN);
        cprintf("\"%s\"",categoria_producto[2]);

        gotoxy(10,10);
        textcolor(WHITE);
        cprintf("4. ");
        textcolor(CYAN);
        cprintf("\"%s\"",categoria_producto[3]);

        gotoxy(10,12);
        textcolor(WHITE);
        cprintf("5. ");
        textcolor(CYAN);
        cprintf("\"%s\"",categoria_producto[4]);

        gotoxy(10,14);
        textcolor(WHITE);
        cprintf("6. ");
        textcolor(CYAN);
        cprintf("\"%s\"",categoria_producto[5]);

        gotoxy(10,16);
        textcolor(WHITE);
        cprintf("7. ");
        textcolor(CYAN);
        cprintf("\"%s\"",categoria_producto[6]);

        gotoxy(10,18);
        textcolor(WHITE);
        cprintf("8. ");
        textcolor(CYAN);
        cprintf("\"%s\"",categoria_producto[7]);

        gotoxy(2,25);
        textcolor(LIGHTGREEN);
        cprintf("Presione la letra q para regresar al menu");


        gotoxy(10,20);
        textcolor(CYAN);
        cprintf("Ingrese el numero de la categoria: ");
        gotoxy(45,20);
        textcolor(GREEN);
        cprintf("                                               ");
        fflush(stdin);
        gotoxy(45,20);
        input(&categoria,sizeof(categoria));
        if (strcmp(categoria,"\n") == 0)
        {
            gotoxy(15,22);
		    textcolor(GREEN);
		    cprintf("Ingrese el numero de la categoria correctamente");
            getch();
            continue;
        }
        eliminar_enter(&categoria);
        mayuscula(&categoria);
        if (strcmp(categoria,"Q") == 0)
        {
            /* Nos salimos de la funcion*/
            strcpy(verificar,"salir");
            return;
        }
        if (strcmp(categoria,"1") == 0)
        {
            break;
        }
        else if (strcmp(categoria,"2") == 0)
        {
            break;
        }
        else if (strcmp(categoria,"3") == 0)
        {
            break;
        }
        else if (strcmp(categoria,"4") == 0)
        {
            break;
        }
        else if (strcmp(categoria,"5") == 0)
        {
            break;
        }
        else if (strcmp(categoria,"6") == 0)
        {
            break;
        }
        else if (strcmp(categoria,"7") == 0)
        {
            break;
        }
        else if (strcmp(categoria,"8") == 0)
        {
            break;
        }
        else
        {
            gotoxy(15,22);
		    textcolor(GREEN);
		    cprintf("Ingrese el numero de la categoria correctamente");
            getch();
            continue;
        }
      
            
        
    }
    contador_de_indices++;
    /*Le restamos 1 para que siempre accedamos ala posicion que se necesita*/
    for (iterable=contador_de_indices-1;iterable<contador_de_indices;iterable++)
    {
        
        strcpy(codigos_agregados[iterable],codigo_producto);
        strcpy(nombre_producto_agregados[iterable],nombre_producto);
        cantidad_de_producto_agregados[iterable] = cantidad;
        precio_del_producto_agregados[iterable] = precio;
        if (strcmp(categoria,"1") == 0)
        {
            strcpy(categoria_producto_ingresado[iterable],categoria_producto[0]);
        }
        else if (strcmp(categoria,"2") == 0)
        {
            strcpy(categoria_producto_ingresado[iterable],categoria_producto[1]);
        }
        else if (strcmp(categoria,"3") == 0)
        {
            strcpy(categoria_producto_ingresado[iterable],categoria_producto[2]);
        }
        else if (strcmp(categoria,"4") == 0)
        {
            strcpy(categoria_producto_ingresado[iterable],categoria_producto[3]);
        }
        else if (strcmp(categoria,"5") == 0)
        {
            strcpy(categoria_producto_ingresado[iterable],categoria_producto[4]);
        }
        else if (strcmp(categoria,"6") == 0)
        {
            strcpy(categoria_producto_ingresado[iterable],categoria_producto[5]);
        }
        else if (strcmp(categoria,"7") == 0)
        {
            strcpy(categoria_producto_ingresado[iterable],categoria_producto[6]);
        }
        else if (strcmp(categoria,"8") == 0)
        {
            strcpy(categoria_producto_ingresado[iterable],categoria_producto[7]);
        }
        
    }
    
    /*borrar();
    printf("codigo %s\n",codigos_agregados[iterable-1]);
    printf("nombre %s\n",nombre_producto_agregados[iterable-1]);
    printf("cantidad %d\n",cantidad_de_producto_agregados[iterable-1]);
    printf("Precio %lf\n",precio_del_producto_agregados[iterable-1]);
    printf("categoria %s\n",categoria_producto_ingresado[iterable-1]);
    getch();*/
    productos_existente++;
    return;

}

/*funcion de agregar_producto*/
void precio_del_producto(char *codigo_producto,char *nombre_producto,short int *cantidad,char *verificar);
void precio_del_producto(char *codigo_producto,char *nombre_producto,short int *cantidad,char *verificar)
{
    /*(Validado para monto reales).*/
    char numero_flotante[50];
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
    if (precio >= 1)
    {
        categoria_del_producto(codigo_producto,nombre_producto,cantidad,precio,verificar);
    }
    else
    {
        gotoxy(15,13);
        textcolor(GREEN);
        cprintf("El numero que ingrese debe ser mayor que 0.0");
        getch();
        precio_del_producto(codigo_producto,nombre_producto,cantidad,verificar);    
    }
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
    char numero[50];
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
    if (cantidad <= 0)
    {
        gotoxy(15,13);
        textcolor(GREEN);
        cprintf("El numero que ingrese debe ser mayor que 0");
        getch();
        cantidad_de_ingreso_de_producto(codigo_producto,nombre_producto,verificar);
    }
    else
    {
        precio_del_producto(codigo_producto,nombre_producto,cantidad,verificar);
    }
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
    char nombre_producto[50];
    short int iterable;
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
            for (iterable=0;iterable<TAMANO;iterable++)
            {
                if (strcmp(nombre_producto,nombre_producto_agregados[iterable]) == 0)
                {
                    strcpy(nombre_producto,"repetido");
                    break;
                }
                else
                {
                    continue;
                }
            }
            if (strcmp(nombre_producto,"repetido") == 0)
            {
                gotoxy(11,13);
                textcolor(GREEN);
                cprintf("El nombre del producto que ingreso ya existe ingrese otro");
                getch();
                continue;
            }
            else
            {
                break;
            }
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
    char codigo_producto[50],verificar[5];
    short int iterable;
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
            /*Ver si el codigo se repite*/
            for (iterable=0;iterable<TAMANO;iterable++)
            {
                if (strcmp(codigo_producto,codigos_agregados[iterable]) == 0)
                {
                    strcpy(codigo_producto,"repetido");
                    break;
                }
                else
                {
                    continue;
                }
            }
            if (strcmp(codigo_producto,"repetido") == 0)
            {
                gotoxy(15,13);
                textcolor(GREEN);
                cprintf("El codigo que ingreso ya existe ingrese otro");
                getch();
                continue;
            }
            else
            {
                break;
            }
            
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

void ver_productos_inventario(void);
void ver_productos_inventario()
{
    /*ver los productos del inventario disponible*/
    short int iterable,contadora=0;
    size_t len;
    char opcion[5];
    while (1)
    {
        borrar();

        gotoxy(19,2);
        textcolor(WHITE);
        cprintf("Productos del invetario disponibles actualmente");
        textcolor(GREEN);

        
        for (iterable=0;iterable<contador_de_indices;iterable++)
        {
            len = strlen(nombre_producto_agregados[iterable]);
            if (len >= 3)
            {
                contadora++;
                gotoxy(10,4+contadora);
                textcolor(WHITE);
                cprintf("%d. ",contadora);
                textcolor(CYAN);
                cprintf("\"%s\"\n",nombre_producto_agregados[iterable]);
            }   
            else
            {
                continue;
            }
        }
        contadora=0;
       
        gotoxy(2,25);
        textcolor(LIGHTGREEN);
        cprintf("Presione la letra q para regresar al menu");


        gotoxy(10,23);
        textcolor(CYAN);
        cprintf("> ");
        gotoxy(12,23);
        textcolor(GREEN);
        cprintf("                                                                               ");
        fflush(stdin);
        gotoxy(12,23);
        input(&opcion,sizeof(opcion));
        if (strcmp(opcion,"\n") == 0)
        {
            gotoxy(15,22);
		    textcolor(GREEN);
		    cprintf("Presion le letra \"Q\" para salir");
            getch();
            continue;
        }
        eliminar_enter(&opcion);
        mayuscula(&opcion);
        if (strcmp(opcion,"Q") == 0)
        {
            /* Nos salimos de la funcion*/
            return;
        }
        else
        {
            continue;
        }
    }

}

/*Editamos los campos del producto*/
actualizar_producto_editar(void);
actualizar_producto_editar()
{
    char opcion[10];
    short int iterable,cantidad;
    short double precio;
    while (1)
    {
        borrar();

        gotoxy(24,2);
        textcolor(WHITE);
        cprintf("Actualizar campos del producto");

        gotoxy(10,4);
        textcolor(WHITE);
        cprintf("1. ");
        textcolor(GREEN);
        cprintf("Codigo del producto: %s",codigos_agregados[indice]);

        gotoxy(10,6);
        textcolor(WHITE);
        cprintf("2. ");
        textcolor(GREEN);
        cprintf("Nombre del producto: %s",nombre_producto_agregados[indice]);

        gotoxy(10,8);
        textcolor(WHITE);
        cprintf("3. ");
        textcolor(GREEN);
        cprintf("Cantidad de ingreso del producto: %d",cantidad_de_producto_agregados[indice]);

        gotoxy(10,10);
        textcolor(WHITE);
        cprintf("4. ");
        textcolor(GREEN);
        cprintf("Precio del producto: %.2lf",precio_del_producto_agregados[indice]);

        gotoxy(10,12);
        textcolor(WHITE);
        cprintf("5. ");
        textcolor(GREEN);
        cprintf("Categoria del producto: %s",categoria_producto_ingresado[indice]);

        textcolor(GREEN);
        gotoxy(2,25);
        textcolor(LIGHTGREEN);
        cprintf("Presione la letra q para regresar al menu");

        gotoxy(10,14);
        textcolor(CYAN);
        cprintf("Ingrese la opcion del producto a actualizar");
        gotoxy(12,15);
        textcolor(GREEN);
        cprintf("                                                                         ");
        fflush(stdin);
        gotoxy(10,15);
        textcolor(LIGHTGREEN);
        cprintf("> ");
        input(&opcion,sizeof(opcion));
        if (strcmp(opcion,"\n") == 0)
        {
            gotoxy(15,22);
            textcolor(GREEN);
            cprintf("Ingrese correctamente el opcion del producto que quiere actualizar");
            getch();
            continue;
        }
        eliminar_enter(&opcion);
        mayuscula(&opcion);
        if (strcmp(opcion,"Q") == 0)
        {
            /* Nos salimos de la funcion*/
            break;
        }
        if (strcmp(opcion,"1") == 0)
        {
            while (1)
            {
                gotoxy(10,4);
                textcolor(WHITE);
                cprintf("1. ");
                textcolor(GREEN);
                cprintf("Codigo del producto:                                              ");
                gotoxy(34,4);
                input(&opcion,sizeof(opcion));
                if (strcmp(opcion,"\n") == 0)
                {
                    gotoxy(15,22);
                    textcolor(GREEN);
                    cprintf("Ingrese correctamente el codigo del producto");
                    getch();
                    gotoxy(15,22);
                    cprintf("                                            ");
                    continue;
                }
                eliminar_enter(&opcion);
                mayuscula(&opcion);
                if (strcmp(opcion,"Q") == 0)
                {
                    /* Nos salimos del bucle*/
                    break;
                }
                ver_si_hay_caracter(&opcion);
                if (strcmp(opcion,"caracter") == 0)
                {
                    /*significa que el usuario ingreso caracteres*/
                    gotoxy(15,22);
                    textcolor(GREEN);
                    cprintf("Ingrese correctamente el codigo del producto");
                    getch();
                    gotoxy(15,22);
                    cprintf("                                            ");
                    continue;
                }
                ver_largo(&opcion);
                if (strcmp(opcion,"codigo corto") == 0)
                {
                    gotoxy(15,22);
                    textcolor(GREEN);
                    cprintf("El codigo del producto es muy corto");
                    getch();
                    gotoxy(15,22);
                    cprintf("                                   ");
                    continue;
                }
                else
                {
                    /*Ver si el codigo se repite*/
                    for (iterable=0;iterable<TAMANO;iterable++)
                    {
                        if (strcmp(opcion,codigos_agregados[iterable]) == 0)
                        {
                            strcpy(opcion,"repetido");
                            break;
                        }
                        else
                        {
                            continue;
                        }
                    }
                    if (strcmp(opcion,"repetido") == 0)
                    {
                        gotoxy(15,22);
                        textcolor(GREEN);
                        cprintf("El codigo que ingreso ya existe ingrese otro");
                        getch();
                        gotoxy(15,22);
                        cprintf("                                            ");
                        continue;
                    }
                    else
                    {
                        strcpy(codigos_agregados[indice],opcion);
                        break;
                    }
            
                }
                
            }
            continue;
            
        }
        else if (strcmp(opcion,"2") == 0)
        {
            while (1)
            {
                gotoxy(10,6);
                textcolor(WHITE);
                cprintf("2. ");
                textcolor(GREEN);
                cprintf("Nombre del producto:                                              ");

                gotoxy(34,6);
                input(&opcion,sizeof(opcion));
                if (strcmp(opcion,"\n") == 0)
                {
                    gotoxy(15,22);
                    textcolor(GREEN);
                    cprintf("Ingrese correctamente el nombre del producto");
                    getch();
                    gotoxy(15,22);
                    cprintf("                                            ");
                    continue;
                }
                eliminar_enter(&opcion);
                mayuscula(&opcion);
                if (strcmp(opcion,"Q") == 0)
                {
                    /* Nos salimos del bucle*/
                    break;
                }
                ver_si_hay_numero_y_signos(&opcion);
                if (strcmp(opcion,"caracter") == 0)
                {
                    /*significa que el usuario ingreso caracteres*/
                    gotoxy(15,22);
                    textcolor(GREEN);
                    cprintf("Ingrese correctamente el nombre del producto");
                    getch();
                    gotoxy(15,22);
                    cprintf("                                            ");
                    continue;
                }
                ver_largo(&opcion);
                if (strcmp(opcion,"codigo corto") == 0)
                {
                    gotoxy(15,22);
                    textcolor(GREEN);
                    cprintf("El nombre del producto es muy corto");
                    getch();
                    gotoxy(15,22);
                    cprintf("                                   ");
                    continue;
                }
                else
                {
                    /*Ver si el codigo se repite*/
                    for (iterable=0;iterable<TAMANO;iterable++)
                    {
                        if (strcmp(opcion,nombre_producto_agregados[iterable]) == 0)
                        {
                            strcpy(opcion,"repetido");
                            break;
                        }
                        else
                        {
                            continue;
                        }
                    }
                    if (strcmp(opcion,"repetido") == 0)
                    {
                        gotoxy(11,22);
                        textcolor(GREEN);
                        cprintf("El nombre del producto que ingreso ya existe ingrese otro");
                        getch();
                        gotoxy(11,22);
                        cprintf("                                                          ");
                        continue;
                    }
                    else
                    {
                        strcpy(nombre_producto_agregados[indice],opcion);
                        break;
                    }
            
                }
                
            }
            continue;
        }
        else if (strcmp(opcion,"3") == 0)
        {
            while (1)
            {

                gotoxy(10,8);
                textcolor(WHITE);
                cprintf("3. ");
                textcolor(GREEN);
                cprintf("Cantidad de ingreso del producto:                                              ");

                gotoxy(47,8);
                input(&opcion,sizeof(opcion));
                if (strcmp(opcion,"\n") == 0)
                {
                    gotoxy(15,22);
                    textcolor(GREEN);
                    cprintf("Cantidad no valida recuerde ingresar numeros enteros");
                    getch();
                    gotoxy(15,22);
                    cprintf("                                                      ");
                    continue;
                }
                eliminar_enter(&opcion);
                mayuscula(&opcion);
                if (strcmp(opcion,"Q") == 0)
                {
                    /* Nos salimos del bucle*/
                    break;
                }
                ver_si_hay_caracter(&opcion);
                if (strcmp(opcion,"caracter") == 0)
                {
                    /*significa que el usuario ingreso caracteres*/
                    gotoxy(15,22);
                    textcolor(GREEN);
                    cprintf("Cantidad no valida recuerde ingresar numeros enteros");
                    getch();
                    gotoxy(15,22);
                    cprintf("                                                     ");
                    continue;
                }
                cantidad = atoi(opcion);
                if (cantidad <= 0)
                {
                    gotoxy(15,22);
                    textcolor(GREEN);
                    cprintf("El numero que ingrese debe ser mayor que 0");
                    getch();
                    gotoxy(15,22);
                    cprintf("                                           ");
                    continue;
                }
                else
                {
                    cantidad_de_producto_agregados[indice] = cantidad;
                    break;
                }
                    
                
                
            }
            continue;
        }
        else if (strcmp(opcion,"4") == 0)
        {
            while (1)
            {

                gotoxy(10,10);
                textcolor(WHITE);
                cprintf("4. ");
                textcolor(GREEN);
                cprintf("Precio del producto:                                              ");

                /*$cantidad_de_producto_agregados*/
                gotoxy(34,10);
                input(&opcion,sizeof(opcion));
                if (strcmp(opcion,"\n") == 0)
                {
                    gotoxy(15,22);
                    textcolor(GREEN);
                    cprintf("Cantidad no valida recuerde ingresar numeros flotantes");
                    getch();
                    gotoxy(15,22);
                    cprintf("                                                         ");
                    continue;
                }
                eliminar_enter(&opcion);
                mayuscula(&opcion);
                if (strcmp(opcion,"Q") == 0)
                {
                    /* Nos salimos del bucle*/
                    break;
                }
                ver_si_hay_flotante(&opcion);
                if (strcmp(opcion,"caracter") == 0)
                {
                    /*significa que el usuario ingreso caracteres*/
                    gotoxy(15,22);
                    textcolor(GREEN);
                    cprintf("Cantidad no valida recuerde ingresar numeros flotantes");
                    getch();
                    gotoxy(15,22);
                    cprintf("                                                         ");
                    continue;
                }
                else
                {
                    precio = atof(opcion); /*Para convertir cadena a double*/
                    if (precio >= 1)
                    {
                        precio_del_producto_agregados[indice] = precio;
                        break;
                    }
                    else
                    {
                        gotoxy(15,22);
                        textcolor(GREEN);
                        cprintf("El numero que ingrese debe ser mayor que 0.0");
                        getch();
                        gotoxy(15,22);
                        cprintf("                                             ");
                        
                        continue;
                    }
                    
                }
                
                
            }
            continue;
        }
        else if (strcmp(opcion,"5") == 0)
        {
            while (1)
            {
                borrar();
                gotoxy(19,2);
                textcolor(WHITE);
                cprintf("Elija la categorias para el producto \"%s\"",nombre_producto_agregados[indice]);
                textcolor(GREEN);

                gotoxy(10,4);
                textcolor(WHITE);
                cprintf("1. ");
                textcolor(CYAN);
                cprintf("\"%s\"",categoria_producto[0]);

                gotoxy(10,6);
                textcolor(WHITE);
                cprintf("2. ");
                textcolor(CYAN);
                cprintf("\"%s\"",categoria_producto[1]);

                gotoxy(10,8);
                textcolor(WHITE);
                cprintf("3. ");
                textcolor(CYAN);
                cprintf("\"%s\"",categoria_producto[2]);

                gotoxy(10,10);
                textcolor(WHITE);
                cprintf("4. ");
                textcolor(CYAN);
                cprintf("\"%s\"",categoria_producto[3]);

                gotoxy(10,12);
                textcolor(WHITE);
                cprintf("5. ");
                textcolor(CYAN);
                cprintf("\"%s\"",categoria_producto[4]);

                gotoxy(10,14);
                textcolor(WHITE);
                cprintf("6. ");
                textcolor(CYAN);
                cprintf("\"%s\"",categoria_producto[5]);

                gotoxy(10,16);
                textcolor(WHITE);
                cprintf("7. ");
                textcolor(CYAN);
                cprintf("\"%s\"",categoria_producto[6]);

                gotoxy(10,18);
                textcolor(WHITE);
                cprintf("8. ");
                textcolor(CYAN);
                cprintf("\"%s\"",categoria_producto[7]);

                gotoxy(2,25);
                textcolor(LIGHTGREEN);
                cprintf("Presione la letra q para regresar al menu");


                gotoxy(10,20);
                textcolor(CYAN);
                cprintf("Ingrese el numero de la categoria: ");
                gotoxy(45,20);
                textcolor(GREEN);
                cprintf("                                               ");
                fflush(stdin);
                gotoxy(45,20);
                input(&opcion,sizeof(opcion));
                if (strcmp(opcion,"\n") == 0)
                {
                    gotoxy(15,22);
                    textcolor(GREEN);
                    cprintf("Ingrese el numero de la categoria correctamente");
                    getch();
                    continue;
                }
                eliminar_enter(&opcion);
                mayuscula(&opcion);
                if (strcmp(opcion,"Q") == 0)
                {
                    /* Nos salimos de la funcion*/
                    break;
                }
                if (strcmp(opcion,"1") == 0)
                {
                    strcpy(categoria_producto_ingresado[indice],categoria_producto[0]);
                    break;
                }
                else if (strcmp(opcion,"2") == 0)
                {
                    strcpy(categoria_producto_ingresado[indice],categoria_producto[1]);
                    break;
                }
                else if (strcmp(opcion,"3") == 0)
                {
                    strcpy(categoria_producto_ingresado[indice],categoria_producto[2]);
                    break;
                }
                else if (strcmp(opcion,"4") == 0)
                {
                    strcpy(categoria_producto_ingresado[indice],categoria_producto[3]);
                    break;
                }
                else if (strcmp(opcion,"5") == 0)
                {
                    strcpy(categoria_producto_ingresado[indice],categoria_producto[4]);
                    break;
                }
                else if (strcmp(opcion,"6") == 0)
                {
                    strcpy(categoria_producto_ingresado[indice],categoria_producto[5]);
                    break;
                }
                else if (strcmp(opcion,"7") == 0)
                {
                    strcpy(categoria_producto_ingresado[indice],categoria_producto[6]);
                    break;
                }
                else if (strcmp(opcion,"8") == 0)
                {
                    strcpy(categoria_producto_ingresado[indice],categoria_producto[7]);
                    break;
                }
                else
                {
                    gotoxy(15,22);
                    textcolor(GREEN);
                    cprintf("Ingrese el numero de la categoria correctamente");
                    getch();
                    continue;
                }   
                
            }
            continue;
        }
        else
        {
            gotoxy(15,22);
            textcolor(GREEN);
            cprintf("Ingrese correctamente el opcion del producto que quiere actualizar");
            getch();
            continue;
        }
        
    }
}

/*opcion 2*/
void actualizar_producto(void);
void actualizar_producto()
{
    short int iterable;
    char campo[50];
    if (productos_existente == 0)
    {
        gotoxy(22,21);
        textcolor(GREEN);
        cprintf("No hay productos en el inventario todavia");
        getch();
    }
    else
    {
        while (1)
        {
            borrar();

            gotoxy(24,2);
            textcolor(WHITE);
            cprintf("Actualizar campos del producto");

            gotoxy(10,8);
            textcolor(WHITE);
            cprintf("!. ");
            textcolor(GREEN);
            cprintf("Si no recuerda el nombre del producto ingrese \"1\"");
            gotoxy(13,9);
            cprintf("para ver todos los productos del inventario");

            textcolor(GREEN);
            gotoxy(2,25);
            textcolor(LIGHTGREEN);
            cprintf("Presione la letra q para regresar al menu");


            gotoxy(10,4);
            textcolor(CYAN);
            cprintf("Ingrese el nombre del producto a actualizar");
            gotoxy(10,5);
            textcolor(GREEN);
            cprintf("                                               ");
            fflush(stdin);
            gotoxy(10,5);
            textcolor(LIGHTGREEN);
            cprintf("> ");
            input(&campo,sizeof(campo));
            if (strcmp(campo,"\n") == 0)
            {
                gotoxy(15,22);
                textcolor(GREEN);
                cprintf("Ingrese correctamente el nombre del producto");
                getch();
                continue;
            }
            eliminar_enter(&campo);
            mayuscula(&campo);
            if (strcmp(campo,"Q") == 0)
            {
                /* Nos salimos de la funcion*/
                return;
            }
            if (strcmp(campo,"1") == 0)
            {
                ver_productos_inventario();
            }
            for (iterable=0;iterable<contador_de_indices;iterable++)
            {
                
                if (strcmp(campo,nombre_producto_agregados[iterable]) == 0)
                {
                    /*eliminamos los campos*/
                    indice = iterable;
                    actualizar_producto_editar();
                    break;
                }
                else
                {
                    continue;
                }
            }
        }
            
    }
    return;        
}


/*opcion 3*/
void eliminar_producto(void);
void eliminar_producto()
{
    short int iterable;
    char opcion[50];
    if (productos_existente == 0)
    {
        gotoxy(22,21);
        textcolor(GREEN);
        cprintf("No hay productos en el inventario todavia");
        getch();
    }
    else
    {
        while (1)
        {
            borrar();

            gotoxy(19,2);
            textcolor(WHITE);
            cprintf("Eliminar productos del inventario");

            gotoxy(10,8);
            textcolor(WHITE);
            cprintf("!. ");
            textcolor(GREEN);
            cprintf("Si no recuerda el nombre del producto ingrese \"1\"");
            gotoxy(13,9);
            cprintf("para ver todos los productos del inventario");

            textcolor(GREEN);
            gotoxy(2,25);
            textcolor(LIGHTGREEN);
            cprintf("Presione la letra q para regresar al menu");


            gotoxy(10,4);
            textcolor(CYAN);
            cprintf("Ingrese el nombre del producto a eliminar");
            gotoxy(10,5);
            textcolor(GREEN);
            cprintf("                                               ");
            if (productos_existente == 0)
            {
                gotoxy(19,21);
                textcolor(GREEN);
                cprintf("No hay productos disponibles en el inventario");
                getch();
                return;
            }
            fflush(stdin);
            gotoxy(10,5);
            textcolor(LIGHTGREEN);
            cprintf("> ");
            input(&opcion,sizeof(opcion));
            if (strcmp(opcion,"\n") == 0)
            {
                gotoxy(15,22);
                textcolor(GREEN);
                cprintf("Ingrese correctamente el nombre del producto");
                getch();
                continue;
            }
            eliminar_enter(&opcion);
            mayuscula(&opcion);
            if (strcmp(opcion,"Q") == 0)
            {
                /* Nos salimos de la funcion*/
                return;
            }
            if (strcmp(opcion,"1") == 0)
            {
                ver_productos_inventario();
                continue;
            }
    
            for (iterable=0;iterable<contador_de_indices;iterable++)
            {
                
                if (strcmp(opcion,nombre_producto_agregados[iterable]) == 0)
                {
                    /*eliminamos los campos*/
                    gotoxy(15,22);
                    textcolor(GREEN);
                    cprintf("Producto \"%s\" ha sido eliminado del inventario",nombre_producto_agregados[iterable]);
                    getch();
                    strcpy(codigos_agregados[iterable],"\0");
                    strcpy(nombre_producto_agregados[iterable],"\0");

                    strcpy(categoria_producto_ingresado[iterable],"\0");
                    cantidad_de_producto_agregados[iterable] = -1;
                    precio_del_producto_agregados[iterable] = -1;
                    productos_existente--;
                    break;
                }
                else
                {
                    continue;
                }
            }
            
            if (iterable == contador_de_indices) 
            {
                gotoxy(15, 22);
                textcolor(GREEN);
                cprintf("Ingrese correctamente el nombre del producto");
                getch();
                continue;
            }
        }
    }
    return;
}

void ver_caracteristicas_del_producto(void);
void ver_caracteristicas_del_producto()
{
    char opcion[5];
    while (1)
    {
        borrar();

        gotoxy(19,2);
        textcolor(WHITE);
        cprintf("Caracteristica del producto \"%s\"",nombre_producto_agregados[indice]);
        textcolor(GREEN);

        gotoxy(10,4);
        textcolor(WHITE);
        cprintf("1. ");
        textcolor(GREEN);
        cprintf("Codigo del producto: %s",codigos_agregados[indice]);

        gotoxy(10,6);
        textcolor(WHITE);
        cprintf("2. ");
        textcolor(GREEN);
        cprintf("Nombre del producto: %s",nombre_producto_agregados[indice]);

        gotoxy(10,8);
        textcolor(WHITE);
        cprintf("3. ");
        textcolor(GREEN);
        cprintf("Cantidad de ingreso del producto: %d",cantidad_de_producto_agregados[indice]);

        gotoxy(10,10);
        textcolor(WHITE);
        cprintf("4. ");
        textcolor(GREEN);
        cprintf("Precio del producto: %.2lf",precio_del_producto_agregados[indice]);

        gotoxy(10,12);
        textcolor(WHITE);
        cprintf("5. ");
        textcolor(GREEN);
        cprintf("Categoria del producto: %s",categoria_producto_ingresado[indice]);
        
       
        gotoxy(2,25);
        textcolor(LIGHTGREEN);
        cprintf("Presione la letra q para regresar al menu");


        gotoxy(10,23);
        textcolor(CYAN);
        cprintf("> ");
        gotoxy(12,23);
        textcolor(GREEN);
        cprintf("                                                                               ");
        fflush(stdin);
        gotoxy(12,23);
        input(&opcion,sizeof(opcion));
        if (strcmp(opcion,"\n") == 0)
        {
            gotoxy(15,22);
		    textcolor(GREEN);
		    cprintf("Presion le letra \"Q\" para salir");
            getch();
            continue;
        }
        eliminar_enter(&opcion);
        mayuscula(&opcion);
        if (strcmp(opcion,"Q") == 0)
        {
            /* Nos salimos de la funcion*/
            return;
        }
        else
        {
            continue;
        }
    }
 
}
/*opcion 4*/
void buscar_producto(void);
void buscar_producto()
{
    short int iterable;
    char opcion[50];
    if (productos_existente == 0)
    {
        gotoxy(22,21);
        textcolor(GREEN);
        cprintf("No hay productos en el inventario todavia");
        getch();
    }
    else
    {
        while (1)
        {
            borrar();

            gotoxy(19,2);
            textcolor(WHITE);
            cprintf("Buscar productos en el inventario");

            gotoxy(10,8);
            textcolor(WHITE);
            cprintf("!. ");
            textcolor(GREEN);
            cprintf("Si no recuerda el nombre del producto ingrese \"1\"");
            gotoxy(13,9);
            cprintf("para ver todos los productos del inventario");

            textcolor(GREEN);
            gotoxy(2,25);
            textcolor(LIGHTGREEN);
            cprintf("Presione la letra q para regresar al menu");


            gotoxy(10,4);
            textcolor(CYAN);
            cprintf("Ingrese el nombre del producto a buscar");
            gotoxy(10,5);
            textcolor(GREEN);
            cprintf("                                               ");
            fflush(stdin);
            gotoxy(10,5);
            textcolor(LIGHTGREEN);
            cprintf("> ");
            input(&opcion,sizeof(opcion));
            if (strcmp(opcion,"\n") == 0)
            {
                gotoxy(15,22);
                textcolor(GREEN);
                cprintf("Ingrese correctamente el nombre del producto");
                getch();
                continue;
            }
            eliminar_enter(&opcion);
            mayuscula(&opcion);
            if (strcmp(opcion,"Q") == 0)
            {
                /* Nos salimos de la funcion*/
                return;
            }
            if (strcmp(opcion,"1") == 0)
            {
                ver_productos_inventario();
                continue;
            }
    
            for (iterable=0;iterable<contador_de_indices;iterable++)
            {
                
                if (strcmp(opcion,nombre_producto_agregados[iterable]) == 0)
                {
                    /*eliminamos los campos*/
                    indice = iterable;
                    ver_caracteristicas_del_producto();
                    break;
                }
                else
                {
                    continue;
                }
            }
            
            if (iterable == contador_de_indices) 
            {
                gotoxy(15, 22);
                textcolor(GREEN);
                cprintf("Ingrese correctamente el nombre del producto");
                getch();
                continue;
            }
        }
    }
    return;
}

void realizar_venta_final(void);
void realizar_venta_final()
{
    char opcion[5];
    short int iterable,cantidad,cantidad_two;
    short double total,subtotal,iva;
    char nombre[50],opcion_salir[10];
    while (1)
    {
        borrar();

        gotoxy(19,2);
        textcolor(WHITE);
        cprintf("Caracteristica del producto \"%s\"",nombre_producto_agregados[indice]);
        textcolor(GREEN);

        gotoxy(10,4);
        textcolor(WHITE);
        cprintf("1. ");
        textcolor(GREEN);
        cprintf("Codigo del producto: %s",codigos_agregados[indice]);

        gotoxy(10,6);
        textcolor(WHITE);
        cprintf("2. ");
        textcolor(GREEN);
        cprintf("Nombre del producto: %s",nombre_producto_agregados[indice]);

        gotoxy(10,8);
        textcolor(WHITE);
        cprintf("3. ");
        textcolor(GREEN);
        cprintf("Unidadades disponibles: %d",cantidad_de_producto_agregados[indice]);

        gotoxy(10,10);
        textcolor(WHITE);
        cprintf("4. ");
        textcolor(GREEN);
        cprintf("Precio del producto: %.2lf",precio_del_producto_agregados[indice]);

        gotoxy(10,12);
        textcolor(WHITE);
        cprintf("5. ");
        textcolor(GREEN);
        cprintf("Categoria del producto: %s",categoria_producto_ingresado[indice]);
        
       
        gotoxy(2,25);
        textcolor(LIGHTGREEN);
        cprintf("Presione la letra q para regresar al menu");

        gotoxy(10,22);
        cprintf("Ingrese la cantidad de productos de \"%s\" que desea comprar",nombre_producto_agregados[indice]);

        textcolor(CYAN);
        gotoxy(10,23);
        textcolor(CYAN);
        cprintf("> ");
        gotoxy(12,23);
        textcolor(GREEN);
        cprintf("                                                                               ");
        fflush(stdin);
        gotoxy(12,23);
        input(&opcion,sizeof(opcion));
        if (strcmp(opcion,"\n") == 0)
        {
            gotoxy(11,17);
		    textcolor(CYAN);
		    cprintf("Presion le letra \"Q\" para salir");
            getch();
            continue;
        }
        eliminar_enter(&opcion);
        mayuscula(&opcion);
        if (strcmp(opcion,"Q") == 0)
        {
            /* Nos salimos de la funcion*/
            return;
        }
       ver_si_hay_caracter(&opcion);
        if (strcmp(opcion,"caracter") == 0)
        {
            /*significa que el usuario ingreso caracteres*/
            gotoxy(11,17);
		    textcolor(CYAN);
		    cprintf("Cantidad no valida recuerde ingresar numeros enteros");
            getch();
            continue;
        }
        else
        {
            cantidad = atoi(opcion);
            if (cantidad <= 0)
            {
                gotoxy(15,13);
                textcolor(GREEN);
                cprintf("El numero que ingrese debe ser mayor que 0");
                getch();
                continue;
            }
            else
            {
                cantidad_two = cantidad_de_producto_agregados[indice];
                cantidad_two = cantidad_two - cantidad;
                if (cantidad_two < 0)
                {
                    gotoxy(11,17);
                    textcolor(CYAN);
                    cprintf("La cantidad ingresada supera la cantidad de \"%s\" disponibles",nombre_producto_agregados[indice]);
                    getch();
                    continue;
                }
                else
                {
                    cantidad_de_producto_agregados[indice] = cantidad_two;
                    while (1)
                    {
                        textcolor(GREEN);
                        gotoxy(2,25);
                        textcolor(LIGHTGREEN);
                        cprintf("Presione la letra q para regresar al menu");

                        borrar();
                        gotoxy(10,2);
                        textcolor(CYAN);
                        cprintf("Para finalizar ingrese solo un nombre");
                        textcolor(GREEN);
                        gotoxy(10,3);
                        cprintf(">                                                                   ");
                        gotoxy(12,3);
                        fflush(stdin);
                        input(&nombre,sizeof(nombre));
                        if (strcmp(nombre,"\n") == 0)
                        {
                            gotoxy(10,13);
                            textcolor(GREEN);
                            cprintf("Nombre del no valido recuerde ingresar solo un nombre");
                            getch();
                            continue;
                        }
                        eliminar_enter(&nombre);
                        mayuscula(&nombre);
                        if (strcmp(nombre,"Q") == 0)
                        {
                            /* Nos salimos de la funcion*/
                            break;
                        }
                        ver_si_hay_numero_y_signos(&nombre);
                        if (strcmp(nombre,"caracter") == 0)
                        {
                            /*significa que el usuario ingreso caracteres*/
                            gotoxy(10,13);
                            textcolor(GREEN);
                            cprintf("Nombre del no valido recuerde ingresar solo un nombre");
                            getch();
                            continue;
                        }
                        ver_largo(&nombre);
                        if (strcmp(nombre,"codigo corto") == 0)
                        {
                            gotoxy(10,13);
                            textcolor(GREEN);
                            cprintf("El nombre es muy corto");
                            getch();
                            continue;
                        }
                        else
                        {
                            
                            break;
                            
                        }
                            
                    }
                    while (1)
                    {
                        borrar();
                        textcolor(GREEN);
                        gotoxy(2,25);
                        textcolor(LIGHTGREEN);
                        cprintf("Presione la letra q para regresar al menu");
                        gotoxy(10,2);
                        textcolor(WHITE);
                        cprintf("----------------------------------------------------------");
                        for (iterable=1;iterable<20;iterable++)
                        {
                            gotoxy(10,2+iterable);
                            textcolor(WHITE);
                            cprintf("|");
                        }
                        gotoxy(10,2+iterable);
                        cprintf("----------------------------------------------------------");

                        for (iterable=1;iterable<20;iterable++)
                        {
                            gotoxy(67,2+iterable);
                            textcolor(WHITE);
                            cprintf("|");
                        }

                        gotoxy(33,4);
                        textcolor(GREEN);
                        cprintf("Factura");

                        gotoxy(13,4);
                        textcolor(WHITE);
                        cprintf("1. ");
                        textcolor(GREEN);
                        cprintf("Codigo del producto: %s",codigos_agregados[indice]);

                        gotoxy(13,6);
                        textcolor(WHITE);
                        cprintf("2. ");
                        textcolor(GREEN);
                        cprintf("Nombre del producto: %s",nombre_producto_agregados[indice]);

                        gotoxy(13,8);
                        textcolor(WHITE);
                        cprintf("3. ");
                        textcolor(GREEN);
                        cprintf("Unidades compradas: %d",cantidad);

                        gotoxy(13,10);
                        textcolor(WHITE);
                        cprintf("4. ");
                        textcolor(GREEN);
                        cprintf("Precio del producto: %.2lf",precio_del_producto_agregados[indice]);

                        gotoxy(13,12);
                        textcolor(WHITE);
                        cprintf("5. ");
                        textcolor(GREEN);
                        cprintf("Categoria del producto: %s",categoria_producto_ingresado[indice]);

                        gotoxy(13,14);
                        textcolor(GREEN);
                        cprintf("Nombre del cliente: %s",nombre);
                        gotoxy(13,16);
                        textcolor(GREEN);
                       /*$d*/
                        subtotal = precio_del_producto_agregados[indice] * cantidad;
                        cprintf("Subtotal: %.2lf",subtotal);
                        gotoxy(13,18);
                        textcolor(GREEN);
                        iva = 0.15 * subtotal;
                        cprintf("IVA: %.2lf",iva);
                        gotoxy(13,20);
                        textcolor(GREEN);
                        total = subtotal + iva;
                        cprintf("Total: %.2lf",total);
                        gotoxy(51,21);
                        textcolor(GREEN);
                        cprintf("Fecha: 4/11/2023");

                        gotoxy(10,23);
                        textcolor(CYAN);
                        cprintf(">");
                        textcolor(GREEN);
                        cprintf("                                                                   ");
                        
                        gotoxy(12,23);
                        fflush(stdin);
                        input(&opcion_salir,sizeof(opcion_salir));
                        if (strcmp(nombre,"\n") == 0)
                        {
                            continue;
                        }
                        eliminar_enter(&opcion_salir);
                        mayuscula(&opcion_salir);
                        if (strcmp(opcion_salir,"Q") == 0)
                        {
                            /* Nos salimos de la funcion*/
                            menu_principal();
                        }
                        else
                        {
                            continue;
                        }
                        
                        
                        
                    }

                    continue;
                }
            }
            
        }
            
    }
    return;
 
}
/*opcion 5*/
void realizar_venta(void);
void realizar_venta()
{
    short int iterable;
    char opcion[50];
    if (productos_existente == 0)
    {
        gotoxy(22,21);
        textcolor(GREEN);
        cprintf("No hay productos en el inventario todavia");
        getch();
    }
    else
    {
        while (1)
        {
            borrar();

            gotoxy(11,2);
            textcolor(WHITE);
            cprintf("Buscar productos en el inventario para realizar venta");

            gotoxy(10,8);
            textcolor(WHITE);
            cprintf("!. ");
            textcolor(GREEN);
            cprintf("Si no recuerda el nombre del producto ingrese \"1\"");
            gotoxy(13,9);
            cprintf("para ver todos los productos del inventario");

            textcolor(GREEN);
            gotoxy(2,25);
            textcolor(LIGHTGREEN);
            cprintf("Presione la letra q para regresar al menu");


            gotoxy(10,4);
            textcolor(CYAN);
            cprintf("Ingrese el nombre del producto a comprar");
            gotoxy(10,5);
            textcolor(GREEN);
            cprintf("                                               ");
            fflush(stdin);
            gotoxy(10,5);
            textcolor(LIGHTGREEN);
            cprintf("> ");
            input(&opcion,sizeof(opcion));
            if (strcmp(opcion,"\n") == 0)
            {
                gotoxy(15,22);
                textcolor(GREEN);
                cprintf("Ingrese correctamente el nombre del producto");
                getch();
                continue;
            }
            eliminar_enter(&opcion);
            mayuscula(&opcion);
            if (strcmp(opcion,"Q") == 0)
            {
                /* Nos salimos de la funcion*/
                return;
            }
            if (strcmp(opcion,"1") == 0)
            {
                ver_productos_inventario();
                continue;
            }
    
            for (iterable=0;iterable<contador_de_indices;iterable++)
            {
                
                if (strcmp(opcion,nombre_producto_agregados[iterable]) == 0)
                {
                    indice = iterable;
                    if (cantidad_de_producto_agregados[indice] == 0)
                    {
                        gotoxy(15,22);
                        textcolor(GREEN);
                        cprintf("Las unidades del producto %s estan agotadas",nombre_producto_agregados[indice]);
                        getch();
                
                    }
                    else
                    {
                        realizar_venta_final();
                    }
                    
                    break;
                }
                else
                {
                    continue;
                }
            }
            
            if (iterable == contador_de_indices) 
            {
                gotoxy(15, 22);
                textcolor(GREEN);
                cprintf("Ingrese correctamente el nombre del producto");
                getch();
                continue;
            }
        }
    }
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

void factura(void);
void factura()
{
    short int iterable;
    char nombre[50],opcion_salir[10];
    
   
    
}
void credenciales(void);
void credenciales() 
{
	int i=0;
	char userName[10],passWord[4];
	cred: do {
		clrscr();
		i++;
		gotoxy(24,10);
		textcolor(YELLOW);
		cprintf("Intento %d de 3.",i);
		gotoxy(24,12);
		cprintf("Ingrese su usuario: ");
		gets(userName);
		gotoxy(24,14);
		cprintf("Ingrese su contrasena: ");
		gets(passWord);
	} while(i<3 && strcmp(strlwr(userName), "daniel") != 0 && strcmp(passWord, "123") != 0 && strcmp(strlwr(userName), "ernesto") != 0 && strcmp(passWord, "000") !=0);

	if(i>=4) 
    {
		clrscr();
		gotoxy(24,16);
        textcolor(LIGHTGREEN);
		cprintf("Intentos agotados, acceso denegado.");
		getch();
	}

	if (strcmp(strlwr(userName), "daniel") == 0 && strcmp(passWord, "123") == 0)
    {
        gotoxy(24,16);
        textcolor(LIGHTGREEN);
		cprintf("Credenciales correctas.");
		getch();
		menu_principal();
	} 
    else if (strcmp(strlwr(userName), "daniel") == 0 && strcmp(passWord, "000") == 0) 
    {
        gotoxy(24,16);
        textcolor(LIGHTGREEN);
		cprintf("Intentos agotados, acceso denegado.");
		getch();
		menu_principal();
	} 
    else if(i<3)
    {
        gotoxy(24,16);
        textcolor(LIGHTGREEN);
		cprintf("Credenciales incorrectas.");
        getch();
		goto cred;
	} 
    else 
    {
		clrscr();
		gotoxy(24,16);
		cprintf("Intentos agotados, acceso denegado.");
		getch();
	}
    return;
}

void principal(void);
void principal()
{
    borrar();
    /*Aqui va
    - el logo
    - la barra de carga 
    - y el login
    y despues el programa sigue al menu principal
    */
    logo();
    inicio();
    credenciales();   
    return;
}
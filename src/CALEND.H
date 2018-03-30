/**************************** LIBRERIA CALEND.H *******************************/
/**** Contiene todas las funciones necesarias para el módulo de Calendario ****/

void crear_calendario(Jornada *calend)
{
/*Declaracion de variables locales*/
/*j=jornadas, p=partidos, l=local, v=visitante*/
	int sw,aux,j,k=1,p,l,v;

/*Recorremos las jornadas hasta la mitad de partidos de liga*/
	for (j=1;j<=NPART;j++)
	{

		/*Recorremos los partidos hasta la mitad de equipos*/
		for (p=1;p<=NEQ/2;p++)
		{
			l=0;
			sw=0;
			do{

/*Se comprueba que no est‚ jugando en la jornada*/
/*Si la funcion devuelve un 1 el equipo local esta
		    disponible*/
				if (comprobar_local(j,p,l,calend)==1)
				{
					calend[j].part[p].id_local=l;
					calend[j].part[p].id_visitante=l;

					sw=1;
				}
				else
				{
					l++;
				}
				if (l>=NEQ) l=0;
			}while (sw!=1);

/*Se comprueba el visitante*/
/*Ahora hay que comprobar que el visitante no este jugando en esa
jornada y ademas que Local - Visitante no se hayan enfrentado antes.
Ademas evitar que juegue Local - Local*/

			v=0;
			sw=0;
			do{
				if (comprobar_visitante(j,p,v,calend[j].part[p].id_local,calend)==1)
				{
					calend[j].part[p].id_visitante=v;
					sw=1;
				}
				else

					v++;
				if (v>=NEQ) v=0;



			}while (sw!=1);


		}
	}

	for (j=NPART+1;j<=NPART*2;j++)
	{

		for (p=1;p<=NEQ/2;p++)
		{

			calend[j].part[p].id_visitante=calend[k].part[p].id_local;
			calend[j].part[p].id_local=calend[k].part[p].id_visitante;
		}

		k++;


	}


}
int comprobar_local(int jornada,int partido,int local, Jornada *calend)
{
/*El parametro jornada nos mostrara la jornada en la que estamos
  El parametro partido nos mostrara el partido en el que estamos
  dentro de dicha jornada
  El parametro local nos dice la id que tenemos que buscar en la tabla*/

	int i=1,sw=1;

	for (i=1;i<partido;i++)
	{

		if ((calend[jornada].part[i].id_local==local)||(calend[jornada].part[i].id_visitante==local))
		sw=0;
	}
	return sw;


}
int comprobar_visitante(int jornada,int partido,int visitante,int local, Jornada *calend)
{
/*El parametro jornada nos mostrara la jornada en la que estamos
/*El parametro partido nos mostrara el partido en el que estamos
  dentro de dicha jornada/*
  El parametro visitante nos dice la id que tenemos que buscar en la tabla
  El parametro local nos dice el equipo con el que vamos a jugar y comprueba
  que no se hayan enfrentado ya*/

	int i=1,sw=1,j;

	for (i=1;i<partido;i++)
	{
		if ((calend[jornada].part[i].id_local==visitante)||(calend[jornada].part[i].id_visitante==visitante))
		sw=0;
	}



	/*Si el sw es 0 ya no deberia buscar mas*/
	if (sw==1)
	{
		/*Si el equipo local es igual que el visitante se pone el
		sw a 0*/
		if (calend[jornada].part[partido].id_local==visitante)
			sw=0;
	}
	/*Si ya se han enfrentado entre ellos anteriormente se pone
	el sw a 0*/
	if (sw==1)
	{

		for (i=1;i<jornada;i++)
		{
			for (j=1;j<=NEQ/2;j++)
			{
				if((calend[i].part[j].id_local==local)&&(calend[i].part[j].id_visitante==visitante))
					sw=0;
				if((calend[i].part[j].id_local==visitante)&&(calend[i].part[j].id_visitante==local))
					sw=0;
			}
		}
	}


	return sw;



}
char mostrar_calendario(Jornada *calend,int jorn,Equipo *Equip,int selec)
{
	char volver;
	int i;
	/*Borra la pantalla*/
	clrscr();
	/*Cambia el modo de texto*/

	/*Elimina el cursor*/
	_setcursortype(_NOCURSOR);
	/*Situa el cursor en esa posicion e imprime el nombre de entrenador*/
	gotoxy(3,2);
	printf("ENTRENADOR: %s ",nomEntrenador);
	/*Situa el cursor en esa posicion e imprime el nombre del equipo*/
	gotoxy(3,3);
	printf("EQUIPO: %s ",Equip[selec].nombre);
	printf("\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\n");
	/*Situa el cursor dos lineas mas abajo e imprime el nombre de
	cada jugador, junto con sus caracteristicas*/

	printf("\n\n               Calendario / Resultados\n");
	    printf("               =======================\n");
	    textcolor(6);
	    cprintf("                      Jornada %d\r\n\r\n",jorn);
	    textcolor(7);
	printf("ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍËÍÍÍÍÍËÍÍÍÍËÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»\n");

		for (i=1;i<=NEQ/2;i++)
		{
			printf("º ");
			if (calend[jorn].part[i].id_local==selec)
				textcolor(3);
			cprintf("%-21s",Equip[calend[jorn].part[i].id_local].nombre);
			textcolor(7);
			printf("º ");
			if (jorn>=jorActual)
				printf("  - º  - º");
			else
				printf(" %3dº %3dº",calend[jorn].part[i].res_local,calend[jorn].part[i].res_visitante);
			if (calend[jorn].part[i].id_visitante==selec)
			textcolor(3);
			cprintf(" %-21s",Equip[calend[jorn].part[i].id_visitante].nombre);
			textcolor(7);
			printf("º\n");
		}
	printf("ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÊÍÍÍÍÍÊÍÍÍÍÊÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼\n");

	gotoxy(58,40);
	printf("ÚÄÄÄÄÄÄÄÄÄ¿");
	gotoxy(58,41);
	printf("³");
	textcolor(3);
	cprintf(" V");
	textcolor(7);
	printf("olver  ³");
	gotoxy(58,42);
	printf("ÀÄÄÄÄÄÄÄÄÄÙ\n\n");
	gotoxy(31,40);
	printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
	gotoxy(31,41);
	printf("³");
	textcolor(3);
	cprintf(" S");
	textcolor(7);
	printf("iguiente Jornada ³");
	gotoxy(31,42);
	printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n\n");
	gotoxy(5,40);
	printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
	gotoxy(5,41);
	printf("³");
	textcolor(3);
	cprintf(" A");
	textcolor(7);
	printf("nterior Jornada ³");
	gotoxy(5,42);
	printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n\n");
	printf("ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ\n\n");
	textcolor(2);
	cprintf("| A= Anterior Jornada | S= Siguiente Jornada | V= Volver |");
	textcolor(7);
	volver=getch();
	return volver;
}


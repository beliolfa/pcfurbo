/********************* LIBRERIA ALINEAC.H *****************************/
/**** Contiene todas las funciones necesarias para el m๓dulo de Alineacion ****/

/*Esta funcion ordena el equipo en Titulares y Reservas y los imprime en una tabla*/
char alineacion(Equipo *Equip,int selec,int sw)
{
	int i,media;
	char volver;
	/*Borra la pantalla*/
	clrscr();

	/*Elimina el cursor*/
	_setcursortype(_NOCURSOR);
	/*Situa el cursor en esa posicion e imprime el nombre de entrenador*/
	gotoxy(3,2);
	textcolor(2);
	cprintf("ENTRENADOR:");
	printf(" %s ",nomEntrenador);
	/*Situa el cursor en esa posicion e imprime el nombre del equipo*/
	gotoxy(3,3);
	cprintf("EQUIPO:");
	printf(" %s ",Equip[selec].nombre);
	printf("\nฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ\n\n");
	/*Situa el cursor dos lineas mas abajo e imprime el nombre de
	cada jugador, junto con sus caracteristicas*/

	printf("\n\n                EQUIPO TITULAR\n");
	printf("ษอออหออออออออออออออออออออออหอออออหออออหออออหออออป\n");
	printf("บ idบ       Jugador        บ DEM บ MO บ CA บ ME บ\n");
	printf("ฬอออฮออออออออออออออออออออออฮอออออฮออออฮออออฮออออน\n");
	Equip[selec].media=0;

	/*El primer jugador de la lista sera el portero.
	Por eso se compruba el 0 y el 12*/
		/*Si uno de los dos porteros es titular se imprime*/
		if (Equip[selec].jug[0].titular==1)
		{
			media=((Equip[selec].jug[0].moral+Equip[selec].jug[0].calidad)/2);
			Equip[selec].media+=media;
			printf("บ %2dบ %-21sบ%4s บ %2d บ %2d บ %2d บ\n",0,Equip[selec].jug[0].nombre,Equip[selec].jug[0].demarca,Equip[selec].jug[0].moral,Equip[selec].jug[0].calidad,media);

		}
		if (Equip[selec].jug[12].titular==1)
		{
			media=((Equip[selec].jug[12].moral+Equip[selec].jug[12].calidad)/2);
			Equip[selec].media+=media;
			printf("บ %2dบ %-21sบ%4s บ %2d บ %2d บ %2d บ\n",12,Equip[selec].jug[12].nombre,Equip[selec].jug[12].demarca,Equip[selec].jug[12].moral,Equip[selec].jug[12].calidad,media);

		}
		/*Recorremos los demas jugadores*/
		for (i=0;i<18 ;i++ )
		 {



			/*La media se calcula con la moral y la calidad de
			cada jugador*/
			media=((Equip[selec].jug[i].moral+Equip[selec].jug[i].calidad)/2);


			/*Aqui se comprueban los demas jugadores excluyendo a
			los porteros*/
			if ((Equip[selec].jug[i].titular==1)&&(i!=0)&&(i!=12))
			{
				Equip[selec].media+=media;
				printf("บ %2dบ %-21sบ%4s บ %2d บ %2d บ %2d บ\n",i,Equip[selec].jug[i].nombre,Equip[selec].jug[i].demarca,Equip[selec].jug[i].moral,Equip[selec].jug[i].calidad,media);
			}

		 }
	printf("ศอออสออออออออออออออออออออออสอออออสออออสออออสออออผ\n");
	Equip[selec].media/=11;
	printf("\n\nMedia de Equipo:%d",Equip[selec].media);
	/*Ahora se muestran los suplentes*/
	printf("\n\n                 SUPLENTES\n");
	printf("ษอออหออออออออออออออออออออออหอออออหออออหออออหออออป\n");
	printf("บ idบ       Jugador        บ DEM บ MO บ CA บ ME บ\n");
	printf("ฬอออฮออออออออออออออออออออออฮอออออฮออออฮออออฮออออน\n");

	/*Hacemos lo mismo que antes pero compribando si titular estแ a 0*/
	/*El primer jugador de la lista sera el portero.
	Por eso se compruba el 0 y el 12*/
	if (Equip[selec].jug[0].titular==0)
		{
			media=((Equip[selec].jug[0].moral+Equip[selec].jug[0].calidad)/2);
			printf("บ %2dบ %-21sบ%4s บ %2d บ %2d บ %2d บ\n",0,Equip[selec].jug[0].nombre,Equip[selec].jug[0].demarca,Equip[selec].jug[0].moral,Equip[selec].jug[0].calidad,media);

		}
		if (Equip[selec].jug[12].titular==0)
		{
			media=((Equip[selec].jug[12].moral+Equip[selec].jug[12].calidad)/2);
			printf("บ %2dบ %-21sบ%4s บ %2d บ %2d บ %2d บ\n",12,Equip[selec].jug[12].nombre,Equip[selec].jug[12].demarca,Equip[selec].jug[12].moral,Equip[selec].jug[12].calidad,media);

		}
	for (i=0;i<18 ;i++ )
		 {



			/*La media se calcula con la moral y la calidad de
			cada jugador*/
			media=((Equip[selec].jug[i].moral+Equip[selec].jug[i].calidad)/2);

			/*Aqui se comprueban los demas jugadores excluyendo a
			los porteros*/
			if ((Equip[selec].jug[i].titular==0)&&(i!=0)&&(i!=12))
			{
				printf("บ %2dบ %-21sบ%4s บ %2d บ %2d บ %2d บ\n",i,Equip[selec].jug[i].nombre,Equip[selec].jug[i].demarca,Equip[selec].jug[i].moral,Equip[selec].jug[i].calidad,media);

			}
		 }
		 /*Botones*/
	printf("ศอออสออออออออออออออออออออออสอออออสออออสออออสออออผ\n");
	gotoxy(60,10);
	printf("ฺฤฤฤฤฤฤฤฤฤฟ");
	gotoxy(60,11);
	printf("ณ");
	textcolor(3);
	cprintf(" C");
	textcolor(7);
	printf("ambios ณ");
	gotoxy(60,12);
	printf("ภฤฤฤฤฤฤฤฤฤู");
	gotoxy(60,40);
	printf("ฺฤฤฤฤฤฤฤฤฤฟ");
	gotoxy(60,41);
	printf("ณ");
	textcolor(3);
	cprintf(" V");
	textcolor(7);
	printf("olver  ณ");
	gotoxy(60,42);
	printf("ภฤฤฤฤฤฤฤฤฤู\n\n");
	printf("ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ\n\n");
	textcolor(2);
	cprintf("| C= Realizar cambios | V= Volver |");
	textcolor(7);
	if (sw==0)
	volver=getch();
	return volver;

}


/*Funcion para realizar cambios*/
void realizar_cambios(Equipo *Equip,int selec)
{
	int idt,ids,sw;
	char ch;

		clrscr();
		alineacion(Equip,selec,sw);
		/*Se sustituye a un titular por un suplente y se le cambian los atributos*/
	do{
		sw=1;
		fflush(stdin);
		gotoxy(60,14);
		printf("                  ");
		gotoxy(60,15);
		printf("               ");
		gotoxy(60,14);
		printf("ID del titular:");
		scanf("%d",&idt);
		/*Si el titular elegido es suplente se pone el sw a 0 para repetir*/
		if ((Equip[selec].jug[idt].titular==0)&&(idt<=17))
		{
			gotoxy(60,15);
			printf("%d es suplente",idt);
			sw=0;
			getch();
		}
		/*Si la id elegida es superior al numero de jugadores se pone el sw a 0 
		para repetir*/
		if (idt>17)
		{
			gotoxy(60,15);
			printf("%d no existe",idt);
			sw=0;
			getch();
		}

	}while((idt>17)||(sw==0));
	/*Hacemos lo mismo para la eleccion del suplente*/
	do{
		sw=1;
		fflush(stdin);
		gotoxy(60,16);
		printf("                  ");
		gotoxy(60,17);
		printf("               ");
		gotoxy(60,16);
		printf("ID del suplente:");
		scanf("%d",&ids);
		if ((Equip[selec].jug[ids].titular==1)&&(idt<=17))
		{
			gotoxy(60,17);
			printf("%d es titular",ids);
			sw=0;
			getch();
		}
		if (ids>17)
		{
			gotoxy(60,17);
			printf("%d no existe",ids);
			sw=0;
			getch();
		}

	}while((ids>17)||(sw==0));
	/*	Una vez que todo es correcto se realiza el cambio*/
	Equip[selec].jug[idt].titular=0;
	Equip[selec].jug[ids].titular=1;
	gotoxy(60,18);
	printf("Cambio Realizado");
	gotoxy(60,19);
	printf("Pulse una tecla..");
	getch();


}
/* Esto calcula las medias de los jugadores y equipo cada vez q se llame, por lo 
que es util para recalcular medias cada vez q se hace un cambio */
void calcular_medias(Equipo *Equip)
{
	int i, j, media=0;
	for (i=0;i<NEQ;i++)
	{
		for (j=0;j<18 ;j++ )
		 {



			/*La media se calcula con la moral y la calidad de
			cada jugador*/
			Equip[i].jug[j].media=((Equip[i].jug[j].moral+Equip[i].jug[j].calidad)/2);


			/*La media del equipo se calcula con las medias de los titulares*/
			if (Equip[i].jug[j].titular==1)
				media+=Equip[i].jug[j].media;

		 }
		 media=media/11;
		 Equip[i].media=media;
	}
}
/*Funcion similar a la de alineacion, en esta se omite la funcion de realizar cambios*/
char ver_rival(Equipo *Equip,int selec)
{
	int i,media;
	char volver;
	/*Borra la pantalla*/
	clrscr();

	/*Elimina el cursor*/
	_setcursortype(_NOCURSOR);
	/*Situa el cursor en esa posicion e imprime el nombre de entrenador*/
	gotoxy(3,2);
	printf("VER RIVAL");
	/*Situa el cursor en esa posicion e imprime el nombre del equipo*/
	gotoxy(3,3);
	printf("EQUIPO: %s ",Equip[selec].nombre);
	printf("\nฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ\n\n");
	/*Situa el cursor dos lineas mas abajo e imprime el nombre de
	cada jugador, junto con sus caracteristicas*/

	printf("\n\n                EQUIPO TITULAR\n");
	printf("ษอออหออออออออออออออออออออออหอออออหออออหออออหออออป\n");
	printf("บ idบ       Jugador        บ DEM บ MO บ CA บ ME บ\n");
	printf("ฬอออฮออออออออออออออออออออออฮอออออฮออออฮออออฮออออน\n");
	Equip[selec].media=0;

	/*El primer jugador de la lista sera el portero.
	Por eso se compruba el 0 y el 12*/
	if (Equip[selec].jug[0].titular==1)
		{
			media=((Equip[selec].jug[0].moral+Equip[selec].jug[0].calidad)/2);
			Equip[selec].media+=media;
			printf("บ %2dบ %-21sบ%4s บ %2d บ %2d บ %2d บ\n",0,Equip[selec].jug[0].nombre,Equip[selec].jug[0].demarca,Equip[selec].jug[0].moral,Equip[selec].jug[0].calidad,media);

		}
		if (Equip[selec].jug[12].titular==1)
		{
			media=((Equip[selec].jug[12].moral+Equip[selec].jug[12].calidad)/2);
			Equip[selec].media+=media;
			printf("บ %2dบ %-21sบ%4s บ %2d บ %2d บ %2d บ\n",12,Equip[selec].jug[12].nombre,Equip[selec].jug[12].demarca,Equip[selec].jug[12].moral,Equip[selec].jug[12].calidad,media);

		}
	for (i=0;i<18 ;i++ )
		 {



			/*La media se calcula con la moral y la calidad de
			cada jugador*/
			media=((Equip[selec].jug[i].moral+Equip[selec].jug[i].calidad)/2);


			/*Aqui se comprueban los demas jugadores excluyendo a
			los porteros*/
			if ((Equip[selec].jug[i].titular==1)&&(i!=0)&&(i!=12))
			{
				Equip[selec].media+=media;
				printf("บ %2dบ %-21sบ%4s บ %2d บ %2d บ %2d บ\n",i,Equip[selec].jug[i].nombre,Equip[selec].jug[i].demarca,Equip[selec].jug[i].moral,Equip[selec].jug[i].calidad,media);
			}

		 }
	printf("ศอออสออออออออออออออออออออออสอออออสออออสออออสออออผ\n");
	Equip[selec].media/=11;
	printf("\n\nMedia de Equipo:%d",Equip[selec].media);

	printf("\n\n                 SUPLENTES\n");
	printf("ษอออหออออออออออออออออออออออหอออออหออออหออออหออออป\n");
	printf("บ idบ       Jugador        บ DEM บ MO บ CA บ ME บ\n");
	printf("ฬอออฮออออออออออออออออออออออฮอออออฮออออฮออออฮออออน\n");

	/*El primer jugador de la lista sera el portero.
	Por eso se compruba el 0 y el 12*/
	if (Equip[selec].jug[0].titular==0)
		{
			media=((Equip[selec].jug[0].moral+Equip[selec].jug[0].calidad)/2);
			printf("บ %2dบ %-21sบ%4s บ %2d บ %2d บ %2d บ\n",0,Equip[selec].jug[0].nombre,Equip[selec].jug[0].demarca,Equip[selec].jug[0].moral,Equip[selec].jug[0].calidad,media);

		}
		if (Equip[selec].jug[12].titular==0)
		{
			media=((Equip[selec].jug[12].moral+Equip[selec].jug[12].calidad)/2);
			printf("บ %2dบ %-21sบ%4s บ %2d บ %2d บ %2d บ\n",12,Equip[selec].jug[12].nombre,Equip[selec].jug[12].demarca,Equip[selec].jug[12].moral,Equip[selec].jug[12].calidad,media);

		}
	for (i=0;i<18 ;i++ )
		 {



			/*La media se calcula con la moral y la calidad de
			cada jugador*/
			media=((Equip[selec].jug[i].moral+Equip[selec].jug[i].calidad)/2);

			/*Aqui se comprueban los demas jugadores excluyendo a
			los porteros*/
			if ((Equip[selec].jug[i].titular==0)&&(i!=0)&&(i!=12))
			{
				printf("บ %2dบ %-21sบ%4s บ %2d บ %2d บ %2d บ\n",i,Equip[selec].jug[i].nombre,Equip[selec].jug[i].demarca,Equip[selec].jug[i].moral,Equip[selec].jug[i].calidad,media);

			}
		 }
	printf("ศอออสออออออออออออออออออออออสอออออสออออสออออสออออผ\n");
	gotoxy(60,40);
	printf("ฺฤฤฤฤฤฤฤฤฤฟ");
	gotoxy(60,41);
	printf("ณ");
	textcolor(3);
	cprintf(" V");
	textcolor(7);
	printf("olver  ณ");
	gotoxy(60,42);
	printf("ภฤฤฤฤฤฤฤฤฤู\n\n");
	printf("ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ\n\n");
	textcolor(2);
	cprintf("V= Volver |");
	textcolor(7);
	volver=getch();
	return volver;

}

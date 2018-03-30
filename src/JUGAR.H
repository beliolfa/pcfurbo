/************************** LIBRERIA JUGAR.H **********************************/
/****** Contiene todas las funciones necesarias para el módulo de Jugar ******/

/*La siguiente funcion modifica las medias de los equipos segun el resultado 
obtenido en el partido*/
void medias(char modo,int local, int visitante, Equipo *equip)
{
	int i;
	/*Si se le ha pasado como parametro una 'e' quiere decir q los equipos han 
	empatado*/
	if (modo=='e')
	{
		/*Por ello se añaden 3 puntos mas de moral a cada jugador de cada equipo*/
		for (i=0;i<18;i++)
		{

				if (equip[local].jug[i].titular==1)
				{
					equip[local].jug[i].moral+=3;
					/*Si la moral se pasa de 99, se pone a 99*/
					if (equip[local].jug[i].moral>99)
						equip[local].jug[i].moral=99;
				}

				if (equip[visitante].jug[i].titular==1)
				{
					equip[visitante].jug[i].moral+=3;
					if (equip[visitante].jug[i].moral>99)
						equip[local].jug[i].moral=99;
				}

		}
	}
	/*Si se le ha pasado como parametro una 'l' quiere decir que ha ganado el equipo
	local*/
	if (modo=='l')
	{
		/*Por ello se añaden 6 puntos mas de moral a cada jugador titular del equipo
		local, y se le restan 2 puntos de moral a cada jugador titular del equipo
		visitante*/
		for (i=0;i<18;i++)
		{

			if (equip[local].jug[i].titular==1)
			{
				equip[local].jug[i].moral+=6;
				if (equip[local].jug[i].moral>99)
						equip[local].jug[i].moral=99;
			}

			if (equip[visitante].jug[i].titular==1)
				equip[visitante].jug[i].moral-=2;
		}
	}
	/*Si se le ha pasado como parametro una 'v' quiere decir que ha ganado el equipo
	visitante*/
	if (modo=='v')
	{
		/*Por ello se añaden 6 puntos mas de moral a cada jugador titular del equipo
		visitante, y se le restan 2 puntos de moral a cada jugador titular del equipo
		local*/
		for (i=0;i<18;i++)
		{
			if (equip[local].jug[i].titular==1)
				equip[local].jug[i].media-=2;

			if (equip[visitante].jug[i].titular==1)
			{
				equip[visitante].jug[i].moral+=6;
				if (equip[local].jug[i].moral>99)
						equip[local].jug[i].moral=99;
			}
		}
	}
}

/*Funcion para disputar los partidos*/
char jugar(Equipo *Equip,int selec,Clasificacion *Clasif,Jornada *Calend)
{
	int i,j,azar,espacios=7,jugtit,alea,est;
	time_t t;
	clrscr();

	pantalla_vacia();
	/*Vamos a disputar la jornada, para ello recorremos todos los
	partidos correspondientes a la jornada actual*/
	for (i=1;i<=NEQ/2;i++)
	{
		/*Calculamos el resultado del local y del visitante con
		un numero al azar no mayor de 2*/
		if(i==1) srand((unsigned) time(&t));
		Calend[jorActual].part[i].res_local=random(4);
		if (i==1) srand((unsigned) time(&t));
		Calend[jorActual].part[i].res_visitante=random(4);



		/*Ahora pasaremos el resultado calculado anteriormente
		por unos cuantos filtros que adecuen el resultado a
		la calidad del equipo en ese momento y a otras circustancias*/
		if(i==1) srand((unsigned) time(&t));
		azar=random(5);


		/*Hay 2 posibilidades entre 5 de que no se entre a los
		filtros*/
		if((azar!=1)&&(azar!=0))
		{
			/*Si el local tiene mayor media que el visitante o
			viceversa se a¤ade un gol mas a su marcador*/
			if(Equip[Calend[jorActual].part[i].id_local].media>Equip[Calend[jorActual].part[i].id_visitante].media)
				Calend[jorActual].part[i].res_local++;
			if(Equip[Calend[jorActual].part[i].id_visitante].media>Equip[Calend[jorActual].part[i].id_local].media)
				Calend[jorActual].part[i].res_visitante++;

			/*Si el local tiene mas de 15 puntos de media
			que el visitante o viceversa se a¤ade un gol mas a su marcador*/
			if(Equip[Calend[jorActual].part[i].id_local].media-15>Equip[Calend[jorActual].part[i].id_visitante].media)
				Calend[jorActual].part[i].res_local++;
			if(Equip[Calend[jorActual].part[i].id_visitante].media-15>Equip[Calend[jorActual].part[i].id_local].media)
				Calend[jorActual].part[i].res_visitante++;

			/*Si el local tiene mas de 30 puntos de media
			que el visitante o viceversa se a¤ade un gol mas a su marcador*/
			if(Equip[Calend[jorActual].part[i].id_local].media-30>Equip[Calend[jorActual].part[i].id_visitante].media)
				Calend[jorActual].part[i].res_local++;
			if(Equip[Calend[jorActual].part[i].id_visitante].media-30>Equip[Calend[jorActual].part[i].id_local].media)
				Calend[jorActual].part[i].res_visitante++;




		}
		//fin de filtros

		/*Imprimimos el partido del equipo del que somos entrenador*/

		if ((Calend[jorActual].part[i].id_local==selec)||(Calend[jorActual].part[i].id_visitante==selec))
		{
			est=i;
			/*Cuestiones de estetica*/
			gotoxy(1,6);
			textcolor(4);
			textbackground(2);
			espacios+=strlen(Equip[Calend[jorActual].part[i].id_local].nombre);
			espacios+=strlen(Equip[Calend[jorActual].part[i].id_visitante].nombre);
			espacios/=2;
			espacios=40-espacios;

			for (j=1;j<=espacios;j++)
				if (j==1)
					printf("º");
				else
					printf(" ");

			cprintf("%s %d - %d %s\n",Equip[Calend[jorActual].part[i].id_local].nombre,Calend[jorActual].part[i].res_local,Calend[jorActual].part[i].res_visitante,Equip[Calend[jorActual].part[i].id_visitante].nombre);

			for (j=1;j<=espacios;j++)
				if (j==espacios)
					printf("º");
				else
					printf(" ");

			textbackground(1);
			textcolor(7);

			/*Mostramos en pantalla quien ha metido los goles*/
			/*Primero el Resultado local*/
			if(Calend[jorActual].part[i].res_local!=0)
			{
				for (j=1;j<=Calend[jorActual].part[i].res_local;j++)
				{
					jugtit=0;
					do
					{
					    alea=random(18);
					    if((Equip[Calend[jorActual].part[i].id_local].jug[alea].titular==1)&&(alea!=0)&&(alea!=12))
					    {
						 jugtit=1;
						 gotoxy(4,7+j);
						 printf("Gol de %s\n",Equip[Calend[jorActual].part[i].id_local].jug[alea].nombre);
					    }
					}while (jugtit!=1);
				}
			}

			/*Mostramos en pantalla quien ha metido los goles*/
			/*Ahora el Resultado visitante*/
			if(Calend[jorActual].part[i].res_visitante!=0)
			{
				for (j=1;j<=Calend[jorActual].part[i].res_visitante;j++)
				{
					jugtit=0;
					do
					{
					    alea=random(18);
					    if((Equip[Calend[jorActual].part[i].id_visitante].jug[alea].titular==1)&&(alea!=0)&&(alea!=12))
					    {
						 jugtit=1;
						 gotoxy(54,7+j);
						 printf("Gol de %s\n",Equip[Calend[jorActual].part[i].id_visitante].jug[alea].nombre);
					    }
					}while (jugtit!=1);
				}
			}

		}
		/*Actualizamos la clasificacion y las medias*/
		if(Calend[jorActual].part[i].res_local==Calend[jorActual].part[i].res_visitante)
		{
		  medias('e',Calend[jorActual].part[i].id_local,Calend[jorActual].part[i].id_visitante,Equip);

		  Clasif[Calend[jorActual].part[i].id_local].puntos++;
		  Clasif[Calend[jorActual].part[i].id_visitante].puntos++;
		}
		else if(Calend[jorActual].part[i].res_local>Calend[jorActual].part[i].res_visitante)
		{

			medias('l',Calend[jorActual].part[i].id_local,Calend[jorActual].part[i].id_visitante,Equip);

			Clasif[Calend[jorActual].part[i].id_local].puntos+=3;
		}
		else if(Calend[jorActual].part[i].res_visitante>Calend[jorActual].part[i].res_local)
		{

			medias('v',Calend[jorActual].part[i].id_local,Calend[jorActual].part[i].id_visitante,Equip);

			Clasif[Calend[jorActual].part[i].id_visitante].puntos+=3;
		}
	}
	/*Un dibujo simulando un estadio de futbol. Mostramos el nombre del estadio del
	equipo local, es decir, donde se disputó el encuentro*/
	textbackground(2);
	gotoxy(6,29);  printf("     ESTADIO       ");
	gotoxy(6,30); cprintf("ÚÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄ¿\n");
	gotoxy(6,31); cprintf("ÃÄÄÄ¿   ³   ÚÄÄÄ´\n");
	gotoxy(6,32); cprintf("ÃÄ¿ ³   ³   ³ ÚÄ´\n");
	gotoxy(6,33); cprintf("³ ³ ³   ³   ³ ³ ³\n");
	gotoxy(6,34); cprintf("² ³ ³) (³) (³ ³ ²\n");
	gotoxy(6,35); cprintf("³ ³ ³   ³   ³ ³ ³\n");
	gotoxy(6,36); cprintf("ÃÄÙ ³   ³   ³ ÀÄ´\n");
	gotoxy(6,37); cprintf("ÃÄÄÄÙ   ³   ÀÄÄÄ´\n");
	gotoxy(6,38); cprintf("ÀÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÙ\n");
	gotoxy(6,39);  printf("%s",Equip[Calend[jorActual].part[est].id_local].estadio);
	textbackground(1);

	/*Aumentamos la jornada y volvemos a la pantalla de Gestion*/
	jorActual++;
	return '0';

}


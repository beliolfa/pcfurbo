void crear_clasificacion(Clasificacion *clasif)
{
	int i;
	for (i=0;i<NEQ;i++)
	{
		clasif[i].puntos=0;
		clasif[i].pos=i+1;
	}


}
char clasificacion(Equipo *Equip, int selec,Clasificacion *clasif,final *final)
{

/*Declaracion de variables locales*/
	int i,j,aux,sw,n,tabAux[NEQ]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	char volver;

/*Borra la pantalla*/
	clrscr();



/*Elimina el cursor*/
	_setcursortype( _NOCURSOR );

/*Situa el cursor en esa posicion e imprime el nombre de entrenador*/
	gotoxy(3,2);
	printf("ENTRENADOR: %s ",nomEntrenador);

/*Situa el cursor en esa posicion e imprime el nombre del equipo y
seguidamente la clasificacion*/
	gotoxy(3,3);
	printf("EQUIPO: %s ",Equip[selec].nombre);
	printf("\n��������������������������������������������������������������������������������\n\n");
	printf("\n\n          CLASIFICACION\n");
	printf("����������������������������������ͻ\n");
	printf("�Pos�        Equipo        � Puntos�\n");
	printf("����������������������������������͹\n");


/*Ordenamos la tabla de clasificacion teniendo en cuenta los puntos*/

	if(jorActual>1)
	{
		for  (i=0;i<NEQ;i++) clasif[i].pos=NEQ;

		for  (i=0;i<NEQ;i++)
		{
			/*n es el mayor*/
//			if (clasif[i].pos!=0)
//				n=i;
//			else continue;
			n=0;
			while (clasif[n].pos == 0) n++;

			for (j=0;j<NEQ;j++)
			{

				if ((clasif[j].puntos > clasif[n].puntos) && (clasif[j].pos !=0))
				{
					n=j;

				}
			}
			clasif[n].pos=0;
			tabAux[i]=n;
		 }

	 }


/*Imprimimos los equipos segun su posicion*/

/*Guardamos quien es el campeon*/
strcpy(final[0].campeon,Equip[tabAux[0]].nombre);


	for (i=0;i<NEQ;i++)
	{
				 if(tabAux[i]==selec)
				 {
					/*Guardamos la posicion de tu equipo*/
					final[0].tuequipo=i+1;
					textcolor(6);
					printf("� %2d�",(i+1));
					cprintf(" %-21s",Equip[tabAux[i]].nombre);
					printf("�%4d   �\n",clasif[tabAux[i]].puntos);
					textcolor(7);
				 }
				 else
					printf("� %2d� %-21s�%4d   �\n",(i+1),Equip[tabAux[i]].nombre,clasif[tabAux[i]].puntos);
	}





	printf("����������������������������������ͼ\n");
	gotoxy(60,40);
	printf("���������Ŀ");
	gotoxy(60,41);
	printf("�");
	textcolor(3);
	cprintf(" V");
	textcolor(7);
	printf("olver  �");
	gotoxy(60,42);
	printf("�����������\n\n");
	printf("��������������������������������������������������������������������������������\n\n");
	textcolor(2);
	cprintf("| V= Volver |");
	textcolor(7);
	volver=getch();
	return volver;

}

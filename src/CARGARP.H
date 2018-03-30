void cargar_partida(Clasificacion*tabclasif,Jornada *tabcalend,Equipo *tabequipos)
{

/*int i,j;
FILE *fichero;

       if((fichero=fopen("c:\\pcfurbo\\param.pcf","rb"))==NULL)
       {
		printf("no es posible abrir 'parametros.pcf'");

       }
       else
       {
		fgets(nomEntrenador,20,fichero);
		fscanf(fichero,"%d",&jorActual);
		printf("%s   %d ",nomEntrenador,jorActual);
		getch();

       }

       fclose(fichero);

       if((fichero=fopen("C:\\pcfurbo\\clasif.pcf","rb"))==NULL)
       {
		printf("No es posible abrir 'clasif.pcf'");
		exit(0);
       }



       for(i=0;i<NEQ;i++)
       {

		fread(&tabclasif[i],sizeof(Clasificacion),1,fichero);

       }
       fclose(fichero);

	if((fichero=fopen("c:\\pcfurbo\\calend.pcf","rb"))==NULL)
       {
		printf("No es posible abrir 'calend.pcf'");
		exit(0);
       }


       for(i=1;i<=NPART*2;i++)
       {
		for (j=1;j<=NEQ/2;j++)
		{
			fread(&tabcalend[i].part[j],sizeof(Jornada),1,fichero);
			mostrar_calendario(tabcalend,i,tabequipos,1);
			getch();
		}
       }
       fclose(fichero);

	if((fichero=fopen("c:\\pcfurbo\\equipo.pcf","rb"))==NULL)
       {
		printf("No es posible abrir 'equipo.pcf'");
		exit(0);
       }


       for(i=0;i<NEQ;i++)
       {

		fread(&tabequipos[i],sizeof(Equipo),1,fichero);

       }
       fclose(fichero);*/

       textbackground(2);
       textcolor(4);
       gotoxy(27,20);
	 cprintf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
       gotoxy(25,21);
       cprintf("ÚÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿³");
       gotoxy(25,22);
       cprintf("³                                      ³³");
       gotoxy(25,23);
       cprintf("³  Funcion deshabilitada por reformas  ³³");
       gotoxy(25,24);
       cprintf("³                                      ÃÙ");
       gotoxy(25,25);
       cprintf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
       textcolor(7);
       textbackground(1);
}




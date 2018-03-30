void guardar_partida(Clasificacion*tabclasif,Jornada *tabcalend,Equipo *tabequipos)
{

int i,j;
FILE *fichero;

       if((fichero=fopen("c:\\pcfurbo\\param.pcf","w"))==NULL)
       {
		printf("no es posible abrir 'parametros.pcf'");

       }
       else
       {
//		fputs(nomEntrenador,fichero);
		fprintf(fichero,"%s %d",nomEntrenador,jorActual);
       }

       fclose(fichero);

       if((fichero=fopen("C:\\pcfurbo\\clasif.pcf","wb"))==NULL)
       {
		printf("No es posible abrir 'clasif.pcf'");
		exit(0);
       }



       for(i=0;i<NEQ;i++)
       {

		fwrite(&tabclasif[i],sizeof(Clasificacion),1,fichero);

       }
       fclose(fichero);

	if((fichero=fopen("c:\\pcfurbo\\calend.pcf","wb"))==NULL)
       {
		printf("No es posible abrir 'calend.pcf'");
		exit(0);
       }


       for(i=1;i<=NPART*2;i++)
       {
		for (j=1;j<=NEQ/2;j++)
			fwrite(&tabcalend[i],sizeof(Jornada),1,fichero);

       }
       fclose(fichero);

	if((fichero=fopen("c:\\pcfurbo\\equipo.pcf","wb"))==NULL)
       {
		printf("No es posible abrir 'equipo.pcf'");
		exit(0);
       }


       for(i=0;i<NEQ;i++)
       {

		fwrite(&tabequipos[i],sizeof(Equipo),1,fichero);

       }
       fclose(fichero);

       textbackground(2);
       textcolor(4);
       gotoxy(29,25);
	 cprintf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
       gotoxy(27,26);
       cprintf("ÚÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿³");
       gotoxy(27,27);
       cprintf("³                            ³³");
       gotoxy(27,28);
       cprintf("³  Se ha guardado la partida ³³");
       gotoxy(27,29);
       cprintf("³                            ÃÙ");
       gotoxy(27,30);
       cprintf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
       textcolor(7);
       textbackground(1);

}




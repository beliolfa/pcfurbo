/************************************** PC FURBO v1.0 ********************************************************************/

/************************************** Funciones Principales ************************************************************/



/*Variables globales*/
char nomEntrenador[20];
int jorActual=1;

/*Numero de equipos*/
#define NEQ 16

/*Numero de partidos que se jugaran en una vuelta de liga*/
#define NPART ((NEQ*2)-2)/2

/*Librerias necesarias*/
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "A:\STRUCT.H"
#include "A:\CALEND.H"
#include "A:\GUARDARP.H"
#include "A:\CARGARP.H"
#include "A:\PANTALLA.H"
#include "A:\ALINEAC.H"
#include "A:\CLASIF.H"
#include "A:\JUGAR.H"

/*Declaracion de funciones*/
void pantalla_principal();
int buscar_rival(Jornada *,int);
void pantalla_mostrarEquipos();
int elegirEquipo();
void mostrar_seleccion(Equipo *,int);
char pantalla_gestion(Equipo *,int,Jornada *);
char alineacion(Equipo *,int,int);
char ver_rival(Equipo *,int);
void realizar_cambios(Equipo *,int);
void crear_clasificacion(Clasificacion *);
char clasificacion(Equipo *,int,Clasificacion *,final *);
void crear_calendario(Jornada *);
char mostrar_calendario(Jornada *,int,Equipo *,int);
int comprobar_local(int,int,int,Jornada *);
int comprobar_visitante(int,int,int,int,Jornada *);
char jugar(Equipo *,int,Clasificacion *,Jornada *);
void calcular_medias(Equipo *);
void pantalla_vacia();
void medias(char,int,int,Equipo *);
char fin(final *);

/*Funcion Principal*/
void main()
{


/*Declaracion de la Clasificacion*/
	Clasificacion tabClasif[NEQ];
/*Tabla utilizada para almacenar el campeon y la posicion final de tu equipo al
finalizar la temporada*/
	final  final[1];

/*Declaracion del Calendario*/
	Jornada tabCalend[(NPART*2)+1];

/*Otras variables necesarias*/
	char ch,selec,volver;
	int sel,i,sw,rival,cargar=0;

/*Declaramos todos los datos de los equipos: nombre,
 jugadores,estadio,caracteristicas tecnicas,etc..
 el valor de titular es un switch en el que 11 jugadores lo tienen
 iniciado a 1 (titulares) y los demas a 0 (suplentes), mas tarde
 se podra elegir a los titulares.
 El valor de lesionado es un switch iniciado a 0.
 La media de cada jugador se calculara mas tarde.
 La media del equipo se calcula con las medias de sus jugadores*/

	Equipo tabEquipos[NEQ]=
	{
	{{{"Dutruel","POR",1,0,44,78,0},{"Ibon Bego�a","DEF",1,0,44,70,0},{"Karmona","DEF",1,0,44,74,0},{"Tellez","DEF",0,0,44,71,0},{"Geli","DEF",1,0,44,71,0},{"Abelardo", "DEF",1,0,44,77,0},{"Tomic","MED",1,0,44,72,0},{"Desio","MED",0,0,44,76,0},{"Luis Helguera","MED",1,0,44,69,0},{"Astudillo","MED",1,0,44,74,0},{"Turiel","MED",1,0,44,73,0},{"Nacho","MED",0,0,44,70,0},{"Juan Pablo","POR",0,0,44,62,0},{"Ruben Navarro","DEL",0,0,44,78,0},{"Magno","DEL",0,0,44,71,0},{"Cruyff","DEL",1,0,44,76,0},{"Illie","DEL",1,0,44,80,0},{"Ivan Alonso","DEL",0,0,44,78,0}},"Alaves",0,"Mendizorroza"},
	{{{"Lafuente","POR",0,0,44,70,0},{"Larrainzar","DEF",0,0,44,69,0},{"Larrazabal","DEF",1,0,44,74,0},{"Carlos Garcia","DEF",1,0,44,75,0},{"Karanka","DEF",1,0,44,73,0},{"Lacruz", "DEF",1,0,44,77,0},{"Julen Guerrero","MED",0,0,44,78,0},{"Yeste","MED",1,0,44,76,0},{"Javi Gonzalez","MED",1,0,44,73,0},{"Alkiza","MED",1,0,44,74,0},{"Tiko","MED",1,0,44,80,0},{"Gurpegui","MED",0,0,44,73,0},{"Aranzubia","POR",1,0,44,70,0},{"25. Carlos Merino","MED",0,0,44,71,0},{"Ezquerro","DEL",0,0,44,71,0},{"Urzaiz","DEL",1,0,44,81,0},{"Joseba Etxeberria","DEL",1,0,44,77,0},{"Arriaga","DEL",0,0,44,70,0}},"Athletic Bilbao",0,"San Mames"},
	{{{"Esteban","POR",0,0,44,83,0},{"Otero","DEF",1,0,44,84,0},{"Hibic","DEF",0,0,44,85,0},{"Garcia Calvo","DEF",1,0,44,85,0},{"Santi","DEF",1,0,44,83,0},{"Sergi","DEF",1,0,44,85,0},{"Nagore","MED",0,0,44,79,0},{"Movilla","MED",1,0,44,82,0},{"Albertini","MED",1,0,44,86,0},{"Stankovic","MED",1,0,44,80,0},{"Dani","MED",0,0,44,80,0},{"Aguilera","MED",0,0,44,82,0},{"Burgos","POR",1,0,44,88,0},{"Fernando Torres","DEL",1,0,44,90,0},{"Correa","DEL",0,0,44,85,0},{"Javi Moreno","DEL",1,0,44,86,0},{"Luis Garcia","DEL",0,0,44,80,0},{"Jose Mari","DEL",1,0,44,89,0}},"Atletico de Madrid",0,"Vicente Calderon"},
	{{{"Bonano","POR",1,0,44,84,0},{"Reiziger","DEF",1,0,44,86,0},{"Frank De Boer","DEF",1,0,44,87,0},{"Anderson","DEF",0,0,44,91,0},{"Puyol","DEF",1,0,44,93,0},{"Christanval","DEF",1,0,44,90,0},{"Xavi","MED",1,0,44,89,0},{"Cocu","MED",0,0,44,87,0},{"Riquelme","MED",1,0,44,88,0},{"Rochemback","MED",0,0,44,88,0},{"Mendieta","MED",1,0,44,90,0},{"Luis Enrique","MED",1,0,44,92,0},{"Enke","POR",0,0,44,84,0},{"Saviola","DEL",0,0,44,90,0},{"Kluivert","DEL",1,0,44,90,0},{"Overmars","DEL",1,0,44,91,0},{"Dani","DEL",0,0,44,89,0},{"Nano","DEL",0,0,44,89,0}},"F.C. Barcelona",0,"Camp Nou"},
	{{{"Toni Prats","POR",1,0,44,80,0},{"Luis Fernandez","DEF",1,0,44,80,0},{"Juanito","DEF",1,0,44,74,0},{"Rivas","DEF",1,0,44,75,0},{"Belenguer","DEF",0,0,44,75,0},{"Tais","DEF",1,0,44,74,0},{"Varela","MED",1,0,44,83,0},{"Cesar","MED",1,0,44,75,0},{"Fernando","MED",0,0,44,74,0},{"Capi","MED",1,0,44,85,0},{"Filipescu","MED",0,0,44,78,0},{"Arzu","MED",1,0,44,79,0},{"Gaspercic","POR",0,0,44,75,0},{"Alfonso","DEL",0,0,44,80,0},{"Denilson","DEL",1,0,44,91,0},{"Joaquin","DEL",1,0,44,94,0},{"Gaston Casas","DEL",0,0,44,73,0},{"Maldonado","DEL",0,0,44,74,0}},"Betis",0,"Ruiz de Lopera"},
	{{{"Cavallero","POR",1,0,44,77,0},{"Velasco","DEF",1,0,44,75,0},{"Silvinho","DEF",0,0,44,76,0},{"Caceres","DEF",1,0,44,75,0},{"Berizo","DEF",1,0,44,75,0},{"JuanFran","DEF",1,0,44,74,0},{"Giovanella","MED",0,0,44,76,0},{"Vagner","MED",1,0,44,77,0},{"Mostovoi","MED",1,0,44,74,0},{"Doriva","MED",0,0,44,76,0},{"Jose Ignacio","MED",1,0,44,74,0},{"Edu","MED",1,0,44,76,0},{"Pinto","POR",0,0,44,75,0},{"Angel","DEL",0,0,44,76,0},{"Gustavo Lopez","DEL",1,0,44,77,0},{"Jesuli","DEL",0,0,44,73,0},{"Catanha","DEL",1,0,44,75,0},{"Benny McCarthy","DEL",0,0,44,76,0}},"Celta",0,"Balaidos"},
	{{{"Molina","POR",1,0,44,84,0},{"Manuel Pablo","DEF",1,0,44,83,0},{"Romero","DEF",1,0,44,86,0},{"Cesar","DEF",1,0,44,75,0},{"Andrade","DEF",0,0,44,73,0},{"Donato","DEF",1,0,44,80,0},{"Mauro Silva","MED",1,0,44,84,0},{"Cesar","MED",1,0,44,77,0},{"Fernando","MED",0,0,44,74,0},{"Scaloni","MED",0,0,44,84,0},{"Sergio","MED",1,0,44,82,0},{"Valeron","MED",1,0,44,87,0},{"Juanmi","POR",0,0,44,82,0},{"Makaay","DEL",1,0,44,88,0},{"Diego Tristan","DEL",1,0,44,89,0},{"Amavisca","DEL",0,0,44,84,0},{"Victor","DEL",0,0,44,79,0},{"Luque","DEL",0,0,44,83,0}},"Depor",0,"Riazor"},
	{{{"Toni","POR",1,0,44,80,0},{"David Garcia","DEF",0,0,44,75,0},{"Lopo","DEF",1,0,44,77,0},{"Soldevilla","DEF",1,0,44,80,0},{"Amaya","DEF",0,0,44,75,0},{"Torricelli","DEF",1,0,44,81,0},{"Velamazan","MED",1,0,44,77,0},{"Morales","MED",1,0,44,77,0},{"Roger","MED",1,0,44,84,0},{"Boghossian","MED",0,0,44,76,0},{"Fredson","MED",0,0,44,72,0},{"Arteaga","MED",1,0,44,78,0},{"Sergio S�nchez","POR",0,0,44,75,0},{"De la Pe�a","MED",1,0,44,86,0},{"Milosevic","DEL",1,0,44,77,0},{"Maxi Rodriguez","DEL",0,0,44,75,0},{"Tamudo","DEL",1,0,44,83,0},{"Oscar","DEL",0,0,44,78,0}},"Espanyol",0,"Lluis Companys"},
	{{{"Rafa","POR",0,0,44,78,0},{"Rojas","DEF",1,0,44,70,0},{"Bravo","DEF",1,0,44,74,0},{"Litos","DEF",0,0,44,71,0},{"Roteta","DEF",1,0,44,71,0},{"Iznata", "DEF",1,0,44,77,0},{"Musampa","MED",1,0,44,82,0},{"Romero","MED",0,0,44,76,0},{"Manu Sanchez","MED",1,0,44,74,0},{"Miguel Angel","MED",1,0,44,74,0},{"Leko","MED",0,0,44,73,0},{"Sandro","MED",1,0,44,80,0},{"Contreras","POR",1,0,44,82,0},{"Dely Valdes","DEL",1,0,44,85,0},{"Dario Silva","DEL",1,0,44,87,0},{"Canabal","DEL",0,0,44,76,0},{"Juanito","DEL",0,0,44,80,0},{"Koke","DEL",0,0,44,78,0}},"Malaga",0,"La Rosaleda"},
	{{{"Sanzol","POR",0,0,44,68,0},{"Yanguas","DEF",1,0,44,70,0},{"Paqui","DEF",0,0,44,75,0},{"Mateo","DEF",1,0,44,78,0},{"Cruchaga","DEF",1,0,44,78,0},{"Josetxo","DEF",1,0,44,77,0},{"Manfredini","MED",0,0,44,79,0},{"Alfredo","MED",1,0,44,78,0},{"Palacios","MED",1,0,44,80,0},{"Patxi Punal","MED",1,0,44,79,0},{"Moha","MED",0,0,44,80,0},{"Pablo Garcia","MED",0,0,44,79,0},{"Unzue","POR",1,0,44,82,0},{"Ivan Rosado","MED",1,0,44,78,0},{"Izquierdo","DEL",0,0,44,79,0},{"Morales","DEL",1,0,44,80,0},{"Gorka","DEL",0,0,44,80,0},{"Aloisi","DEL",1,0,44,89,0}},"Osasuna",0,"Sadar"},
	{{{"Sergio Segura","POR",1,0,44,79,0},{"Dorado","DEF",1,0,44,76,0},{"De Quintana","DEF",1,0,44,77,0},{"Corino","DEF",0,0,44,71,0},{"Graff","DEF",1,0,44,73,0},{"Mora","DEF",1,0,44,70,0},{"Mainz","MED",1,0,44,69,0},{"Michel","MED",0,0,44,77,0},{"Quevedo","MED",1,0,44,78,0},{"Luis Cembranos","MED",0,0,44,78,0},{"Santos","MED",1,0,44,70,0},{"Azkoitia","MED",1,0,44,72,0},{"Imanol Etxeberria","POR",0,0,44,74,0},{"Camonas","DEL",0,0,44,70,0},{"Peragon","DEL",1,0,44,70,0},{"Bolic","DEL",1,0,44,71,0},{"Michel II","DEL",0,0,44,69,0},{"Bolo","DEL",0,0,44,75,0}},"Rayo Vallecano",0,"Teresa Rivero"},
	{{{"Casillas","POR",1,0,44,92,0},{"Michel Salgado","DEF",1,0,44,85,0},{"Roberto Carlos","DEF",1,0,44,90,0},{"Hierro","DEF",1,0,44,86,0},{"Helguera","DEF",1,0,44,87,0},{"Pavon","DEF",0,0,44,80,0},{"Zidane","MED",1,0,44,94,0},{"Flavio Conceicao","MED",0,0,44,81,0},{"Cambiasso","MED",0,0,44,81,0},{"Makelele","MED",1,0,44,88,0},{"Solari","MED",1,0,44,85,0},{"McManaman","MED",0,0,44,87,0},{"Cesar","POR",0,0,44,80,0},{"Raul","DEL",1,0,44,91,0},{"Morientes","DEL",0,0,44,89,0},{"Ronaldo","DEL",1,0,44,95,0},{"Figo","DEL",1,0,44,90,0},{"Portillo","DEL",0,0,44,88,0}},"Real Madrid",0,"Santiago Bernabeu"},
	{{{"Reinke","POR",1,0,44,86,0},{"Clavero","DEF",0,0,44,80,0},{"Pedro largo","DEF",1,0,44,84,0},{"Mikel Lasa","DEF",1,0,44,88,0},{"Carrero","DEF",1,0,44,79,0},{"Juanma", "DEF",1,0,44,87,0},{"Tito","MED",0,0,44,88,0},{"Maciel","MED",1,0,44,88,0},{"Acciari","MED",1,0,44,88,0},{"Setvalls","MED",0,0,44,82,0},{"Isaach","MED",0,0,44,80,0},{"Gomez","MED",0,0,44,85,0},{"Valero","POR",0,0,44,82,0},{"Loreto","DEL",0,0,44,89,0},{"Richi","DEL",1,0,44,89,0},{"D.Karanka","DEL",1,0,44,87,0},{"Albiol","DEL",1,0,44,87,0},{"Ismael","DEL",1,0,44,90,0}},"Real Murcia",0,"La condomina"},
	{{{"Alberto","POR",0,0,44,80,0},{"Aranzabal","DEF",0,0,44,75,0},{"Gurrutxaga","DEF",1,0,44,77,0},{"Schurrer","DEF",1,0,44,80,0},{"Pikabea","DEF",0,0,44,75,0},{"Lopez Rekarte","DEF",1,0,44,81,0},{"Xabi Alonso","MED",1,0,44,77,0},{"De Pedro","MED",1,0,44,87,0},{"Tayfun","MED",1,0,44,84,0},{"Gabilondo","MED",0,0,44,80,0},{"Karpin","MED",0,0,44,85,0},{"Jauregui","MED",1,0,44,78,0},{"Westerveld","POR",1,0,44,75,0},{"Mikel Alonso","MED",1,0,44,86,0},{"Kovacevic","DEL",1,0,44,87,0},{"Nihat","DEL",0,0,44,88,0},{"Aramburu","DEL",1,0,44,83,0},{"De Paula","DEL",0,0,44,82,0}},"Real Sociedad",0,"Anoeta"},
	{{{"Trigo","POR",1,0,44,94,0},{"Sergio","DEF",1,0,44,90,0},{"Javi paez","DEF",1,0,44,93,0},{"Antonio Tomas","DEF",0,0,44,90,0},{"Rivas","DEF",1,0,44,95,0},{"Manolo","DEF",1,0,44,90,0},{"Jose Juan Otika","MED",1,0,44,93,0},{"Pedro Pintika","MED",0,0,44,94,0},{"Victor Terrorista","MED",1,0,44,90,0},{"Pepe Maneta","MED",0,0,44,93,0},{"Marcos Blaya","MED",1,0,44,90,0},{"Loren","MED",1,0,44,90,0},{"Paco E.","POR",0,0,44,92,0},{"Paco Blaya","DEL",0,0,44,97,0},{"Belio","DEL",1,0,44,99,0},{"Pomares","DEL",1,0,44,91,0},{"Kubatas","DEL",0,0,44,90,0},{"Ramon del Malena","DEL",0,0,44,89,0}},"Recambios Paco",0,"Pabellon de Mula"},
	{{{"Ca�izares","POR",1,0,44,87,0},{"Pellegrino","DEF",1,0,44,82,0},{"Ayala","DEF",0,44,84,0},{"Djukic","DEF",1,0,44,85,0},{"Carboni","DEF",1,0,44,87,0},{"Curro Torres","DEF",1,0,44,84,0},{"Marchena","DEF",0,0,44,76,0},{"Albelda","MED",1,0,44,87,0},{"Baraja","MED",1,0,44,89,0},{"Kily Gonzalez","MED",0,0,44,86,0},{"Aimar","MED",1,0,44,88,0},{"Angulo","MED",1,0,44,81,0},{"Palop","POR",0,0,44,81,0},{"Carew","DEL",0,0,44,88,0},{"Juan Sanchez","DEL",1,0,44,83,0},{"Vicente","DEL",0,0,44,80,0},{"Mista","DEL",1,0,44,75,0},{"Borja","DEL",0,0,44,76,0}},"Valencia",0,"Mestalla"}
	};



/*Rellenamos el calendario*/

	crear_calendario(tabCalend);

/*Rellenamos la clasificacion inicialmente por orden alfabetico y
asignandole 0 puntos a cada equipo*/

	crear_clasificacion(tabClasif);

/*Calculo de media de todos los equipos*/

	calcular_medias(tabEquipos);

/*Eliminamos el cursor*/
	_setcursortype(_NOCURSOR);

/*Muestra la pantalla principal hasta que se pulsa C para continuar*/
	do
	{
		pantalla_principal();
		ch=getch();

		if ((ch=='c')||(ch=='C'))
		{
			cargar_partida(tabClasif,tabCalend,tabEquipos);
			getch();
			/*cargar=1;
			ch='s';*/
		}
	}while ((ch!='s')&&(ch!='S'));

/*Se muestra el listado de equipos, se devuelve el valor sel y se
	compreba que sea menor que el numero de equipos*/

	if(cargar==0)
	{
		pantalla_mostrarEquipos();
		do
		{
			sel=elegirEquipo();

		}while (sel>=NEQ);
	}

/*Una vez elegido el equipo se muestra la pantalla de gestion*/
	do{
		if (jorActual==(NPART*2)+1) selec=fin(final);
		else selec=pantalla_gestion(tabEquipos,sel,tabCalend);
		rival=buscar_rival(tabCalend,sel);
/*Si se pulsa A entramos a la gestion de alineacion*/
		if((selec=='a')||(selec=='A'))
		{

			do{

			/* si al llamar a alineacion el sw esta a 0*/
			/* hace un getch */
				sw=0;
				volver=alineacion(tabEquipos,sel,sw);

				/*Si se pulsa C entramos a la gestion*/
				/*de cambios*/
				if ((volver=='c')||(volver=='C'))
				{
					realizar_cambios(tabEquipos,sel);

				}

			/*No salimos de aqui hasta pulsar V*/
			}while ((volver!='v')&&(volver!='V'));
		}
/*Si se pulsa V entramos a Ver Rival*/
		if((selec=='v')||(selec=='V'))
		{

			do{

			/* si al llamar a alineacion el sw esta a 0*/
			/* hace un getch */
				volver=ver_rival(tabEquipos,rival);


			/*No salimos de aqui hasta pulsar V*/
			}while ((volver!='v')&&(volver!='V'));
		}
/*Si se pulsa C entramos a la Clasificacion*/
		if ((selec=='c')||(selec=='C'))
		{
			do{

				volver=clasificacion(tabEquipos,sel,tabClasif,final);

			/*No salimos de aqui hasta pulsar V*/
			}while ((volver!='v')&&(volver!='V'));
		}

/*Si se pulsa R entramos a los  Resultados*/
		if ((selec=='r')||(selec=='R'))
		{
			i=jorActual;
			do{

				volver=mostrar_calendario(tabCalend,i,tabEquipos,sel);
				/*Si se pulsa s, se ven los partidos de la siguiente jornada,
				para ello se aumenta la variable i*/
				if ((volver=='s')||(volver=='S'))
					i++;
				/*Si se pulsa a, se ven los partidos de la anterior jornada,
				para ello se decrementa la variable i*/
				else if ((volver=='a')||(volver=='A'))
					i--;
				/*Si nos pasamos por algun extremo, nos muestra la jornada 1*/
				if (i>NPART*2)
					i=1;
				if (i<=0)
					i=1;

			/*No salimos de aqui hasta pulsar V*/
			}while ((volver!='v')&&(volver!='V'));
		}
/*Si se pulsa J disputamos la jornada*/
		if ((selec=='j')||(selec=='J'))
		{
			jugar(tabEquipos,sel,tabClasif,tabCalend);
			getch();
		}

/*Si se pulsa G guardamos partida*/
		if ((selec=='g')||(selec=='G'))
		{
			guardar_partida(tabClasif,tabCalend,tabEquipos);
			getch();
		}



	}while ((selec!='s')&&(selec!='S'));

}


/*Esta funcion muestra un menu para introducir tu nombre de entrenador y elegir tu
equipo*/
int elegirEquipo()
{

	int sel;
	textcolor(14);
	_setcursortype(_NORMALCURSOR);
	do{
		gotoxy(3,40);
		printf("                                                          ");
		gotoxy(3,40);
		cprintf("Tu nombre de Entrenador:");
		fflush(stdin);
		gets(nomEntrenador);
	}while (nomEntrenador=="");

	do{
		gotoxy(3,41);
		printf("                   ");
		gotoxy(3,41);
		fflush(stdin);
		cprintf("Elige tu equipo:");
		scanf("%d",&sel);
	}while (sel>=NEQ);
	textcolor(7);
	return sel;
}

/*Cuando se llega al final de la temporada se entra a estra a esta funcion
Se muestra el campeon de liga y tu posicion final*/
char fin(final *final)
{
	char fin;
	printf("\n\n------------------------------------------------");
	printf("\nSe ha terminado la liga. Comprate la nueva version");
	printf("\nCampeon de liga = %s",final[0].campeon);
	printf("\nTu posicion final ha sido = %d",final[0].tuequipo);
	getch();
	fin='s';
	return fin;
}
/*Esto es solo para permitir que en cada jornada podamos ver al rival
con el que vamos a jugar*/
int buscar_rival(Jornada *calend,int selec)
{
	int i,riv;

	for (i=1;i<=NEQ/2;i++)
	{
		if(calend[jorActual].part[i].id_local==selec)
			riv=calend[jorActual].part[i].id_visitante;

		if(calend[jorActual].part[i].id_visitante==selec)
			riv=calend[jorActual].part[i].id_local;
	}
	return riv;
}
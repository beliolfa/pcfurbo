/************************** LIBRERIA STRUCT.H *************************************/
/*************Esta libreria solo contiene declaraciones de estructuras*************/
typedef struct {
		char nombre[25];
		char demarca[4];
		int titular;
		int lesionado;
		int moral;
		int calidad;
		int media;
		}Jugador;

typedef struct {
		int res_local;
		int res_visitante;
		int id_local;
		int id_visitante;
		}Partidos;

typedef struct {
		Jugador jug[18];
		char nombre[30];
		int media;
		char estadio[20];
		}Equipo;

typedef struct {
		int puntos;
		int pos;
		}Clasificacion;

typedef struct {
		Partidos part[11];
		}Jornada;

typedef struct{
	char campeon[30];
	int tuequipo;
	}final;

//Declaracion de bibliotecas y constantes
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define MAX 25
//Datos compuestos
typedef char tString[MAX];
//Contenido de los nodos
typedef struct {
	int LU;
	tString nombreAlumno;
	tString apellidoAlumno;
	
}tr_Alumno;
//Tipo de nodo/lista
typedef struct nodo {
	tr_Alumno alumno;
	struct nodo *siguiente;
}t_ListaAlumno;
//Prototipado de las funciones
tr_Alumno ingresarAlumno(tr_Alumno);
void concatenarNombreCompleto();
void inicializarLista();
bool listaVacia(t_ListaAlumno*);
void insAlumno(tr_Alumno);
void insPrimAlumno(tr_Alumno);
void insAlumnoAdelante(tr_Alumno);
void insAlumnoPosk(tr_Alumno, int);
void elimPrimAlumno();
void elimAlumnoPosk(int);
void visualizarAlumnos(t_ListaAlumno*);
int cantAlumnos(t_ListaAlumno*);
void menu();
//Variables globales
t_ListaAlumno *listaAlumnos;
//Funcion Principal
int main() {
	inicializarLista();
	menu();
	system("pause");
return 0;
}
//Implementacion de funciones 
void inicializarLista() {
	listaAlumnos = NULL;
	printf("Lista iniciada\n");
}
bool listaVacia(t_ListaAlumno* pListaAlumnos) {
	return(pListaAlumnos == NULL);
}
tr_Alumno ingresarAlumno(tr_Alumno pAlumno) {
	printf("Ingrese su Libreta Universitaria:");
	scanf("%d", &pAlumno.LU);
	printf("Ingrese su nombre:");
	fflush(stdin);
	scanf("%[^\n]s", &pAlumno.nombreAlumno);
	printf("Ingrese su Apellido:");
	fflush(stdin);
	scanf("%[^\n]s", &pAlumno.apellidoAlumno);
	return pAlumno;
}
void insAlumno(tr_Alumno pAlumno) {
	if(listaVacia(listaAlumnos)){
		insPrimAlumno(pAlumno);
	}else{
		insAlumnoAdelante(pAlumno);
	}
}
void insPrimAlumno(tr_Alumno pAlumno) {
	t_ListaAlumno *nuevoAlumno;
	nuevoAlumno = (t_ListaAlumno*)malloc(sizeof(t_ListaAlumno));
	nuevoAlumno->alumno = pAlumno;
	nuevoAlumno->siguiente = NULL;
	listaAlumnos = nuevoAlumno;
	printf("\nAlumno %s ingresado\n", pAlumno.nombreAlumno);
}
void insAlumnoAdelante(tr_Alumno pAlumno) {
	t_ListaAlumno *nuevoAlumno;
	nuevoAlumno = (t_ListaAlumno*)malloc(sizeof(t_ListaAlumno));
	nuevoAlumno->alumno = pAlumno;
	nuevoAlumno->siguiente = listaAlumnos;
	listaAlumnos = nuevoAlumno;
	printf("\nAlumno %s ingresado al principio\n", pAlumno.nombreAlumno);
}
void insAlumnoPosk(tr_Alumno pAlumno, int pos) {
	t_ListaAlumno *nuevoAlumno;
	t_ListaAlumno *aux;
	int i;
	aux = listaAlumnos;
	for(i=1;i<pos-1;i++) {
		aux=aux->siguiente;
	}
	nuevoAlumno =(t_ListaAlumno*)malloc(sizeof(t_ListaAlumno));
	nuevoAlumno->alumno = pAlumno;
	nuevoAlumno->siguiente = aux->siguiente;
	aux->siguiente = nuevoAlumno;
	if(pos == 4) {
		printf("Se ingreso a %s, %s en la posicion %d\n", pAlumno.nombreAlumno, pAlumno.apellidoAlumno, pos);
	}else{
		if(pos == 2) {
			printf("Se ingreso a %s, %s  %d en la posicion\n", pAlumno.nombreAlumno, pAlumno.apellidoAlumno, pos);
		}
		printf("Se ingreso a %s, %s en la posicion %d\n", pAlumno.nombreAlumno, pAlumno.apellidoAlumno, pos);
	}
	printf("Se ingreso a %s, %s en la posicion %d\n", pAlumno.nombreAlumno, pAlumno.apellidoAlumno, pos);
}
void elimPrimAlumno() {
	if(!listaVacia(listaAlumnos)) {
		t_ListaAlumno *alumnoSuprimir;
		alumnoSuprimir = listaAlumnos;
		listaAlumnos = listaAlumnos->siguiente;
		printf("Se elimino a %s, %s \n", alumnoSuprimir->alumno.apellidoAlumno, alumnoSuprimir->alumno.nombreAlumno);
		free(alumnoSuprimir);
		alumnoSuprimir = NULL;
	}else{
		printf("No hay alumnos para eliminar...\n");
	}
}
void elimAlumnoPosk(int pos) {
	if(!listaVacia(listaAlumnos)) {
		t_ListaAlumno *alumnoSuprimir;
		t_ListaAlumno *aux;
		aux = listaAlumnos;
		int i;
		for(i=1;i<pos-1;i++) {
			aux = aux->siguiente;
		}
		alumnoSuprimir = aux->siguiente;
		aux->siguiente = alumnoSuprimir->siguiente;
		printf("Se elimino a %s, %s de la posicion %d", alumnoSuprimir->alumno.apellidoAlumno, alumnoSuprimir->alumno.nombreAlumno, pos);
		free(alumnoSuprimir);
		alumnoSuprimir = NULL;
	}else{
		printf("No hay alumnos en esa posicion.");
	}
}
void visualizarAlumnos(t_ListaAlumno *pListaAlumnos) {
	t_ListaAlumno *aux;
	aux = pListaAlumnos;
	if(!listaVacia(aux)) {
		printf("\033[1m|APELLIDO | NOMBRE | LIBRETA UNIVERSITARIA |\033[0m\n");
		while(aux != NULL) {
			printf("|\t%s \t    | \t %s \t  |\t%d\t    |\n", aux->alumno.apellidoAlumno, aux->alumno.nombreAlumno, aux->alumno.LU);
			aux = aux->siguiente;
		}
		printf("\n");
	}else{
		printf("No hay alumnos en la lista...\n");
	}
}
int cantAlumnos(t_ListaAlumno* pListaAlumnos) {
	int cantAlumnos = 0;
	if(!listaVacia(pListaAlumnos)) {
		t_ListaAlumno *aux;
		aux = pListaAlumnos;
		while(aux != NULL) {
			aux = aux->siguiente;
			cantAlumnos++;
		}
	}
	return cantAlumnos;
}
void menu() {
	int opcion, pos;
	tr_Alumno pAlumno;
	printf("\nOpciones: 1: Ingresar alumno 2:Ingresar alumno en lugar k 3:Eliminar alumno  4:Eliminar un alumno en alguna posicion k 5:Visualizar 0:Salir");
	printf("\nSeleccione una opcion:");
	scanf("%d", &opcion);
	switch(opcion) {
		case 1:
    		pAlumno = ingresarAlumno(pAlumno);
    		insAlumno(pAlumno); // Insertar el producto en la lista
    		menu();
    							break;
		case 2: 
			printf("Ingrese una posicion:");
			scanf("%d", &pos);
			pAlumno = ingresarAlumno(pAlumno);
			insAlumnoPosk(pAlumno, pos);
			menu();
								break;
		case 3: 
			elimPrimAlumno();
			menu();
								break;
		case 4:
			printf("Ingrese una posicion:");
			scanf("%d", &pos);
			elimAlumnoPosk(pos);
			menu();	
								break;
		case 5: 
			visualizarAlumnos(listaAlumnos);
			menu();
								break;
		default:
			printf("La cantidad de alumnos es:%d...\n", cantAlumnos(listaAlumnos));
								break;
	}
}














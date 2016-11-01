#include <iostream>
#include <stdlib.h>   //rand
#include "carta.h"
#include "ListaConArreglo.h"
#include "Lista.h"
#include "queue.h"
#include "stack.h"

using namespace std;

/**	@brief Funcion crearPalo
*
* Crea un palo de un juego de naipes, guarda la posición en un puntero a un array de objetos tipo carta
*
*/
void crearPalo(Carta* ptrUnPalo){
  Carta dos(2);
  Carta tres(3);
  Carta cuatro(4);
  Carta cinco(5);
  Carta seis(6);
  Carta siete(7);
  Carta ocho(8);
  Carta nueve(9);
  Carta diez(10);
  Carta J(10);
  Carta Q(10);
  Carta K(10);
  Carta A(11);
  Carta arrayPalo[13] = {dos, tres, cuatro, cinco, seis, siete, ocho, nueve, diez, J, Q, K, A};
  for (int carta = 0; carta < 13; carta++) {
    ptrUnPalo[carta] = arrayPalo[carta];
  }
}

/**	@brief Funcion barajearPalo
*
* Llena la pila con 52 objetos tipo carta, de manera aleatorea; si estaba llena primero la vacia.
* Verifica que no hallan mas de 4 cartas iguales.
*/
void barajearPalo(Carta* ptrUnPalo, Stack<Carta>* stackCartas){
  int randCarta;
  int cantCartas[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
  bool seguirBarajeando;

  if (stackCartas->size() != 0) stackCartas->clear();

  for (int i = 0; i < 52; i++) {
    seguirBarajeando = false;
    while (!seguirBarajeando){
      randCarta = rand() % 13; //randCarta in the range 0 to 12
      cantCartas[randCarta]++;
      if (cantCartas[randCarta] > 4) seguirBarajeando = false;
      else seguirBarajeando = true;
    }
    stackCartas->push(ptrUnPalo[randCarta]);
  }
}

/**	@brief Funcion primerEntregaCarta
*
* Retorna la suma de las 2 primeras cartas entregadas, es la primer entrega del juego.
*
*/
int primerEntregaCarta(Stack<Carta>* stackCartas){
  Carta primerCarta = stackCartas->recuperarCarta();
  stackCartas->pop();
  Carta segundaCarta = stackCartas->recuperarCarta();
  stackCartas->pop();
  return (primerCarta.valorCarta + segundaCarta.valorCarta);
}

/**	@brief Funcion entregaCarta
*
* Retorna el valor de la carta entregada. A diferencia de la primer entrega, es que este metodo se llama indefinidamente en la partida, bajo las condiciones del juego.
*
*/
int entregaCarta(Stack<Carta>* stackCartas){
  Carta primerCarta = stackCartas->recuperarCarta();
  stackCartas->pop();
  return (primerCarta.valorCarta);
}

/**	@brief Funcion clasificarClientes
*
* Diferencia o clasifica los clientes por tipo
*
*/
void clasificarClientes(Queue<char>* entrada, Queue<char>* ejecutivos, Queue<char>* trabajadores, Queue<char>* desempleados ){
  // Se vacia la cola de entrada y se llenan las diferentes salas de espera
  while(entrada->size() !=0){
    if(char(entrada->queueArray->recuperar(0)) == 'E'){
      ejecutivos->enQueue('E');
      entrada->deQueue();
    }else if (char(entrada->queueArray->recuperar(0)) == 'T') {
      trabajadores->enQueue('T');
      entrada->deQueue();
    }else if (char(entrada->queueArray->recuperar(0)) == 'D') {
      desempleados->enQueue('D');
      entrada->deQueue();
    }
  }
}

/**	@brief Funcion asignarClientes
*
* Reparte los clientes en las mesas de juego, los toma de la salsa de espera.
*
*/
void asignarClientes(Queue<char>* tipoCliente, ListaConArreglo<char>* mesa){
  while(tipoCliente->size()!=0 && mesa->tam<3){
     mesa->agregar(tipoCliente->queueArray->recuperar(0));
     tipoCliente->deQueue();
  }
}

/**	@brief Funcion partidaInicial
*
* LLama la funcion primerEntregaCarta; ya que esta funcion entrega las dos cartas iniciales en la mesa a cada jugador, independientemente cuantos halla (maximo 3, minimo 1).
*
*/
void partidaInicial(int *cartasClientes, Stack<Carta>* baraja, ListaConArreglo<char>* mesa){
  for(int i = 0; i < mesa->tam; i++)
    cartasClientes[i] = primerEntregaCarta(baraja);
}

/**	@brief Funcion partida
*
* Similar que partidaInicial; tan solo entrega en la mesa de juego a todos los jugadores una unica carta.
*
*/
void partida(int *cartasClientes, Stack<Carta>* baraja, ListaConArreglo<char>* mesa){
  for(int i = 0; i < mesa->tam; i++){
    if(cartasClientes[i] < 19){
      cartasClientes[i] = cartasClientes[i] + entregaCarta(baraja);
    }
  }
}

/**	@brief Funcion salidaJugador
*
* Retorna true si elimino un jugador que ha perdido y deba salir de la mesa
*
*/
bool salidaJugador(int *cartasClientes, ListaConArreglo<char>* mesa){
  bool elimarJugador = false;
  for (int i = 0; i < 3; i++) {

    if(cartasClientes[i] >= 22){
      mesa->eliminarK(i);
      cartasClientes[i] = 0;
      elimarJugador = true;
    }
  }
  return elimarJugador;
}

/**	@brief Funcion imprimirPartida
*
* Imprime el estado de las cartas de los clientes de una mesa
*
*/
void imprimirPartida(int *cartasClientes, ListaConArreglo<char>* mesa){
  for (int i = 0; i < 3; i++)
    cout << "Cliente " << mesa->recuperar(i) << i <<" posee " << " " << cartasClientes[i] << endl;
}

/**	@brief Funcion pararPartida
*
* Retorna un true si una persona pierde o ya no pide mas cartas
*
*/
bool pararPartida(int *cartasClientes){
  int contador = 0;
  for(int i = 0; i < 3; i++) if(cartasClientes[i] > 21) contador++;
  for(int i = 0; i < 3; i++){
    int valor = cartasClientes[i];
    if(valor == 19) return true;
    else if(valor == 20) return true;
    else if(valor == 21) return true;
  }
  if(contador == 3) return true;
  else return false;
}


/**	@brief Funcion ganador
*
* Retorna true si un jugador gano, si tiene 19,20,21 en total
*
*/
bool ganador(int *cartasClientes){
  for(int i = 0; i < 3; i++){
    int valor = cartasClientes[i];
    if(valor == 19) return true;
    else if(valor == 20) return true;
    else if(valor == 21) return true;
  }
  return false;
}

/**	@brief Funcion vaciarCartas
*
* Pone en cero el total de las cartas de los jugadores de una mesa
*
*/
void vaciarCartas(int* cartasClientes){
  cartasClientes[0] = 0;
  cartasClientes[1] = 0;
  cartasClientes[2] = 0;
}

int main(int argc, char const** argv){
            /**Se crean las colas para entrada y 3 salas de espera*/
  /** Cola entrada*/
  ListaConArreglo<char>* entrada = new ListaConArreglo<char>();
  Queue<char>* colaEntrada = new Queue<char>();
  colaEntrada->queueArray = entrada;

  /**Cola Ejecutiva*/
  ListaConArreglo<char>* ejecutivos = new ListaConArreglo<char>();
  Queue<char>* salaEjecutivos = new Queue<char>();
  salaEjecutivos->queueArray = ejecutivos;

  /**Cola trabajadores*/
  ListaConArreglo<char>* trabajadores = new ListaConArreglo<char>();
  Queue<char>* salaTrabajadores= new Queue<char>();
  salaTrabajadores->queueArray = trabajadores;

  /**Cola Desempleados*/
  ListaConArreglo<char>* desempleados = new ListaConArreglo<char>();
  Queue<char>* salaDesempleados = new Queue<char>();
  salaDesempleados->queueArray = desempleados;

  /**Creacion de las Mesas, se posee una convencion*/
  /**mesa1: mesa ejecutivos*/
  /**mesa2: mesa trabajadores*/
  /**mesa3: mesa desempleados*/
  ListaConArreglo<char>* mesa1 = new ListaConArreglo<char>();
  ListaConArreglo<char>* mesa2 = new ListaConArreglo<char>();
  ListaConArreglo<char>* mesa3 = new ListaConArreglo<char>();

  /**Se determina el tamaño del argv[1]*/
  int lenArgv=0;
  while (argv[1][lenArgv]!= '\0'){
    lenArgv= lenArgv+1;
  }
  /**Se llena la cola de entrada con los datos recibidos*/
  for(int cola = 0; cola<lenArgv; cola++){
    colaEntrada->enQueue(argv[1][cola]);
  }

                          /**Se crean las barajas*/
  /**Crea la Stack de cartas con ListaConArreglo, naipes de cartas*/
  ListaConArreglo<Carta>* listaArregloCartasUno = new ListaConArreglo<Carta>();
  Stack<Carta>* barajaUno = new Stack<Carta>();
  barajaUno->pilaConArreglo = listaArregloCartasUno;

  ListaConArreglo<Carta>* listaArregloCartasDos = new ListaConArreglo<Carta>();
  Stack<Carta>* barajaDos = new Stack<Carta>();
  barajaDos->pilaConArreglo = listaArregloCartasDos;

  ListaConArreglo<Carta>* listaArregloCartasTres = new ListaConArreglo<Carta>();
  Stack<Carta>* barajaTres = new Stack<Carta>();
  barajaTres->pilaConArreglo = listaArregloCartasTres;


  /**Puntero a los objetos tipo carta, valores de las cartas en los naipes.
  * Es el machote para indicar los tipos de carta dentro de la baraja.
  */
  Carta* ptrUnPalo = new Carta[13];

  /////////////////////////////////////////////////////////////////////////////
  /**portero clasifica clientes a sus salas de espera*/
  clasificarClientes(colaEntrada, salaEjecutivos, salaTrabajadores, salaDesempleados );
  /**portero ingresa clientes a la mesa1*/
  asignarClientes(salaEjecutivos, mesa1);
  asignarClientes(salaTrabajadores, mesa2);
  asignarClientes(salaDesempleados, mesa3);
  /**se toma baraja y se barajea*/
  crearPalo(ptrUnPalo);

  int* cartasClientesMesa1 = new int[3];  //valores de las cartas de la mesa1
  int* cartasClientesMesa2 = new int[3];
  int* cartasClientesMesa3 = new int[3];
  int* estadoCasino = new int[3];         //verifica los valores de las mesas
  bool pararPartidaMesa1 = false;
  bool pararPartidaMesa2 = false;
  bool pararPartidaMesa3 = false;

  bool pararMesa1 = false;
  bool banderaParadoMesa = false;


  while (!pararMesa1){
    /**Se barajean los naipes en las mesas, existe tension en las mismas*/
    barajearPalo(ptrUnPalo, barajaUno);
    barajearPalo(ptrUnPalo, barajaDos);
    barajearPalo(ptrUnPalo, barajaTres);

    /**Se entregan dos cartas en las mesas*/
    partidaInicial(cartasClientesMesa1, barajaUno, mesa1);
    partidaInicial(cartasClientesMesa2, barajaDos, mesa2);
    partidaInicial(cartasClientesMesa3, barajaTres, mesa3);

    /**Se revisa en las mesas si alguno debe para la partida de antemano*/
    pararPartidaMesa1 = pararPartida(cartasClientesMesa1);
    pararPartidaMesa2 = pararPartida(cartasClientesMesa2);
    pararPartidaMesa3 = pararPartida(cartasClientesMesa3);

    while ( !pararPartidaMesa1 ) {
      partida(cartasClientesMesa1, barajaUno, mesa1);
      pararPartidaMesa1 = pararPartida(cartasClientesMesa1);
    }

    while ( !pararPartidaMesa2 ) {
      partida(cartasClientesMesa2, barajaDos, mesa2);
      pararPartidaMesa2 = pararPartida(cartasClientesMesa2);
    }

    while ( !pararPartidaMesa3 ) {
      partida(cartasClientesMesa3, barajaTres, mesa3);
      pararPartidaMesa3 = pararPartida(cartasClientesMesa3);
    }

    /**Si la sala de espera esta vacia y hay un ganador*/
    if( (banderaParadoMesa == true) && ganador(cartasClientesMesa1) ){
      cout << "Cliente " << mesa1->recuperar(0) << 0 <<" posee " << " " << cartasClientesMesa1[0] << endl;
      cout << "Cliente " << mesa1->recuperar(1) << 1 <<" posee " << " " << cartasClientesMesa1[1] << endl;
      cout << "Cliente " << mesa1->recuperar(2) << 2 <<" posee " << " " << cartasClientesMesa1[2] << endl;
      pararMesa1 = true;
    }
    /**Revisar si se elimino a alguien para agregarlo, si no se reinicia las partidas*/
    /**En mesa1*/
    if( salidaJugador(cartasClientesMesa1, mesa1) == true ){
      asignarClientes(salaEjecutivos, mesa1);
      cout << "\n***SE INGRESA EJECUTIVOS*** : "  << salaEjecutivos->size() << "\n" << endl;
      if(salaEjecutivos->size() == 0) estadoCasino[0] = 1;
    }
    else{
      cout << "\nSE REINICIA LA PARTIDA EN MESA: " << 1 << "\n" <<endl;
    }
    /**En mesa2*/
    if( salidaJugador(cartasClientesMesa2, mesa2) == true ){
      asignarClientes(salaTrabajadores, mesa2);
      cout << "\n***SE INGRESA TRABAJADOR*** : "  << salaTrabajadores->size() << "\n" << endl;
      if(salaTrabajadores->size() == 0) estadoCasino[1] = 1;
    }
    else{
      cout << "\nSE REINICIA LA PARTIDA EN MESA: " << 2 << "\n" <<endl;
    }
    /**En mesa3*/
    if( salidaJugador(cartasClientesMesa3, mesa3) == true ){
      asignarClientes(salaDesempleados, mesa3);
      cout << "\n***SE INGRESA DESEMPLEADO*** : "  << salaDesempleados->size() << "\n" << endl;
      if(salaDesempleados->size() == 0) estadoCasino[2] = 2;
    }
    else{
      cout << "\nSE REINICIA LA PARTIDA EN MESA: " << 3 << "\n" <<endl;
    }

    cout << "Mesa 1\n" << endl;
    imprimirPartida(cartasClientesMesa1, mesa1);
    cout << "\nMesa 2\n" << endl;
    imprimirPartida(cartasClientesMesa2, mesa2);
    cout << "\nMesa 3\n" << endl;
    imprimirPartida(cartasClientesMesa3, mesa3);
    vaciarCartas(cartasClientesMesa1);
    vaciarCartas(cartasClientesMesa2);
    vaciarCartas(cartasClientesMesa3);
  }
  /////////////////////////////////////////////////////////////////////////////


  /**	@brief Destructores y delete
  *
  * Se liberan los punteros en general.
  */
  salaDesempleados->~Queue();
  salaTrabajadores->~Queue();
  salaEjecutivos->~Queue();
  colaEntrada->~Queue();
  mesa1->~ListaConArreglo();
  mesa2->~ListaConArreglo();
  mesa3->~ListaConArreglo();
  delete [] ptrUnPalo;
  delete cartasClientesMesa1;
  delete cartasClientesMesa2;
  delete cartasClientesMesa3;
  delete estadoCasino;
  return 0;
}

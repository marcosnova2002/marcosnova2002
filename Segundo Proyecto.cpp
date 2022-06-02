#include<iostream>
#include <math.h>
#include<sstream>

using namespace std;

class Articulo {
private:
	string id;
	string nombre;
	int precio;
	int existencias;
	double ventas;
	double peso;
	double ganancia;
	int mnmexistencia;
public:
	Articulo();
	Articulo(string, string, int, int, double, double, double, int);
	virtual ~Articulo();
	
	void setId(string);
	void setNombre(string);
	void setPrecio(int);
	void setExistencias(int);
	void setPosArt(string);
	void setVentas(double);
	void setPeso(double);
	void setGanancia(double);
	void setMnmexistencia(int);
	
	string getId();
	string getNombre();
	int getPrecio();
	int getExistencias();
	string getPosArticulo();
	double getVentas();
	double getPeso();
	double getGanancia();
	int getMnmexistencia();
	string toString();
};

Articulo::Articulo() {
	id = "";
	nombre = "";
	precio = 0;
	existencias = 0;
	ventas = 0;
	peso = 0;
	ganancia = 0.0;
	mnmexistencia = 0;
}

Articulo::Articulo(string iid, string nom, int pr, int exi, double ven, double pess, double gann, int mnexi) {
	id = iid;
	nombre = nom;
	precio = pr;
	existencias = exi;
	ventas = ven;
	peso = pess;
	ganancia = gann;
	mnmexistencia = mnexi;
}

Articulo::~Articulo() {
}



void Articulo::setId(string iid) { id = iid; }
void Articulo::setNombre(string nom) { nombre = nom; }
void Articulo::setPrecio(int pr) { precio = pr; }
void Articulo::setExistencias(int exi) { existencias = exi; }
void Articulo::setVentas(double ven) {ventas == ven;}
void Articulo::setPeso(double pess) {peso == pess;}
void Articulo::setGanancia(double gann) {ganancia == gann;}
void Articulo::setMnmexistencia(int mnexi) {mnmexistencia == mnexi;} 

string Articulo::getId() { return id; }
string Articulo::getNombre() { return nombre; }
int Articulo::getPrecio() { return precio; }
int Articulo::getExistencias() {return existencias;}
double Articulo::getVentas() {return ventas;}
double Articulo::getPeso()	{return peso;}
double Articulo::getGanancia() {return ganancia;}
int Articulo::getMnmexistencia() {return mnmexistencia;}

string Articulo::toString() { 
	stringstream s;
	s << "--------Producto------" << endl
		<< " Codigo = " << id << endl
		<< " Nombre = " << nombre << endl
		<< " Precio base = " << precio << endl
		<< " Existencias"<< existencias << endl
		<< " Kilogramos = " << peso << endl
		<< " ganancia = " << ganancia << endl
		<< " minima existencia = " << mnmexistencia << endl;
	return s.str();
}

class SuperContenedorV {
private:
	Articulo vec[199];
	int cantidad;
	int tamano;
	string posicion;
public: 
	SuperContenedorV();
	virtual ~SuperContenedorV();
	
	int getCantidad();
	int getTamano();
	
	string toString();
	
	bool ingresaNuevoArticulo();
	
	double promedioPrecio();
	void ordenarAscPorPrecio();
	void ordenarAscPorId();
	void ordenarAscPorNombre();
	void laDeMayorPrecio();
	void imprimePrecMayoresDe();
	void eliminarArtPorSuId();
	void productoDeMayorValor();
	void productoConMayorExistencia();
	void cuantosKgsSeHanVendidoEnGeneral();
	void cuantosKgsSeHanVendidoDelProducto();
	void graficoDeVentasDeLos15ProductsMenosVendidos();
	void ventaDeProductos();
	void cantDeProductosBajosDeExistencia();
	void imprimirProductosBajosDeExistencia();
	void cuantasUnidadesSeHanVendidoDelProducto();
	
};

SuperContenedorV::SuperContenedorV() {
	cantidad = 0; 
	tamano = 199; 
}

SuperContenedorV::~SuperContenedorV() {
}

int SuperContenedorV::getCantidad() { return cantidad; }
int SuperContenedorV::getTamano() { return tamano; }

string SuperContenedorV::toString() {
	stringstream s;
	for (int i = 0; i < cantidad; i++)
		s << vec[i].toString() << endl;
	return s.str();
}

bool SuperContenedorV::ingresaNuevoArticulo() {
	string idd, nom;
	int prec, exist, minexist, vent;
	double pesso, ganan;
	if (cantidad < tamano) {
		cout << "--INGRESAR LOS DATOS DEL PRODUCTO--" << endl;
		cout << "--Ingrese el id del producto-- ";
		cin >> idd;
		cout << "--Ingrese el nombre del producto-- ";
		cin >> nom;
		cout << "--Ingrese el precio base del producto-- ";
		cin >> prec;
		cout << "--Inregese las existencias del producto-- ";
		cin >> exist;
		cout << "--Ingrese el peso del producto-- ";
		cin >> pesso;
		cout << "--Ingrese el porcentaje de ganancia del producto(entre 1 y 0)-- ";
		cin >> ganan;
		cout << "--Ingrese la existencia minima del producto-- ";
		cin >> minexist;
		cout << "--Ingrese el numero de productos vendidos-- ";
		cin >> vent;
		vec[cantidad].setId(idd);
		vec[cantidad].setNombre(nom);
		vec[cantidad].setPrecio(prec);
		vec[cantidad].setExistencias(exist); 
		vec[cantidad].setPeso(pesso);
		vec[cantidad].setGanancia(ganan);
		vec[cantidad].setMnmexistencia(minexist);
		vec[cantidad].setVentas(vent);
		
		cantidad++;
		return true;
	}
	else {
		cout << "No hay espacio en el vector para m�s productos.." << endl;
		return false;
	}
}


void SuperContenedorV::eliminarArtPorSuId(){
	string cod;
	cout<<"ingrese el id del producto"<<endl;
	cin >> cod;
	
	for (int i = 0; i < cantidad; i++){
		if (vec[i].getId() == cod) {
			for (int j = i; j<cantidad; j++){
				vec[j]=vec[j+1];
				}
			cantidad --;
		}
	}
}

void SuperContenedorV::ordenarAscPorPrecio() {
	Articulo aux;
	for (int i = 0; i < cantidad; i++) { 
		for (int j = i + 1; j < cantidad; j++) { 
			if (vec[i].getPrecio() > vec[j].getPrecio()) {
				aux = vec[i];
				vec[i] = vec[j];
				vec[j] = aux;
			}
		}
	}
}
	
void SuperContenedorV::productoDeMayorValor(){
	int pos;
	float mayor=0;
	
	for(int i=0; i< cantidad; i++){
		if (vec[i].getPrecio() > mayor){
			mayor = vec[i].getPrecio();
		pos = i;
		}
	}
	cout<<vec[pos].getId()<<endl;
	cout<<vec[pos].getNombre()<<endl;
	cout<<vec[pos].getPrecio()<<endl;
}

void SuperContenedorV::productoConMayorExistencia(){
	int pos;
	float mayor=0;
	
	for(int i=0; i< cantidad; i++){
		if (vec[i].getExistencias() > mayor){
			mayor = vec[i].getExistencias();
			pos = i;
		}
	}
	cout<<vec[pos].getId()<<endl;
	cout<<vec[pos].getNombre()<<endl;
	cout<<vec[pos].getExistencias()<<endl;
}



void SuperContenedorV::ordenarAscPorId() {
	Articulo aux;
	for (int i = 0; i < cantidad; i++) { 
		for (int j = i + 1; j < cantidad; j++) { 
			if (vec[i].getId() > vec[j].getId()) {
				aux = vec[i];
				vec[i] = vec[j];
				vec[j] = aux;
			}
		}
	}
}

void SuperContenedorV::cuantosKgsSeHanVendidoEnGeneral() {
	int KgsVG = 0;
		for (int i=1; i<cantidad; i++){
			KgsVG += (vec[i]).getPeso()*(vec[i]).getVentas();
	}
		cout<<KgsVG<<endl;
}


void SuperContenedorV::cuantosKgsSeHanVendidoDelProducto() {
	int KgsVenProd, posicion;
	string cod;
	cout<<"ingrese el id del producto"<<endl;
	cin >> cod;
	
	for (int i = 0; i < cantidad; i++){
		if (vec[i].getId() == cod) {
			posicion = i;
			KgsVenProd= vec[posicion].getVentas() * vec[posicion].getPeso();
			}
		cout<<KgsVenProd;
		}
}


void SuperContenedorV::graficoDeVentasDeLos15ProductsMenosVendidos(){

}

void SuperContenedorV::cantDeProductosBajosDeExistencia(){
	int num;
	
	for(int i=0; i< cantidad; i++){
		if (vec[i].getExistencias() < vec[i].getMnmexistencia()){
			num++;
		}
		cout<<"la cantidad de productos bajos de existencias son: ";
		cout<<num;
	}	
}

void SuperContenedorV::imprimirProductosBajosDeExistencia(){
	Articulo aux;
	string num1,nomb;
	int pos = 4;
	for (int i = 0; i < cantidad; i++) { 
		for (int j = i + 1; j < cantidad; j++) { 
			if (vec[i].getId() > vec[j].getId()) {
				aux = vec[j];
				vec[j] = vec[i];
				vec[i] = aux;
			}
			for (int i =0; i < pos; i++) {
				num1=vec[i].getNombre();
				nomb=vec[i].getId();
				cout<<nomb<<endl;
				cout<<num1<<endl;	
				
			}
		}
	}
}

void SuperContenedorV::cuantasUnidadesSeHanVendidoDelProducto(){
	string cod;
	int pos;
	cout<<"ingrese el id del producto"<<endl;
	cin >> cod;
	for (int i = 0; i < cantidad; i++){
		if (vec[i].getId() == cod) {
			pos = i;
			}
			cout<<vec[pos].getVentas();
		}
}


int menu();
void ingresaArticulo(SuperContenedorV&);
void eliminarId(SuperContenedorV&);
void ordenarAcPorId(SuperContenedorV&);
void proDeMayVal(SuperContenedorV&);
void proDeMayExist(SuperContenedorV&);
void ordernarId(SuperContenedorV&);
void imprimirContenedor(SuperContenedorV&);
void imprCantDeProdBajosDeExist(SuperContenedorV&);
void imprimirProdBajosDeExist(SuperContenedorV&);
void ordenaAscendente(SuperContenedorV&);
void KgsVendDelProd(SuperContenedorV&);
void KgsVendEnGnl(SuperContenedorV&);
void uniSVenDelProd(SuperContenedorV);
void logicaDeControl(int, string, SuperContenedorV&);


int main() {
	int op;
	string valor;
	SuperContenedorV SCONV;
	do {
		op = menu();
		logicaDeControl(op, valor , SCONV);
		system("pause");
	} while (op != 20);
	
	system("pause");
	return 0;
}

int menu() {
	int op;
	system("cls");
	cout << endl << endl;
	cout << "---------MENU DE OPCIONES-----------" << endl;
	cout << "-1- Ingresar un producto." << endl;
	cout << "-2- Eliminar un producto." << endl;
	cout << "-3- Desplegar el producto de mayor precio" << endl;
	cout << "-4- Desplegar el producto de mayor existencias" << endl;
	cout << "-5- Ordenar los productos por codigo" << endl;
	cout << "-6- desplegar todos los productos" << endl;
	cout << "-7- Desplegar la cantidad los productos bajos de existencias" << endl;
	cout << "-8- Desplegar los productos bajos de existencias " << endl;
	cout << "-9- Desplegar el total de kilogramos de todos los productos vendidos" << endl;
	cout << "-10- Desplegar el total de Kilogramos vendidos de un producto." << endl;
	cout << "-11- Desplegar la lista de productos que son m�s costosos que un producto dado." << endl;
	cout << "-12- Desplegar la cantidad de unidades vendidas de un producto en particular." << endl;
	cout << "-13- Desplegar el Costo del Inventario." << endl;
	cout << "-14- Desplegar el Costo de las Ventas." << endl;
	cout << "-15- Desplegar el Valor de las Ventas." << endl;
	cout << "-16- Desplegar la ganancia total del supermercado por concepto de ventas." << endl;
	cout << "-17- Desplegar el gr�fico de las ventas de los 5 productos m�s vendidos." << endl;
	cout << "-18- Desplegar el gr�fico de las ventas de los 5 productos menos vendidos." << endl;
	cout << "-19- Desplegar el promedio de precios de venta de los productos vendidos con ganancia." << endl;
	cout << "-20- Salir." << endl;
	cout << "------------------------------------" << endl;
	cout << "Digite una opcion...";
	cin >> op;
	return op;
}

void ingresaArticulo(SuperContenedorV& C) {
	cout << " 1- Ingresar un producto." << endl;
	C.ingresaNuevoArticulo();
}

void eliminarId(SuperContenedorV& C){
	cout << "2- Eliminar un producto por su Id.";
	C.eliminarArtPorSuId();
	cout << "Producto eliminado" << endl;
}

void proDeMayVal(SuperContenedorV& C) {
	cout << " 3- Ordenar asc por precio." << endl;
	C.productoDeMayorValor();
}

void proDeMayExist(SuperContenedorV& C){
	cout << "-4- Desplegar el producto de mayor existencias" <<endl;
	C.productoConMayorExistencia();	
}

void ordenarAcPorId(SuperContenedorV& C){
	cout << "-5- Ordenar los productos por codigo" << endl;
	C.ordenarAscPorId();
}
void imprimirContenedor(SuperContenedorV& C) {
	cout << " 6- Imprimir el contenedor." << endl;
	cout << C.toString() << endl;
}
void imprCantDeProdBajosDeExist(SuperContenedorV& C){
	cout << "-7- Desplegar la cantidad los productos bajos de existencias " << endl;	
	C.cantDeProductosBajosDeExistencia();
}
void imprimirProdBajosDeExist(SuperContenedorV& C){
	cout << "-8- Desplegar los productos bajos de existencias " << endl;
	C.imprimirProductosBajosDeExistencia();
}
void KgsVendEnGnl(SuperContenedorV& C){
	cout << "-9- Desplegar el total de kilogramos de todos los productos vendidos " << endl;
	C.cuantosKgsSeHanVendidoEnGeneral ();
}
void KgsVendDelProd(SuperContenedorV& C){
	cout << "-10- Desplegar el total de Kilogramos vendidos de un producto." << endl;
	C.cuantosKgsSeHanVendidoDelProducto();
}
void uniSVenDelProd(SuperContenedorV C){
	cout << "-12- Desplegar la cantidad de unidades vendidas de un producto en particular." << endl;
	C.cuantasUnidadesSeHanVendidoDelProducto();
}

void logicaDeControl(int op, string valor, SuperContenedorV& C) {
	switch (op) {
	case 1: {
		ingresaArticulo(C);
	}break;
	
	case 2: {
		eliminarId(C);
	}break;

	case 3: {
		proDeMayVal(C);
	}break;
	
	case 4: {
		proDeMayExist(C);
	}break;
	case 5: {
		ordenarAcPorId(C);
	}break;
	case 6: {
		imprimirContenedor(C);
	}break;
	case 7: {
		imprCantDeProdBajosDeExist(C);
	}break;
	case 8: {
		imprimirProdBajosDeExist(C);
	}break;
	case 9: {
		KgsVendEnGnl(C);
	}break;
	case 10: {
		KgsVendDelProd(C);
	}break;
	case 11: {
		
	}break;
	case 12: {
		uniSVenDelProd(C);
	}break;
	case 13: {
		
	}break;
	case 14: {
		
	}break;
	case 15: {
		
	}break;
	case 16: {
		
	}break;
	case 17: {
		
	}break;
	case 18: {
		
	}break;
	case 19: {
		
	}break;
case 20: {
	cout << " 20- Salir." << endl;
}
	};
}

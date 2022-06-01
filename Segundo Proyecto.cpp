#include<iostream>
#include<sstream>

using namespace std;

class Articulo {
private:
	string id;
	string nombre;
	int precio;
	int existencias;
public:
	Articulo();
	Articulo(string, string, int, int);
	virtual ~Articulo();
	
	void setId(string);
	void setNombre(string);
	void setPrecio(int);
	void setExistencias(int);
	void setPosArt(string);
	

	string getId();
	string getNombre();
	int getPrecio();
	int getExistencias();
	string getPosArticulo();

	string toString();
};

Articulo::Articulo() {
	id = "";
	nombre = "";
	precio = 0;
	existencias = 0;
}

Articulo::Articulo(string iid, string nom, int pr, int exi) {
	id = iid;
	nombre = nom;
	precio = pr;
	existencias = exi;
}

Articulo::~Articulo() {
}



void Articulo::setId(string iid) { id = iid; }
void Articulo::setNombre(string nom) { nombre = nom; }
void Articulo::setPrecio(int pr) { precio = pr; }
void Articulo::setExistencias(int exi) { existencias = exi; }

string Articulo::getId() { return id; }
string Articulo::getNombre() { return nombre; }
int Articulo::getPrecio() { return precio; }
int Articulo::getExistencias() {return existencias;}

string Articulo::toString() { 
	stringstream s;
	s << "--------Producto------" << endl
		<< " iD = " << id << endl
		<< " Nombre = " << nombre << endl
		<< " Precio = " << precio << endl
		<< " Existencias"<< existencias << endl;
	return s.str();
}

class SuperContenedorV {
private:
	Articulo vec[200];
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
	bool ingresaNuevoArticulo(Articulo x);
	
	double promedioPrecio();
	void ordenarAscPorPrecio();
	void ordenarAscPorNombre();
	void laDeMayorPrecio();
	void imprimePrecMayoresDe();
	void eliminarArtPorSuId();
	
	
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
	int prec, exist;
	if (cantidad < tamano) {
		cout << "--INGRESAR LOS DATOS DEL PRODUCTO--" << endl;
		cout << "Ingrese el id del producto...";
		cin >> idd;
		cout << "Ingrese el nombre del producto...";
		cin >> nom;
		cout << "Ingrese el precio del producto...";
		cin >> prec;
		cout << "inregese las existencias del producto..." <<endl;
		cin >> exist;
		
		vec[cantidad].setId(idd);
		vec[cantidad].setNombre(nom);
		vec[cantidad].setPrecio(prec);
		vec[cantidad].setExistencias(exist); 
		cantidad++;
		return true;
	}
	else {
		cout << "No hay espacio en el vector para m�s productos.." << endl;
		return false;
	}
}

bool SuperContenedorV::ingresaNuevoArticulo(Articulo pE) {
	string idd, nom;
	int prec;
	if (cantidad < getTamano()) { 
		idd= pE.getId();
		nom = pE.getNombre();
		prec = pE.getPrecio();
		vec[cantidad].setId(idd);
		vec[cantidad].setNombre(nom);
		vec[cantidad].setPrecio(prec);
		
		cantidad++;
		return true;
	}
	else {
		cout << "No ha espacio en el vector de productos." << endl;
		return false;
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

void SuperContenedorV::ordenarAscPorNombre() {
	Articulo aux;
	for (int i = 0; i < cantidad; i++) { 
		for (int j = i + 1; j < cantidad; j++) { 
			if (vec[i].getNombre() > vec[j].getNombre()) {
				aux = vec[i];
				vec[i] = vec[j];
				vec[j] = aux;
			}
		}
	}
}

void SuperContenedorV::laDeMayorPrecio() {
	
	Articulo aux;
	for (int i = 0; i < cantidad; i++) { 
		for (int j = i + 1; j < cantidad; j++) { 
			if (vec[i].getPrecio() < vec[j].getPrecio()) {
				aux = vec[i];
				vec[i] = vec[j];
				vec[j] = aux;
			}
		}
	}
}
	
//void SuperContenedorV::proDeMayExist();{
//	
//	int n_articulos, valM=0;
//	float mayor=0;
//	cout<<"Digite el n�mero de art�culos:"<<
//		cin>>n_articulos>>endl;
//	for(int i=0; i<n_articulos; i++){
//		cout<<i+1<<"Digite su art�culo:";
//		cin>>(art[i].art�culo,20,�\n�)>>endl;
//		cout<<i+1<<�Digite su valor: �;
//		cin>>art[i].valor;
//		if (art[i].valor > mayor){
//			mayor = art[i].valor;
//			posM = i;
//		}
//	
//}

//void SuperContenedorV::eliminarArtPorSuId()		{    
//	string cod;
//	cout<< endl;
//	cout<<" Ingrese el id del articulo que desea eliminar"<<endl;
//	cin>>cod;
//	for (int i = 0; i < cantidad; i++)
//		if(vec[i].getId() == cod) {
//		vec[i].setId("");
//		vec[i].setNombre("");
//		vec[i].setPrecio(0);
//		vec[i].setExistencias(0);
//	}
//		cantidad = -1;
//}
//	


int menu();
void ingresaArticulo(SuperContenedorV&);
void eliminarId(SuperContenedorV&);
void proDeMayVal(SuperContenedorV&);
void proDeMayExist(SuperContenedorV&);
void ordernarId(SuperContenedorV&);
void imprimirContenedor(SuperContenedorV&);
void imprCantDeProdBajosDeExist(SuperContenedorV&);

void ordenaAscendente(SuperContenedorV&);

void desplegProdMayQue(SuperContenedorV&);
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

//void eliminarId(SuperContenedorV& C){
//	cout << "2- Eliminar un producto por su Id.";
//	C.eliminarArtPorSuId();
//	cout << "Producto eliminado" << endl;
//}

void ordenaAscendente(SuperContenedorV& C) {
	cout << " 3- Ordenar asc por precio." << endl;
	C.ordenarAscPorPrecio();
	C.laDeMayorPrecio();
	cout << "LISTO - ORDENADO" << endl;
}

void proDeMayVal(SuperContenedorV& C){
	cout << "-4- Desplegar el producto de mayor existencias" <<endl;
		
}
void
	
	
void imprimirContenedor(SuperContenedorV& C) {
	cout << " 6- Imprimir el contenedor." << endl;
	cout << C.toString() << endl;
}
void imprCantDeProdBajosDeExist(SuperContenedorV C);


//void desplegProdMayQue(SuperContenedorV& C){
//	cout << " 11- Desplegar la lista de productos que son m�s costosos que un producto dado." <<endl;
//	cout << C.imprimePrecMayoresDe();
//}

void logicaDeControl(int op, string valor, SuperContenedorV& C) {
	switch (op) {
	case 1: {
		ingresaArticulo(C);
	}break;
	
//	case 2: {
//		eliminarId(C);
//	}break;

	case 3: {
		proDeMayVal(C);
		imprimirContenedor(C);
	}break;
	
	case 4: {
		
	}break;
	case 5: {
		
		
		
	}break;
	case 6: {
		imprimirContenedor(C);
	}break;
	case 7: {
		
	}break;
case 20: {
	cout << " 20- Salir." << endl;
}
	};
}

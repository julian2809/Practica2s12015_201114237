struct nodo
{
int dato;
int fe;
struc nodo *izdo, *dcho;
};
typedef struct nodo Nodo;

void rotacionII(Nodo** n, Nodo* n1)
{
 (*n)-> izdo = n1-> dcho;
 n1-> dcho = (*n);
 if (n1->fe==-1)
{
 (*n) -> fe=0;
  n1->fe=0;
}
else
{
 (*n) -> fe =-1;
 n1->fe=1;
}
(n)=n1;
}

void rotacionDD(Nodo** n, Nodo*n1)
{
	(*n)->dcho=n1->izdo;
	n1->izdo=(*n);
	if (n1->fe==1)
	{
		(*n)->fe=0;
		n1->fe=0;
	}
	else
	{
		(*n)->fe=1;
		n1->fe=-1;
	}
	(*n)=n1;
}

void rotacionID(Nodo** n, Nodo*n1)
{
	Nodo * n2;
	n2 = n2->dcho;
	(*n)->izdo=n2->dcho;
	n2->dcho=*n;
	n1->dcho=n2->izdo;
	n2->izdo = n1;
	if (n2->fe==1)
		n1->fe=-1;
	else
		n1->fe=0;
	if (n2->fe==-1)
		(*n)->fe=1;
	else
		(*n)->fe=0;
	n2->fe=0;
	(*n)=n2;
}

void rotacionDI(Nodo **n,Nodo *n1)
{
	Nodo *n2;
	n2=n1->izdo;
	(*n)->dcho=n2->izdo;
	n2->izdo=*n;
	n1->izdo=n2->dcho;
	n2->dcho=n1;
	if(n2->fe==1)
		(*n)->fe=-1;
	else
		(*n) -> fe =0;
	if (n2-> fe == -1)
		n1-> fe =1;
	else 
		n1-> fe =0;
	n2 -> fe =0;
	(*n) = n2;
}

void insertarEquilibrado (Nodo ** raiz, int clave, int* h)
{
}

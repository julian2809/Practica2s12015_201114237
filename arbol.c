//#include <iostream>
#include <stdlib.h>

struct nodo
{
int dato;
int fe;
struct nodo *izdo, *dcho;
};
typedef struct nodo Nodo;

Nodo* crearNodo(int x)
{
 Nodo *a;
 a = (Nodo*) malloc (sizeof (Nodo));
 a->dato=x;
 a->dcho=a->izdo=NULL;
 a->fe=0;
 return a;
}
void ordBurbuja(int *a[], int n){
    int interruptor=1;
    int pasada j;
    for (pasada =0; pasada < n-1 && interruptor; pasada++)
    {
        interruptor=0;
        for (j=0; j<n-pasada-1;j++)
            if (a[j]>a[j+1])
            {
                int aux;
                interruptor =1;
                aux=a[j];
                a[j]=a[j+1];
                a[j+1]=aux;
            }
    }
}

void quicksort (int *a[], int primero, int ultimo){
    int i,j,central;
    int pivote;
    central = (primero + ultimo)/2;
    pivote=a[central];
    i=primero;
    j=ultimo;
    
    do{
        while (a[i]<pivote) i++;
        
        while (a[j]>pivote) j--;
        if  (i<=j)
        {
            int tmp;
            tmp=a[i];
            a[i]=a[j];
            a[j]=tmp;
            i++;
            j--;
        }
    }while (i<=j);
    
    if (primero <j)
        quicksort(a,primero,j);
    
    if (i<ultimo)
        quicksort(a,i,ultimo);
}

Nodo* buscar (Nodo* raiz, int buscado)
{
    if (!raiz)
        return 0;
    else if (buscado==raiz->dato)
        return raiz;
    else if (buscado < raiz->dato)
        return buscar (raiz->izdo, buscado);
    else
        return buscar (raiz->dcho, buscado);
}

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
(*n)=n1;
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
    n2 = n1->dcho;
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
    Nodo *n1;
    if (!(*raiz))
    {
        *raiz=crearNodo(clave);
        *h=1;
    }
    else if (clave<(*raiz) -> dato)
    {
        insertarEquilibrado(&((*raiz)->izdo),clave, h);
        if (*h)
        {
            switch((*raiz)->fe)
            {
                 case 1: (*raiz)->fe=0;
                (*h) =0;
                break;

                case 0: (*raiz)->fe=-1;
                break;

                case -1:
                n1=(*raiz) -> izdo;
                if (n1->fe==-1)
                    rotacionII(raiz,n1);
                else
                    rotacionID(raiz,n1);
                (*h)=0;
            }
        }
    }
    else if (clave > (*raiz)->dato)
    {
        insertarEquilibrado(&((*raiz)->dcho),clave,h);

        if (*h)
        {
            switch((*raiz)->fe)
            {
                case 1:
                n1=(*raiz)->dcho;
                if (n1->fe==1)
                    rotacionDD(raiz,n1);
                else
                    rotacionDI(raiz,n1);
                (*h)=0;
                break;

                case 0: (*raiz)->fe=1;
                break;

                case -1:(*raiz)->fe=0;
                (*h)=0;
                break;

            }
        }
    }
    else
    {
        //puts("Clave repetida");
        (*h)=0;
    }
}

void equilibrar1(Nodo** n,int* cambiaAltura)
{
    Nodo* n1;
    switch ((*n)->fe)
    {
        case -1: (*n)->fe=0;
            break;
        case 0: (*n)->fe=1;
            *cambiaAltura=0;
            break;
        case 1:
            n1=(*n)->dcho;
            if (n1->fe>=0)
            {
                if (n1->fe==0)
                    *cambiaAltura=0;
                rotacionDD(n,n1);
            }
            else
                rotacionDI(n,n1);
            break;
    }
}

void equilibrar2(Nodo** n, int* cambiaAltura)
{
    Nodo *n1;
    switch ((*n)->fe)
    {
        case -1:
            n1=(*n)->izdo;
            if (n1->fe <=0)
            {
                if (n1->fe==0)
                    *cambiaAltura=0;
                rotacionII(n,n1);
            }
            else
                rotacionID(n,n1);
            break;
        case 0: (*n)->fe=-1;
                        *cambiaAltura=0;
                        break;
        case 1: (*n)->fe=0;
                    break;
    }
}

void reemplazar(Nodo** n, Nodo** act, int * cambiarAltura)
{
    if ((*act)->dcho)
    {
        reemplazar(n,&((*act)->dcho),cambiarAltura);
        if (*cambiarAltura)
            equilibrar2(act,cambiarAltura);
    }
    else
    {
        (*n)->dato = (*act)->dato;
        (*n)=*act;
        (*act)=(*act)->izdo;
        *cambiarAltura=1;
    }
}

void borrarBalanceado (Nodo** raiz, int clave, int* cambiaAltura)
{
    if (!(*raiz))
    {
        //puts("!! Nodo no encontrado !!");
        *cambiaAltura=0;
    }
    else if (clave<(*raiz)->dato)
    {
        borrarBalanceado(&((*raiz)->izdo),clave,cambiaAltura);
        if (*cambiaAltura)
            equilibrar2(raiz,cambiaAltura);
    }
    else
    {
        Nodo* q;
        q=(*raiz);

        if(q->izdo==NULL)
        {
            (*raiz)=q->dcho;
            *cambiaAltura=1;
        }
        else if (q->dcho==NULL)
        {
            (*raiz)=q->izdo;
            *cambiaAltura=1;
        }
        else
        {
            reemplazar(&q,&(q->izdo),cambiaAltura);
            if (*cambiaAltura)
                equilibrar1(raiz,cambiaAltura);
        }
        free(q);
    }
}

#include <iostream>
#include <bits/stdc++.h>
#include <list>

using namespace std;

class Avocat
{
protected:
    int cod;
    string nume;
    int nr_procese;
    int *vector_procese;    ///initializarea parametrilor
private:
public:

    Avocat(int, string, int);
    int get_nr_procese() const  ///get_nr_procese ~ nr_procese
    {
        return nr_procese;
    }

    virtual void citire(istream &in);       ///functiile virtuale care urmeaza sa fie rescrise in Avocat_Oficiu
    virtual void afisare(ostream &out);     ///functiile virtuale care urmeaza sa fie rescrise in Avocat_Oficiu


    friend istream& operator>>(istream& in, Avocat&); ///supraincarcarea operatorului de citire
    friend ostream& operator<<(ostream& out, Avocat&);  ///supraincarcarea operatorului de afisare

    bool operator<(Avocat &a)   ///supraincarcarea operatorului de comparare
    {
        return nr_procese<a.get_nr_procese();
    }
};

Avocat::Avocat(int C=0, string N="", int P=0) ///definim Avocat
{
    cod=C;
    nume=N;
    nr_procese=P;
}


void Avocat::citire(istream& in) ///citire
{
    cout<<"Introduceti codul avocatului: ";
    in>>cod;
    cout<<"Introduceti numele avocatului ";
    in>>nume;
    cout<<"Introduceti numar procese: ";
    in>>nr_procese;
}

void Avocat::afisare(ostream &out)  ///afisare
{
    out<<"Codul avocatului: "<<cod<<"\n";
    out<<"Numele avocatului: "<<nume<<"\n";
    out<<"Numarul total de procese: "<<nr_procese<<"\n";
}

istream& operator>>(istream& in, Avocat& f) ///citire componente f
{
    f.citire(in);
    return in;
}
ostream& operator<<(ostream& out, Avocat& f) ///afisare componente f
{
    f.afisare(out);
    return out;
}


class Avocat_Oficiu:public Avocat
{
public:
    string nume_client;
    int durata;         ///accesarea functiilor Avocat prin upcasting
    Avocat_Oficiu(int C=0,string N="",int P=0):Avocat(C,N,P)  ///definirea noilor caracteristici
    {
        nume_client="";
        durata=0;
    }
    void citire(istream &in);
    void afisare(ostream &out);

    friend istream& operator>>(istream& in, Avocat_Oficiu&);
    friend ostream& operator<<(ostream& out, Avocat_Oficiu&);


};

void Avocat_Oficiu::afisare(ostream &out)
{
    Avocat::afisare(out);
    out<<"Nume client: ";
    out<<nume_client;
    out<<"Durata: ";
    out<<durata;
}

void Avocat_Oficiu::citire(istream& in)
{
    Avocat::citire(in);
    cout<<"Introduceti durata: ";
    in>>durata;
    cout<<"Introduceti numele clientului: ";
    in>>nume_client;
}


istream& operator>>(istream& in, Avocat_Oficiu& f)
{
    f.citire(in);
    return in;
}
ostream& operator<<(ostream& out, Avocat_Oficiu& f)
{
    f.afisare(out);
    return out;
}

bool comparare(const Avocat& f, const Avocat& s) ///definitia functii de comparare
{
    return f.get_nr_procese()<s.get_nr_procese();
}

void menu_output()
{
    cout<<"\n Metesan Raul Petru - 211 - Tema 9 - Avocat\n";
    cout<<"\n\t MENIU:";
    cout<<"\n===========================================\n";
    cout<<"\n";
    cout<<"1. Introduceti avocati"<<endl;
    cout<<"2. Introduceti avocati din oficiu"<<endl;
    cout<<"3. Sortati lista de avocati"<<endl;
    cout<<"4. Avocatul cu timpul maxim petrecut cu clientul"<<endl;
    cout<<"0. Iesire"<<endl;
}

int main()
{
    int i,n,option,maxim=0;///optiunea aleasa din meniu
    Avocat *p;
    list<Avocat*> l;
    Avocat **v;

    do
    {
        menu_output();


        cout<<"\nIntroduceti numarul actiunii: ";
        cin>>option;

        if (option==1)
        {
            cout<<"Introduceti numarul de avocati: "; ///introducem lista de avocati
            cin>>n;
            v=new Avocat*[n];
            for(int i=0; i<n; i++)
            {
                p=new Avocat;
                cin>>*p;
                l.push_back(*&p);
            }
        }
        if (option==2)
        {
            cout<<"Introduceti numarul de avocati din oficiu: "; ///introducem lista de avocati din oficiu
            cin>>n;
            v=new Avocat*[n];
            for(int i=0; i<n; i++)
            {
                p=new Avocat_Oficiu;
                cin>>*p;
                l.push_back(*&p);
            }
        }

        if (option==3)
        {   ///o incercare de sortare
            list<Avocat*>::iterator i;
                for (i = l.begin(); i != l.end(); ++i){
                /// if(comparare(**i.get_nr_procese,*i.get_nr_procese)>0)
                ///    aux=**i;
                ///    **i=*i;
                ///    *i=aux;
                }
        }
        if (option==4)
        {   ///o incercare de aflare a duratei maxime
            list<Avocat*>::iterator i;
                for (i = l.begin(); i != l.end(); ++i){
           ///         if(**i.durata>maxim)
           ///             maxim=**i.durata;
           }
        }


        if (option==0)
        {
            cout<<"EXIT";
        }
        if (option<0||option>4)
        {
            cout<<"ABNORMAL PROGRAM TERMINATION";
        }
        cout<<endl;


        system("pause"); ///Pauza - Press any key to continue...
        system("cls");   ///Sterge continutul curent al consolei
    }
    while(option!=0);

}


#include <iostream>
using namespace std;
class Pereche {
private:
    int *a,*b;
public:
    Pereche () {
        a = new int;
        b = new int;
        *a = 0;
        *b = 0;
    }
    Pereche (int aa,int bb) {
        a = new int;
        b = new int;
        *a = aa;
        *b = bb;
    }
    Pereche (Pereche &obj) {
        a = new int;
        b = new int;
        *a = *obj.a;
        *b = *obj.b;
    }
    ~Pereche () {
        delete a;
        delete b;
    }
    int get_a ();
    int get_b ();
    void print ();
    Pereche &operator = (Pereche &);
    friend istream & operator >> (istream &,Pereche &);
    friend ostream & operator << (ostream &,Pereche &);
};
int Pereche::get_a () {return *a;}
int Pereche::get_b () {return *b;}
void Pereche::print () {cout<<*a<<" "<<*b<<'\n';}
Pereche& Pereche::operator = (Pereche &obj) {
    *a = *obj.a;
    *b = *obj.b;
}
istream & operator >> (istream &in,Pereche &obj) {in>>*obj.a>>*obj.b;}
ostream & operator << (ostream &out,Pereche &obj) {out<<*obj.a<<" "<<*obj.b<<'\n';}

class Multime_pereche {
private:
    int *n;
    Pereche *p;
public:
    Multime_pereche () {
        n = new int;
        *n = 0;
    }
    Multime_pereche (int nn,Pereche per) {
        n = new int;
        *n = nn;
        p = new Pereche [*n];
        for (int i=0;i<*n;++i)
            p[i] = per;
    }
    Multime_pereche (Multime_pereche &m) {
        n = new int;
        *n = *m.n;
        *p = *m.p;
    }
    ~Multime_pereche () {
        delete n;
        delete p;
    }

    int get_n ();
    void print ();
    Multime_pereche & operator = (Multime_pereche &);
    friend istream & operator >> (istream &,Multime_pereche &);
    friend ostream & operator << (ostream &,Multime_pereche &);
};

int Multime_pereche::get_n () {return *n;}
void Multime_pereche::print () {
    for (int i=0;i<*n;++i)
        cout<<p[i]<<" ";
    cout<<'\n';
}
Multime_pereche & Multime_pereche::operator = (Multime_pereche &m) {
    *n = *m.n;
    p = new Pereche [*n];
    for (int i=0;i<*n;++i)
        p[i]=m.p[i];
}
istream & operator >> (istream &in,Multime_pereche &m) {
    in>>*m.n;
    for (int i=0;i<*m.n;++i)
        in>>m.p[i];
}
ostream & operator << (ostream &out,Multime_pereche &m) {
    for (int i=0;i<*m.n;++i)
        out<<m.p[i];
    out<<'\n';
}



int main()
{
    return 0;
}




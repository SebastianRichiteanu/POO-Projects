// Richiteanu Mihai-Sebastian , Grupa 142
#include <iostream>
#include <cmath>
using namespace std;
int n;
class numar_complex {
private:
    double a,b;
public:
    numar_complex () {a=b=0;} //constructor default
    numar_complex (numar_complex &n) {a=n.a,b=n.b;} //constructor dupa un alt obiect de tip numar_complex
    numar_complex (double a1,double b1) {a=a1,b=b1
    ;} //constructor dupa valori date
    ~numar_complex () {} //deconstructor
    void indici () {cout<<a<<" "<<b<<'\n';} //functie pentru afisarea indicilor
    void afis () { //functie pentru afisarea pe ecran a numarului
        if (!a && !b)
            cout<<"0 ";
        else {
            if (a)
                cout<<a;
            if (!b)
                cout<<" ";
            else if (b>0) {
                if (b==1)
                    cout<<"+i ";
                else
                    cout<<"+i*"<<b<<" ";}
            else {
                if (b==-1)
                    cout<<"-i ";
                else
                    cout<<"-i*"<<-b<<" ";}}}
    double modul () { //functie pentru calcularea modulului numarului complex
        double mdl=sqrt(a*a+b*b);
        return mdl;}
    void st (double aa,double bb) {a=aa,b=bb;} //functie pentru setarea indicilor
    numar_complex operator + (const numar_complex &n) { //supraincarcarea operatiei + pentru a aduna 2 obiecte
        numar_complex nn;
        nn.a=n.a+a;
        nn.b=n.b+b;
        return nn;}
    numar_complex operator * (const numar_complex &n) { //supraincarcarea operatiei * pentru a inmulti 2 obiecte
        numar_complex nn;
        nn.a=a*n.a-b*n.b;
        nn.b=a*n.b+b*n.a;
        return nn;}};
class matrice_complexa {
private:
    int n,m;
    numar_complex** a;
public:
    friend class numar_complex; //declararea prieteniei cu clasa numar_complex
    matrice_complexa (int n1,int m1,numar_complex &nr) { //constructor dupa indici de linii si coloana si dupa un numar dat de tip numar_complex
        n=n1;
        m=m1;
        a = new numar_complex* [n];
        for (int i=0;i<n;++i)
            a[i] = new numar_complex[m];
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j)
                a[i][j] = nr;}
    matrice_complexa (int n1,int m1) { //constructor dupa indici de linii si coloane pentru matrice nula
        n=n1;
        m=m1;
        numar_complex n0(0,0);
        a = new numar_complex* [n];
        for (int i=0;i<n;++i)
            a[i] = new numar_complex[m];
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j)
                a[i][j] = n0;}
    matrice_complexa (matrice_complexa &mm) { //constructor dupa alta matrice
        n=mm.n;
        m=mm.m;
        a = new numar_complex* [n];
        for (int i=0;i<n;++i)
            a[i] = new numar_complex[m];
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j)
                a[i][j] = mm.a[i][j];}
    matrice_complexa () {} //constructorul default
    ~matrice_complexa () { //deconstructorul
        n=m=0;
        for (int i=0;i<n;++i)
            delete[] a[i];
        delete[] a;}
    matrice_complexa operator = (const matrice_complexa &mm) { //supraincarcarea operatiei = pentru atribuire
        n=mm.n;
        m=mm.m;
        a = new numar_complex* [n];
        for (int i=0;i<n;++i)
            a[i] = new numar_complex[m];
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j)
                a[i][j] = mm.a[i][j];}
    matrice_complexa operator + (matrice_complexa &mm) { //supraincarcarea operatiei + pentru a aduna 2 matrici
        matrice_complexa idk(n,m);
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j)
                idk.a[i][j] = a[i][j]+mm.a[i][j];
        return idk;}
    friend matrice_complexa operator * (matrice_complexa &,matrice_complexa &);
    friend ostream & operator << (ostream &, const matrice_complexa &);
    friend istream & operator >> (istream &,matrice_complexa &);
};
matrice_complexa operator * (matrice_complexa &m1,matrice_complexa &m2) { //supraincarcarea operatorului * pentru a inmulti 2 matrici
    numar_complex n0(0,0);
    matrice_complexa idk(m1.n,m2.m,n0);
    for (int i=0;i<m1.n;++i)
        for (int j=0;j<m2.m;++j)
            for (int k=0;k<m1.m;++k)
                idk.a[i][j] = idk.a[i][j] + (m1.a[i][k] * m2.a[k][j]);
    return idk;}
ostream & operator << (ostream &out, const matrice_complexa &mm) { //supraincarea operatorului << pentru a afisa o matrice
    for (int i=0;i<mm.n;++i) {
        for (int j=0;j<mm.m;++j)
            mm.a[i][j].afis();
        cout<<'\n';}
    return out;}
istream & operator >> (istream &in,matrice_complexa &m) { //supraincarcarea operatorului >> pentru a citi o matrice
    cout<<"Nr linii si coloane:";
    in>>m.n>>m.m;
    m.a = new numar_complex* [m.n];
    for (int i=0;i<m.n;++i)
        m.a[i] = new numar_complex[m.m];
    for (int i=0;i<m.n;++i)
        for (int j=0;j<m.m;++j) {
            cout<<"introduceti a si b pentru elementul a["<<i<<"]["<<j<<"]"<<'\n';
            double aa,bb;
            in>>aa>>bb;
            m.a[i][j].st(aa,bb);}
    return in;}
void go () { //functie pentru citirea, memorarea si afisarea a n obiecte
    cout<<"N:";
    cin>>n;
    matrice_complexa *vect;
    vect = new matrice_complexa[n];
    for (int i=0;i<n;++i)
        cin>>vect[i];
    for (int i=0;i<n;++i)
        cout<<vect[i]<<'\n';}
int main()
{   go();
    return 0;
}

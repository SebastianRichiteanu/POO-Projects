#include <iostream>
using namespace std;
class Pereche {
private:
    int a, b;
public:
    Pereche() {
        a = b = 0;
    }
    Pereche(int aa, int bb) {
        a = aa;
        b = bb;
    }
    Pereche(Pereche &obj) {
        a = obj.get_a();
        b = obj.get_b();
    }
    ~Pereche() {
        a = b = 0;
    }
    void setter(int aa,int bb) {
        a = aa;
        b = bb;
    }
    int get_a() { return a; }
    int get_b() { return b; }

    Pereche& operator = (const Pereche& per) {
        if (this != &per) {
            a = per.a;
            b = per.b;
        }
        return *this;
    }

    friend istream& operator >> (istream&, Pereche&);
    friend ostream& operator << (ostream&,const Pereche&);
    
};
istream& operator >> (istream& in, Pereche& per) {
    int aa, bb;
    in >> aa >> bb;
    per.setter(aa, bb);
    return in;
}
ostream& operator << (ostream& out, const Pereche& per) {
    out << per.a << " " << per.b;
    return out;
}
class Multime_pereche {
protected:
    int n;
    Pereche* p;
public:
    Multime_pereche() {
        n = 0;
    }
    Multime_pereche(int nn,Pereche& per) {
        n = nn;
        p = new Pereche[n];
        for (int i = 0; i < n; ++i)
            p[i] = per;
    }
    Multime_pereche(Multime_pereche& m) {
        n = m.n;
        p = new Pereche[n];
        for (int i = 0; i < n; ++i)
            p[i] = m.p[i];
    }
    ~Multime_pereche() {
        n = 0;
        delete[] p;
    }
    void setter_n(int nn) {
        n = nn;
        p = new Pereche[n];
    }
    void setter_pi(int nn,Pereche& per) {
        p[nn] = per;
    }
    void setter(int nn,Pereche &per) {
        n = nn;
        p = new Pereche[n];
        for (int i = 0; i < n; ++i)
            p[i] = per;
    }
    int get_n() { return n; }
    Pereche * get_per() { return p; }

    Multime_pereche operator = (Multime_pereche& m) {
        if (this != &m) {
            n = m.n;
            p = new Pereche[n];
            for (int i = 0; i < n; ++i)
                p[i] = m.p[i];
        }
        return *this;
    }

    friend istream& operator >> (istream&, Multime_pereche&);
    friend ostream& operator << (ostream&, Multime_pereche&);
};
istream& operator >> (istream& in, Multime_pereche& m) {
    int nn;
    in >> nn;
    m.setter_n(nn);
    Pereche pr;
    for (int i = 0; i < m.n; ++i) {
        in >> pr;
        m.setter_pi(i, pr);
    }
    return in;
}
ostream& operator << (ostream& out, Multime_pereche& m) {
    out << m.n << '\n';
    for (int i = 0; i < m.n; ++i)
        cout << m.p[i] << '\n';
    return out;
}
class Stiva_pereche:public Multime_pereche{
public:
    Stiva_pereche() {};
    Stiva_pereche(int nn, Pereche& per) {
        n = nn;
        p = new Pereche[n];
        for (int i = 0; i < n; ++i)
            p[i] = per;
    }
    Stiva_pereche(Stiva_pereche& m) {
        n = m.n;
        p = new Pereche[n];
        for (int i = 0; i < n; ++i)
            p[i] = m.p[i];
    }
    ~Stiva_pereche() {}
    Stiva_pereche operator = (Stiva_pereche& m) {
        if (this != &m) {
            n = m.n;
            p = new Pereche[n];
            for (int i = 0; i < n; ++i)
                p[i] = m.p[i];
        }
        return *this;
    }
    friend istream& operator >> (istream&, Stiva_pereche&);
    friend ostream& operator << (ostream&, Stiva_pereche&);
    void push(Pereche per) {
        Pereche* v;
        v = new Pereche[++n];
        for (int i = 0; i < n-1 ; ++i)
            v[i] = p[i];
        v[n-1] = per;
        p = new Pereche[n];
        for (int i = 0; i < n ; ++i)
            p[i] = v[i];
    }
    Pereche pop() {
        if (n) {
            Pereche pr;
            pr = p[n - 1];
            --n;
            return pr;
        }
    }

};
istream& operator >> (istream& in, Stiva_pereche& m) {
    int nn;
    in >> nn;
    m.setter_n(nn);
    Pereche pr;
    for (int i = 0; i < m.n; ++i) {
        in >> pr;
        m.setter_pi(i, pr);
    }
    return in;
}
ostream& operator << (ostream& out, Stiva_pereche& m) {
    out << m.n << '\n';
    for (int i = 0; i < m.n; ++i)
        cout << m.p[i] << '\n';
    return out;
}
class Coada_pereche : public Multime_pereche {
public:
    Coada_pereche() {};
    Coada_pereche(int nn, Pereche& per) {
        n = nn;
        p = new Pereche[n];
        for (int i = 0; i < n; ++i)
            p[i] = per;
    }
    Coada_pereche(Coada_pereche& m) {
        n = m.n;
        p = new Pereche[n];
        for (int i = 0; i < n; ++i)
            p[i] = m.p[i];
    }
    ~Coada_pereche() {}
    Coada_pereche operator = (Coada_pereche& m) {
        if (this != &m) {
            n = m.n;
            p = new Pereche[n];
            for (int i = 0; i < n; ++i)
                p[i] = m.p[i];
        }
        return *this;
    }
    friend istream& operator >> (istream&, Coada_pereche&);
    friend ostream& operator << (ostream&, Coada_pereche&);
    void push(Pereche per) {
        Pereche* v;
        v = new Pereche[++n];
        for (int i = 0; i < n - 1; ++i)
            v[i] = p[i];
        v[n - 1] = per;
        p = new Pereche[n];
        for (int i = 0; i < n; ++i)
            p[i] = v[i];
    }
    Pereche pop() {
        if (n) {
            Pereche per = p[0];
            Pereche* v;
            v = new Pereche[--n];
            for (int i = 1; i <= n; ++i)
                v[i - 1] = p[i];
            p = new Pereche[n];
            for (int i = 0; i < n; ++i)
                p[i] = v[i];
            return per;
        }
    }
};
istream& operator >> (istream& in, Coada_pereche& m) {
    int nn;
    in >> nn;
    m.setter_n(nn);
    Pereche pr;
    for (int i = 0; i < m.n; ++i) {
        in >> pr;
        m.setter_pi(i, pr);
    }
    return in;
}
ostream& operator << (ostream& out, Coada_pereche& m) {
    out << m.n << '\n';
    for (int i = 0; i < m.n; ++i)
        cout << m.p[i] << '\n';
    return out;
}

void go() {
    Coada_pereche c1, c2;
    Stiva_pereche st;
    Pereche p1(1, 1);
    Pereche p2(2, 2);
    Pereche p3(3, 3);
    Pereche p4(4, 4);
    Pereche p5(5, 5);
    Pereche p6(6, 6);
    Pereche p7(7, 7);
    Pereche p8(8, 8);

    c1.push(p1);
    c1.push(p2);
    c1.push(p3);
    c1.push(p4);
    cout << "Coada 1: \n" << c1;

    c2.push(p5);
    c2.push(p6);
    c2.push(p7);
    c2.push(p8);
    cout << "\nCoada 2: \n" << c2;
     
    while (c1.get_n() && c2.get_n()) {
        Pereche pp1, pp2;
        pp1 = c1.pop();
        pp2 = c2.pop();
        st.push(pp1);
        st.push(pp2);
    }
    cout <<"\nStiva initiala:  \n"<< st;
    cout << "\nCate elemente sa elimin din coada?";
    int aux;
    cin >> aux;
    for (int i = 0; i < aux; ++i)
        cout<<st.pop()<<'\n';
}
int main() 
{
    go();
    return 0;
}

/*TO DO
    pop sa returneze exceptie
    push(pop());
*/
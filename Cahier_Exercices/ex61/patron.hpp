#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

template<class T1, class T2, class T3>
T1 somme(const T1& x, const T2&y, const T3&z){
    cout << "type1= " << typeid(T1).name() << " " << "type2= " << typeid(T2).name() << " " << "type3= " << typeid(T3).name() << endl;
    return x+y+z;
}

template<class X, class Y>
class Couple
{
private:
    X premier;
    Y second;
public:
    Couple(const X& p = X(), const Y& s = Y());
    ~Couple() {}
    const X& getPremier() const {return premier;}
    const Y& getSecond() const {return second;}
    void setPremier(const X& p);
    void setSecond(const Y& s);

    Couple<X,Y> get_valeur() const {return *this;}

    template<class T1, class T2>
    bool operator==(const Couple<T1, T2>& c) const;
};

template<class X, class Y>
Couple<X, Y>::Couple(const X& p, const Y& s) : premier(p), second(s) {}

template<class X, class Y>
void Couple<X, Y>::setPremier(const X& p) {premier = p;}

template<class X, class Y>
void Couple<X, Y>::setSecond(const Y& s) {second = s;}

template<class X, class Y>
ostream& operator<<(ostream& f, const Couple<X,Y>& c){
    f << "(" << c.getPremier() << ", " << c.getSecond() << ")";
    return f;
}

template<class X, class Y>
template<class T1, class T2>
bool Couple<X, Y>::operator==(const Couple<T1, T2>& c) const{
    return (premier == c.getPremier() && second == c.getSecond());
}
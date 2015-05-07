#ifndef COMPLEX_H
#define COMPLEX_H
class Complex {
public:
    Complex(int r, int i) : real{r}, imag{i} {}
    ostream& operator<<(ostream& out) { out<<real<<"+"<<imag<<"i"<<endl; return out;}
    void add(const Complex& c2);
private:
    int real, imag;
};
#endif

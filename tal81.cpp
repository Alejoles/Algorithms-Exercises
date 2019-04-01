#include <iostream>


using namespace std;

class Racional{
	int num,deno;
public:
	Racional(): num(0), deno(1) {}
	Racional(int num, int den): num(num), deno(den) {}
	int getNum();
	int getDen();
	void setNum(int v);
	void setDen(int v);
	friend Racional & operator--(Racional & n, int x);
	Racional operator=(Racional p);
	Racional operator+=(Racional r);
	Racional operator-=(Racional r);
	Racional operator*=(Racional r);
	Racional operator/=(Racional r);
	friend bool operator==(Racional r, Racional q);
	friend bool operator>(Racional r, Racional q);
	friend bool operator<(Racional r, Racional q);
	friend bool operator<=(Racional r, Racional q);
	friend bool operator>=(Racional r, Racional q);
	friend Racional operator+(Racional p, Racional q);
	friend Racional operator-(Racional p, Racional q);
	friend Racional operator*(Racional p, Racional q);
	friend Racional operator/(Racional p, Racional q);
	friend istream & operator>>(istream & is, Racional & r);
	friend ostream & operator<<(ostream & os, Racional &r);
	

};
ostream & operator<<(ostream & os, Racional &r){
	return os << r.getNum() << "/" << r.getDen();
}
istream & operator>>(istream & is, Racional &r){
	is >> r.num;
	is >> r.deno;
	
	return is;
}
bool operator<=(Racional &r, Racional &q){
	return (r.getNum() * q.getNum()) <= (r.getDen() * q.getDen());
}
bool operator>=(Racional &r, Racional &q){
	return (r.getNum() * q.getNum()) >= (r.getDen() * q.getDen());
}
bool operator>(Racional &r, Racional &q){
	return (r.getNum() * q.getNum()) > (r.getDen() * q.getDen());
}

bool operator<(Racional &r, Racional &q){
	return (r.getNum() * q.getNum()) < (r.getDen() * q.getDen());
}
bool operator==(Racional r, Racional q){
	return (r.getNum()*q.getDen() == q.getNum()*r.getDen());
}
Racional operator/(Racional p, Racional q){
	int num = p.getNum()*q.getDen();
	int den = p.getDen()*q.getNum();
	return Racional(num,den);
}
Racional operator-(Racional p, Racional q){
	int num = (p.getNum()*q.getDen()) - (p.getDen()*p.getNum());
	int den = p.getDen()*q.getDen();
	return Racional(num,den);
}
Racional operator*(Racional p, Racional q){
	int num = p.getNum()*q.getNum();
	int den = p.getDen()*q.getDen();
	return Racional(num,den);
}
Racional Racional::operator/=(Racional r){
	num = r.getNum()*deno;
	deno = r.getDen()*num;
	return *this;
}
Racional Racional::operator*=(Racional r){
	num = r.getNum()*num;
	deno = r.getDen()*deno;
	return *this;
}
Racional Racional::operator+=(Racional r){
	num = (r.getNum()*deno) + (r.getDen()*num);
	deno = r.getDen()*deno;
	return *this;
}
Racional Racional::operator-=(Racional r){
	num = (r.getNum()*deno) - (r.getDen()*num);
	deno = r.getDen()*deno;
	return *this;
}
Racional Racional::operator=(Racional p){
	num = p.getNum();
	deno = p.getDen();
	return *this;
}
Racional operator+(Racional p, Racional q){
	int num = (p.getNum()*q.getDen()) + (p.getDen()*p.getNum());
	int den = p.getDen()*q.getDen();
	return Racional(num,den);
}
int Racional::getNum(){
	return num;
}
int Racional::getDen(){
	return deno;
}
void Racional::setNum(int v){
	num = v;	
}
void Racional::setDen(int v){
	deno = v;	
}
Racional operator--(Racional n, int x){
	x = 1;
	int numer = n.getNum() - n.getDen()*x;
	int denomi = n.getDen()*x;
	n.setNum(numer);
	n.setDen(denomi);
	return n;
}

int main(void){
	Racional p;
	Racional q;
	q.setNum(5);
	q.setDen(2);
	cin >> p;
	cout << p << endl;
	if(q == p) cout << "true" << endl;
	cout << q << endl;
	
	return 0;
}





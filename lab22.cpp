#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double,double);
		ComplexNumber operator+(const ComplexNumber &);
		ComplexNumber operator-(const ComplexNumber &);
		ComplexNumber operator*(const ComplexNumber &);
		ComplexNumber operator/(const ComplexNumber &);
		bool operator==(const ComplexNumber &);
		double abs();
		double angle();
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
	real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
	return ComplexNumber(real+c.real,imag+c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
	return ComplexNumber(real-c.real,imag-c.imag);
}

//Write your code here.
ComplexNumber ComplexNumber::operator*(const ComplexNumber &c){
    return ComplexNumber(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c){
    double denominator = pow(c.real, 2) + pow(c.imag, 2);
    return ComplexNumber((real * c.real + imag * c.imag) / denominator, 
                         (imag * c.real - real * c.imag) / denominator);
}

bool ComplexNumber::operator==(const ComplexNumber &c){
    return (real == c.real && imag == c.imag);
}

double ComplexNumber::abs(){
    return sqrt(pow(real, 2) + pow(imag, 2));
}

double ComplexNumber::angle(){
    return atan2(imag, real) * 180.0 / 3.14159265358979323846; 
}

ComplexNumber operator+(double s, const ComplexNumber &c){
    return ComplexNumber(s + c.real, c.imag);
}

ComplexNumber operator-(double s, const ComplexNumber &c){
    return ComplexNumber(s - c.real, -c.imag);
}

ComplexNumber operator*(double s, const ComplexNumber &c){
    return ComplexNumber(s * c.real, s * c.imag);
}

ComplexNumber operator/(double s, const ComplexNumber &c){
    double denominator = pow(c.real, 2) + pow(c.imag, 2);
    return ComplexNumber((s * c.real) / denominator, (-s * c.imag) / denominator);
}

bool operator==(double s, const ComplexNumber &c){
    return (s == c.real && c.imag == 0);
}

ostream& operator<<(ostream &os, const ComplexNumber &c){
    if(c.real == 0 && c.imag == 0){
        return os << "0";
    }
    else if(c.real == 0){
        return os << c.imag << "i";
    }
    else if(c.imag == 0){
        return os << c.real;
    }
    else{
        if(c.imag > 0){
            return os << c.real << "+" << c.imag << "i";
        }
        else{
            return os << c.real << c.imag << "i"; 
        }
    }
}

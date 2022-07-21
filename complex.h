#ifndef __Complex_H__
#define __Complex_H__
#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

class Complex
{ 
public:
  double Real, Imag;
  Complex ():Real (0), Imag (0)
  {
  };

  Complex (double co)
  {
    Real = co;
    Imag = 0;
  };

  Complex (double Real, double Imag)
  {
    this->Real = Real;
    this->Imag = Imag;
  };

  Complex & operator= (const Complex & s)
  {
    Real = s.Real;
    Imag = s.Imag;
    return *this;
  };

  Complex operator- () const
  {
    return Complex(-Real,-Imag);
  };

  Complex & operator= (double co)
  {
    Real = co;
    Imag = 0;
    return *this;
  };

  Complex & operator-= (Complex co)
  {
    Real -= co.Real;
    Imag -= co.Imag;
    return *this;
  };
  friend Complex operator- (Complex s1, Complex s2)
  {
  Complex n (s1);
  return n -= s2;
  }

  friend ostream & operator << (ostream & s, const Complex & c)
  {
    s << "(" << c.Real << "," << c.Imag << ")";
    return s;
  };
  
  friend Complex operator+ (Complex s1 , Complex s2)
  {
	Complex n(s1);
	return n += s2;
  };
  friend Complex operator* (Complex s1, Complex s2) 
  {
	Complex n(s1);
	return n *= s2;
  }

  friend Complex operator/ (Complex s1, Complex s2) 
  {
	Complex n(s1);
	return n /= s2;
  }

  friend bool operator== (Complex s1, Complex s2) 
  {
	if(s1.Real == s2.Real && s1.Imag == s2.Imag)
		return 1;
	return 0;
  }

  friend bool operator!= (Complex s1, Complex s2) 
  {
	if(s1.Real == s2.Real && s1.Imag == s2.Imag)
		return 0;
	return 1;
  }

  Complex & operator+= (Complex co) 
  {
	Complex n;
	n.Real = this->Real + co.Real;
	n.Imag = this->Imag + co.Imag;
	Real=n.Real;
	Imag=n.Imag;
	return *this;
  }


  Complex & operator*= (Complex co)   
  {
	Complex n;
	n.Real = (this->Real * co.Real) - (this->Imag * co.Imag);
	n.Imag = (this->Real * co.Imag) + (this->Imag * co.Real);
	Real=n.Real;
	Imag=n.Imag;
	return *this;
  }

  Complex & operator/= (Complex co) 
  {
	if(co.Real == 0 && co.Imag == 0) {
		perror("Division by 0 error!");
		return *this;
	}
	Complex n;
	n.Real = ((this->Real * co.Real) + (this->Imag * co.Imag)) / (pow(co.Real,2) + pow(co.Imag,2));
	n.Imag = ((this->Real * co.Imag) - (this->Imag * co.Real)) / (pow(co.Real,2) + pow(co.Imag,2));
	Real=n.Real;
	Imag=n.Imag;
	return *this;
  }


  const double getRealPart() const { return Real; }
  const double getImaginaryPart() const { return Imag; }
  double amplitude() const { return sqrt(pow(this->Real, 2) + pow(this->Imag, 2)); }
  double phase() const 
  {
	  /*
	  if(Real > 0)
	  {
		return atan(Imag/Real);
	  }
	  else if(Real < 0 && Imag >= 0)
	  {
		  return atan(Imag/Real) + M_PI;
	  }
	  else if(Real < 0 && Imag < 0)
	  {
		  return atan(Imag/Real) - M_PI;
	  }
	  else if(Real == 0 && Imag > 0)
	  {
		  return M_PI/2;
	  }
	  else if(Real == 0 && Imag < 0)
	  {
		  return -(M_PI/2);
	  }
	  else if(Real == 0 && Imag == 0)
	  {
		  cout << "indeterminate" << endl;
		  return 0;
	  }
	  else
	  {
		  return 0;
	  }	
	  */	
	 
	  return atan2(Imag, Real);	 
  }

  Complex conjugate() const { return Complex(Real, -Imag); }
};
#endif /* __Complex_H__ */

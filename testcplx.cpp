/*
#include <iostream>
#include "complex.h"

using namespace std;


int main()
{
	Complex a(2.0,4), b(2,6), c(0.0), d(0,5), f(3,15), g(0,0), h(2,4), i(2,4);
	cout << c << endl;
	c = -a;
	cout << c << endl;  
	c = a + b;
	c = c - Complex(10);
	cout << c << endl;  
	c = 10 - a;
	(c -= b) -= 10;
	cout << c << endl;
	g += d;
	cout << g <<endl;
	g += f;
	cout << g <<endl;
	a += b += c;
	cout << a << endl; 
	c = a / b;
	cout << c << endl; 
	
	if (i == h)
	{
		cout << "The same" << endl;
	}
	else
	{
		cout << "Different" << endl;
	}
		cout << h.phase() << endl;
		
	Complex j = 10 * i;

	cout << j << endl;

	j = i * Complex(20);

	cout << j << endl;
}
*/

#include <iostream>
using namespace std;
#include "complex.h"


int main()
{
  Complex a(0.0,15),b(0,13), c;
  c = 10;
  cout << c << endl;
  c = -a;
  cout << c << endl;  
  c = a + b;
  c = c - Complex(10);
  cout << c <<endl;  
  c = 10 - a;
  (c -=b) -=10;
  cout << c <<endl;
  cout << c.phase() << endl;
  Complex d;
  d *= 5;
  cout << d << endl;
  d += Complex(20, 5);
  cout << d << endl;
  d /= 3;
  cout << d << endl;
  Complex e = d.conjugate();
  cout << e << endl;
  Complex f = a;
  if(e == f)
	  cout << "equal\n";
  else
	  cout << "not equal\n";
  f = e;
  if(e != f)
	  cout << "not equal\n";
  else
	  cout << "equal\n";
  cout << "Real part: " << f.getRealPart() << endl;
  cout << "Imaginary part: " << f.getImaginaryPart() << endl;
  f += c = Complex(0,0) * a * Complex(1, 1);
  cout << c << endl;
  cout << f << endl;
}
 
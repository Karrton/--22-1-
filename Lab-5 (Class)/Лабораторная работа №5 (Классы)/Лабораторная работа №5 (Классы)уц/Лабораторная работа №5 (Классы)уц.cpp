#include "Object.h" 
#include "Person.h" 
#include "Student.h"
#include "Vector.h" 
#include <string> 
#include <iostream> 
using namespace std; 
void main() 
{ 
	Vector v(5);
	person a;
	cin >> a; 
	student b;
	cin >> b;
	student c;
	cin >> c;
	Object *p = &a;
	v.Add(p);
	p=&b;
	v.Add(p);
	p = &c;
	v.Add(p); 
	cout << v;
}

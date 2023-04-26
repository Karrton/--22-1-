#include "Tree.h"
#include "Dialog.h"
#include "Event.h"
#include "Magazin.h"
#include "Object.h"
#include "Print.h"

int main() 
{
	cout << "m : Create a group" << endl;
	cout << "+ : Add element" << endl;
	cout << "- : Delete element" << endl;
	cout << "s : Group member information" << endl;
	cout << "z : Information about group element names" << endl;
	cout << "q : End of work" << endl;
	Dialog D;
	D.Execute();
	return 0;
}

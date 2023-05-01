#include"List.h"
#include"Error.h"
#include <iostream>

int main()
{
	List<int> lst;
	try
	{
        lst.push_back(1);
        lst.push_back(2);
        lst.push_back(4);
		lst.push_back(4);
	}
	catch (Error& a)
	{
		a.what();
	}
	try
	{
		std::cout << "List[0] * List[5] = " << lst[0] * lst[5] << std::endl;
	}
	catch (Error& a)
	{
		a.what();
	}
	try
	{
		std::cout << "List[-3] * List[0] = " << lst[-3] * lst[0] << std::endl;
	}
	catch (Error& a)
	{
		a.what();
	}
	return 0;
}

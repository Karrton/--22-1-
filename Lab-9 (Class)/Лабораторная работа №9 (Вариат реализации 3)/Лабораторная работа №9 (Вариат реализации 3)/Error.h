#pragma once
#include <string> 
#include <iostream> 
class Error { public: virtual void what() {}; };
class IndexError:
	public Error
{
protected: std::string msg; 
public:
	IndexError() { msg = "Index Error - "; } 
	virtual void what() { std::cout << msg << std::endl; }
};
class MaxSizeError: public Error
{
protected: std::string msg;
public:
	MaxSizeError() { msg = "Size error"; } 
	virtual void what() { std::cout << msg << std::endl; }
};
class IndexError1: public IndexError
{
protected: std::string msg_; 
public:
	IndexError1() { IndexError(); msg_ = "The index is less than zero"; } 
	virtual void what() { std::cout << msg << msg_ << std::endl; }
};
class IndexError2: public IndexError 
{
protected: std::string msg_;
public:
	IndexError2() { IndexError(); msg_ = "Index out of range"; } 
	virtual void what() { std::cout << msg << msg_ << std::endl; }
};

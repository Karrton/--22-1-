#include<string>
class cash 
{
private:
    std::string name;
    double salary;
    int prize;
public:
    cash();
    cash(std::string, int, double);
    cash(const cash&);
    ~cash(); 
    void set_name(std::string);
    std::string get_name();
    void set_salary(double);
    double get_salary();
    void set_prize(int);
    int get_prize();
    void show();
};

#include "../inc/postman.h"
// PostMan ---------------------------------------------------
PostMan::PostMan(const std::string &name_, const std::string &address_, const std::string &phoneNumber_, const std::string &mail_, int salary_)
    : Person(name_, address_, phoneNumber_, mail_), salary(salary_) {}
void  PostMan::displayInfo() const
{
    std::cout << "Postman Information:" << std::endl;
    Person::displayInfo();
    std::cout << "Salary: " << salary << std::endl;
}
int PostMan::getSalary()
{
    return salary;
}
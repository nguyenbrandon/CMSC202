#include "Supervisor.h"
using namespace std;

Supervisor::Supervisor(string name,
		       double payRate,
		       string Department)
  : Manager(name, payRate, true)
{
  m_department = Department;
}

string Supervisor::GetDept(){
  return m_department;
}

void Supervisor::SetDept(string dept){
  m_department = dept;
}

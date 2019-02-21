#ifndef SUPERVISOR_H
#define SUPERVISOR_H

#include "Manager.h"
#include <string>

class Supervisor : public Manager {
 public:
  Supervisor(string name, 
	     double payRate, 
	     string Department);

  string GetDept();
  void SetDept(string dept);

 protected:
  string m_department;


};
#endif

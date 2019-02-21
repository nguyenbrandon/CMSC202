#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h"
#include <string>

class Manager : public Employee {
 public:
  Manager(string name,
          double payRate,
          bool isSalaried);

  bool GetSalaried();
  double Pay(double hoursWorked);
  void SetSalaried(bool salaried);

 protected:
  bool m_salaried;
};

#endif

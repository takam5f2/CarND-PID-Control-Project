#include "PID.h"

using namespace std;

/*
 * TODO: Complete the PID class.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
  
  this->p_error = 0.0;
  this->i_error = 0.0;
  this->d_error = 0.0;
  this->prev_cte = 0.0;
}

void PID::UpdateError(double cte) {
  this->p_error = cte;
  this->i_error += cte;
  this->d_error = cte - prev_cte;
  this->prev_cte = cte;
}

double PID::TotalError() {
  double total_error = 0;
  total_error += this->p_error;
  total_error += this->i_error;
  total_error += this->d_error;
  return total_error;
}


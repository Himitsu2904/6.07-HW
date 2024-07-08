#pragma once
#include <string.h>
#include <iostream>
using namespace std;

class Payment
{
	string FIO;
	double salary;
	double total_pay;
	double held_pay;
	double bonus_payment;
	double day_pay;
	const double income_tax = 0.13;
	const int working_days_in_month = 22;
	int experience;
	int worked_days_in_month;
	int start_year;
public:
	Payment(string _FIO, int _worked_days, double _day_pay, int _start_year);
	double Count_total_pay();
	double Count_held_pay();
	double Count_final_salary();
	int Count_experience();
	void Show();
};
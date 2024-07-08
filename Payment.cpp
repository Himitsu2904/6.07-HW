#define _CRT_SECURE_NO_WARNINGS
#include "Payment.h"
#include <iostream>
using namespace std;

Payment::Payment(string _FIO, int _worked_days, double _day_pay, int _start_year)
{
	FIO = _FIO;
	worked_days_in_month = _worked_days;
	day_pay = _day_pay;
	start_year = _start_year;
	salary = 0;
	total_pay = 0;
	held_pay = 0;
	bonus_payment = 0;
	experience = 0;
}

double Payment::Count_total_pay()
{
	total_pay = worked_days_in_month * day_pay;
	cout << "Have you worked overtime? (y/n) ";
	char answer;
	cin >> answer;
	if (answer == 'y')
	{
		while (!(bonus_payment > 0 && bonus_payment <= 100))
		{
			cout << "What is the amount of your overtime? (%) ";
			cin >> bonus_payment;
		}
		total_pay += total_pay * bonus_payment / 100;
	}
	return total_pay;
}

double Payment::Count_held_pay()
{
	held_pay = total_pay * (income_tax + 0.01);
	return held_pay;
}

double Payment::Count_final_salary()
{
	salary = total_pay - held_pay;
	return salary;
}

int Payment::Count_experience()
{
	time_t t = time(NULL);
	tm* current_t = localtime(&t);
	int current_int = 1900 + current_t->tm_year;
	experience = current_int - start_year;
	return experience;
}

void Payment::Show()
{
	cout << "\n----------PAYMENT REPORT----------" << endl;
	cout << "FIO:\t\t\t" << FIO << endl;
	cout << "Payment per day:\t" << "$ " << day_pay << endl;
	cout << "Worked days in month:\t" << worked_days_in_month << endl;
	cout << "Overtime:\t\t" << bonus_payment << " %" << endl;
	cout << "Total pay:\t\t" << "$ " << total_pay << endl;
	cout << "Income tax:\t\t" << income_tax * 100 << " %" << endl;
	cout << "Held pay:\t\t" << "$ " << held_pay << endl;
	cout << "Salary worker receives:\t" << "$ " << salary << endl;
	cout << "Experience:\t\t" << experience << " years" << endl;
	cout << "-------------------------------------" << endl;
}
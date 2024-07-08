#include <iostream>
#include "Payment.h"
using namespace std;

int main()
{
	Payment worker("Federko Sofia Ivanivna", 22, 125.65, 1999);
	worker.Count_total_pay();
	worker.Count_held_pay();
	worker.Count_final_salary();
	worker.Count_experience();
	worker.Show();
}
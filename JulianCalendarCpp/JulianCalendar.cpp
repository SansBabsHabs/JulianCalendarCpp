#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX_DAY= 31;
const string MONTH_NAMES[] = { "Jan","Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
const int MONTH_LENGTH[] = { 31, 28, 31,30,31, 30, 31, 31, 30, 31, 30, 31 };
int numberOfMonths = sizeof(MONTH_NAMES) / sizeof(MONTH_NAMES[0]);

void setWidth() {
	cout << setw(3) << setfill('0');
}

void displayTitle() {

	cout << "Day" << " ";

	for (int i = 0; i < numberOfMonths; i++) {
		cout << MONTH_NAMES[i] << " ";
	}

	cout << "Day\n";
}


void displayNumbers() {
	int daysPrevMonth = 0;	//
	int numOfDays = 0;
	int currentMonth = 0;
	for (numOfDays = 1; numOfDays <= MAX_DAY; numOfDays++) {
		setWidth();
		daysPrevMonth = 0;
		cout << numOfDays << " ";

		for (currentMonth = 1; currentMonth <= (numberOfMonths); currentMonth++) {
			setWidth();
			if (numOfDays <= MONTH_LENGTH[currentMonth-1]) {
				cout << numOfDays + daysPrevMonth << " ";
			}
			else {
				//print "000" if the day of the year does not exist
				cout << "000" << " ";
			}
			daysPrevMonth += MONTH_LENGTH[currentMonth-1];
		}
		
		setWidth();
		cout << numOfDays << endl;
	}
}

int main() {
	setWidth();
	displayTitle();
	setWidth();
	displayNumbers();
	return 0;
}
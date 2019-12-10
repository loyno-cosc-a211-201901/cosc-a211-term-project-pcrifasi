// Final Project
// Patrick Crifasi
// This program is designed to allow a user to choose a date and 
// give the sunrise time for that day in New Orleans, LA.
// 12/9/19

#include <iostream>
#include <fstream>
using namespace std;

const int DAYS = 366; // number of rows = number of days in a year (including Feb 29th for leap year)
                      // each row holds the sunrise time for that day of the year
					  // Sunrise times are only a matter of seconds different on leap years so I included Feb. 29 to be compatible with leap years


void file_info (double sunrise_time[]);
// function to input times from file into an array

void get_date_and_time (double sunrise_time[], double, double);
// function to get month and date from user
// calculates day in the year and uses that to give the sunrise time


int main()
{
    double sunrise_time[366];
	double month=0;
	double day=0;

	cout << "Welcome to the Sunrise Calculator!\nThis program allows you to enter a date and get the sunrise time for New Orleans, LA.\n\n";

    file_info (sunrise_time);

	get_date_and_time (sunrise_time, month, day);

    return 0;
}



void file_info (double sunrise_time[])
{
    int i;
    ifstream inputFile;

    inputFile.open ("sunrisetimes.txt"); // open the document with times on it
    if(inputFile.fail())
    {
        cout << "Correct Answers file did not open. Try it again.\n";
        system ("EXIT");
    }
    for (i=0; i<366; i++)
    {
        inputFile>>sunrise_time[i];
    }
    inputFile.close(); // close the document
}



void get_date_and_time (double sunrise_time[], double month, double day)
{
	double current_day_in_year;

	cout << "Enter the month (1-12): ";
	cin >> month;

	while (month < 1 || month > 12)
	{
		cout << "Please enter a valid month(1-12): ";
		cin >> month;
	}

	cout << "Now enter the date for that month: ";
	cin >> day;
	
	if (month == 1 || 3 || 5 || 7 || 8|| 10 || 12)
	{
		while (day <1 || day > 31)
		{
			cout << "Please enter a valid date(1-31): ";
			cin >> day;
		}
	}
	else if (month  == 4 || 6 || 9 || 11)
	{
		while (day <1 || day > 30)
		{
			cout << "Please enter a valid date(1-30): ";
			cin >> day;
		}
	}
	else
	{
		while (day <1 || day > 29)
		{
			cout << "Please enter a valid date(1-29): ";
			cin >> day;
		}
	}

	cout << "You selected the following date: " << month << "/" << day << endl << endl;

	if (month == 1)
	{
		current_day_in_year = day;
	}
	else if (month == 2)
	{
		current_day_in_year = (31 + day);
	}
	else if (month == 3)
	{
		current_day_in_year = (60 + day);
	}
	else if (month == 4)
	{
		current_day_in_year = (91 + day);
	}
	else if (month == 5)
	{
		current_day_in_year = (121 + day);
	}
	else if (month == 6)
	{
		current_day_in_year = (152 + day);
	}
	else if (month == 7)
	{
		current_day_in_year = (182 + day);
	}
	else if (month == 8)
	{
		current_day_in_year = (213 + day);
	}
	else if (month == 9)
	{
		current_day_in_year = (244 + day);
	}
	else if (month == 10)
	{
		current_day_in_year = (274 + day);
	}
	else if (month == 11)
	{
		current_day_in_year = (305 + day);
	}
	else
	{
		current_day_in_year = (345 + day);
	}
	int value;
	value = (current_day_in_year-1);

	cout << "Sunrise on the selected date is at " << sunrise_time[value] << " AM.\n" << endl;
}
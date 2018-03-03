#include "stdafx.h"
#include "Date.h"

Date::Date()
{
	setDay(01);
	setMonth(01);
	setYear(2000);
}
Date::Date(string newDate) {
	setDate(newDate);
}


Date::~Date()
{
}

void Date::setDay(int newDay) {
	day = newDay;
}
void Date::setMonth(int newMonth) {
	month = newMonth;
}
void Date::setYear(int newYear) {
	year = newYear;
}
void Date::setDate(Date newDate) {
	//for base values
	// 0 values enable timespann search!
	if (newDate.getDay() > 0 && newDate.getMonth() > 0 && newDate.getMonth() < 13 && newDate.getYear()> 2017 ) {
		//for months with 31 days
		if (newDate.getDay() < 32 && newDate.getMonth() % 2 == 1) {
			setDay(newDate.getDay());
			setMonth(newDate.getMonth());
			setYear(newDate.getYear());
		}
		//for months with 30 days
		else if (newDate.getDay() < 31 && newDate.getMonth() % 2 == 0 && newDate.getMonth() != 2) {
			setDay(newDate.getDay());
			setMonth(newDate.getMonth());
			setYear(newDate.getYear());
		}
		//for februray
		else if (newDate.getDay() < 29 && newDate.getMonth() == 2 && newDate.getYear() % 4 != 0) {
			setDay(newDate.getDay());
			setMonth(newDate.getMonth());
			setYear(newDate.getYear());
		}
		//for leapyears
		else if (newDate.getDay() < 30 && newDate.getMonth() == 2 && newDate.getYear() % 4 == 0) {
			setDay(newDate.getDay());
			setMonth(newDate.getMonth());
			setYear(newDate.getYear());
		}
		else {
			setDay(01);
			setMonth(01);
			setYear(2000);
		}
	}
	else if (newDate.getDay()== 0 && newDate.getMonth() > -1 && newDate.getMonth() < 13 && newDate.getYear() == 0 || newDate.getYear() > 2017) {
		setDay(newDate.getDay());
		setMonth(newDate.getMonth());
		setYear(newDate.getYear());
	}
	else if (newDate.getMonth() == 0 && newDate.getDay() > -1 && newDate.getDay() < 32 && newDate.getYear() == 0 || newDate.getYear() > 2017) {
		setDay(newDate.getDay());
		setMonth(newDate.getMonth());
		setYear(newDate.getYear());
	}
	else {
		setDay(01);
		setMonth(01);
		setYear(2000);
	}
}
void Date::setDate(string newDate) {
	Date tempDate;
	string stringDay, stringMonth, stringYear;
	stringDay = "empty";
	stringMonth = "empty";
	stringYear = "empty";
	int tempDay, tempMonth, tempYear;

	int p = 0;
	for (int i = 0; i < newDate.size();i++) {
		//filter for day
		if ((newDate[i] == '.') && stringDay == "empty") {
			//for ..'year' syntax
			if (i == 0) {
				stringDay = "0";
			}
			else {
				stringDay = copyStringPart(p, i, newDate);
			}
			p = i;
		}
		//filter for month
		else if ((newDate[i] == '.') && stringMonth == "empty" && stringDay != "empty") {
			//for ..'year' syntax
			if (newDate[i - 1] == '.') {
				stringMonth = "0";
			}
			else {
				stringMonth = copyStringPart(p + 1, i, newDate);
			}
			p = i;
		}
		//filter for year
		if (i+1==newDate.size()) {
			//for 'day'.. syntax
			if (newDate[i] == '.') {
				stringYear = "0";
			}
			else {
				stringYear = copyStringPart(p + 1, i + 1, newDate);
			}
		}
	}
	//Convert to string to integer
	istringstream bufferOne(stringDay);
	bufferOne >> tempDay;

	istringstream bufferTwo(stringMonth);
	bufferTwo >> tempMonth;

	istringstream bufferThree(stringYear);
	bufferThree >> tempYear;

	//bring values in date format
	tempDate.setDay(tempDay);
	tempDate.setMonth(tempMonth);
	tempDate.setYear(tempYear);

	//check if values are corect and set them if so
	setDate(tempDate);
}
void Date::addMonth(int amaount) {
	if (amaount > 12 || amaount < -12 || month == 0)
		return;
	else if (amaount < 0) {
		if (month + amaount > 0) {
			month += amaount;
		}
		else {
			month = (month + amaount) + 12;
			if (year != 0) {
				year -= 1;
			}
		}
	}
	else if (amaount > 0) {
		if (month + amaount < 13) {
			month += amaount;
		}
		else {
			month = (month + amaount) - 12;
			if (year != 0) {
				year += 1;
			}
		}
	}
	if (day > 28 && month == 2) {
		day == 28;
	}
	if (day == 31 && month % 2 == 0) {
		day = 30;
	}
	if (year != 0) {
		
		if (day > 28 && month == 2 && year % 4 != 0) {
			day == 28;
		}
		if (day > 29 && month == 2 && year % 4 == 0) {
			day == 29;
		}
	}
}
string Date::copyStringPart( int start, int end, string mainString) {
	string result;
	switch (end - start) {
	case 1: result = "0"; break;
	case 2: result = "00";break;
	case 3: result = "000";break;
	case 4: result = "0000";break;
	}
	for (int i = 0;i+start < end;i++) {
		result[i] = mainString[i + start];
	}
	return result;
}
Date Date::getDate(){
	return Date();
}

string Date::getDateAsString() {
	string partOne, partTwo, partThree;
	partOne = to_string(day);
	partTwo = to_string(month);
	partThree = to_string(year);

	return partOne + "." + partTwo + "." + partThree;
}
int Date::getDay() {
	return day;
}
int Date::getMonth() {
	return month;
}
int Date::getYear() {
	return year;
}
bool Date::operator==(Date tempDate) {
	// 0 values enable timespann search
	if ((day == tempDate.getDay() || day == 0 || tempDate.getDay()== 0) && 
		(month == tempDate.getMonth() || month == 0 || tempDate.getMonth()==0) && 
		(year == tempDate.getYear() || year == 0 || tempDate.getYear() == 0)) {
		return true;
	}
	return false;
}
bool Date::operator!=(Date tempDate) {
	// 0 values enable timespann search
	if ((day == tempDate.getDay() || day == 0 || tempDate.getDay() == 0) &&
		(month == tempDate.getMonth() || month == 0 || tempDate.getMonth() == 0) &&
		(year == tempDate.getYear() || year == 0 || tempDate.getYear() == 0)) {
		return false;
	}
	return true;
}
bool Date::operator<(Date tempDate) {
	if (year < tempDate.getYear()) {
		return true;
	}
	if ((year == tempDate.getYear() || year == 0 || tempDate.getYear() == 0) && month < tempDate.getMonth()) {
		return true;
	}
	if ((year == tempDate.getYear() || year == 0 || tempDate.getYear() == 0) && 
		(month == tempDate.getMonth() || month == 0 || tempDate.getMonth() == 0) && 
		(day < tempDate.getDay())) {
		return true;
	}
	return false;
}
bool Date::operator>(Date tempDate) {
	if (year > tempDate.getYear()) {
		return true;
	}
	if ((year == tempDate.getYear() || year == 0 || tempDate.getYear() == 0) && month > tempDate.getMonth()) {
		return true;
	}
	if ((year == tempDate.getYear() || year == 0 || tempDate.getYear() == 0) &&
		(month == tempDate.getMonth() || month == 0 || tempDate.getMonth() == 0) &&
		(day > tempDate.getDay())) {
		return true;
	}
	return false;
}
Date Date::operator=(Date tempDate) {
	Date newDate;
	newDate.setDay(tempDate.getDay());
	newDate.setMonth(tempDate.getMonth());
	newDate.setYear(tempDate.getYear());
	return newDate;
}
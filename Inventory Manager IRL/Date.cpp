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
	if (newDate.day > 0 && newDate.month > 0 && newDate.month < 13 && newDate.year> 2017) {
		//for months with 31 days
		if (newDate.day < 32 && newDate.month % 2 == 1) {
			setDay(newDate.day);
			setMonth(newDate.month);
			setYear(newDate.year);
		}
		//for months with 30 days
		else if (newDate.day < 31 && newDate.month % 2 == 0 && newDate.month != 2) {
			setDay(newDate.day);
			setMonth(newDate.month);
			setYear(newDate.year);
		}
		//for februray
		else if (newDate.day < 29 && newDate.month == 2 && newDate.year % 4 != 0) {
			setDay(newDate.day);
			setMonth(newDate.month);
			setYear(newDate.year);
		}
		//for leapyears
		else if (newDate.day < 30 && newDate.month == 2 && newDate.year % 4 == 0) {
			setDay(newDate.day);
			setMonth(newDate.month);
			setYear(newDate.year);
		}
		else {
			setDay(01);
			setMonth(01);
			setYear(2000);
		}
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
		if ((newDate[i] == '.')&& stringDay == "empty") {
			stringDay = copyStringPart(p, i, newDate);
			p = i;
		}
		//filter for month
		else if ((newDate[i] == '.')&& stringMonth == "empty") {
			stringMonth = copyStringPart(p+1, i, newDate);
			p = i;
		}
		//filter for year
		else if (i+1==newDate.size()) {
			stringYear = copyStringPart(p+1, i+1, newDate);
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
	if (day == tempDate.getDay() && month == tempDate.getMonth() && year == tempDate.getYear()) {
		return true;
	}
	return false;
}
bool Date::operator!=(Date tempDate) {
	if (day == tempDate.getDay() && month == tempDate.getMonth() && year == tempDate.getYear()) {
		return false;
	}
	return true;
}

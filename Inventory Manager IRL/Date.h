#pragma once
#include <string>

class Date 
{
public:
	Date();
	Date(string newDate);
	~Date();
	void setDay(int newDay);
	void setMonth(int newMonth);
	void setYear(int newYear);
	void setDate(Date newDate);
	void setDate(string newDate);
	void addMonth(int amaout);
	string copyStringPart(int start, int end, string mainString);
	Date getDate();
	string getDateAsString();
	int getDay();
	int getMonth();
	int getYear();
	bool operator==(Date tempDate);
	bool operator!=(Date tempDate);
	bool operator<(Date tempDate);
	bool operator>(Date tempDate);
	Date operator=(Date tempDate);
private:
	int day;
	int month;
	int year;
};
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
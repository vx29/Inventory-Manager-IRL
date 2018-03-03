#pragma once
#include "Date.h"
using namespace std;
enum STORAGETYPES  { Frozen, Cooled, Normal };
enum ITEMTYPES { Food, Cleaning, Bathroom };
class Item
{
public:
	Item();
	Item(string newDate, string newName, STORAGETYPES newType, ITEMTYPES newItemType);
	~Item();
	void setExperationDate(Date newDate);
	void setExperationDate(string newDate);
	string getExperationDate();
	void setItemName(string newName);
	string getItemName();
	void setStorageType(STORAGETYPES newType);
	STORAGETYPES getStorageType();
	string getStorageTypeAsString();
	void setItemType(ITEMTYPES newType);
	ITEMTYPES getItemType();
	string getItemTypeAsString();
private:
	Date experationDate;
	string itemName;
	STORAGETYPES storageType;
	ITEMTYPES itemType;
};


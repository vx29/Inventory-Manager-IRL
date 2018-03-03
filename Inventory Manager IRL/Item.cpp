#include "stdafx.h"
#include "Item.h"


Item::Item()
{
	setExperationDate("01.01.2000");
	setItemName("Nudeln");
	setStorageType(Normal);
	setItemType(Food);
}
Item::Item(string newDate, string newName, STORAGETYPES newType, ITEMTYPES newItemType) {
	setExperationDate(newDate);
	setItemName(newName);
	setStorageType(newType);
	setItemType(newItemType);
}
Item::~Item()
{
}
void Item::setExperationDate(Date newDate) {
	experationDate = newDate;
}
void Item::setExperationDate(string newDate) {
	experationDate.setDate(newDate);
}
string Item::getExperationDate() {
	return experationDate.getDateAsString();
}
void Item::setItemName(string newName) {
	itemName = newName;
}
string Item::getItemName() {
	return itemName;
}
void Item::setStorageType(STORAGETYPES newType) {
	storageType = newType;
}
STORAGETYPES Item::getStorageType() {
	return storageType;
}
string Item::getStorageTypeAsString() {
	switch (getStorageType()) {
	case Frozen:
		return "Frozen";
		break;
	case Cooled:
		return "Cooled";
		break;
	case Normal:
		return "Normal";
		break;
	default:
		return "No StorageTyp present";
		break;
	}
}
void Item::setItemType(ITEMTYPES newType) {
	itemType = newType;
}
ITEMTYPES Item::getItemType() {
	return itemType;
}
string Item::getItemTypeAsString() {
	switch (getItemType()) {
	case Food:
		return "Food";
		break;
	case Bathroom:
		return "Bathroom";
		break;
	case Cleaning:
		return "Cleaning";
		break;
	default:
		return "No ItemTyp present";
		break;
	}
}

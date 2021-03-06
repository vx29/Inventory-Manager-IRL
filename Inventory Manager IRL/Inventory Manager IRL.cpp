// Inventory Manager IRL.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Item.h"

void addItem();
void addFoodItem();
void addCleaningItem();
void addBathroomItem();
void subtractItem();
void subtractFoodItem();
void subtractCleaningItem();
void subtractBathroomItem();
void writeNewItem(Item newItem);
void deleteExistingItem(Item newItem);
void compileList();
void display(string newItemType, string newType, string newName, Date newDate, int timeSpann);

void display();
bool dateWithinTimespann(int timeSpann, Date middleDate, Date actualDate);

string exctract(string mainString, int positionOfInformation);
void manageItems();
void compileShoppingList();
void compileAboutToSpoileList();

int main()
{
	int choice = 0;
	//runs until ended by user
	while (choice != 6) {
		cout << ("Menue: Bitte waehle aus!\n");
		cout << ("1 Fuege Item hinzu.\n");
		cout << ("2 Entferne Item.\n");
		cout << ("3 Erstelle Einkaufsliste.\n");
		cout << ("4 Was muss drigend weg?!\n");
		cout << ("5 Erstelle eine Liste.\n");
		cout << ("6 Beende das Programm!\n");
		cout << endl;

		//user choice
		cin >> choice;
		switch (choice) {
		case 1:
			addItem();
			break;
		case 2:
			subtractItem();
			break;
		case 3:
			compileShoppingList();
			break;
		case 4:
			compileAboutToSpoileList();
			break;
		case 5:
			compileList();
			break;
		case 6://end programm
			cout << ("Auf Wiedersehen!");
			cout << endl;
			break;
		default:
			cout << ("Keine Gieltige Eingabe! Bitte Versuche es erneut!");
			cout << endl;
			break;
		}
	}

    return 0;
}
void addItem() {
	int choice = 0;
	//runs until ended by user
	while (choice != 4) {
		cout << ("Welche Art von Item moechtest du hinzufuegen?\n");
		cout << ("1 Etwas zum Essen.\n");
		cout << ("2 Etwas fuers Badezimmer wie Duschgel etc.\n");
		cout << ("3 Etwas zum Putzen.\n");
		cout << ("4 Zurueck zum Menue!\n");
		cout << endl;
		//user choice
		cin >> choice;

		switch (choice) {
		case 1:
			addFoodItem();
			break;
		case 2:
			addBathroomItem();
			break;
		case 3:
			addCleaningItem();
			break;
		case 4://returns to main
			cout << ("Auf Wiedersehen!");
			cout << endl;
			break;
		default:
			cout << ("Keine Gueltige Eingabe! Bitte Versuche es erneut!");
			cout << endl;
			break;
		}
	}
}
void addFoodItem() {
	int choice = 0;
	STORAGETYPES tempType;
	string tempName;
	string tempDate;
	while (choice != 4) {
		cout << ("Art der Aufbewahrung?\n");
		cout << ("1 Gefrohren.\n");
		cout << ("2 Gekuehlt\n");
		cout << ("3 Ganz Normal\n");
		cout << ("4 Zurueck zum Menue!\n");
		cout << endl;

		cin >> choice;

		switch (choice) {
		case 1:
			tempType = Frozen;
			choice = 4;
			break;
		case 2:
			tempType = Cooled;
			choice = 4;
			break;
		case 3:
			tempType = Normal;
			choice = 4;
			break;
		case 4://returns to main
			cout << ("Auf Wiedersehen!");
			cout << endl;
			break;
		default:
			cout << ("Keine Gueltige Eingabe! Bitte Versuche es erneut!");
			cout << endl;
			break;
		}
	}
	//prompt for name of product
	cout << ("Name:");
	cout << endl;
	cin >> tempName;

	//prompt for experation date
	cout << ("Haltbarkeitsdatum:");
	cout << endl;
	cin >> tempDate;

	//create new Item to save data
	Item FoodItem(tempDate, tempName, tempType, Food);

	cout << ("Danke. Speicher Eingabe.");
	cout << endl;	

	//write data to file
	writeNewItem(FoodItem);
}
void addCleaningItem() {
	string tempName;
	string tempDate;

	//prompt for name of product
	cout << ("Name:");
	cout << endl;
	cin >> tempName;

	//promt for experation date?! sensible?
	cout << ("Haltbarkeitsdatum:");
	cout << endl;
	cin >> tempDate;

	//save data in new object
	Item CleaningItem(tempDate, tempName, Normal, Cleaning);

	cout << ("Danke. Speicher Eingabe.");
	cout << endl;

	//write data to file
	writeNewItem(CleaningItem);
}
void addBathroomItem() {
	string tempName;
	string tempDate;

	//prompt for name of product
	cout << ("Name:");
	cout << endl;
	cin >> tempName;

	//prompt for experation date
	cout << ("Haltbarkeitsdatum:");
	cout << endl;
	cin >> tempDate;

	//save data in new Object
	Item BathroomItem(tempDate, tempName, Normal, Bathroom);

	cout << ("Danke. Speicher Eingabe.");
	cout << endl;

	//write data to file
	writeNewItem(BathroomItem);
}
void subtractItem() {
	int choice = 0;
	while (choice != 4) {
		cout << ("Welche Art von Item moechtest du entfernen?\n");
		cout << ("1 Etwas zum Essen.\n");
		cout << ("2 Etwas fuers Badezimmer wie Duschgel etc.\n");
		cout << ("3 Etwas zum Putzen.\n");
		cout << ("4 Beende das Programm!\n");
		cout << endl;

		//user choice
		cin >> choice;

		switch (choice) {
		case 1:
			subtractFoodItem();
			break;
		case 2:
			subtractBathroomItem();
			break;
		case 3:
			subtractCleaningItem();
			break;
		case 4://returns to main
			cout << ("Auf Wiedersehen!");
			cout << endl;
			break;
		default:
			cout << ("Keine Gueltige Eingabe! Bitte Versuche es erneut!");
			cout << endl;
			break;
		}
	}
}
void subtractFoodItem() {
	int choice = 0;
	STORAGETYPES tempType;
	string tempName;
	string tempDate;
	while (choice != 4) {
		cout << ("Art der Aufbewahrung?\n");
		cout << ("1 Gefrohren.\n");
		cout << ("2 Gekuehlt\n");
		cout << ("3 Ganz Normal\n");
		cout << ("4 Zurueck zum Menue!\n");
		cout << endl;

		cin >> choice;

		switch (choice) {
		case 1:
			tempType = Frozen;
			choice = 4;
			break;
		case 2:
			tempType = Cooled;
			choice = 4;
			break;
		case 3:
			tempType = Normal;
			choice = 4;
			break;
		case 4:
			cout << ("Auf Wiedersehen!");
			cout << endl;
			break;
		default:
			cout << ("Keine Gueltige Eingabe! Bitte Versuche es erneut!");
			cout << endl;
			break;
		}
	}
	cout << ("Name:");
	cout << endl;
	cin >> tempName;

	cout << ("Haltbarkeitsdatum:");
	cout << endl;
	cin >> tempDate;

	Item FoodItem(tempDate, tempName, tempType, Food);

	cout << ("Danke. Suche nach zu entfernendem Eintrag.");
	cout << endl;

	//search for existing item
	deleteExistingItem(FoodItem);
}
void subtractCleaningItem() {
	string tempName;
	string tempDate;

	cout << ("Name:");
	cout << endl;
	cin >> tempName;

	cout << ("Haltbarkeitsdatum:");
	cout << endl;
	cin >> tempDate;

	Item CleaningItem(tempDate, tempName, Normal, Cleaning);

	cout << ("Danke. Suche nach zu entfernendem Eintrag.");
	cout << endl;

	deleteExistingItem(CleaningItem);
}
void subtractBathroomItem() {
	string tempName;
	string tempDate;

	cout << ("Name:");
	cout << endl;
	cin >> tempName;

	cout << ("Haltbarkeitsdatum:");
	cout << endl;
	cin >> tempDate;

	Item BathroomItem(tempDate, tempName, Normal, Bathroom);

	cout << ("Danke. Suche nach zu entfernendem Eintrag.");
	cout << endl;

	deleteExistingItem(BathroomItem);
}
void writeNewItem(Item newItem) {
	string helperStringOne, helperStringTwo, helperStringThree, helperStringFour;
	ofstream ItemList;
	helperStringOne = newItem.getItemTypeAsString();
	helperStringTwo = newItem.getStorageTypeAsString();
	helperStringThree = newItem.getItemName();
	helperStringFour = newItem.getExperationDate();
	ItemList.open("ItemList.txt", ios_base::out | ios_base::app);
	//Format ItemType StorageType ItemName ExperationDate
	ItemList << ("{[" + helperStringOne + "][" + helperStringTwo + "][" + helperStringThree + "][" + helperStringFour + "]}");
	ItemList << endl;
	ItemList.close();
}
void deleteExistingItem(Item newItem) {
	bool wasItemDeleted = false;
	string helperStringOne, helperStringTwo, helperStringThree, helperStringFour;
	string searchedString, line;
	//compile searchedString
	helperStringOne = newItem.getItemTypeAsString();
	helperStringTwo = newItem.getStorageTypeAsString();
	helperStringThree = newItem.getItemName();
	helperStringFour = newItem.getExperationDate();
	searchedString = ("{[" + helperStringOne + "][" + helperStringTwo + "][" + helperStringThree + "][" + helperStringFour + "]}");
	
	// open input file
	ifstream in("ItemList.txt");
	if (!in.is_open())
	{
		cout << "ItemList konnte nicht geoeffnet werden!\n";
	}
	// now open temp output file
	ofstream out("ItemListTemp.txt");
	// loop to read/write the file.  Note that you need to add code here to check
	// if you want to write the line
	while (getline(in, line))
	{
		if (line != searchedString) {
			out << line << "\n";
		}
		else {
			cout << "Objekt wurde gefunden und erflgreich geloescht.";
			cout << endl;
			wasItemDeleted = true;
		}
	}
	in.close();
	out.close();
	// delete the original file
	remove("ItemList.txt");
	// rename old to new
	rename("ItemListTemp.txt", "ItemList.txt");
	// all done!
	if (wasItemDeleted == false) {
		cout << "Objekt konnte nicht gefunden werden!";
		cout << endl;
	}
}
void compileList() {
	int choice = 0;
	int choiceTwo = 0;
	int choiceThree = 0;
	int timeSpann = 0;
	string tempName = "";
	string inputStorage;
	string appendStorage;
	string appendStorageTwo;
	Date tempDate;
	string tempType = "";
	string tempItemType = "";
	while (choice != 6) {
		cout << ("Welche Art von Liste moechtest du erstellen?\n");
		cout << ("1 Nur Essen.\n");
		cout << ("2 Nur Badezimmersachen.\n");
		cout << ("3 Nur Putzsachen.\n");
		cout << ("4 Benutzerdefiniert.\n");
		cout << ("5 Alles.\n");
		cout << ("6 Zurueck zum Menue!\n");
		cout << endl;

		cin >> choice;

		switch (choice)//switch for List Type
		{
		case 1: tempItemType = "Food"; break;
		case 2: tempItemType = "Bathroom"; break;
		case 3: tempItemType = "Cleaning"; break;
		case 4://custome
			cout << "Art der Lagerung?\n";
			cout << ("1 Gefroren.\n");
			cout << ("2 Gekuehlt.\n");
			cout << ("3 Normal.\n");
			cout << ("4 Egal.\n");
			cout << endl;

			cin >> choiceTwo;//choice for Storage Type

			switch (choiceTwo)//switch for Storage Type
			{
			case 1: tempType = "Frozen"; break;
			case 2: tempType = "Cooled"; break;
			case 3: tempType = "Normal"; break;
			case 4: break;
			default:
				cout << "Eingabe ungueltig! Lagerungstyp wurde auf Egal gestzt";
				cout << endl;
				break;
			}

			cout << "Art der gesuchten Objektes?\n";
			cout << ("1 Essen.\n");
			cout << ("2 Putzsachen.\n");
			cout << ("3 Badezimmersachen.\n");
			cout << ("4 Egal.\n");
			cout << endl;

			cin >> choiceThree;//choice for Item Type

			switch (choiceThree)//switch von Item Type
			{
			case 1: tempItemType = "Food"; break;
			case 2: tempItemType = "Cleaning"; break;
			case 3: tempItemType = "Bathroom"; break;
			case 4: break;
			default:
				cout << "Eingabe ungueltig! Objektstyp wurde auf Egal gestzt";
				cout << endl;
				break;
			}

			//set name and Date or choose not to with 1
			cout << "Wie heisst das Objekt(Falls du nicht nach Namen suchen moechtest, drueck einfach 1)?" << endl;
			cin >> inputStorage;

			if (inputStorage != "1") {//set name if user wants to search for name
				tempName = inputStorage;
			}

			cout << ("Wann laeuft das Objekt ab(Falls du nicht nach Datum suchen moechtest, drueck einfach 1)?\n")
				<< ("Fuer einen Zeitraum gebe \n'anzahlDerMonate(1 bis 9)'-\n'Tag oder leer lassen(0 bis 31)'.\n'Monat oder leer lassen(0 bis 12)'.\n'Jahr oder leer lassen(0 der < 2017)'\n")
				<< endl;
			cin >> inputStorage;

			if (inputStorage != "1") {//set date if user wants to search for date
				if (inputStorage[1] == '-') {//time spann feature
					//extract timespann
					appendStorage.append(inputStorage.begin(), inputStorage.begin()+1);
					istringstream bufferOne(appendStorage);
					bufferOne >> timeSpann;
					appendStorageTwo.append(inputStorage.begin() + 2, inputStorage.end());
					tempDate.setDate(appendStorageTwo);
				}
				else {//no time spann
					tempDate.setDate(inputStorage);
				}
			}
			break;//end case 4
		case 5:
			display();
			break;
		case 6:
			cout << ("Auf Wiedersehen!");
			cout << endl;
			break;
		default:
			cout << ("Keine Gueltige Eingabe! Bitte Versuche es erneut!");
			cout << endl;
			break;
		}
		display(tempItemType, tempType, tempName, tempDate, timeSpann);
	}
}
void display(string newItemType, string newType, string newName, Date newDate, int timeSpann) {
	Date standartDate;
	Date tempDate;
	string line;
	ifstream in("ItemList.txt");

	if (!in.is_open())
	{
		cout << "ItemList konnte nicht geoeffnet werden!\n";
	}
	cout << "\n\n" << endl;
	while (getline(in, line))
	{
		//only criteria which aren't empty(or in case of date standart date) will be chosen to find correct line
		tempDate.setDate(exctract(line, 4));

		if ((exctract(line, 1) == newItemType || newItemType == "") &&
			(exctract(line, 2) == newType || newType == "") &&
			(exctract(line, 3) == newName || newName == "") &&
			((tempDate == newDate || newDate == standartDate) && (timeSpann == 0 || newDate.getMonth() == 0)) ||
			(dateWithinTimespann(timeSpann, newDate, tempDate))) {
			cout << exctract(line, 1)
				<< "---"
				<< exctract(line, 2)
				<< "---"
				<< exctract(line, 3)
				<< "---"
				<< exctract(line, 4)
				<< endl;
		}
	}
	cout << "\n\n" << endl;
	in.close();
}
void display() {
	string line;
	ifstream in("ItemList.txt");
	if (!in.is_open())
	{
		cout << "ItemList konnte nicht geoeffnet werden!\n";
	}
	cout << "\n\n" << endl;
	while (getline(in, line))
	{
		cout << exctract(line, 1)
			<< "---"
			<< exctract(line, 2)
			<< "---"
			<< exctract(line, 3)
			<< "---"
			<< exctract(line, 4)
			<< endl;
	}
	cout << "\n\n" << endl;
	in.close();
}
bool dateWithinTimespann(int timeSpann, Date middleDate, Date actualDate) {
	Date lowerLimit = middleDate, upperLimit = middleDate;
	//lower limit 
	lowerLimit.addMonth(-timeSpann);
	//upper limit
	upperLimit.addMonth(timeSpann);
	//checks if actualDate is in between of lower and upper limit
	if (lowerLimit < actualDate && upperLimit > actualDate) {
		return true;
	}
	return false;
}
string exctract(string mainString, int positionOfInformation) {
	bool isWritting = false;
	int counter = 0, n=0;
	string result = "                                  ";

	if (positionOfInformation < 1 || positionOfInformation>4) {
		cout << "Invalide searchposition!";
		cout << endl;
		return "empty";
	}
	for (int i = 0;i < mainString.size();i++) {
		if (mainString[i] == '[') {
			counter++;
		}
		else if (mainString[i] == ']'&& counter == positionOfInformation) {
			isWritting = false;
			break;
		}
		if (isWritting) {
			result[n] = mainString[i];
			n++;
		}
		else if (counter == positionOfInformation) {
			isWritting = true;
		}
		
	}
	result.resize(n);
	return result;
}
void manageItems() {

}
void compileShoppingList() {

}
void compileAboutToSpoileList() {

}
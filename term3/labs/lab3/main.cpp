#include "EducatorPartyMember.h"


int main() {
	
	std::cout << "class EducatorPartyMember" << std::endl;
	EducatorPartyMember educatorsPartyMembers[2];

	for (int i = 0; i < 2; i++) {
		std::cin >> educatorsPartyMembers[i];
		std::cout << std::endl;
	}

	
	EducatorPartyMember::classView();
	for (int i = 0; i < 2; i++)	{
		std::cout << educatorsPartyMembers[i] << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << "Choose person which you want change: ";
	int numberEducatorPartyMember;
	std::cin >> numberEducatorPartyMember;
	std::cout << std::endl;
	numberEducatorPartyMember--;

	std::cout << "Choose parametr which you want change: " << std::endl;
	std::cout << "1. name\t2.BirthYear\t3.Specialty\t4.PartyName\t5.PartyRole: ";
	int numberParametr;
	std::cin >> numberParametr;

	std::cout << std::endl;
	std::cin.ignore();

	String newString;
	int newInt;
	
	switch (numberParametr)
	{
	case 1:
		std::cout << "Enter new name: ";
		std::cin >> newString;
		educatorsPartyMembers[numberEducatorPartyMember].setName(newString);
		break;
		
	case 2:
		std::cout << "Enter new year of birth: ";
		std::cin >> newInt;
		educatorsPartyMembers[numberEducatorPartyMember].setBirthYear(newInt);
		break;

	case 3:
		std::cout << "Enter new specialty: ";
		std::cin >> newString;
		educatorsPartyMembers[numberEducatorPartyMember].setSpecialty(newString);
		break;
	case 4:
		std::cout << "Enter new party name: ";
		std::cin >> newString;
		educatorsPartyMembers[numberEducatorPartyMember].setPartyName(newString);
		break;
	case 5:
		std::cout << "Enter new party role: ";
		std::cin >> newString;
		educatorsPartyMembers[numberEducatorPartyMember].setPartyRole(newString);
		break;
	default:
		break;
	}
	
	std::cout << std::endl;

	EducatorPartyMember::classView();
	for (int i = 0; i < 2; i++) {
		std::cout << educatorsPartyMembers[i] << std::endl;
	}
	system("pause");
	system("cls");


	return 0;
}	
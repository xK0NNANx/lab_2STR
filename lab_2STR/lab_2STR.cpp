#define _CRT_SECURE_NO_WARNINGS
#include <iostream>



void proccesing(char* String) {
	int i = 0;
	int j;
	while (String[i] != '\0') {
		if (String[i] == '?') {
			if ((String[i + 1] > 64 and String[i + 1] < 91) or (String[i + 1] > 96 and String[i + 1] < 123)) {
				if (String[i + 1] != 65 and String[i + 1] != 69 and String[i + 1] != 73 and String[i + 1] != 79 and String[i + 1] != 85 and String[i + 1] != 89
					and String[i + 1] != 97 and String[i + 1] != 101 and String[i + 1] != 105 and String[i + 1] != 111 and String[i + 1] != 113 and String[i + 1] != 117) {
					j = i + 1;
					String[i] = '!';
					char time_el = '!';
					while (String[j] != '\0') {
						char t = String[j];
						String[j] = time_el;
						time_el = t;
						j++;
					}
					String[j] = time_el;
					String[j + 1] = '\0';
				}
				else
				{
					String[i] = ' ';
				}
			}
		}
		i++;
	}
}


void quest1() {
	char* string;
	char* string2;
	char letter;
	int CountEl = 1;

	std::cin >> letter;
	string = (char*)malloc(CountEl * sizeof(char));
	string[CountEl-1] = letter;
	std::cin >> letter;
	while (letter != '.') {
		CountEl++;
		string2 = (char*)malloc(CountEl * sizeof(char));
		for (int i = 0; i < CountEl-1; i++) {
			string2[i] = string[i];
		}
		string2[CountEl-1] = letter;
		std::cin >> letter;
		free(string);
		string = string2;
	}

	proccesing(string);

	for (int i = 0; i < CountEl - 1; i++) {
		std::cout << string[i];
	}
}


void quest2() {
	char* string;
	char letter;
	int id = 0;
	int SizeString = 3;

	string = (char*)calloc(SizeString, sizeof(char));
	std::cin >> letter;
	while (letter != '.') {
		string[id] = letter;
		id++;
		if (id > SizeString-1) {
			string = (char*)realloc(string, (SizeString += 3) * sizeof(char));
		}
		std::cin >> letter;
	}


	proccesing(string);

	for (int i = 0; string[i] >= 0 and string[i] <= 127; i++) {
		std::cout << string[i];
	}
}


void quest3() {
	FILE* Enter_file = fopen("Enter.txt", "w+");
	FILE* Out_file = fopen("Out.txt", "w");
	char* string;
	char letter;
	int id = 0;
	int SizeString = 3;

	string = (char*)calloc(SizeString, sizeof(char));
	std::cin >> letter;
	while (letter != '.') {
		string[id] = letter;
		id++;
		if (id > SizeString - 1) {
			string = (char*)realloc(string, (SizeString += 3) * sizeof(char));
		}
		std::cin >> letter;
	}

	fputs(string, Enter_file);
	fclose(Enter_file);

	proccesing(string);

	for (int i = 0; string[i] >= 0 and string[i] <= 127; i++) {
		fputc(string[i], Out_file);
	}

}

int main()
{
	//quest1();

	//quest2();

	quest3();
}

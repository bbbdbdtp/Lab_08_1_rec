#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

int Count(char* str, int index = 0) {
    if (str[index] == '\0')
        return 0;

    int count = Count(str, index + 1);

    if (str[index] == 'B' || str[index] == 'A' || str[index] == 'S' || str[index] == 'I' || str[index] == 'C')
        count++;

    return count;
}

char* Change(char* str, char* tmp, char* t, size_t i) {
    if (strlen(str) < 5)
        return str;

    if (str[i + 4] == '\0') {
        *t++ = str[i++];
        *t++ = str[i++];
        *t++ = str[i++];
        *t++ = str[i++];
        *t = '\0';

        strcpy(str, tmp);
        return tmp;
    }

    if (str[i] == 'B' && str[i + 1] == 'A' && str[i + 2] == 'S' && str[i + 3] == 'I' && str[i + 4] == 'C') {
        strcat(t, "Delphi");
        t += 6;
        i += 5;
    }
    else {

        *t++ = str[i++];
        *t = '\0';
    }

    return Change(str, tmp, t, i);
}

int main()
{
    char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);
	cout << "String contained " << Count(str, 0) << " characters included in the word \"BASIC\"" << endl;
	char* dest = new char[121];

    char* tmp = new char[strlen(str) * 6 / 5 + 1];
    char* t = tmp;
    tmp[0] = '\0';
    
	dest = Change(str, tmp, t, 0);
	cout << "Modified string: " << dest << endl;
	return 0;
}
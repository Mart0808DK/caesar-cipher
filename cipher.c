#include "cipher.h"
#include <string.h>
#include <ctype.h>

const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZÆØÅ";
const int alphabetLength = sizeof(alphabet) - 1;

int letter_to_number(char letter) {
    letter = toupper(letter);
    for (int i = 0; i < alphabetLength; i++) {
        if (alphabet[i] == letter) {
            return i;
        }
    }
    return -1;
}

char number_to_letter(int number) {
    if (number >= 0 && number < alphabetLength) {
        return alphabet[number];
    }
    return '\0';
}

int shift(int number, int shiftValue) {
    return (number + shiftValue + alphabetLength) % alphabetLength;
}

void encrypt(char *text, int shiftValue) {
    for (int i = 0; i < strlen(text); i++) {
        int is_lowercase = islower(text[i]);
        int letterNumber = letter_to_number(text[i]);
        if (letterNumber != -1) {
            int shiftedNumber = shift(letterNumber, shiftValue);
            text[i] = number_to_letter(shiftedNumber);
            if (is_lowercase) {
                text[i] = tolower(text[i]);
            }
        }
    }
}

void decrypt(char *text, int shiftValue) {
    for (int i = 0; i < strlen(text); i++) {
        int is_lowercase = islower(text[i]);
        int letterNumber = letter_to_number(text[i]);
        if (letterNumber != -1) {
            int shiftedNumber = shift(letterNumber, -shiftValue);
            text[i] = number_to_letter(shiftedNumber);
            if (is_lowercase) {
                text[i] = tolower(text[i]);
            }
        }
    }
}
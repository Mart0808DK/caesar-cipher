#include <stdio.h>
#include <string.h>
#include "cipher.h"
#include <stdlib.h>


void get_choice_char(char *choice);
void get_shift_value(int *shiftValue);
void get_text(char *text);
void display_menu();

int main() {
    char choice = '\0';
    char text[256];
    int shiftValue;

    while (1) {
        display_menu();
        get_choice_char(&choice);

        if (choice == 'q') {
            break;
        }

        printf("Enter the text: ");
        get_text(text);

        printf("Enter the shift value: ");
        get_shift_value(&shiftValue);

        if (choice == 'e') {
            encrypt(text, shiftValue);
            printf("Encrypted text: %s\n", text);
        } else if (choice == 'd') {
            decrypt(text, shiftValue);
            printf("Decrypted text: %s\n", text);
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void get_choice_char(char *choice) {
    char buffer[256];
    if (fgets(buffer, sizeof(buffer), stdin) != NULL)
    {
        *choice = buffer[0];
    } else
    {
        *choice = 'q';
    }
}

void get_shift_value(int *shiftValue) {
    char buffer[256];
    if (fgets(buffer, sizeof(buffer), stdin) != NULL)
    {
        *shiftValue = atoi(buffer);
    } else
    {
        *shiftValue = 0;
    }
}

void get_text(char *text) {
    char buffer[256];
    if (fgets(buffer, sizeof(buffer), stdin) != NULL)
    {
        strcpy(text, buffer);
        text[strcspn(text, "\n")] = '\0';
    } else
    {
        *text = '\0';
    }
}

void display_menu() {
    printf("please select if you want to encrypt or decrypt\n");
    printf("(e) for encrypt\n");
    printf("(d) for derypt\n");
    printf("(q) for qutting the program\n");
    printf("Please enter a letter here: ");
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define PASSWORD_LENGTH 8  // Change this to set the length of the password

int main()
{
    char password[PASSWORD_LENGTH + 1];
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"; // Change this to set the characters allowed in the password
    int charset_length = sizeof(charset) - 1; // Subtract 1 to exclude the null terminator

    srand(time(NULL)); // Seed the random number generator with the current time

    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        password[i] = charset[rand() % charset_length];
    }

    password[PASSWORD_LENGTH] = '\0'; // Add null terminator to the end of the password string

    // Check if password contains at least one uppercase letter, one lowercase letter, and one digit
    int has_uppercase = 0, has_lowercase = 0, has_digit = 0;
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
        } else if (islower(password[i])) {
            has_lowercase = 1;
        } else if (isdigit(password[i])) {
            has_digit = 1;
        }
    }

    // If password is not valid, generate a new one
    if (!has_uppercase || !has_lowercase || !has_digit) {
        main();
    } else {
        printf("Generated password: %s\n", password);
    }

    return 0;
}


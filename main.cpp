#include <cstring>
#include <stdio.h>
#include <wiringPi.h>

// Define the pins for RGB
#define RED 0
#define GREEN 1
#define BLUE 2


// Function declaration
void askFor();
void setByBinary();
void allOff();

// Main
int main (void)
{
    // Initialize pins
    wiringPiSetup();
    pinMode (RED, OUTPUT);
    pinMode (GREEN, OUTPUT);
    pinMode (BLUE, OUTPUT);

    askFor();

    return 0;
}

// Ask what the user wants
void askFor()
{
    char whatDo[5]; // Input var

    // Ask
    printf("What would you like to do:\n");
    printf("1 - 🔴 Red\n");
    printf("2 - 🟢 Green\n");
    printf("3 - 🔵 Blue\n");
    printf("4 - 🔟 Enter binary\n");
    printf("5 - ⚫ Turn off and exit\n");

    scanf("%s", whatDo); // Input

    // Check what the input is
    if (!strcmp(whatDo, "1")) {
        int readColor = digitalRead(RED); // Read red

        // Toggle
        if (!readColor) {
            digitalWrite (RED, 1);
            printf("Turned red on.\n\n");
        } else if (readColor) {
            digitalWrite (RED, 0);
            printf("Turned red off.\n\n");
        } else {
            printf("ERROR READING COLOR");
        }

        askFor(); // Reprompt
    } else if (!strcmp(whatDo, "2")) {
        int readColor = digitalRead(GREEN); // Read green

        // Toggle
        if (!readColor) {
            digitalWrite (GREEN, 1);
            printf("Turned green on.\n\n");
        } else if (readColor) {
            digitalWrite (GREEN, 0);
            printf("Turned green off.\n\n");
        } else {
            printf("ERROR READING COLOR");
        }

        askFor(); // Reprompt
    } else if (!strcmp(whatDo, "3")) {
        int readColor = digitalRead(BLUE); // Read blue

        // Toggle
        if (!readColor) {
            digitalWrite (BLUE, 1);
            printf("Turned blue on.\n\n");
        } else if (readColor) {
            digitalWrite (BLUE, 0);
            printf("Turned blue off.\n\n");
        } else {
            printf("ERROR READING COLOR");
        }

        askFor(); // Reprompt
    } else if (!strcmp(whatDo, "4")) {
        setByBinary(); // Ask for binary
        askFor(); // Repromps
    } else if (!strcmp(whatDo, "5")) {
        allOff(); // Turn off light
        printf("Goodbye 👋\n"); // Send goodbye message
        return;
    } else {
        // If not 1-5 then reprompt
        printf("Please pick a number 1-5.");
        askFor();
    }
}

// Ask for binary function
void setByBinary()
{   
    char colorValue[5]; // Input var
    printf("Please input binary value (RGB): "); // Ask
    scanf("%s", colorValue); // Get input

    // Assign the chars to vars so the code is more readable
    char firstVal = colorValue[0];
    char secondVal = colorValue[1];
    char thirdVal = colorValue[2];  

    // Make sure it begins with binary
    if ((firstVal == '0' || firstVal == '1') && (secondVal == '0' || secondVal == '1') && (thirdVal == '0' || thirdVal == '1')) {
        digitalWrite (RED, firstVal == '1');
        digitalWrite (GREEN, secondVal == '1');
        digitalWrite (BLUE, thirdVal == '1');
        return;
    } else {
        printf("Please enter binary anywhere from 000-111.\n");
        setByBinary();
    }
    
}

// Turn all pins off function
void allOff()
{
    digitalWrite (RED, 0);
    digitalWrite (GREEN, 0);
    digitalWrite (BLUE, 0);
}
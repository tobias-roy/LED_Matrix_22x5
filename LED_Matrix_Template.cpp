#include <Adafruit_NeoPixel.h>

#define LED_PIN    12
#define LED_COUNT 110
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

//Multidimensional Array Marks LED's in a 5x22 coordinate system. My LED's are set up in a zig zag pattern.
const int matrix [5][22] = {
{ 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21},
{ 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43},
{ 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65},
{ 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87},
{ 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109}
};

//The alphabet in 3x5 pixel letters. Define the amount of LED's in the print array. 1's are lit - 0's are turned off.
int printA[15] = {1,1,1,1,1, 1,0,1,0,0, 1,1,1,1,1};
int printB[15] = {1,1,1,1,1, 1,0,1,0,1, 1,1,1,1,1};
int printC[15] = {0,1,1,1,0, 1,0,0,0,1, 1,0,0,0,1};
int printD[15] = {1,1,1,1,1, 1,0,0,0,1, 0,1,1,1,0};
int printE[15] = {1,1,1,1,1, 1,0,1,0,1, 1,0,1,0,1};
int printF[15] = {1,1,1,1,1, 1,0,1,0,0, 1,0,1,0,0};
int printG[15] = {0,1,1,1,0, 1,0,0,0,1, 1,0,1,1,1};
int printH[15] = {1,1,1,1,1, 0,0,1,0,0, 1,1,1,1,1};
int printI[15] = {1,0,0,0,1, 1,1,1,1,1, 1,0,0,0,1};
int printJ[15] = {0,0,0,1,1, 0,0,0,0,1, 1,1,1,1,1};
int printK[15] = {1,1,1,1,1, 0,0,1,0,0, 1,1,0,1,1};
int printL[15] = {1,1,1,1,1, 0,0,0,0,1, 0,0,0,0,1};
int printM[15] = {1,1,1,1,1, 0,1,0,0,0, 1,1,1,1,1};
int printN[15] = {1,1,1,1,1, 1,0,0,0,0, 1,1,1,1,1};
int printO[15] = {1,1,1,1,1, 1,0,0,0,1, 1,1,1,1,1};
int printP[15] = {1,1,1,1,1, 1,0,1,0,0, 1,1,1,0,0};
int printQ[15] = {1,1,1,0,0, 1,0,1,0,0, 1,1,1,1,1};
int printR[15] = {1,1,1,1,1, 1,0,1,0,0, 0,1,0,1,1};
int printS[15] = {0,1,0,0,1, 1,0,1,0,1, 1,0,0,1,0};
int printT[15] = {1,0,0,0,0, 1,1,1,1,1, 1,0,0,0,0};
int printU[15] = {1,1,1,1,1, 0,0,0,0,1, 1,1,1,1,1};
int printV[15] = {1,1,1,1,0, 0,0,0,0,1, 1,1,1,1,0};
int printW[15] = {1,1,1,1,1, 0,0,0,1,0, 1,1,1,1,1};
int printX[15] = {1,1,0,1,1, 0,0,1,0,0, 1,1,0,1,1};
int printY[15] = {1,1,1,0,0, 0,0,1,1,1, 1,1,1,0,0};
int printZ[15] = {1,0,0,1,1, 1,0,1,0,1, 1,1,0,0,1};
int print0[15] = {1,1,1,1,1, 1,0,0,0,1, 1,1,1,1,1};
int print1[15] = {0,1,0,0,1, 1,1,1,1,1, 0,0,0,0,1};
int print2[15] = {1,0,1,1,1, 1,0,1,0,1, 1,1,1,0,1};
int print3[15] = {1,0,1,0,1, 1,0,1,0,1, 1,1,1,1,1};
int print4[15] = {1,1,1,0,0, 0,0,1,0,0, 1,1,1,1,1};
int print5[15] = {1,1,1,0,1, 1,0,1,0,1, 1,0,1,1,1};
int print6[15] = {1,1,1,1,1, 1,0,1,0,1, 1,0,1,1,1};
int print7[15] = {1,0,0,0,0, 1,0,0,0,0, 1,1,1,1,1};
int print8[15] = {1,1,1,1,1, 1,0,1,0,1, 1,1,1,1,1};
int print9[15] = {1,1,1,0,0, 1,0,1,0,0, 1,1,1,1,1};
int printSPACE[15] = {0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0};

//Icons in 5x5 or 5x6
int printPackman[25] = {0,1,1,1,0, 1,1,1,1,1, 1,0,1,1,1, 1,1,0,1,1, 1,0,0,0,1};
int printPackmanClosed[30] = {0,1,1,1,0, 1,1,1,1,1, 1,0,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 0,1,1,1,0};
int printGhost[25] = {0,1,1,1,1, 1,0,1,1,0, 1,1,1,1,1, 1,0,1,1,0, 0,1,1,1,1};

void setup() {
    strip.begin(); //This initializes the NeoPixel library for LED control.
    strip.show();  //This resets all LED's
    strip.setBrightness(0);
}

void loop() {
    runningLetters(110, 80);
    //packmanKiller(90, 80);
}

void runningLetters(int speed, int brightness){
    strip.clear();
    strip.setBrightness(brightness);
    for(int i = 0; i <= 73; i++){

       // genericLetter(letterPlacement(1), i, strip.Color(255, 0, 15), printK);

        strip.show();
        delay(speed);
        strip.clear();
    }
}

void packmanKiller(int speed, int brightness){
    strip.clear();
    strip.setBrightness(brightness);
    bool open = true;
    for(int i = 0; i <= 35; i++){
        if(open == true){
        genericIcon5x5(-13, i, strip.Color(255, 255, 0), printPackman);
        open = false;
        }else {
        genericIcon6x5(-13, i, strip.Color(255, 255, 0), printPackmanClosed);
        open = true;
        }
        genericIcon5x5(-5, i, strip.Color(0, 0, 255), printGhost);
        strip.show();
        delay(speed);
        strip.clear();
    }
}

int letterPlacement(int placering){
    placering = placering * 4 + 17;
    return placering;
}

void genericLetter(int start, int i, uint32_t rgb, int letterArray[]){
    int column1 = start - i;    //Defines start column, i defines the movement
    int column2 = column1 + 1;  //Defines 2nd column
    int column3 = column1 + 2;  //Defines 3rd column
    if(column1 >= 0 && column1 <= 21){      //Makes sure the column is in bounds of the LED matrix before it initiates the LED's. If this is not setup properly the LEDS will change rows.
        for(int j = 0; j <= 4; j++){    //This is set to loop 5 times since we have 5 rows and it only loops through column 1 once.
            if(letterArray[j] == 1){    //Checks wether or not the LED in the first column is on or off.
                strip.setPixelColor(matrix[j][column1], rgb);   //If the LED is specified to 1 the specified placement in the matrix will be picked by the row and column values and set to a color value to turn on.
            }                                                   //j is defined as the first value in matrix = row, column1 is defined as the specific LED in that column, from the defined start and i (for movement).
        }
    }
    if(column2 >= 0 && column2 <= 21){
        for(int j = 0; j <= 4; j++){
            if(letterArray[j + 5] == 1){ //Checks wether or not the LED in the second column is on or off, thus starting from the 5th value in the array.
                strip.setPixelColor(matrix[j][column2], rgb);
            }
        }
    }
    if(column3 >= 0 && column3 <= 21){
        for(int j = 0; j <= 4; j++){
            if(letterArray[j + 10] == 1){
                strip.setPixelColor(matrix[j][column3], rgb);
            }
        }
    }
}

void genericIcon5x5(int start, int i, uint32_t rgb, int letterArray[]){
    int column1 = start + i;
    int column2 = column1 + 1;
    int column3 = column1 + 2;
    int column4 = column1 + 3;
    int column5 = column1 + 4;
    if(column1 >= 0 && column1 <= 21){
        for(int j = 0; j <= 4; j++){
            if(letterArray[j] == 1){
                strip.setPixelColor(matrix[j][column1], rgb);
            }
        }
    }
    if(column2 >= 0 && column2 <= 21){
        for(int j = 0; j <= 4; j++){
            if(letterArray[j + 5] == 1){
                strip.setPixelColor(matrix[j][column2], rgb);
            }
        }
    }
    if(column3 >= 0 && column3 <= 21){
        for(int j = 0; j <= 4; j++){
            if(letterArray[j + 10] == 1){
                strip.setPixelColor(matrix[j][column3], rgb);
            }
        }
    }
    if(column4 >= 0 && column4 <= 21){
        for(int j = 0; j <= 4; j++){
            if(letterArray[j + 15] == 1){
                strip.setPixelColor(matrix[j][column4], rgb);
            }
        }
    }
    if(column5 >= 0 && column5 <= 21){
        for(int j = 0; j <= 4; j++){
            if(letterArray[j + 20] == 1){
                strip.setPixelColor(matrix[j][column5], rgb);
            }
        }
    }
}

void genericIcon6x5(int start, int i, uint32_t rgb, int letterArray[]){
    int column1 = start + i;
    int column2 = column1 + 1;
    int column3 = column1 + 2;
    int column4 = column1 + 3;
    int column5 = column1 + 4;
    int column6 = column1 + 5;
    if(column1 >= 0 && column1 <= 21){
        for(int j = 0; j <= 4; j++){
            if(letterArray[j] == 1){
                strip.setPixelColor(matrix[j][column1], rgb);
            }
        }
    }
    if(column2 >= 0 && column2 <= 21){
        for(int j = 0; j <= 4; j++){
            if(letterArray[j + 5] == 1){
                strip.setPixelColor(matrix[j][column2], rgb);
            }
        }
    }
    if(column3 >= 0 && column3 <= 21){
        for(int j = 0; j <= 4; j++){
            if(letterArray[j + 10] == 1){
                strip.setPixelColor(matrix[j][column3], rgb);
            }
        }
    }
    if(column4 >= 0 && column4 <= 21){
        for(int j = 0; j <= 4; j++){
            if(letterArray[j + 15] == 1){
                strip.setPixelColor(matrix[j][column4], rgb);
            }
        }
    }
    if(column5 >= 0 && column5 <= 21){
        for(int j = 0; j <= 4; j++){
            if(letterArray[j + 20] == 1){
                strip.setPixelColor(matrix[j][column5], rgb);
            }
        }
    }
    if(column6 >= 0 && column6 <= 21){
        for(int j = 0; j <= 4; j++){
            if(letterArray[j + 25] == 1){
                strip.setPixelColor(matrix[j][column6], rgb);
            }
        }
    }
}
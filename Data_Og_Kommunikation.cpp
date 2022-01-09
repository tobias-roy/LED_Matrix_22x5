#include <Adafruit_NeoPixel.h>

#define LED_PIN    12
#define LED_COUNT 110
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

int animationDelay = 5;
int runningLetter = 120;
int rotation = 30;

const int matrix [5][22] = {
{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21},
{ 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43},
{ 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65},
{ 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87},
{ 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109}
};

//alfabet
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

void setup() {
    strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
    strip.show();            // Turn OFF all pixels ASAP
    strip.setBrightness(0);
}

void loop() {
    dataFade();
    ogSpinAndFade();
    runningLetters();
    delay(runningLetter);
}


void dataFade(){
    for (int i = 0; i<120;i++){
        strip.setPixelColor(3, 72, 149, 239);strip.setPixelColor(4, 72, 149, 239);strip.setPixelColor(7, 72, 149, 239);strip.setPixelColor(8, 72, 149, 239);strip.setPixelColor(9, 72, 149, 239);strip.setPixelColor(11, 72, 149, 239);strip.setPixelColor(12, 72, 149, 239);strip.setPixelColor(13, 72, 149, 239);strip.setPixelColor(15, 72, 149, 239);strip.setPixelColor(16, 72, 149, 239);strip.setPixelColor(17, 72, 149, 239);strip.setPixelColor(25, 72, 149, 239);strip.setPixelColor(27, 72, 149, 239);strip.setPixelColor(29, 72, 149, 239);strip.setPixelColor(31, 72, 149, 239);strip.setPixelColor(34, 72, 149, 239);strip.setPixelColor(37, 72, 149, 239);strip.setPixelColor(39, 72, 149, 239);strip.setPixelColor(47, 72, 149, 239);strip.setPixelColor(49, 72, 149, 239);strip.setPixelColor(51, 72, 149, 239);strip.setPixelColor(52, 72, 149, 239);strip.setPixelColor(53, 72, 149, 239);strip.setPixelColor(56, 72, 149, 239);strip.setPixelColor(59, 72, 149, 239);strip.setPixelColor(60, 72, 149, 239);strip.setPixelColor(61, 72, 149, 239);strip.setPixelColor(69, 72, 149, 239);strip.setPixelColor(71, 72, 149, 239);strip.setPixelColor(73, 72, 149, 239);strip.setPixelColor(75, 72, 149, 239);strip.setPixelColor(78, 72, 149, 239);strip.setPixelColor(81, 72, 149, 239);strip.setPixelColor(83, 72, 149, 239);strip.setPixelColor(91, 72, 149, 239);strip.setPixelColor(92, 72, 149, 239);strip.setPixelColor(95, 72, 149, 239);strip.setPixelColor(97, 72, 149, 239);strip.setPixelColor(100, 72, 149, 239);strip.setPixelColor(103, 72, 149, 239);strip.setPixelColor(105, 72, 149, 239);
        strip.setBrightness(i);
        strip.show();
        delay(animationDelay);
    }
    for(int o = 120; o>0; o--){
        strip.setPixelColor(3, 72, 149, 239);strip.setPixelColor(4, 72, 149, 239);strip.setPixelColor(7, 72, 149, 239);strip.setPixelColor(8, 72, 149, 239);strip.setPixelColor(9, 72, 149, 239);strip.setPixelColor(11, 72, 149, 239);strip.setPixelColor(12, 72, 149, 239);strip.setPixelColor(13, 72, 149, 239);strip.setPixelColor(15, 72, 149, 239);strip.setPixelColor(16, 72, 149, 239);strip.setPixelColor(17, 72, 149, 239);strip.setPixelColor(25, 72, 149, 239);strip.setPixelColor(27, 72, 149, 239);strip.setPixelColor(29, 72, 149, 239);strip.setPixelColor(31, 72, 149, 239);strip.setPixelColor(34, 72, 149, 239);strip.setPixelColor(37, 72, 149, 239);strip.setPixelColor(39, 72, 149, 239);strip.setPixelColor(47, 72, 149, 239);strip.setPixelColor(49, 72, 149, 239);strip.setPixelColor(51, 72, 149, 239);strip.setPixelColor(52, 72, 149, 239);strip.setPixelColor(53, 72, 149, 239);strip.setPixelColor(56, 72, 149, 239);strip.setPixelColor(59, 72, 149, 239);strip.setPixelColor(60, 72, 149, 239);strip.setPixelColor(61, 72, 149, 239);strip.setPixelColor(69, 72, 149, 239);strip.setPixelColor(71, 72, 149, 239);strip.setPixelColor(73, 72, 149, 239);strip.setPixelColor(75, 72, 149, 239);strip.setPixelColor(78, 72, 149, 239);strip.setPixelColor(81, 72, 149, 239);strip.setPixelColor(83, 72, 149, 239);strip.setPixelColor(91, 72, 149, 239);strip.setPixelColor(92, 72, 149, 239);strip.setPixelColor(95, 72, 149, 239);strip.setPixelColor(97, 72, 149, 239);strip.setPixelColor(100, 72, 149, 239);strip.setPixelColor(103, 72, 149, 239);strip.setPixelColor(105, 72, 149, 239);
        strip.setBrightness(o);
        strip.show();
        delay(animationDelay);
    }
}

void ogSpinAndFade(){
        strip.clear();
    strip.setPixelColor(9, 72, 12, 168);strip.setPixelColor(13, 72, 12, 168);
    strip.show();
    delay(rotation);

    //2
    strip.clear();
    strip.setPixelColor(8, 72, 12, 168);strip.setPixelColor(9, 72, 12, 168);strip.setPixelColor(12, 72, 12, 168);strip.setPixelColor(13, 72, 12, 168);
    strip.show();
    delay(rotation);

    //3
    strip.clear();
    strip.setPixelColor(7, 72, 12, 168);strip.setPixelColor(8, 72, 12, 168);strip.setPixelColor(9, 72, 12, 168);strip.setPixelColor(11, 72, 12, 168);strip.setPixelColor(12, 72, 12, 168);strip.setPixelColor(13, 72, 12, 168);
    strip.show();
    delay(rotation);

    //4
    strip.clear();
    strip.setPixelColor(7, 72, 12, 168);strip.setPixelColor(8, 72, 12, 168);strip.setPixelColor(9, 72, 12, 168);strip.setPixelColor(11, 72, 12, 168);strip.setPixelColor(12, 72, 12, 168);strip.setPixelColor(13, 72, 12, 168);strip.setPixelColor(29, 72, 12, 168);strip.setPixelColor(33, 72, 12, 168);
    strip.show();
    delay(rotation);

    //5
    strip.clear();
    strip.setPixelColor(7, 72, 12, 168);strip.setPixelColor(8, 72, 12, 168);strip.setPixelColor(9, 72, 12, 168);strip.setPixelColor(11, 72, 12, 168);strip.setPixelColor(12, 72, 12, 168);strip.setPixelColor(13, 72, 12, 168);strip.setPixelColor(29, 72, 12, 168);strip.setPixelColor(33, 72, 12, 168);strip.setPixelColor(51, 72, 12, 168);strip.setPixelColor(55, 72, 12, 168);
    strip.show();
    delay(rotation);

    //6
    strip.clear();
    strip.setPixelColor(7, 72, 12, 168);strip.setPixelColor(8, 72, 12, 168);strip.setPixelColor(9, 72, 12, 168);strip.setPixelColor(11, 72, 12, 168);strip.setPixelColor(12, 72, 12, 168);strip.setPixelColor(13, 72, 12, 168);strip.setPixelColor(29, 72, 12, 168);strip.setPixelColor(33, 72, 12, 168);strip.setPixelColor(51, 72, 12, 168);strip.setPixelColor(55, 72, 12, 168);strip.setPixelColor(73, 72, 12, 168);strip.setPixelColor(77, 72, 12, 168);
    strip.show();
    delay(rotation);

    //7
    strip.clear();
    strip.setPixelColor(7, 72, 12, 168);strip.setPixelColor(8, 72, 12, 168);strip.setPixelColor(9, 72, 12, 168);strip.setPixelColor(11, 72, 12, 168);strip.setPixelColor(12, 72, 12, 168);strip.setPixelColor(13, 72, 12, 168);strip.setPixelColor(29, 72, 12, 168);strip.setPixelColor(33, 72, 12, 168);strip.setPixelColor(51, 72, 12, 168);strip.setPixelColor(55, 72, 12, 168);strip.setPixelColor(73, 72, 12, 168);strip.setPixelColor(77, 72, 12, 168);strip.setPixelColor(95, 72, 12, 168);strip.setPixelColor(99, 72, 12, 168);
    strip.show();
    delay(rotation);

    //8
    strip.clear();
    strip.setPixelColor(7, 72, 12, 168);strip.setPixelColor(8, 72, 12, 168);strip.setPixelColor(9, 72, 12, 168);strip.setPixelColor(11, 72, 12, 168);strip.setPixelColor(12, 72, 12, 168);strip.setPixelColor(13, 72, 12, 168);strip.setPixelColor(29, 72, 12, 168);strip.setPixelColor(33, 72, 12, 168);strip.setPixelColor(51, 72, 12, 168);strip.setPixelColor(55, 72, 12, 168);strip.setPixelColor(73, 72, 12, 168);strip.setPixelColor(77, 72, 12, 168);strip.setPixelColor(95, 72, 12, 168);strip.setPixelColor(96, 72, 12, 168);strip.setPixelColor(99, 72, 12, 168);strip.setPixelColor(100, 72, 12, 168);
    strip.show();
    delay(rotation);

    //9
    strip.clear();
    strip.setPixelColor(7, 72, 12, 168);strip.setPixelColor(8, 72, 12, 168);strip.setPixelColor(9, 72, 12, 168);strip.setPixelColor(11, 72, 12, 168);strip.setPixelColor(12, 72, 12, 168);strip.setPixelColor(13, 72, 12, 168);strip.setPixelColor(29, 72, 12, 168);strip.setPixelColor(33, 72, 12, 168);strip.setPixelColor(51, 72, 12, 168);strip.setPixelColor(55, 72, 12, 168);strip.setPixelColor(73, 72, 12, 168);strip.setPixelColor(77, 72, 12, 168);strip.setPixelColor(95, 72, 12, 168);strip.setPixelColor(96, 72, 12, 168);strip.setPixelColor(97, 72, 12, 168);strip.setPixelColor(99, 72, 12, 168);strip.setPixelColor(100, 72, 12, 168);strip.setPixelColor(101, 72, 12, 168);
    strip.show();
    delay(rotation);

    //10
    strip.clear();
    strip.setPixelColor(7, 72, 12, 168);strip.setPixelColor(8, 72, 12, 168);strip.setPixelColor(9, 72, 12, 168);strip.setPixelColor(11, 72, 12, 168);strip.setPixelColor(12, 72, 12, 168);strip.setPixelColor(13, 72, 12, 168);strip.setPixelColor(29, 72, 12, 168);strip.setPixelColor(33, 72, 12, 168);strip.setPixelColor(51, 72, 12, 168);strip.setPixelColor(55, 72, 12, 168);strip.setPixelColor(73, 72, 12, 168);strip.setPixelColor(75, 72, 12, 168);strip.setPixelColor(77, 72, 12, 168);strip.setPixelColor(79, 72, 12, 168);strip.setPixelColor(95, 72, 12, 168);strip.setPixelColor(96, 72, 12, 168);strip.setPixelColor(97, 72, 12, 168);strip.setPixelColor(99, 72, 12, 168);strip.setPixelColor(100, 72, 12, 168);strip.setPixelColor(101, 72, 12, 168);
    strip.show();
    delay(rotation);

    //11
    strip.clear();
    strip.setPixelColor(7, 72, 12, 168);strip.setPixelColor(8, 72, 12, 168);strip.setPixelColor(9, 72, 12, 168);strip.setPixelColor(11, 72, 12, 168);strip.setPixelColor(12, 72, 12, 168);strip.setPixelColor(13, 72, 12, 168);strip.setPixelColor(29, 72, 12, 168);strip.setPixelColor(33, 72, 12, 168);strip.setPixelColor(51, 72, 12, 168);strip.setPixelColor(53, 72, 12, 168);strip.setPixelColor(55, 72, 12, 168);strip.setPixelColor(57, 72, 12, 168);strip.setPixelColor(73, 72, 12, 168);strip.setPixelColor(75, 72, 12, 168);strip.setPixelColor(77, 72, 12, 168);strip.setPixelColor(79, 72, 12, 168);strip.setPixelColor(95, 72, 12, 168);strip.setPixelColor(96, 72, 12, 168);strip.setPixelColor(97, 72, 12, 168);strip.setPixelColor(99, 72, 12, 168);strip.setPixelColor(100, 72, 12, 168);strip.setPixelColor(101, 72, 12, 168);
    strip.show();
    delay(rotation);

    //12
    strip.clear();
    strip.setPixelColor(7, 72, 12, 168);strip.setPixelColor(8, 72, 12, 168);strip.setPixelColor(9, 72, 12, 168);strip.setPixelColor(11, 72, 12, 168);strip.setPixelColor(12, 72, 12, 168);strip.setPixelColor(13, 72, 12, 168);strip.setPixelColor(29, 72, 12, 168);strip.setPixelColor(31, 72, 12, 168);strip.setPixelColor(33, 72, 12, 168);strip.setPixelColor(51, 72, 12, 168);strip.setPixelColor(53, 72, 12, 168);strip.setPixelColor(55, 72, 12, 168);strip.setPixelColor(57, 72, 12, 168);strip.setPixelColor(73, 72, 12, 168);strip.setPixelColor(75, 72, 12, 168);strip.setPixelColor(77, 72, 12, 168);strip.setPixelColor(79, 72, 12, 168);strip.setPixelColor(95, 72, 12, 168);strip.setPixelColor(96, 72, 12, 168);strip.setPixelColor(97, 72, 12, 168);strip.setPixelColor(99, 72, 12, 168);strip.setPixelColor(100, 72, 12, 168);strip.setPixelColor(101, 72, 12, 168);
    strip.show();
    delay(rotation);

    for(int o = 120; o>0; o--){
        strip.setPixelColor(7, 72, 12, 168);strip.setPixelColor(8, 72, 12, 168);strip.setPixelColor(9, 72, 12, 168);strip.setPixelColor(11, 72, 12, 168);strip.setPixelColor(12, 72, 12, 168);strip.setPixelColor(13, 72, 12, 168);strip.setPixelColor(29, 72, 12, 168);strip.setPixelColor(31, 72, 12, 168);strip.setPixelColor(33, 72, 12, 168);strip.setPixelColor(51, 72, 12, 168);strip.setPixelColor(53, 72, 12, 168);strip.setPixelColor(55, 72, 12, 168);strip.setPixelColor(57, 72, 12, 168);strip.setPixelColor(73, 72, 12, 168);strip.setPixelColor(75, 72, 12, 168);strip.setPixelColor(77, 72, 12, 168);strip.setPixelColor(79, 72, 12, 168);strip.setPixelColor(95, 72, 12, 168);strip.setPixelColor(96, 72, 12, 168);strip.setPixelColor(97, 72, 12, 168);strip.setPixelColor(99, 72, 12, 168);strip.setPixelColor(100, 72, 12, 168);strip.setPixelColor(101, 72, 12, 168);
        strip.setBrightness(o);
        strip.show();
        delay(animationDelay);
    }
}

void runningLetters(){
    strip.clear();
    strip.setBrightness(50);
    for(int i = 0; i <= 73; i++){
        //K
        genericLetter(21, i, strip.Color(255, 0, 0), printK);

        //O
        genericLetter(25, i, strip.Color(255, 0, 0), printO);

        //M
        genericLetter(29, i, strip.Color(255, 0, 0), printM);

        //M
        genericLetter(33, i, strip.Color(255, 0, 0), printM);

        //U
        genericLetter(37, i, strip.Color(255, 0, 0), printU);

        //N
        genericLetter(41, i, strip.Color(255, 0, 0), printN);

        //I
        genericLetter(45, i, strip.Color(255, 0, 0), printI);

        //K
        genericLetter(49, i, strip.Color(255, 0, 0), printK);

        //A
        genericLetter(53, i, strip.Color(255, 0, 0), printA);

        //T
        genericLetter(57, i, strip.Color(255, 0, 0), printT);
        
        //I
        genericLetter(61, i, strip.Color(255, 0, 0), printI);

        //O
        genericLetter(65, i, strip.Color(255, 0, 0), printO);

        //N
        genericLetter(69, i, strip.Color(255, 0, 0), printN);

        strip.show();
        delay(150);
        strip.clear();
    }
}

void genericLetter(int start, int i, uint32_t rgb, int array[]){
    int column1 = start - i;
    int column2 = column1 + 1;
    int column3 = column1 + 2;
    if(column1 >= 0 && column1 <= 21){
        for(int j = 0; j <= 4; j++){
            if(array[j] == 1){
                strip.setPixelColor(matrix[j][column1], rgb);
            }
        }
    }
    if(column2 >= 0 && column2 <= 21){
        for(int j = 0; j <= 4; j++){
            if(array[j + 5] == 1){
                strip.setPixelColor(matrix[j][column2], rgb);
            }
        }
    }
    if(column3 >= 0 && column3 <= 21){
        for(int j = 0; j <= 4; j++){
            if(array[j + 10] == 1){
                strip.setPixelColor(matrix[j][column3], rgb);
            }
        }
    }
}
// Program: demo2.cpp
// Purpose: Demonstrate use of bmplip for handling
//          bmp colored and grayscale images
//          Program load a gray image and store in another file
// Author:  Mohammad El-Ramly
// Date:    30 March 2018
// Version: 1.0

//-----------------------------------------------------------

// FCI – Programming 1 – 2022 - Assignment 3 part1
// Program Name: PhotoShop.cpp
// Author: Ali Mohammed 20210876
// Author: Ehab  20211021
// Author: Moafak  20210845
// Last Modification Date: 6 April 2022
// Version 2.0

//-----------------------------------------------------------

// FCI – Programming 1 – 2022 - Assignment 3 part2
// Program Name: PhotoShop.cpp
// Author: Ali Mohammed 20210876
// Author: Ehab  20211021
// Author: Moafak  20210845
// Last Modification Date: 20 April 2022
// Version 3.0

//-----------------------------------------------------------

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;

//defining the images
unsigned char image1[SIZE][SIZE], image2[SIZE][SIZE], outimage[SIZE][SIZE], rightHalf[SIZE][SIZE], leftHalf[SIZE][SIZE], downHalf[SIZE][SIZE],  upperHalf[SIZE][SIZE];


// functions
void loadImage(), DetectImageEdges(), Mirror(), Shuffle(), enlarge(), rotate90(), RotateImage(), mergerLoadImage(), saveImage(), merger(), dark(), shrink(), blur(), Black_White(), flip(), Mirror(), changeImage(), Invert() ;

//main
int main()
{
    //declaring the input
    string input1;
    // welcome message
    cout << "\n Ahlan ya user ya habibi :D \n";
    while (true) {
        // output message
        cout << "\n \n 1-Black & White Filter \n 2-Invert Filter \n 3-Merge Filter  \n 4-Flip Image \n 5-Rotate Image \n 6-Darken and Lighten Image \n 7-Detect Image Edges \n 8-Enlarge Image \n 9-Shrink Image \n a-Mirror 1/2 Image\n b-Shuffle Image \n c-Blur Image \n 0- Exit \n \n choose from the list above: \n";
        //  selecting  filter
        cin >> input1;

        // if select = 1  (Black & White)
        if (input1 == "1"){
            loadImage();
            Black_White();
            saveImage();
            break;
        }
        // if select = 2 (invert)
          else if (input1 == "2"){
            loadImage();
            Invert();
            saveImage();
            break;
}
            // if select = 3 (merge)
        else if (input1 == "3"){
            mergerLoadImage();
            merger();
            saveImage();
            break;
        }
            // if select = 4 (flip)
        else if (input1 == "4"){
            loadImage();
            flip();
            saveImage();
            break;

        }
            // if select = 5 (mirror)
        else if (input1 == "5"){
            loadImage();
            RotateImage();
            saveImage();
            break;
        }
            // if select = 6 (brightness)
        else if (input1 == "6"){
            loadImage();
            dark();
            saveImage();
            break;
        }
        // if select = 7 (edges)
        else if (input1 == "7"){
            loadImage();
            DetectImageEdges();
            saveImage();
            break;

        }
        // if select = 8 (enlarge)
        else if (input1 == "8") {
            loadImage();
            enlarge();
            saveImage();
            break;
        }

            // if select = 9 (shrink)
        else if (input1 == "9"){
            loadImage();
            shrink();
            saveImage();
            break;

        }
            // if select = a (mirror)
        else if (input1 == "a"){
            loadImage();
            Mirror();
            saveImage();
            break;
        }

            // if select = c (blur)
        else if (input1 == "c"){
            loadImage();
            for (int i = 0; i < 5; i++){
                blur();
                changeImage();
            }
            saveImage();
            break;

        }
        // if select = b (shuffle)
          else if (input1 == "b"){
            loadImage();
            Shuffle();
            saveImage();
            break;
        }

            // if select = 0 (exit)
        else if (input1 == "0"){
            cout << "\n Thank You !" << endl;
            break;

        }

        else{
            cout << "\n Your input is Valid ! \n ";
        }
    }
}
//__

// function for load 2 images (merge)
void mergerLoadImage(){
    char image1FileName[100];
    char image2FileName[100];

    // Get gray scale image files name
    cout << "Enter the source image file name: ";
    cin >> image1FileName;
    cout << "Enter the source image file name: ";
    cin >> image2FileName;

    // Add to it .bmp extension and load image 1 and 2
    strcat (image1FileName, ".bmp");
    readGSBMP(image1FileName, image1);
    strcat (image2FileName, ".bmp");
    readGSBMP(image2FileName, image2);
}

// function for load 1 image
void loadImage () {
    char image1FileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> image1FileName;


    // Add to it .bmp extension and load image 1
    strcat (image1FileName, ".bmp");
    readGSBMP(image1FileName, image1);

}

//__
void saveImage () {
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the new image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load imagea

    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, outimage);

}
//rotate
void RotateImage() {
    //declaring rotate
int rotate;
//output message for choosing
    cout << "90, 180, 270 \n choose what do you want to do: ";
    //take input
    cin >> rotate;

    //if taking a valid input
    while (rotate != 90 && rotate != 180 && rotate != 270){
    cout << "Enter a valid input ! ";
    cin >> rotate;

    }
    //rotate 90, 1 time
    if (rotate == 90){
        rotate90();
    }

    //rotate 90, 2 times
    else if (rotate == 180){
            rotate90();
            rotate90();
}



    //rotate 90, 3 times
    else if (rotate == 270){
            rotate90();
            rotate90();
            rotate90();
    }

}

//rotate
void rotate90() {
    for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                    //swiping the i and j
                outimage[i][j] = image1[j][255 - i];

        }
    }
    for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++){
                image1[i][j] = outimage[i][j];

        }
    }
}



//edges
void DetectImageEdges() {
    int color = 255;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
                // making out image =  255 if it is > 127
            if (image1[i][j] > 127){
                image1[i][j] = 255;


            }
            else {
                // if it is < 127 make the out image = 0
                image1[i][j] = 0;
            }
        }
    }

    //making the picture black and white then removing all of the black color except the edges
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++){
            if (image1[i][j] != color){
                outimage[i][j] = 0;
                if (color == 255)
                    color = 0;
                else if (color == 0)
                    color = 255;
            }
            else{
                outimage[i][j] = 255;


            }
        }
    }
}


//invert
void Invert() {
    // main for loop
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
            // subtract from 255 the image
         outimage[i][j] = 255 - image1[i][j];
        }
    }
}

void Shuffle() {
    // declaring the quarters
    int p1,p2,p3,p4;
    cout << "Please,Enter the number of the first quarter in the image : ";
    //input
    cin >> p1;
    // if first quarter = 1
    if ( p1 == 1 ){
            //main for loop
        for ( int i = 0; i<= SIZE/2 ; i++) {
            for (int j = 0; j<=SIZE/2 ; j++) {
                // out image = input image
                outimage[i][j] = image1[i][j];
            }
        }
    }
        // if fisrt quarter = 2
    else if ( p1 == 2 ){
            // main for loop
        for (int i = 0 ; i <= SIZE / 2 ; i++){
            for (int j = 0; j <= SIZE / 2 ; j++){
                        outimage[i][j] = image1[i][j + SIZE / 2];
            }
        }
    }
    // if first quarter = 3
      else if ( p1 == 3 ){
          // main for loop
        for (int i = 0 ; i<=SIZE/2;i++){
            for (int j = 0; j<=SIZE/2 ; j++){
                        outimage[i][j] = image1[i+SIZE/2][j];
            }
        }
    }
        // if first quarter = 4
      else if ( p1 == 4 ){
        for (int i = 0 ; i<=SIZE/2; i++){
            for (int j = 0; j<=SIZE/2 ; j++){
                        outimage[i][j] = image1[i+SIZE/2][j+SIZE/2];
            }
        }
    }

    cout << "Please,Enter the number of the second quarter in the image: ";
    //input second quarter
    cin >> p2;
            // if second quarter = 1
    if ( p2 == 1 ){
        for (int i = 0 ; i<=SIZE/2; i++) {
            for (int j = SIZE/2; j<=SIZE; j++) {
                    outimage[i][j] = image1[i][j-SIZE/2];
            }
        }
    }
            // if second quarter = 2
    if ( p2 == 2 ){
        for (int i = 0; i<=SIZE/2; i++) {
            for (int j = 128; j<=SIZE; j++) {
                    outimage[i][j] = image1[i][j];
            }
        }
    }
            // if second quarter = 3
    else if ( p2 == 3 ){
       for(int i = 0 ; i<=SIZE/2; i++){
            for(int j = SIZE/2; j<=SIZE; j++){
                        outimage[i][j] = image1[i+SIZE/2][j-SIZE/2];
            }
        }
    }
            // if second quarter = 4
    else if ( p2 == 4 ){
        for(int i = 0 ; i<=SIZE/2;i++){
                for (int j = SIZE/2; j<=SIZE;j++){
                        outimage[i][j] = image1[i+SIZE/2][j];
                }
            }
        }

    cout << "Please,Enter the number of the third quarter in the image: ";
    // take the third quarter
    cin >> p3;
            // if third quarter = 1
        if( p3 == 1 ){
            for (int i = SIZE / 2; i <= SIZE; i++) {
                for (int j = 0; j <= SIZE/2; j++) {
                         outimage[i][j] = image1[i - SIZE / 2][j];
                    }
                }
            }
            // if third quarter = 2
    else if ( p3 == 2 ){
        for (int i = SIZE / 2; i <= SIZE; i++) {
            for (int j = 0; j <= SIZE/2; j++) {
                    outimage[i][j] = image1[i - SIZE / 2][j + SIZE / 2];
                }
            }
        }
                    // if third quarter = 3
    else if ( p3 == 3 ){
       for (int i = SIZE/2 ; i<=SIZE;i++){
            for (int j = 0; j<=SIZE/2; j++){
                        outimage[i][j] = image1[i][j];
            }
        }
    }
                // if third quarter = 4
    else if ( p3 == 4 ){
        for (int i = SIZE/2 ; i<=SIZE;i++){
            for (int j = 0; j<SIZE/2; j++){
                        outimage[i][j] = image1[i][j+SIZE/2];
            }
        }
    }
     cout << "Please,Enter the number of the fourth quarter in the image: ";
     // take the fourth quarter
     cin >> p4;
                 // if fourth quarter = 1
    if ( p4 == 1 ){
            for (int i = SIZE/2; i<=SIZE; i++) {
                for (int j = SIZE/2; j<=SIZE; j++){
                            outimage[i][j] =image1[i-SIZE/2][j-SIZE/2];
                }
            }
        }
                         // if fourth quarter = 2
    if ( p4 == 2 ){
           for (int i = SIZE/2; i<=SIZE; i++) {
                for (int j = SIZE/2; j<=SIZE; j++) {
                         outimage[i][j] =image1[i-SIZE/2][j];
                }
            }
        }
                         // if fourth quarter = 3
   if ( p4 == 3 ){
           for (int i = SIZE/2; i<=SIZE; i++) {
                for (int j = SIZE/2; j<=SIZE; j++) {
                         outimage[i][j] =image1[i][j-SIZE/2];
                }
            }
        }
                         // if fourth quarter = 4
    if ( p4 == 4 ){
        for (int i = SIZE/2; i<=SIZE; i++) {
            for (int j = SIZE/2; j<=SIZE; j++) {
                    outimage[i][j] = image1[i][j];
            }
        }
    }
}


//enlarge
void enlarge(){
    int quarter ;
    //Ask ueser about qurater.
    cout << "Please Enter the number of quarter : ";
        //take input

    cin >> quarter;
    while (quarter != 1 & quarter != 2 & quarter != 3 & quarter != 4){
        //defense the user from himself (taking a valid input)
    cout << "Enter a valid input ! : ";
    //take input
    cin >> quarter;
    }
    // input the qurater.
    if ( quarter ==  1 ){
       //loop for qurater one.
        for ( int  i = 0 ; i <= SIZE/2 ; i++ ){
            for ( int  j = 0  ; j <= SIZE/2 ; j++ ){
            //The outimage = 1 * 2 in image.
            //code for enlarge outimage.
                outimage[i*2][j*2] = image1[i][j];
                outimage[i*2][j*2+1] = image1[i][j];
                outimage[i*2+1][j*2] = image1[i][j];
                outimage[i*2+1][j*2+1] = image1[i][j];
            }
        }
    }
    else if ( quarter  ==  2 ){
        //loop for qurater scound.
        for ( int  i = 0  ; i <= SIZE/2 ; i++ ){
            for ( int j = SIZE/2  ; j <= SIZE ; j++ ){
                //The outimage = 1 * 2 in image.
                //code for enlarge outimage.
                outimage[i*2][j*2] = image1[i][j];
                outimage[i*2][j*2+1] = image1[i][j];
                outimage[i*2+1][j*2] = image1[i][j];
                outimage[i*2+1][j*2+1] = image1[i][j];
            }
        }
    }
    else if ( quarter  ==  3 ){
        //loop for qurater third.
        for  ( int  i = 0  ; i < SIZE/2 ; i++ ){
            for  ( int  j = 0  ; j <= SIZE/2 ; j++ ){
               //The outimage = 1 * 2 in image.
               //code for enlarge outimage.
                outimage[i*2][j*2] = image1[i+127][j];
                outimage[i*2][j*2+1] = image1[i+127][j];
                outimage[i*2+1][j*2] = image1[i+127][j];
                outimage[i*2+1][j*2+1] = image1[i+127][j];
            }
        }
    }
    else if ( quarter  ==  4 ){
        //loop for qurater fourth.
        for  ( int  i = 0  ; i < SIZE/2 ; i++ ){
            for  ( int  j = SIZE/2  ; j <SIZE ; j++ ){
                //The outimage = 1 * 2 in image.
                //code for enlarge outimage.
                outimage[i*2][j*2] = image1[i+127][j];
                outimage[i*2][j*2+1] = image1[i+127][j];
                outimage[i*2+1][j*2] = image1[i+127][j];
                outimage[i*2+1][j*2+1] = image1[i+127][j];
            }
        }
    }
}


//merge
void merger(){
        for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
   // using it to merge the image and take the average
            outimage[i][j] = (image1[i][j] + image2[i][j]) / 2;

        }
    }
}
// dark and light
void dark() {
    string type;
    while (true){
        //ask the user
        cout << "do you want to make it darker or lighter: ";
        cin >> type;
        if (type == "darker" || type == "lighter"){
            // break the while loop and go on to the for loop
            break;
        }

        else{
            //if taking a valid input
            cout << "enter a valid input ! " << endl;
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            if (type == "darker"){
                // subtract 63 from the image
                outimage[i][j] = image1[i][j] - 63;
                //if the brightness is < 0.. make it 0
                if ((image1[i][j] - 63) < 0){
                    outimage[i][j] = 0;
                }
            }
            else if (type == "lighter"){
                outimage[i][j] = image1[i][j] + 63;
                if ((image1[i][j] + 63) > 255){
                    //if the brightness is > 255.. make it 255
                    outimage[i][j] = 255;
                }
            }
        }
    }
}
//shrink
void shrink(){
    //Shrinking variable
    string number;
    int Wtrue;
    Wtrue = true;
    //while loop in case of taking a valid input
    while (Wtrue) {
        cout << "press \" 4 \" for 1/4... press \" 3 \" for 1/3...press \"2\" for 1/2: ";
        cin >> number;
        if (number == "2" || number == "3" || number == "4"){
            // break the while loop and go on to the for loop
            break;
        }

        else {
            cout << "enter a valid input ! " << endl;
        }
    }
    for (int i = 0; i < SIZE; i+=2) {
        for (int j = 0; j< SIZE; j+=2) {

            if (number == "2"){
                // divide i,j by 2 for making the photo to half its real
                outimage[i/2][j/2] = image1[i][j];
            }
            else if (number == "3"){
                // divide i,j by 3 for making the photo to third its real
                outimage[i/3][j/3] = image1[i][j];
            }
            else if (number == "4"){
                // divide i,j by 4 for making the photo to quarter its real
                outimage[i/4][j/4] = image1[i][j];
            }
        }
    }
}
//blur
void blur () {
    int average = 0;
    for (int i=0 ; i < SIZE ; i++){
        for (int j=0 ; j < SIZE ; j++){
            for (int k = -1; k <= 1; k ++){
                for (int l = -1; l <= 1 ;l++){
                    // if condition for not making some edges black
                    if((i + k) >= 0 && (i + k) <= 255 && (j + l) >= 0 && (j + l) <= 255){
                        average += image1[i + k][j + l];
                    }
                }
            }
            outimage[i][j] = (average / 9);
            // making average = 0 again
            average = 0;
        }
    }
}


// helper function for blur
void changeImage(){
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            // input image = out image
            image1[i][j] = outimage[i][j];
        }
    }
}
// function for black and white
void Black_White(){
    // loop into the image
    for (int i = 0; i < SIZE ; i++){
        for (int j = 0; j < SIZE ; j++){
            // making out image =  255 if it is > 127
            if (image1[i][j] > 127){
                outimage[i][j] = 255;

            }
            else {
                // if it is < 127 make the out image = 0
                outimage[i][j] = 0;
            }
        }
    }
}

// function to flip the image
void flip(){
    for (int i = 0; i < SIZE ; i++){
        for (int j = 0; j < SIZE ; j++){
            //code to flip image
            outimage[i][j] = image1[SIZE-i][SIZE-j];
        }
    }
}

void Mirror(){
	cout << "Enter the part you need to mirror (Upper=1 , Lower = 2 Left = 3 ,Right=4) : ";
	int part;
	cin >> part;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            if( i < 128 ){ // upper half
                upperHalf[i][j] = image1[i][j];
            }
            if( i >= 128 ){ // below half
                downHalf[i][j] = image1[i][j];
            }
            if( j < 128 ){ // left half
                leftHalf[i][j] = image1[i][j];
            }
            if( j >= 128 ){ // right half
                rightHalf[i][j] = image1[i][j];
            }
    }
}


  // result image

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {

            if( part == 1 ){
                if( i < 128 ){ // upper half
                    outimage[i][j] = upperHalf[i][j];
                }
                if( i >= 128 ){ // below half
                    outimage[i][j] = upperHalf[256-i][j];
                }
            }
            else if( part == 2 ){
                if( i < 128 ){ // upper half
                    outimage[i][j] = downHalf[256-i][j];
                }
                if( i >= 128 ){ // below half
                    outimage[i][j] = downHalf[i][j];
                }
            }
            else if( part == 3 ){
                if( j <= 128 ){ // left half
                    outimage[i][j] = leftHalf[i][j];
                }

                if( j > 128 ){ // right half
                    outimage[i][j] = leftHalf[i][256-j];
                    }
                }
            else if( part == 4 ){
                if( j < 128 ){ // left half
                    outimage[i][j] = rightHalf[i][256-j];
                }
                if( j >= 128 ){ // right half

                    outimage[i][j] = rightHalf[i][j];
                }
            }
        }
    }
}


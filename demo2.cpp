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


        // if select = 2 (invert)
        if (input1 == "2"){
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
            // if select = 5 (mirror)
        else if (input1 == "5"){
            loadImage();
            RotateImage();
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


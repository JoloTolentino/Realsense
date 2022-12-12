
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <direct.h>


using namespace cv;
using namespace std; 




// string get_root(string debug_dir){


// };


string save_dir(string current_dir){
    string SAVE_DIR = current_dir+"/Images";
    return SAVE_DIR; 
}

string Get_Current_Directory(){
    char* buffer = _getcwd( 0, 0 );
    string DEBUG_DIRECTORY(buffer); 
    free(buffer);
    // string CURRENT_DIRECTORY = get_root(DEBUG_DIRECTORY); 
    // return CURRENT_DIRECTORY;
    return DEBUG_DIRECTORY;
}



int main(int argc, char** argv )
{
    if ( argc != 2 )
    {
        printf("usage: DisplayImage.out <Image_Path>\n");
        return -1;
    }
    Mat image;
    image = imread( argv[1], 1 );
    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }
    namedWindow("Display Image", WINDOW_AUTOSIZE );
    imshow("Display Image", image);
    waitKey(0);
    return 0;
}
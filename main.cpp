
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <direct.h>


using namespace cv;
using namespace std; 




string root(string debug_dir){
    int delimiter = debug_dir.find("\build");
    string ROOT_DIRECTORY = debug_dir.substr(0,delimiter);
    return ROOT_DIRECTORY; 
};


string save_dir(string current_dir){
    string SAVE_DIR = current_dir+"/Images";
    return SAVE_DIR; 
}

string Get_Current_Directory(){
    char* buffer = _getcwd( 0, 0 );
    string DEBUG_DIRECTORY(buffer); 
    free(buffer);
    string CURRENT_DIRECTORY = root(DEBUG_DIRECTORY); 
    return CURRENT_DIRECTORY;

}



int main(int argc, char** argv )
{

    string CURRENT_DIR = Get_Current_Directory(); 
    string IMAGE_DIR =  CURRENT_DIR+ 'images'; 

    if ( argc != 2 )
    {
        printf("usage: DisplayImage.out <Image_Path>\n");
        return -1;
    }

    Mat image;
    cout << IMAGE_DIR+argv[1]; 

    image = imread( IMAGE_DIR+argv[1], 1 );
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
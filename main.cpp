#include <iostream>
#include <opencv2/opencv.hpp>

#define BOARD        "C:/Users/winss/Desktop/C++practice/Omok/omok_board.jpg"
#define NONMOUSE     "Non MouseEvent"
#define USEMOUSE     "Mouse Event"

using namespace cv;

void onMouseEvent(int event, int x, int y, int flags, void* dstImage){
    Mat mouseImage = *(Mat*)dstImage;

    switch(event){
        case EVENT_LBUTTONDOWN:
        // circle(mouseImage, Point(x, y), 14, Scalar(255, 255, 255), -1, 16, 0);
        std::cout << Point(x, y) << std::endl;
        break;
    }

    imshow(USEMOUSE, mouseImage);
}

int main(int, char**) {
    Mat scrImage = imread(BOARD);
    if(scrImage.empty()){
        return -1;
    }

    imshow(USEMOUSE, scrImage);
    setMouseCallback(USEMOUSE, onMouseEvent, (void*)&scrImage);
    waitKey();

    return 0;
}

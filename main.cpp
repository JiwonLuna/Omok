#include <iostream>
#include <opencv2/opencv.hpp>

#define BOARD        "C:/Users/winss/Desktop/C++practice/Omok/omok_board.jpg"
#define NONMOUSE     "Non MouseEvent"
#define USEMOUSE     "Mouse Event"

void onMouseEvent(int event, int x, int y, int flags, void* dstImage){
    cv::Mat mouseImage = *(cv::Mat*)dstImage;

    switch(event){
        case cv::EVENT_LBUTTONDOWN:
        std::cout << cv::Point(x, y) << std::endl;
        break;
    }

    cv::imshow("Mouse Event", mouseImage);
}

int main(int, char**) {
    cv::Mat scrImage = cv::imread(BOARD);
    if(scrImage.empty()){
        return -1;
    }

    cv::imshow(USEMOUSE, scrImage);
    cv::setMouseCallback(USEMOUSE, onMouseEvent, (void*)&scrImage);
    cv::waitKey();

    return 0;
}

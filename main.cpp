#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>

#define BOARD        "C:/Users/winss/Desktop/C++practice/Omok/omok_board.jpg"
#define NONMOUSE     "Non MouseEvent"
#define USEMOUSE     "Mouse Event"


using namespace cv;

int turn = 0;

void onMouseEvent(int event, int x, int y, int flags, void* dstImage){
    Mat mouseImage = *(Mat*)dstImage;
    Scalar black(0, 0, 0), white(255, 255, 255);
    Scalar stone_color, num_color;
    switch(event){
        case EVENT_LBUTTONDOWN:
        turn++;
        std::string text = std::to_string(turn);
        double correct_x = 52 + (int)((x-31.2857)/41.4286)*41.4286;
        double correct_y = 49 + (int)((y-31.2857)/41.4286)*41.4286;
        
        if(turn%2 == 0) stone_color = white, num_color = black;
        else stone_color = black, num_color = white;

        circle(mouseImage, Point(correct_x, correct_y), 14, stone_color, -1, 16, 0);
        int i = 0;
        if(turn < 10) i = 6;
        else if(10<= turn && turn < 100) i = 9;
        else if(turn>=100) i = 13;
        putText(mouseImage, text, Point(correct_x-i, correct_y+7), FONT_HERSHEY_SIMPLEX, 0.5, num_color);
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

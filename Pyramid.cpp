#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;

int main(int argc, char *argv[])
{
    // 讀取argv[1]指定的影像
    cv::Mat image;
    image = cv::imread(argv[1]); // 用cv::imread函數讀取指定路徑下的影像
    // 判斷影像文件是否正確讀取
    if (image.data == nullptr) //數據不存在,也是可能文件不存在
    {
        cerr << "File" << argv[1] << "does not exist!" << endl;
        return 0;
    }

    cv::Mat image_up, image_down, image_down_up, image_diff;
    cv::imshow("Original", image);
    // 上採樣（zoom in 放大）
    cv::pyrUp(image, image_up, cv::Size(image.cols * 2, image.rows * 2));
    cv::imshow("Zoom in", image_up);
    // 降採樣（zoom out 縮小）
    cv::pyrDown(image, image_down, cv::Size(image.cols / 2, image.rows / 2));
    cv::imshow("Zoom out", image_down);
    // 降採樣後的影像image_down再進行上採樣（zoom out than zoom in）
    cv::pyrUp(image_down, image_down_up, cv::Size(image.cols, image.rows));
    cv::imshow("Zoom out than zoom in", image_down_up); 
    // 顯示image和image_down_up的差異
    // 因為pyrUp和pyrDown在說小和放大過程中會進行濾波
    // 所以image和image_down_up兩者會存在不同的地方
    image_diff = image - image_down_up;
    cv::imshow("Image difference", image_diff);
    cv::waitKey(0);
    // 關閉所有圖像視窗
    cv::destroyAllWindows();

    return 0;
}

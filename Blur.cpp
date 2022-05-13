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

    // 採用3x3維度的Gaussian kernel
    cv::Mat image_blurred_with_3x3_kernel;
    cv::GaussianBlur(image, image_blurred_with_3x3_kernel, cv::Size(3, 3), 0);

    // 採用5x5維度的Gaussian kernel
    cv::Mat image_blurred_with_5x5_kernel;
    cv::GaussianBlur(image, image_blurred_with_5x5_kernel, cv::Size(5, 5), 0);

    // 設定顯示圖像的名稱
    cv::String window_name = "Original";
    cv::String window_name_blurred_with_3x3_kernel = "Blurred with 3 x 3 Kernel";
    cv::String window_name_blurred_with_5x5_kernel = "Blurred with 5 x 5 Kernel";

    // 顯示原先圖片、和模糊化後的圖片
    cv::imshow(window_name, image);
    cv::imshow(window_name_blurred_with_3x3_kernel, image_blurred_with_3x3_kernel);
    cv::imshow(window_name_blurred_with_5x5_kernel, image_blurred_with_5x5_kernel);
    cv::waitKey(0);

    // 關閉所有圖像視窗
    cv::destroyAllWindows();

    return 0;
}

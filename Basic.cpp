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

    // 文件順利讀取, 输出一些影像的基本訊息
    cout << "Image width: " << image.cols << ", image height: " << image.rows << ",image channels: " << image.channels() << endl;
    cv::imshow("image", image); // 用cv::imshow顯示圖像

    // 將讀入的檔案image轉換成灰階影像image_gray
    cv::Mat image_gray;
    cv::cvtColor(image, image_gray, cv::COLOR_RGB2GRAY);
    cv::imshow("image_gray", image_gray);        // 用cv::imshow顯示圖像
    cv::imwrite("../logo_gray.png", image_gray); // 用cv::imwrite儲存image_gray
    cv::waitKey(0);                              // 暂停程式,等待使用者輸入任意按鍵則程式繼續執行

    // 判斷輸入影像的類型
    if (image.type() == CV_8UC1)
        cout << "Image type: gray" << endl;
    if (image.type() == CV_8UC3)
        cout << "Image type: RGB" << endl;
    if (image_gray.type() == CV_8UC1)
        cout << "Image type: gray" << endl;
    if (image_gray.type() == CV_8UC3)
        cout << "Image type: RGB" << endl;

    // 關於cv::Mat 的拷貝
    // 直接赋值並不會拷貝数劇
    cv::Mat image_another = image;
    // 修改image_another會導致image發生變化
    image_another(cv::Rect(0, 0, 50, 50)).setTo(0); // 將左上角的50*50的區域設置為0
    cv::imshow("image", image);
    cv::imshow("image_another", image_another);
    cv::waitKey(0);

    // 使用clone函數實現圖像數據拷貝
    cv::Mat image_clone = image.clone();
    image_clone(cv::Rect(0, 0, 50, 50)).setTo(255); // 將左上角的50*50的區域設置為255
    cv::imshow("image", image);
    cv::imshow("image_clone", image_clone);
    cv::waitKey(0);

    // 關閉所有圖像視窗
    cv::destroyAllWindows();

    return 0;
}

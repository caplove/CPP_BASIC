#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>


using namespace cv;


// 함수 선언
void generateGradientImage(int width, int height, const std::string& filename);
void readImageFile(const char* filename, unsigned short* buf, int& width, int& height);
void binning(unsigned short* buf, int width, int height, int bin, const std::string& filename);




int main() {

    int width = 600;
    int height = 400;
    const std::string& filename = "test_2.tif";

    // 그래디언트 이미지 생성
    generateGradientImage(width, height, filename);

    Mat img1;
    img1 = imread("test_2.tif");

    //waitKey(0); // key 누를때 까지 기다림.


    imshow("gradient Img", img1);
    waitKey(0); // key 누를때 까지 기다림.


    // 이미지 to 버퍼
    unsigned short* buf = new unsigned short[width * height];
    readImageFile("test_2.tif", buf, width, height);


    // 비닝 : 가로*세로*depth --> 가로*세로만 줄임
    binning(buf, width, height, 2,"binned_img.tif");
    waitKey(0); // key 누를때 까지 기다림.


    Mat img3;
    img3 = imread("binned_img.tif");
    imshow("binned 이미지", img3);
    waitKey(0); // key 누를때 까지 기다림.

    delete[] buf;

    return 0;
}




void generateGradientImage(int width, int height, const std::string& filename) {
    cv::Mat image(height, width, CV_16UC1);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            uint16_t pixel = (uint16_t)((double)x / width * UINT16_MAX);
            image.at<uint16_t>(y, x) = pixel;
        }
    }

    cv::imwrite(filename, image);
}


void readImageFile(const char* filename, unsigned short* buf, int& width, int& height) {
    cv::Mat image = cv::imread(filename, cv::IMREAD_ANYDEPTH);

    if (image.empty() || image.type() != CV_16UC1) {
        // 이미지 파일이 제대로 읽어지지 않았을 경우, 예외 처리 혹은 로그 작성 등 필요한 처리를 수행한다.
        return;
    }

    width = image.cols;
    height = image.rows;

    // 이미지의 픽셀 값을 buf로 복사한다.
    memcpy(buf, image.data, width * height * sizeof(unsigned short));

}


void binning(unsigned short* buf, int width, int height, int bin, const std::string& filename) {
    // binning = 1, 2, 4, 8 중 하나의 값을 가질 수 있다.
    if (bin <= 1) {
        return;
    }

    int binWidth = width / bin;
    int binHeight = height / bin;
    unsigned short* newBuf = new unsigned short[binWidth * binHeight];

    for (int y = 0; y < binHeight; y++) {
        for (int x = 0; x < binWidth; x++) {
            int sum = 0;

            for (int i = 0; i < bin; i++) {
                for (int j = 0; j < bin; j++) {
                    int offsetX = x * bin + i;
                    int offsetY = y * bin + j;
                    int index = offsetY * width + offsetX;
                    sum += buf[index];
                }
            }

            newBuf[y * binWidth + x] = sum / (bin * bin);
        }
    }

    memcpy(buf, newBuf, binWidth * binHeight * sizeof(unsigned short));
    delete[] newBuf;


    cv::Mat binned_img(binHeight, binWidth, CV_16UC1, buf);
    cv::imwrite(filename, binned_img);

}

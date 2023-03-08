#include <iostream>
#include <vector>

typedef unsigned char BYTE;

int main() {

    int BUFF_SIZE = 100;

    BYTE* acReadBuf = new BYTE[BUFF_SIZE]; // 동적 할당된 acReadBuf 포인터 생성
    acReadBuf[0] = 1; // 임의의 acReadBuf 배열 값 설정
    acReadBuf[1] = 2;
    acReadBuf[2] = 3;
    acReadBuf[3] = 4;
    acReadBuf[4] = 5;
    acReadBuf[5] = 6;
    acReadBuf[6] = 7;
    acReadBuf[7] = 8;

    int idx = 0; // 임의의 idx 변수 생성
    int buf = 0; // 임의의 buf 변수 생성
    std::vector<unsigned short> data;

    int binning;
    std::cout << "Enter binning value (0, 1, or 2): ";
    std::cin >> binning;


    for (int i = 0; i < BUFF_SIZE; i++) {
        switch (binning) {
        case 0: {
            buf = (acReadBuf[idx] | acReadBuf[idx + 1] << 8);
            idx += 2;
            data.push_back(buf);
            std::cout << "case 0: buf = " << buf << ", idx = " << idx << ", data = " << data.back() << std::endl;

            // 데이터 백터값 출력
            std::cout << "data: ";
            for (int i = 0; i < data.size(); i++) {
                std::cout << data[i] << " ";
            }
            std::cout << std::endl;


            break;
        }
        case 1: {
            buf = (acReadBuf[idx] | (acReadBuf[idx + 1] << 8)) + (acReadBuf[idx + 2] | (acReadBuf[idx + 3] << 8)) - 65535;
            buf = buf < 0 ? 0 : buf > 65535 ? 65535 : buf;

            idx += 4;
            data.push_back(buf);
            data.push_back(buf);
            std::cout << "case 1: buf = " << buf << ", idx = " << idx << ", data = " << data.back() << std::endl;
            break;
        }
        case 2: {
            buf = ((acReadBuf[idx] | acReadBuf[idx + 1] << 8) + (acReadBuf[idx + 2] | acReadBuf[idx + 3] << 8)) / 2;

            idx += 4;
            data.push_back(buf);
            data.push_back(buf);
            std::cout << "case 2: buf = " << buf << ", idx = " << idx << ", data = " << data.back() << std::endl;
            break;
        }
        default:
            std::cout << "Invalid binning value" << std::endl;
            break;
        }
    }
        delete[] acReadBuf; // 동적 할당된 메모리 해제

        return 0;
    
}

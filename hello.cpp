#include "hello.h"

#include <iostream>
#include <string>
#include <fstream>

#include "ReadBarcode.h"

int main(void) {
    std::ifstream image;
    image.open("./68x68.jpeg", std::ios::binary);
    image.seekg (0, std::ios::end);
    int n = image.tellg();
    image.seekg (0, std::ios::beg);
    char* res = new char[n];
    for(int i = 0; i < n; i++) {
        res[i] = '5';
    }

    bool bit = image.eof();
    image.read(res, n);

    unsigned char* img = (unsigned char*) res;

    // auto im = ZXing::ImageView(img, 68, 68, ZXing::ImageFormat::Lum);
    // auto options = ZXing::ReaderOptions().setFormats(ZXing::BarcodeFormat::Any);
    // auto result = ZXing::ReadBarcode(im, options);
    // auto results = ZXing::ReadBarcodes(im, options);

    // for (const auto& r : results) {
    //     std::cout << ZXing::ToString(r.format()) << ": " << r.text() << "\n";
    // }

    return 0;
}
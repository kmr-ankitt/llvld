#define STB_IMAGE_IMPLEMENTATION
#include "../lib/stb_image.h"

#include "document_element.h"
#include <iostream>

ImageElement::ImageElement(const std::string& path) {
    this->imagePath = path;
}

void imageToAscii(const std::string& imagePath) {
    int width, height, channels;

    unsigned char* image = stbi_load(
        imagePath.c_str(),
        &width,
        &height,
        &channels,
        1
    );

    if (!image) {
        std::cerr << "Failed to load image: "
                  << imagePath << '\n';
        return;
    }

    const std::string chars = "@%#*+=-:. ";

    const int outputWidth = 100;
    const int outputHeight =
        height * outputWidth / width / 2;

    for (int y = 0; y < outputHeight; ++y) {
        for (int x = 0; x < outputWidth; ++x) {
            int srcX = x * width / outputWidth;
            int srcY = y * height / outputHeight;

            unsigned char pixel =
                image[srcY * width + srcX];

            int index =
                pixel * (chars.size() - 1) / 255;

            std::cout << chars[index];
        }

        std::cout << '\n';
    }

    stbi_image_free(image);
}

void ImageElement::render() {
    imageToAscii(this->imagePath);
}

#include <png++/png.hpp>
#include <vector>
#include <math.h>
#include <string>
#include <iostream>

#include "vec.hpp"

using colour = vec<float, 3>;
using canvas = std::vector<std::vector<colour>>;
using pt = vec<int, 2>;

// lb --- left bottom
void fill(canvas &img, const pt &lb, const int &sz, const colour c) {
    for (int x = 0; x < sz; ++x) {
        for (int y = 0; y < sz; ++y) {
            img[lb.x + x][lb.y + y] = c;
        }
    }
}

void carpet(canvas &img, const pt &lb, const int &sz, const colour c) {
    if (sz <= 1) return;
    fill(img, lb + pt(sz / 3), sz / 3, c);
    for (int x = 0; x < 3; ++x) {
        for (int y = 0; y < 3; ++y) {
            if (x == 1 && y == 1) continue;
            carpet(img, lb + pt({x * sz / 3, y * sz / 3}), sz / 3., c * 2.f);
        }
    }
}

void usage() {
    std::cout << "Usage:\n"
        "Argumernts: [filename.png] [image_size] OR [image_size] [filename.png]\n"
        "It is a good idea to use a power of 3 as an image_size.\n";
}

int main(int argc, char** argv) {
    usage();

    size_t IMG_SIZE = 243;
    std::string FILENAME = "output.png";
    if (argc > 1) {
        try {
            IMG_SIZE = std::stoi(argv[1]);
            if (argc > 2) {
                FILENAME = argv[2];
            }
        } catch (const std::invalid_argument&) {
            FILENAME = argv[1];
            if (argc > 2) {
                IMG_SIZE = std::stoi(argv[2]);
            }
        }
    }

    canvas img(IMG_SIZE, std::vector<colour>(IMG_SIZE));
    fill(img, pt({0, 0}), IMG_SIZE, 0.);
    carpet(img, pt({0, 0}), IMG_SIZE,
        1./exp2(floor(log(IMG_SIZE)/log(3)) - 1.));

    png::image<png::rgb_pixel> rgb_image(IMG_SIZE, IMG_SIZE);
    for (size_t x = 0; x < IMG_SIZE; ++x) {
        for (size_t y = 0; y < IMG_SIZE; ++y) {
            // sqrt for gamma correction
            rgb_image.set_pixel(x, y,
                png::rgb_pixel(std::max(0.f, std::min(1.f, sqrt(img[x][y].r))) * 255,
                               std::max(0.f, std::min(1.f, sqrt(img[x][y].g))) * 255,
                               std::max(0.f, std::min(1.f, sqrt(img[x][y].b))) * 255));
        }
    }
    rgb_image.write(FILENAME);

    std::cout << "Your output is in file \"" << FILENAME << "\".\n";
}

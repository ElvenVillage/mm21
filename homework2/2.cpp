#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <cmath>

int main(int argc, char** argv) {
    if (argc == 2) {
        std::ifstream infile(argv[1]);

        std::vector < std::pair < double, double >> obstacles;
        double h;
        double x = 0;

        infile >> h;

        double vx, vy;
        infile >> vx >> vy;

        double g = -9.81;

        int interval = 0;
        int size = 0;

        while (true) {
            int target = (vx > 0) ? interval : interval - 1;
            if (target < 0) {
                std::cout << "0" << std::endl;
                return 0;
            }
            if (target > size - 1) {
                if (!infile || (infile && infile.peek() == EOF)) {
                    std::cout << size - 1 << std::endl;
                    return 0;
                } else {
                    double x_obs, h_obs;
                    infile >> x_obs >> h_obs;
                    obstacles.push_back(std::make_pair(x_obs, h_obs));
                    size++;
                }
            }

            double t = std::abs(x - obstacles[target].first) / vx;

            vy = vy + g * t;
            x = x + vx * t;
            h = h + vy * t + 0.5 * g * t * t;

            if (h <= 0) {
                std::cout << interval << std::endl;
                return 0;
            }
            if (h >= obstacles[target].second) {
                (vx > 0) ? interval++ : interval--;
            } else {
                vx = vx * (-1);
            }
        }
    }
}

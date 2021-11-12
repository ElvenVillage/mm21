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
                break;
            }
            if (target > size - 1) {
                if (infile && infile.peek() == EOF) {
                    std::cout << size << std::endl;
                } else {
                    double x_obs, h_obs;
                    infile >> x_obs >> h_obs;
                    std::pair < double, double > temp;
                    temp.first = x_obs;
                    temp.second = h_obs;
                    obstacles.push_back(temp);
                    size++;
                }
            }

            double t = std::abs(x - obstacles[target].first) / vx;

            vy = vy + g * t;
            x = x + vx * t;
            h = h + vy * t + 0.5 * g * t * t;

            if (h <= 0) {
                std::cout << target << std::endl;
                break;
            }
            if (h > obstacles[target].second) {
                (vx > 0) ? interval++ : interval--;
            } else {
                vx = vx * (-1);
            }
        }
    } else {}
}

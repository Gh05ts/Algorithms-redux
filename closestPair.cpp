#include <iostream>
#include <vector>
#include <algorithm>
#include <cfloat>

using namespace std;

struct Point {
    double x, y;
    int id;
};

struct Result {
    double distSq;
    Point p1, p2;
};

double distSquared(const Point &a, const Point &b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return dx * dx + dy * dy;
}

Result checkSubset(const vector<Point> &P, const Result &currentBest, int maxChecks) {
    Result best = currentBest;
    for(size_t i = 0; i < P.size(); i++) {
        size_t limit = (maxChecks > 0)? min(P.size(), i + 1 + (size_t)maxChecks) :P.size();
        for(size_t j = i + 1; j < limit; j++) {
            double dSq = distSquared(P[i], P[j]);
            if (dSq < best.distSq) {
                best = {dSq, P[i], P[j]};
            }
        }
    }
    return best;
}

Result closestPairHelper(vector<Point> &Px, vector<Point> &Py, vector<Point> &temp, int left, int right) {
    if(Px.size() <= 3) {
        return checkSubset(Px, {DBL_MAX, {0, 0}, {0, 0}}, 0);
    }

    int mid = left + (right - left)/2;
    double midX = Px[mid].x;
    for_each(begin(Py) + left, begin(Py), [] (const auto &point) {
        
    });

    return Result{};
}

Result closestPair(vector<Point> &initialInput) {
    vector<Point> input;
    int counter = 0;
    transform(begin(initialInput), end(initialInput), back_inserter(input), [&counter](auto p) {
        return Point{p.x, p.y, counter++};
    });
    vector<Point> inputCopy = input;
    sort(begin(input), end(input), [] (const auto &left, const auto &right) {
        return left.x < right.x || (left.x == right.x && left.y < right.y);
    });
    sort(begin(inputCopy), end(inputCopy), [] (const auto &left, const auto &right) {
        return left.y < right.y;
    });
    vector<Point> temp(input.size());
    return closestPairHelper(input, inputCopy, temp, 0, input.size() - 1);
}

int main() {
    vector<Point> input = {{1, 3}, {-2, -4}, {0, 0}, {34, 32}, {-22, -25}, {33, 33}};
    closestPair(input);
    // cout << closestPoints(input, 0, input.size() - 1, inputCopy);
    return 0;
}
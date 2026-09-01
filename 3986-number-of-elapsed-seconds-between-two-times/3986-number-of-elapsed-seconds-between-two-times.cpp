class Solution {
public:
    int toSeconds(string time) {
        int h = stoi(time.substr(0, 2));
        int m = stoi(time.substr(3, 2));
        int s = stoi(time.substr(6, 2));

        return h * 3600 + m * 60 + s;
    }

    int secondsBetweenTimes(string startTime, string endTime) {
        return toSeconds(endTime) - toSeconds(startTime);
    }
};
class Solution {
public:
    // Convert MM-DD into the day number of the year
    int dayOfYear(string date) {
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));

        int days[] = {31, 28, 31, 30, 31, 30,
                      31, 31, 30, 31, 30, 31};

        // Add days from all previous months
        for (int i = 0; i < month - 1; i++) {
            day += days[i];
        }

        return day;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {

        // Convert all dates into day numbers
        int a1 = dayOfYear(arriveAlice);
        int a2 = dayOfYear(leaveAlice);
        int b1 = dayOfYear(arriveBob);
        int b2 = dayOfYear(leaveBob);

        // Find the overlapping interval
        int start = max(a1, b1);
        int end = min(a2, b2);

        // Count inclusive days
        return max(0, end - start + 1);
    }
};
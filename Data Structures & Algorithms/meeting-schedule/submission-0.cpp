/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {

        if (intervals.empty()) {
            return true;
        }

        // Ordenamos en función del inicio de cada intervalo
        for (int i = 0; i < intervals.size(); i++) {
            for (int j = i + 1; j < intervals.size(); j++) {
                if (intervals[j].start < intervals[i].start) {
                    swap(intervals[i], intervals[j]);
                }
            }
        }

        int lastEnd = intervals[0].end;

        for (int i = 1; i < intervals.size(); i++) {

            if (intervals[i].start < lastEnd) {
                return false;
            }

            lastEnd = intervals[i].end;
        }

        return true;
    }
};